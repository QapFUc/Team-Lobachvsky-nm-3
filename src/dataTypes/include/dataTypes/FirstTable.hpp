#ifndef FIRSTTABLE_H
#define FIRSTTABLE_H

#include <vector>
#include <string>
#include <stdexcept>

struct FirstTable {
    std::vector<double> x_i_1;
    std::vector<double> x_i;
    std::vector<double> a_i;
    std::vector<double> b_i;
    std::vector<double> c_i;
    std::vector<double> d_i;

    std::vector<double>& operator[](const std::string& name);
    const std::vector<double>& operator[](const std::string& name) const;

    void setValue(const std::string& name, const std::vector<double>& values);

    std::vector<double> getValue(const std::string& name) const;
};

#endif // FIRSTTABLE_H
