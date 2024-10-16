//
// Created by René Descartes Muala on 15/10/24.
//

#ifndef SNAPSHOT_H
#define SNAPSHOT_H
#include <opencv2/opencv.hpp>

namespace model {

struct Snapshot {
    cv::Point2f start, end;
    time_t timestamp = time(nullptr);
    cv::Point2f get_center() const;
    double operator-(const Snapshot &other) const;
};

} // model

#endif //SNAPSHOT_H
