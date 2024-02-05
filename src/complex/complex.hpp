/**
 * @file    complex.hpp
 * @brief   This file contains the declaration of the complex number class.
 * @author  Mert Ozer
 * @date    26.11.2023
 * @version 1.0
 */
#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>

namespace mozer
{

class Complex{
private:
    double m_real {};
    double m_imag {};
public:
    Complex() = default;
    Complex(double r, double i);
    Complex operator+(const Complex& obj) const;
    Complex operator-(const Complex& obj) const;
    Complex operator*(const Complex& obj) const;
    bool operator==(const Complex& obj) const;
    Complex& operator++();
    Complex& operator--();
    Complex operator++(int);
    Complex operator--(int);
    friend std::ostream& operator<<(std::ostream& out, const Complex& obj);
};

}

#endif // COMPLEX_HPP