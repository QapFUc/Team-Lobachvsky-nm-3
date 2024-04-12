#pragma once

#include "dataTypes/common.hpp"
#include "nm/utils/profiler.hpp"

// Tridiagonal matrix algorithm
// A - pointer to tridiagonal matrix data
// data consists of triplets of numbers which lies in one row in original linear
// syste, matrix
// F - pointer to RHS of linear systrm
// X - pointer to variable to find 
// returns only nm::Status::Failure or nm::Status::Success
nm::Status ProcessTMA(const double* A, const double* F, double* X, nm::Profiler& prof);
