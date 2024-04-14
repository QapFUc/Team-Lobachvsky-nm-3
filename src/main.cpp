#include <cstddef>
#include <iostream>
#include "dataTypes/include/dataTypes/common.hpp"
#include "nm/utils/profiler.hpp"
#include "nm/utils/logger.hpp"
#include "core/TMA.hpp"

double testKernel(const double& a, nm::Timer& t, nm::Profiler& prof) {
	nm::Timer f{ nm::Timer::scopeTimer(&t)};
	nm::Profiler p{ prof.nest(nm::GET_CURRENT_SCOPE())};
	volatile double res = 0.l;
	std::cout << "kernel calc" << '\n';

	for (size_t i = 0; i < 1; i++) {
		for(size_t j = 0; j < 100; j++) {
			for(size_t k = 0; k < 100; k++) {
				res += a*a*0.5 + a;
			}
		}
	}

	return res;
}
void testMyFunc( double *A,  double *F, double *X, const int n,nm::Profiler& prof) {
	nm::Profiler p{ prof.nest(nm::GET_CURRENT_SCOPE())};
	nm::Status func = ProcessTMA(A,F,X,n,p);
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
	nm::Timer t;

	std::cout << "got prof" << '\n';
	double res = testKernel(1.05l, t, prof);
	double coeffs[5][3] = {{0.0,2.0,3.0},{1.0,2.0,3.0},{1.0,2.0,3.0},{1.0,2.0,3.0},{1.0,2.0,0.0}}; 
	double X_1[5];
	double X_2[5];
	double RHS_1[] = {5,6,7,8,9};
	double RHS_2[] = {5,6,7,8,9};
	double result_A[] = {0.0,2.0,3.0,1.0,2.0,3.0,1.0,2.0,3.0,1.0,2.0,3.0,1.0,2.0,0.0};
	std::cout << "MyFunc start" << '\n';
	testMyFunc(result_A,RHS_1,X_1,5,prof);
	std::cout << "RefFunc start" << '\n';
	testRefFunc(coeffs,RHS_2,X_2,5,prof);
	std::cout << "kernel passed" << '\n';
	auto profdata = prof.getAllData();
	std::cout << "Profiling data" << '\n';
	for (auto& d : profdata) {
		std::cout << d;
	}

	std::cout << t.getClocks() << '\n';
	std::cout << t.getDuration() << '\n';
	for(int i = 0;i<5;++i) {
		std::cout << "my = "<<X_1[i]<<" ref ="<<X_2[i]<<",";
	}
	return 0;
}
