//
// Created by René Descartes Muala on 15/10/24.
//

#include "Path.h"

namespace model {
    const Snapshot& Path::get_last() const
    {
        if(snapshots.empty())
            throw std::out_of_range("Path::get_last() called on an empty Path");
        return snapshots.back();
    }
} // model