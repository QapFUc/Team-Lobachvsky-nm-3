#pragma once

#include <cmath>
#include <cstddef>
#include <iostream>

namespace testing {

template <typename T>
bool CompareArrays(const T* a1, const T* a2, const std::size_t& n, const double& absTolerance) {
    double maxTolerance = 0.l;
    double currTolerance = 0.l;

    for (size_t i = 0; i < n; ++i) {
        currTolerance = std::abs(a1[i] - a2[i]);
        if (currTolerance > maxTolerance)
            maxTolerance = currTolerance;
    }

    if (maxTolerance < absTolerance)
        return true;

    std::cout << "Max toleranse = " << maxTolerance << " >= " << absTolerance << '\n';
    return false;
}

}  // namespace testing