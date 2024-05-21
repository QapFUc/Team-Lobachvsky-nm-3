#pragma once

#ifndef CONFIG_HPP
#    define CONFIG_HPP

struct Config {
    double XStart = .0;
    double XEnd = .0;
    double N = .0;
    int Task = 0;
    Config(const double& XStart, const double& XEnd, const double& N, const int& Task);
    Config() = default;
};
#endif