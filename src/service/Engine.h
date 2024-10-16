//
// Created by René Descartes Muala on 15/10/24.
//

#ifndef ENGINE_H
#define ENGINE_H
#include "../model/Entity.h"
#include <sstream>
namespace service {
    class Engine {
        public:
        std::vector<model::Entity> entities;
        model::EntityID emplace(const model::Snapshot& snapshot);
        model::EntityID step(std::string& src);
    };
}

#endif //ENGINE_H
