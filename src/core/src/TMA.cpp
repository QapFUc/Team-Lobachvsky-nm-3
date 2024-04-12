#include "core/TMA.hpp"
#include "dataTypes/common.hpp"
#include "nm/utils/profiler.hpp"

nm::Status ProcessTMA(const double *A, const double *F, double *X, nm::Profiler& prof) {
    nm::Profiler localProf = prof.nest(nm::GET_CURRENT_SCOPE());

    // TODO: TMA Algorithm

    return nm::Status::Success;
}