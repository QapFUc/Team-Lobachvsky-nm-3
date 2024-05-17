#include <cstddef>
#include <iostream>
#include "dataTypes/include/dataTypes/common.hpp"
#include "nm/utils/profiler.hpp"
#include "nm/utils/logger.hpp"
#include <cstdlib>
#include "core/TMA.hpp"

void testMyFunc( double *A,  double *F, double *X, const int n,nm::Profiler& prof) {
	nm::Status func = ProcessTMA(A,F,X,n,prof);
}

void testRefFunc(double coeffs[][3],double *rhs, double *x, const size_t& n,nm::Profiler& prof) {
	nm::Profiler p{ prof.nest(nm::GET_CURRENT_SCOPE())};
	double temp;
    for (size_t i = 1; i < n; i++) { 
        temp = coeffs[i][0] / coeffs[i - 1][1];
        coeffs[i][1] = coeffs[i][1] - temp * coeffs[i - 1][2];
        rhs[i] = rhs[i] - temp * rhs[i - 1];
    }

    x[n - 1] = rhs[n - 1] / coeffs[n - 1][1];

    for (long long int i = n - 2; i >= 0; i--) {
        x[i] = (rhs[i] - coeffs[i][2] * x[i + 1]) / coeffs[i][1];
    }
}


int main(int argc, char* argv[]) {
	nm::Profiler prof;
	long long int  n = 30000;

	std::cout << "got prof" << '\n';
	double coeffs[n][3];
	double X_1[n];
	double X_2[n];
	double RHS_1[n];
	double RHS_2[n];
	double result_A[n];
	result_A[0]=result_A[n*3]=0;
    for (int i = 1; i < n*3-1; ++i) {
        result_A[i] = static_cast<double>(rand()) / RAND_MAX; // Генерируем случайное число от 0 до 1
    }
	for (int i = 0; i<n;i++) {
		coeffs[i][0] = result_A[i*3];
		coeffs[i][1] = result_A[i*3+1];
		coeffs[i][2] = result_A[i*3+2];
	}
	for (int i = 0; i < n; ++i) {
        RHS_1[i] = static_cast<double>(rand()) / RAND_MAX; // Генерируем случайное число от 0 до 1
		RHS_2[i]=RHS_1[i];
    }
	testMyFunc(result_A,RHS_1,X_1,5,prof);
	testRefFunc(coeffs,RHS_2,X_2,5,prof);
	auto profdata = prof.getAllData();
	std::cout << "Profiling data" << '\n';
	for (auto& d : profdata) {
		std::cout << d;
	}
	return 0;
}
