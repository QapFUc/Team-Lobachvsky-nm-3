#include "core/Eval.hpp"

#include <cmath>
#include <cstddef>
#include <functional>
#include <iostream>
#include <vector>

double func(const double& x) {
    return std::exp(x - 1) * (x - 2);
}

int main() {
    double x_start = 0.l;
    double step = 0.01l;
    size_t n = 100;
    double absTolerance = 1e-4;

    std::vector<double> xs(n);
    for (size_t i = 0; i < n; ++i) {
        xs[i] = x_start + i * step;
    }

    std::vector<double> values(n);
    for (size_t i = 0; i < n; ++i) {
        values[i] = func(xs[i]);
    }

    CubicSplineInterpolation interpWFunc = CubicSplineInterpolation::Interpolate(x_start, n, step, &func, 0, 1);
    CubicSplineInterpolation interpWValues = CubicSplineInterpolation::Interpolate(x_start, n, step, values, 0, 1);
    CubicSplineInterpolation interpWXs = CubicSplineInterpolation::Interpolate(xs, values, 0, 1);

    double x = x_start;
    for (size_t i = 0; i < n; ++i) {
        if (std::abs(interpWFunc(x) - func(x)) >= absTolerance) {
            std::cout << "Tolerance between interpolation and function in x=" << x << " more than limit " << absTolerance << '\n';
            std::cout << "Interpolation value = " << interpWFunc(x) << " Func value = " << func(x) << '\n';
            return 1;
        }
        if (std::abs(interpWValues(x) - func(x)) >= absTolerance) {
            std::cout << "Tolerance between interpolation and function in x=" << x << " more than limit " << absTolerance << '\n';
            std::cout << "Interpolation value = " << interpWValues(x) << " Func value = " << func(x) << '\n';
            return 1;
        }
        if (std::abs(interpWXs(x) - func(x)) >= absTolerance) {
            std::cout << "Tolerance between interpolation and function in x=" << x << " more than limit " << absTolerance << '\n';
            std::cout << "Interpolation value = " << interpWXs(x) << " Func value = " << func(x) << '\n';
            return 1;
        }
    }
    return 0;
}