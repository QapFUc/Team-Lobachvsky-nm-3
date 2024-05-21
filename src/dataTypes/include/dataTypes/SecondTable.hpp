#ifndef SECONDTABLE_H
#define SECONDTABLE_H

#include <vector>
#include <string>
#include <stdexcept>

struct SecondTable {
    std::vector<double> x_j;
    std::vector<double> F_x_j;
    std::vector<double> S_x_j;
    std::vector<double> F_x_j_minus_S_x_j;
    std::vector<double> F_prime_x_j;
    std::vector<double> S_prime_x_j;
    std::vector<double> F_prime_x_j_minus_S_prime_x_j;

    std::vector<double>& operator[](const std::string& name);
    const std::vector<double>& operator[](const std::string& name) const;

    void setValue(const std::string& name, const std::vector<double>& values);

    std::vector<double> getValue(const std::string& name) const;
};

#endif // SECONDTABLE_H
