#include "core/Eval.hpp"

#include "core/TMA.hpp"
#include "dataTypes/common.hpp"
#include "nm/utils/logger.hpp"
#include <cstddef>
#include <stdexcept>
#include <vector>

CubicSpline::CubicSpline(const double& x, const double& a, const double& b, const double& c, const double& d) {
    coefs[0] = a;
    coefs[1] = b;
    coefs[2] = c;
    coefs[3] = d;
    this->a = x;
}

double CubicSpline::operator()(const double& x) {
    double y = x - a;
    return coefs[0] + coefs[1] * y + coefs[2] * y * y + coefs[3] * y * y * y;
}

CubicSplineInterpolation::CubicSplineInterpolation(std::vector<CubicSpline> splines, std::vector<double> points) {
    this->splines = splines;
    this->points = points;
}

CubicSplineInterpolation CubicSplineInterpolation::Interpolate(const double& x_start,
                                                               const size_t& n,
                                                               const double& step,
                                                               std::function<double(double)> f,
                                                               const double& lval,
                                                               const double& rval) {
    std::vector<double> mTMA_v(n * 3 + 3);
    std::vector<double> mTMA_rhs_v(n + 1);
    std::vector<double> C(n);
    double* mTMA = mTMA_v.data();
    double* mTMA_rhs = mTMA_rhs_v.data();

    mTMA[0] = 0.l;
    mTMA[1] = 1.l;
    mTMA[2] = 0.l;
    mTMA[n * 3] = 0.l;
    mTMA[n * 3 + 1] = 1.l;
    mTMA[n * 3 + 2] = 0.l;

    mTMA_rhs[0] = lval;
    mTMA_rhs[n] = rval;

    for (size_t i = 1; i < n; ++i) {
        mTMA[i * 3] = step;
        mTMA[i * 3 + 1] = 4 * step;
        mTMA[i * 3 + 2] = step;

        mTMA_rhs[i] = 6 * ((f(x_start + (i + 1) * step) - f(x_start + i * step)) / step - (f(x_start + i * step) - f(x_start + (i - 1) * step)) / step);
    }

    if (ProcessTMA(mTMA, mTMA_rhs, C.data(), n) != nm::Status::Success) {
        LOG_ERROR_CLI("Interpolation failed: error during processing TMA");
        throw std::runtime_error("Interpolation failed");
    }

    std::vector<double> ps(n);
    std::vector<CubicSpline> splines(n - 1);

    ps[0] = x_start;
    for (size_t i = 1; i < n; ++i) {
        ps[i] += step;
        splines[i - 1] =
            CubicSpline(ps[i], f(ps[i]), ((f(ps[i]) - f(ps[i - 1])) / step + C[i] * step / 3 + C[i - 1] * step / 6), C[i] / 2, ((C[i] - C[i - 1]) / step) / 6);
    }

    return CubicSplineInterpolation(splines, ps);
}

CubicSplineInterpolation CubicSplineInterpolation::Interpolate(const double& x_start,
                                                               const size_t& n,
                                                               const double& step,
                                                               std::vector<double> values,
                                                               const double& lval,
                                                               const double& rval) {
    std::vector<double> mTMA_v(n * 3 + 3);
    std::vector<double> mTMA_rhs_v(n + 1);
    std::vector<double> C(n);
    double* mTMA = mTMA_v.data();
    double* mTMA_rhs = mTMA_rhs_v.data();

    mTMA[0] = 0.l;
    mTMA[1] = 1.l;
    mTMA[2] = 0.l;
    mTMA[n * 3] = 0.l;
    mTMA[n * 3 + 1] = 1.l;
    mTMA[n * 3 + 2] = 0.l;

    mTMA_rhs[0] = lval;
    mTMA_rhs[n] = rval;

    for (size_t i = 1; i < n; ++i) {
        mTMA[i * 3] = step;
        mTMA[i * 3 + 1] = 4 * step;
        mTMA[i * 3 + 2] = step;

        mTMA_rhs[i] = 6 * ((values[i + 1] - values[i]) / step - (values[i] - values[i - 1]) / step);
    }

    if (ProcessTMA(mTMA, mTMA_rhs, C.data(), n) != nm::Status::Success) {
        LOG_ERROR_CLI("Interpolation failed: error during processing TMA");
        throw std::runtime_error("Interpolation failed");
    }

    std::vector<double> ps(n);
    std::vector<CubicSpline> splines(n - 1);

    ps[0] = x_start;
    for (size_t i = 1; i < n; ++i) {
        ps[i] += step;
        splines[i - 1] =
            CubicSpline(ps[i], values[i], ((values[i] - values[i - 1]) / step + C[i] * step / 3 + C[i - 1] * step / 6), C[i] / 2, ((C[i] - C[i - 1]) / step) / 6);
    }

    return CubicSplineInterpolation(splines, ps);
}

CubicSplineInterpolation CubicSplineInterpolation::Interpolate(std::vector<double> xs, std::vector<double> values, const double& lval, const double& rval) {
    size_t n = xs.size();
    std::vector<double> mTMA_v(n * 3 + 3);
    std::vector<double> mTMA_rhs_v(n + 1);
    std::vector<double> C(n);
    double* mTMA = mTMA_v.data();
    double* mTMA_rhs = mTMA_rhs_v.data();

    mTMA[0] = 0.l;
    mTMA[1] = 1.l;
    mTMA[2] = 0.l;
    mTMA[n * 3] = 0.l;
    mTMA[n * 3 + 1] = 1.l;
    mTMA[n * 3 + 2] = 0.l;

    mTMA_rhs[0] = lval;
    mTMA_rhs[n] = rval;

    for (size_t i = 1; i < n; ++i) {
        mTMA[i * 3] = xs[i] - xs[i - 1];
        mTMA[i * 3 + 1] = 2 * (xs[i + 1] - xs[i - 1]);
        mTMA[i * 3 + 2] = xs[i + 1] - xs[i];

        mTMA_rhs[i] = 6 * ((values[i + 1] - values[i]) / (xs[i + 1] - xs[i]) - (values[i] - values[i - 1]) / (xs[i] - xs[i - 1]));
    }

    if (ProcessTMA(mTMA, mTMA_rhs, C.data(), n) != nm::Status::Success) {
        LOG_ERROR_CLI("Interpolation failed: error during processing TMA");
        throw std::runtime_error("Interpolation failed");
    }

    std::vector<CubicSpline> splines(n - 1);

    for (size_t i = 1; i < n; ++i) {
        double step = xs[i] - xs[i - 1];
        splines[i - 1] =
            CubicSpline(xs[i], values[i], ((values[i] - values[i - 1]) / step + C[i] * step / 3 + C[i - 1] * step / 6), C[i] / 2, ((C[i] - C[i - 1]) / step) / 6);
    }

    return CubicSplineInterpolation(splines, xs);
}

double CubicSplineInterpolation::operator()(const double& x) {
    for (size_t i = 0; i < splines.size(); ++i) {
        if (x >= points[i] && x <= points[i + 1]) {
            return splines[i](x);
        }
    }
    return 0;
}