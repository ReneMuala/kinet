//
// Created by René Descartes Muala on 15/10/24.
//

#include "Engine.h"

model::EntityID service::Engine::emplace(const model::Snapshot& snapshot)
{
    for (auto& entity : entities)
    {
        auto r = abs(entity.path.get_last() - snapshot);
        if (r < 5)
        {
            entity.path.snapshots.emplace_back(snapshot);
            return entity.id;
        }
    }
    return -1;
}

model::EntityID service::Engine::step(std::string& src)
{
    std::stringstream stream(src);

    std::string name;
    double x1, y1, x2, y2;

    stream >> name >> x1 >> y1 >> x2 >> y2;

    auto snapshot = model::Snapshot{
        .start = cv::Point2f(x1, y1),
        .end = cv::Point2f(x2, y2)
    };

    model::EntityID id = emplace(snapshot);

    if (id == -1)
    {
        auto entity = model::Entity{
            .name = name,
        };

        id = entity.id;

        std::cout << "NEW ENTITY: " << entity.name << std::endl;

        entity.path.snapshots.emplace_back(snapshot);
        entities.emplace_back(entity);
    }

    return id;
}
