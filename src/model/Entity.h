//
// Created by René Descartes Muala on 15/10/24.
//

#ifndef ENTITY_H
#define ENTITY_H
#include <string>
#include <dlib/mlp.h>
#include <dlib/matrix/matrix.h>

#include "Path.h"

namespace model {

typedef long long EntityID;

typedef cv::Point2f Speed2D;

struct Entity
{
    static EntityID globalId;
    EntityID id = globalId++;
    Path path;
    Snapshot lastSnapshot;
    std::string name;
    std::string limbo;
    std::unordered_map<std::string, std::chrono::duration<long long, std::ratio<1, 1000>>> limbos;
    long limbo_count{};
    bool valid = true;
    explicit Entity(const std::string & name): name (name) {}
};

} // model

#endif //ENTITY_H
