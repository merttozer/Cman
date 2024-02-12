/**
 * @file    bitset.cpp
 * @brief   This file contains the declaration of the bitset class.
 * @author  Mert Ozer
 * @date    26.10.2023
 * @version 1.0
 */
#include "bitset.hpp"

namespace mozer
{

Bitset::Bitset(size_t size) : bits(size, false) {}

void Bitset::setBit(size_t pos) {
    if (pos >= bits.size()) {
        throw std::out_of_range("Bitset::setBit - Position out of range");
    }
    bits[pos] = true;
}

void Bitset::clearBit(size_t pos) {
    if (pos >= bits.size()) {
        throw std::out_of_range("Bitset::clearBit - Position out of range");
    }
    bits[pos] = false;
}

void Bitset::flipBit(size_t pos) {
    if (pos >= bits.size()) {
        throw std::out_of_range("Bitset::flipBit - Position out of range");
    }
    bits[pos] = !bits[pos];
}

bool Bitset::testBit(size_t pos) const {
    if (pos >= bits.size()) {
        throw std::out_of_range("Bitset::testBit - Position out of range");
    }
    return bits[pos];
}

size_t Bitset::size() const {
    return bits.size();
}

} // namespace mozer