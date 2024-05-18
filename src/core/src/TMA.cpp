#include "core/TMA.hpp"
#include "dataTypes/common.hpp"
#include "nm/utils/profiler.hpp"

nm::Status ProcessTMA(double *A, double *F, double *X, const int &n, nm::Profiler& prof) {
    nm::Profiler p{ prof.nest(nm::GET_CURRENT_SCOPE())};
    double mult;
    for (size_t i = 1; i < n; ++i) {
        mult = A[i * 3] / A[(i - 1) * 3 + 1];
        A[i * 3 + 1] = A[i * 3 + 1] - mult * A[(i - 1) * 3 + 2];
        F[i] = F[i] - mult * F[i - 1];
    }

    X[n - 1] = F[n - 1] / A[(n - 1) * 3 + 1];

    for (long long i = n - 2; i >= 0; i--) {
        X[i] = (F[i] - A[i * 3 + 2] * X[i + 1]) / A[i * 3 + 1];
    }

    return nm::Status::Success;
}

nm::Status ProcessTMA(double *A, double *F, double *X, const int &n) {
    double mult;
    for (size_t i = 1; i < n; ++i) {
        mult = A[i * 3] / A[(i - 1) * 3 + 1];
        A[i * 3 + 1] = A[i * 3 + 1] - mult * A[(i - 1) * 3 + 2];
        F[i] = F[i] - mult * F[i - 1];
    }

    X[n - 1] = F[n - 1] / A[(n - 1) * 3 + 1];

    for (long long i = n - 2; i >= 0; i--) {
        X[i] = (F[i] - A[i * 3 + 2] * X[i + 1]) / A[i * 3 + 1];
    }


    return nm::Status::Success;
}
