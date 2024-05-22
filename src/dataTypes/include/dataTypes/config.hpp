#pragma once

#include <cstddef>
#ifndef CONFIG_HPP
#    define CONFIG_HPP

struct Config {
    double XStart = .0;
    double XEnd = .0;
    size_t N = 0;
    size_t N_control = 0;
    int Task = 0;
    Config(const double& XStart, const double& XEnd, const size_t& N, const int& Task, const size_t& N_control);
    Config() = default;
};
#endif