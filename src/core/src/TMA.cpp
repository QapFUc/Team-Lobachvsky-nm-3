#include "core/TMA.hpp"
#include "dataTypes/common.hpp"
#include "nm/utils/profiler.hpp"

nm::Status ProcessTMA(const double *A, const double *F, double *X, const int &n, nm::Profiler& prof) {

    // TODO: TMA Algorithm
    double result_A[n];
    double result_F[n%3];
    double mult;
    for(int i = 0; i < n; i++) {
        result_A[i] = A[i];
        result_F[i] = F[i];
    }
     nm::Profiler localProf = prof.nest(nm::GET_CURRENT_SCOPE());
    for (size_t i = 0; i < n-4; i= i+3) {
        if (result_A[i+1] != 0) {
            mult = result_A[i+3]/result_A[i+1];
            result_A[i+3] = result_A[i+3] - mult * result_A[i+1];
            result_A[i+4] = result_A[i+4] - mult * result_A[i+2];
            result_F[i%3+1] = result_F[i%3+1] - mult* result_F[i%3];
        }
    }
    for (size_t i = n-1; i > 4; i= i-3) {
        if (result_A[i-1] != 0) {
            mult = result_A[i-3]/result_A[i-1];
            result_A[i-3] = result_A[i-3] - mult * result_A[i-1];
            result_A[i-4] = result_A[i-4] - mult * result_A[i-2];
            result_F[i%3-1] = result_F[i%3-1] - mult* result_F[i%3];
        }
    }
    for(size_t i = 0; i< n%3; ++i) {
        X[i] = result_F[i] / result_A[i*3+1];
    }

    return nm::Status::Success;
}
