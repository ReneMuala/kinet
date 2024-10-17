//
// Created by René Descartes Muala on 15/10/24.
//

#include "Engine.h"

model::EntityID service::Engine::emplace(const model::Snapshot& snapshot, const std::string& name)
{
    for (auto& entity : entities)
    {
        if (not entity->valid)
            continue;
        auto r = abs(entity->path.get_last() - snapshot);
        if (r <= 40 and entity->name == name)
        {
            entity->path.addSnapshot(snapshot);
            return entity->id;
        }
    }
    return -1;
}

model::EntityID service::Engine::step(std::string& src)
{
    std::stringstream stream(src);
    validateEntities();
    std::string name;

    stream >> name;

    if (name.starts_with("#LMB"))
    {
        double cx, cy, r;
        int count;
        stream >> cx >> cy >> r >> count;
        const auto limbo = model::Limbo{
            .name = name,
            .center = cv::Point2f(cx, cy),
            .radius = r,
            .requiredLimbosCount = count
        };
        return limboStep(limbo);
    }
    else
    {
        double x1, y1, x2, y2;
        stream >> x1 >> y1 >> x2 >> y2;

        const auto snapshot = model::Snapshot{
            .start = cv::Point2f(x1, y1),
            .end = cv::Point2f(x2, y2)
        };
        return snapshotStep(snapshot, name);
    }
}

model::EntityID service::Engine::limboStep(const model::Limbo& limbo)
{
    this->limbos.emplace_back(limbo);
    return limbo.id;
}

model::EntityID service::Engine::snapshotStep(const model::Snapshot& snapshot, const std::string& entityName)
{
    using namespace model;
    model::EntityID id = emplace(snapshot, entityName);

    if (id == -1)
    {
        auto& entity = entities.emplace_back(std::make_unique<Entity>(entityName));
        id = entity->id;

        std::cout << "NEW ENTITY: " << entity->name << " #" << entities.size() << std::endl;

        entity->path.addSnapshot(snapshot);
        // entity->isolate_train();
    }
    return id;
}

void service::Engine::validateEntities()
{
    using namespace model;
    for (auto& entity : entities)
    {
        if (not entity->valid)
            continue;
        if (std::chrono::duration_cast<
                std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()) - entity->path.
            get_last().
            timestamp > std::chrono::duration<double>(std::chrono::milliseconds(750)))
        {
            entity->valid = false;
        }
        else
        {
            for (auto& limbo : limbos)
            {
                if (entity->limbos.contains(limbo.name))
                    continue;
                if (limbo.center - entity->path.get_last().get_center() < limbo.radius)
                {
                    entity->limbos[limbo.name] = std::chrono::duration_cast<
                        std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
                }
            }
        }
    }
}

