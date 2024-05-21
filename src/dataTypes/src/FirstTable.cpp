#include "dataTypes/FirstTable.hpp"

std::vector<double>& FirstTable::operator[](const std::string& name) {
    if (name == "x(i-1)") return x_i_1;
    if (name == "x(i)") return x_i;
    if (name == "a(i)") return a_i;
    if (name == "b(i)") return b_i;
    if (name == "c(i)") return c_i;
    if (name == "d(i)") return d_i;
    throw std::invalid_argument("Invalid header name");
}

const std::vector<double>& FirstTable::operator[](const std::string& name) const {
    if (name == "x(i-1)") return x_i_1;
    if (name == "x(i)") return x_i;
    if (name == "a(i)") return a_i;
    if (name == "b(i)") return b_i;
    if (name == "c(i)") return c_i;
    if (name == "d(i)") return d_i;
    throw std::invalid_argument("Invalid header name");
}

void FirstTable::setValue(const std::string& name, const std::vector<double>& values) {
    (*this)[name] = values;
}

std::vector<double> FirstTable::getValue(const std::string& name) const {
    return (*this)[name];
}
