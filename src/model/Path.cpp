//
// Created by René Descartes Muala on 15/10/24.
//

#include "Path.h"

namespace model {
    void Path::addSnapshot(const Snapshot& snapshot)
    {
        snapshots[size] = snapshot;
        size = (size + 1) % max_size;
    }

    const Snapshot& Path::get_last() const
    {
        if (size == 0)
            return snapshots[max_size - 1];
        return snapshots[size - 1];
        if(snapshots.empty())
            throw std::out_of_range("Path::get_last() called on an empty Path");
        return snapshots.back();
    }
} // model