/**
 * @file    complex.cpp
 * @brief   This file contains the declaration of the complex number class.
 * @author  Mert Ozer
 * @date    26.11.2023
 * @version 1.0
 */
#include "complex.hpp"

namespace mozer
{

Complex::Complex(double r, double i) : m_real(r), m_imag(i) {}

Complex Complex::operator+(const Complex& obj) const {
    return Complex(m_real + obj.m_real, m_imag + obj.m_imag);
}

Complex Complex::operator-(const Complex& obj) const {
    return Complex(m_real - obj.m_real, m_imag - obj.m_imag);
}

Complex Complex::operator*(const Complex& obj) const {
    return Complex(m_real * obj.m_real - m_imag * obj.m_imag, m_real * obj.m_imag + m_imag * obj.m_real);
}

bool Complex::operator==(const Complex& obj) const {
    return m_real == obj.m_real && m_imag == obj.m_imag;
}

Complex& Complex::operator++() {
    m_real++;
    m_imag++;
    return *this;
}

Complex& Complex::operator--() {
    m_real--;
    m_imag--;
    return *this;    
}

Complex Complex::operator++(int) {
    Complex temp = *this;  // Make a copy for result
    ++(*this);  // Use the prefix operator to increment this object
    return temp;  // Return the copy (the original value)
}

Complex Complex::operator--(int) {
    Complex temp = *this;  // Make a copy for result
    --(*this);  // Use the prefix operator to increment this object
    return temp;  // Return the copy (the original value)
}

std::ostream& operator<<(std::ostream& out, const Complex& obj) {
    out << obj.m_real << "+" << obj.m_imag << "i";
    return out;
}

} // namespace mozer