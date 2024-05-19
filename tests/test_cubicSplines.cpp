#include "core/Eval.hpp"

#include <cmath>
#include <cstddef>
#include <functional>
#include <iostream>
#include <vector>

double func(const double& x) {
    return (std::log(x+1))/x;
}

int main() {
    double x_start = 2l;
    size_t n = 100;
    double step = 4-x_start/n;
    double absTolerance = 1e-4;

    std::vector<double> xs(n+1);
    for (size_t i = 0; i < n + 1; ++i) {
        xs[i] = x_start + i * step;
    }

    std::vector<double> values(n+1);
    for (size_t i = 0; i < n; ++i) {
        values[i] = func(xs[i]);
    }

    CubicSplineInterpolation interpWFunc = CubicSplineInterpolation::Interpolate(x_start, n, step, &func, 0, 0);
    CubicSplineInterpolation interpWValues = CubicSplineInterpolation::Interpolate(x_start, n, step, values, 0, 1);
    CubicSplineInterpolation interpWXs = CubicSplineInterpolation::Interpolate(xs, values, 0, 1);

    double x = x_start;
    for (size_t i = 0; i < n; ++i) {
        std::cout<<interpWFunc(x)<<" "<<func(x)<<std::endl;
        if (std::abs(interpWFunc(x) - func(x)) >= absTolerance) {
            std::cout << "(Interpolation w/ function given) Tolerance between interpolation and function in x=" << x << " more than limit " << absTolerance << '\n';
            std::cout << "Interpolation value = " << interpWFunc(x) << " Func value = " << func(x) << '\n';
            return 1;
        }
        if (std::abs(interpWValues(x) - func(x)) >= absTolerance) {
            std::cout << "(Interpolation w/ values given) Tolerance between interpolation and function in x=" << x << " more than limit " << absTolerance << '\n';
            std::cout << "Interpolation value = " << interpWValues(x) << " Func value = " << func(x) << '\n';
            return 1;
        }
        if (std::abs(interpWXs(x) - func(x)) >= absTolerance) {
            std::cout << "(Interpolation w/ xs and values given) Tolerance between interpolation and function in x=" << x << " more than limit " << absTolerance << '\n';
            std::cout << "Interpolation value = " << interpWXs(x) << " Func value = " << func(x) << '\n';
            return 1;
        }
        x += step;
    }
    return 0;
}