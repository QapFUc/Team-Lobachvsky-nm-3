#include "dataTypes/config.hpp"

Config::Config(const double& XStart, const double& XEnd, const double& N, const int& Task) {
    this->XStart = XStart;
    this->XEnd = XEnd;
    this->N = N;
    this->Task = Task;
}