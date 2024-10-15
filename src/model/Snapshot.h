//
// Created by René Descartes Muala on 15/10/24.
//

#ifndef SNAPSHOT_H
#define SNAPSHOT_H
#include <opencv2/opencv.hpp>

#include "entity.h"

namespace model {

struct Snapshot {
    cv::Point2f start, end;
    time_t timestamp;
};

} // model

#endif //SNAPSHOT_H
