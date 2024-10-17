//
// Created by René Descartes Muala on 15/10/24.
//

#ifndef SNAPSHOT_H
#define SNAPSHOT_H
#include <opencv2/opencv.hpp>
#include <chrono>
namespace model {
    double operator-(const cv::Point2f& p1, const cv::Point2f& p2);
struct Snapshot {
    cv::Point2f start{0}, end{0};
    std::chrono::duration<long long, std::ratio<1, 1000>> timestamp = std::chrono::duration_cast<
        std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    cv::Point2f get_center() const;
    double operator-(const Snapshot &other) const;
};

} // model

#endif //SNAPSHOT_H
