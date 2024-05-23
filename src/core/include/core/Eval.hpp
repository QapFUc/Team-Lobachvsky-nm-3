#pragma once

#include <cstddef>
#include <functional>
#include <vector>

class CubicSpline {
    // S(x) = ai + bi(x-a) + ci/2 * (x-a)^2 + di/6 * (x-a)^3
    double coefs[4];  // ai, bi, ci, di
    double a;

public:
    CubicSpline() = default;
    ~CubicSpline() = default;

    CubicSpline(const double&, const double&, const double&, const double&, const double&);
    // CubicSpline is a callable object
    double operator()(const double& x) const;

    double get1stDerivative(const double&) const;
    double get2ndDerivative(const double&) const;

    double getCoef(const size_t& i) const {
        return coefs[i];
    }

    double getPoint() const {
        return a;
    }
};

class CubicSplineInterpolation {
    std::vector<CubicSpline> splines;
    std::vector<double> points;

public:
    CubicSplineInterpolation() = default;
    ~CubicSplineInterpolation() = default;

    CubicSplineInterpolation(std::vector<CubicSpline>, std::vector<double>);

    double operator()(const double&) const;
    static CubicSplineInterpolation Interpolate(const double& x_start,
                                                const size_t& n,
                                                const double& step,
                                                std::function<double(double)> f,
                                                const double& lval,
                                                const double& rval);
    static CubicSplineInterpolation Interpolate(const double& x_start,
                                                const size_t& n,
                                                const double& step,
                                                std::vector<double> values,
                                                const double& lval,
                                                const double& rval);
    static CubicSplineInterpolation Interpolate(std::vector<double> xs, std::vector<double> values, const double& lval, const double& rval);


    double get1stDerivative(const double&) const;
    double get2ndDerivative(const double&) const;
    
    const CubicSpline& getSpline(const size_t& i) const {
        return splines[i];
    }
    double getPoint(const size_t& i) const {
        return points[i];
    }
};