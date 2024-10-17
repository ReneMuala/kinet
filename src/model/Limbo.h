//
// Created by dte on 10/16/2024.
//

#ifndef LIMBO_HPP
#define LIMBO_HPP
#include <opencv2/opencv.hpp>

#include "Entity.h"

namespace model {
struct Limbo {
    EntityID id = Entity::globalId++;
    std::string name;
    cv::Point2f center;
    double radius{};
    int requiredLimbosCount = 2;
};
} // model

#endif //LIMBO_HPP
