/**
 * @file    String.cpp
 * @brief   This file contains the declaration of the String class.
 * @author  Mert Ozer
 * @date    26.11.2023
 * @version 1.0
 */
#include "string.hpp"
#include <algorithm> // For std::copy
#include <stdexcept>

namespace mozer
{

String::String() : size(0) {
    memset(small, '\0', 15);
}
String::String(const char* str) : size(strlen(str)){
    if(isLargeString()){
        large = new char[size + 1];
        std::copy(str, str + size + 1, large);
    } else {
        std::copy(str, str + size + 1, small);
    }
}

String::String(const String& other) : size(other.size){
    if (isLargeString()) {
        large = new char[size + 1];
        std::copy(other.large, other.large + size + 1, large);
    } else {
        std::copy(other.small, other.small + SSO_SIZE, small);
    }
}

String::String(String&& other) noexcept : size(other.size){
    if (isLargeString()) {
        large = other.large;
        other.large = nullptr;
    } else {
        std::copy(other.small, other.small + SSO_SIZE, small);
    }
    other.size = 0;
}

String::~String(){
    if (isLargeString()) {
        delete large;
        large = nullptr;
    }
} 

String& String::operator=(const String& other) {
    if (this != &other) {
        if (isLargeString()) {
            delete[] large;
        }
        size = other.size;
        if (isLargeString()) {
            large = new char[size + 1];
            std::copy(other.large, other.large + size + 1, large);
        } else {
            std::copy(other.small, other.small + SSO_SIZE, small);
        }
    }
    return *this;
}

String& String::operator=(String&& other) noexcept {
    if (this != &other) {
        if (isLargeString()) {
            delete[] large;
        }
        size = other.size;
        if (isLargeString()) {
            large = other.large;
            other.large = nullptr;
        } else {
            std::copy(other.small, other.small + SSO_SIZE, small);
        }
        other.size = 0;
    }
    return *this;
}

char& String::operator[](size_t index) {
    if (index >= size) {
        // Handle out-of-bounds access in a manner appropriate for your needs
        // For simplicity, we'll just throw an exception here
        throw std::out_of_range("Index out of range");
    }
    return isLargeString() ? large[index] : small[index];
}

const char& String::operator[](size_t index) const {
    if (index >= size) {
        // Handle out-of-bounds access in a manner appropriate for your needs
        // For simplicity, we'll just throw an exception here
        throw std::out_of_range("Index out of range");
    }
    return isLargeString() ? large[index] : small[index];
}

const char* String::c_str() const {
    return isLargeString() ? large : small;
}

size_t String::length() const {
    return size;
}

bool String::isLargeString() const {
    return size >= SSO_SIZE;
}

} // namespace mozer