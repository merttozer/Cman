/**
 * @file    string.hpp
 * @brief   This file contains the declaration of the string class.
 * @author  Mert Ozer
 * @date    26.11.2023
 * @version 1.0
 */
// String.hpp
#ifndef STRING_HPP
#define STRING_HPP

#include <cstring> // For strcpy, strlen, etc.

namespace mozer
{

class String {
public:
    String(); // Default constructor
    String(const char* str); // Constructor from C-style string
    String(const String& other); // Copy constructor
    String(String&& other) noexcept; // Move constructor
    ~String(); // Destructor

    String& operator=(const String& other); // Copy assignment
    String& operator=(String&& other) noexcept; // Move assignment
    char& operator[](size_t index);
    const char& operator[](size_t index) const;

    const char* c_str() const; // Get C-style string
    size_t length() const; // Get length of string

private:
    static const size_t SSO_SIZE = 15; // Size for small string optimization, including null terminator
    size_t size; // Actual size of string, excluding null terminator
    union {
        char small[SSO_SIZE]; // Fixed-size array for SSO
        char* large; // Pointer for strings larger than SSO_SIZE
    };
    bool isLargeString() const; // Helper to check if string uses large storage
};

} // namespace mozer

#endif // STRING_HPP
