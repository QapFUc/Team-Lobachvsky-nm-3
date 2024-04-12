#pragma once

#include "dataTypes/common.hpp"

// Tridiagonal matrix algorithm
// A - pointer to tridiagonal matrix data
// data consists of triplets of numbers which lies in one row in original linear
// syste, matrix
// F - pointer to RHS of linear systrm
// X - pointer to variable to find 
nm::Status ProcessTMA(const double* A, const double* F, double* X);
