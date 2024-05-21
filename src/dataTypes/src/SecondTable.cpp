#include "dataTypes/SecondTable.hpp"

std::vector<double>& SecondTable::operator[](const std::string& name) {
    if (name == "x(j)") return x_j;
    if (name == "F(x_j)") return F_x_j;
    if (name == "S(x_j)") return S_x_j;
    if (name == "F(x_j) - S(x_j)") return F_x_j_minus_S_x_j;
    if (name == "F'(x_j)") return F_prime_x_j;
    if (name == "S'(x_j)") return S_prime_x_j;
    if (name == "F'(x_j) - S'(x_j)") return F_prime_x_j_minus_S_prime_x_j;
    throw std::invalid_argument("Invalid header name");
}

const std::vector<double>& SecondTable::operator[](const std::string& name) const {
    if (name == "x(j)") return x_j;
    if (name == "F(x_j)") return F_x_j;
    if (name == "S(x_j)") return S_x_j;
    if (name == "F(x_j) - S(x_j)") return F_x_j_minus_S_x_j;
    if (name == "F'(x_j)") return F_prime_x_j;
    if (name == "S'(x_j)") return S_prime_x_j;
    if (name == "F'(x_j) - S'(x_j)") return F_prime_x_j_minus_S_prime_x_j;
    throw std::invalid_argument("Invalid header name");
}

void SecondTable::setValue(const std::string& name, const std::vector<double>& values) {
    (*this)[name] = values;
}

std::vector<double> SecondTable::getValue(const std::string& name) const {
    return (*this)[name];
}