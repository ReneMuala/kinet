//
// Created by René Descartes Muala on 15/10/24.
//

#ifndef ENTITY_H
#define ENTITY_H
#include <string>

#include "path.h"

namespace model {

typedef long long EntityID;

struct Entity {
    static EntityID globalId;
    EntityID id;
    Path path;
    double speed;
    std::string name;
};

} // model

#endif //ENTITY_H
