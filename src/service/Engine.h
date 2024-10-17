//
// Created by René Descartes Muala on 15/10/24.
//

#ifndef ENGINE_H
#define ENGINE_H
#include "../model/Entity.h"
#include <sstream>
#include "../model/Limbo.h"
namespace service {
    class Engine {
    public:

        std::vector<std::unique_ptr<model::Entity>> entities;
        std::vector<model::Limbo> limbos;
        model::EntityID emplace(const model::Snapshot& snapshot, const std::string & name);
        model::EntityID step(std::string& src);
        model::EntityID limboStep(const model::Limbo & limbo);
        model::EntityID  snapshotStep(const model::Snapshot& snapshot, const std::string & entityName);
        void validateEntities();
        void validateLimbos();
    };
}

#endif //ENGINE_H
