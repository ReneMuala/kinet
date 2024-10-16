//
// Created by René Descartes Muala on 15/10/24.
//

#ifndef PATH_H
#define PATH_H
#include <vector>

#include "Snapshot.h"

namespace model {

struct Path {
    std::vector<Snapshot> snapshots;
    std::string entity_name;

    [[nodiscard]] const Snapshot& get_last() const;
};

} // model

#endif //PATH_H
