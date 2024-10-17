//
// Created by René Descartes Muala on 15/10/24.
//

#ifndef PATH_H
#define PATH_H
#include <vector>

#include "Snapshot.h"

namespace model {

struct Path {
    static constexpr auto max_size = 100;
    std::array<Snapshot, max_size> snapshots;
    std::string entity_name;
    int size{};
    void addSnapshot(const Snapshot & snapshot);
    [[nodiscard]] const Snapshot& get_last() const;
};

} // model

#endif //PATH_H
