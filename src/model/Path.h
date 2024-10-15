//
// Created by René Descartes Muala on 15/10/24.
//

#ifndef PATH_H
#define PATH_H
#include <vector>

#include "snapshot.h"

namespace model {

struct Path: std::vector<Snapshot> {
    std::string entity_name;
};

} // model

#endif //PATH_H
