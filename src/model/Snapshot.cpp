//
// Created by René Descartes Muala on 15/10/24.
//

#include "Snapshot.h"
#include <cmath>
namespace model {
    double operator-(const cv::Point2f& p1, const cv::Point2f& p2)
    {
        return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
    }

    cv::Point2f Snapshot::get_center() const
    {
        return cv::Point2f( start.x + (end.x - start.x) / 2, start.y + (end.y - start.y) / 2 );
    }

    double Snapshot::operator-(const Snapshot& other) const
    {
        auto const c1 = get_center();
        auto const c2 = other.get_center();
        return c1 - c2;
    }
} // model