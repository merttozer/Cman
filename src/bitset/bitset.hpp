/**
 * @file    bitset.hpp
 * @brief   This file contains the declaration of the bitset class.
 * @author  Mert Ozer
 * @date    26.10.2023
 * @version 1.0
 */
#ifndef BITSET_HPP
#define BITSET_HPP

#include <vector>
#include <stdexcept> // Include for std::out_of_range exception

namespace mozer{

class Bitset {
public:
    Bitset(size_t size); // Constructor to initialize the bitset with a given size
    ~Bitset() = default; // Default destructor

    void setBit(size_t pos); // Set a bit to 1 at the specified position
    void clearBit(size_t pos); // Clear a bit (set to 0) at the specified position
    void flipBit(size_t pos); // Flip a bit at the specified position
    bool testBit(size_t pos) const; // Check if a bit at the specified position is set
    size_t size() const; // Get the size of the bitset

private:
    std::vector<bool> bits; // Internal storage for the bits
};

} // namespace mozer

#endif // BITSET_HPP
