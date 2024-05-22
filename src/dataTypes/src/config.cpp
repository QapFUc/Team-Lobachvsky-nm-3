#include "dataTypes/config.hpp"
#include <cstddef>

Config::Config(const double& XStart, const double& XEnd, const size_t& N, const int& Task, const size_t& N_control) {
    this->XStart = XStart;
    this->XEnd = XEnd;
    this->N = N;
    this->Task = Task;
    this->N_control = N_control;
}