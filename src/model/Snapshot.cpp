//
// Created by René Descartes Muala on 15/10/24.
//

#include "Snapshot.h"
#include <cmath>
namespace model {
    cv::Point2f Snapshot::get_center() const
    {
        return cv::Point2f( start.x + (end.x - start.x) / 2, start.y + (end.y - start.y) / 2 );
    }

    double Snapshot::operator-(const Snapshot& other) const
    {
        auto const c1 = get_center();
        auto const c2 = other.get_center();
        return sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));
    }
} // model