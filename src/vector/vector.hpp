/**
 * @file    vector.hpp
 * @brief   This file contains the declaration of the vector class.
 * @author  Mert Ozer
 * @date    26.01.2024
 * @version 1.0
 */
#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <stdexcept> // For std::out_of_range


namespace mozer
{

template<typename T>
class vector{
private:
    T* m_ptr;
    size_t m_size;
public:
    // Default constructor: Initializes a vector with no elements
    vector() : m_ptr(nullptr), m_size(0) {}

    // Constructor with size: Initializes a vector with a specific number of elements
    explicit vector(size_t size) : m_ptr(new T[size]), m_size(size) {}

    // Constructor with size and value: Initializes a vector with a specific number of elements, each element is initialized by a specific value
    vector(size_t size, T value) : m_ptr(new T[size]), m_size(size) {
        for (size_t i = 0; i < m_size; i++) {
            m_ptr[i] = value;
        }
    }


    // Copy constructor: Initializes a vector with a copy of each of the elements in another vector
    vector(const vector& other) : m_ptr(new T[other.m_size]) {
        for (size_t i = 0; i < other.m_size; i++) {
            m_ptr[i] = other.m_ptr[i];
        }
    }

    // Move constructor: Initializes a vector by moving the elements from another vector
    vector(vector&& other) noexcept : m_ptr(other.m_ptr), m_size(other.m_size) {
        other.m_ptr = nullptr;
        other.m_size = 0;
    }

    // Destructor: Releases the memory that was allocated by the vector
    ~vector() {
        delete[] m_ptr;
        m_ptr = nullptr;
    }

    // Copy assignment operator: Replaces the elements of a vector with a copy of the elements of another vector
    vector& operator=(const vector& other) {
        if (this != &other) {
            delete[] m_ptr;
            m_ptr = new T[other.m_size];
            m_size = other.m_size;
            for (size_t i = 0; i < m_size; i++) {
                m_ptr[i] = other.m_ptr[i];
            }
        }
        return *this;
    }

    // Move assignment operator: Replaces the elements of a vector with the elements of another vector using move semantics
    vector& operator=(vector&& other) noexcept {
        if (this != &other) {
            delete[] m_ptr;
            m_ptr = other.m_ptr;
            m_size = other.m_size;
            other.m_ptr = nullptr;
            other.m_size = 0;
        }
        return *this;
    }

    // Access element: Throws std::out_of_range exception if the index is out of bounds
    T& operator[](size_t index) {
        if (index >= m_size) {
            throw std::out_of_range("Index out of range");
        }
        return m_ptr[index];
    }

    // Access element (const): Throws std::out_of_range exception if the index is out of bounds
    const T& operator[](size_t index) const {
        if (index >= m_size) {
            throw std::out_of_range("Index out of range");
        }
        return m_ptr[index];
    }

    // Get the number of elements in the vector
    size_t size() const {
        return m_size;
    }

    // Resize the vector
    void resize(size_t new_size) {
        T* new_data = new T[new_size];
        size_t min_size = (new_size > m_size) ? m_size : new_size;
        for (size_t i = 0; i < min_size; i++) {
            new_data[i] = m_ptr[i];
        }
        delete[] m_ptr;
        m_ptr = new_data;
        m_size = new_size;
    }

    // Clear the vector
    void clear() {
        delete[] m_ptr;
        m_ptr = nullptr;
        m_size = 0;
    }

    // Add an element to the end of the vector
    void push_back(const T& value) {
        resize(m_size + 1);
        m_ptr[m_size - 1] = value;
    }

    // Remove the last element of the vector
    void pop_back() {
        if (m_size > 0) {
            resize(m_size - 1);
        }
    }

    // Check if the vector is empty
    bool empty() const {
        return m_size == 0;
    }

    // Get the first element of the vector
    T& front() {
        return m_ptr[0];
    }

    // Get the first element of the vector (const)
    const T& front() const {
        return m_ptr[0];
    }

    // Get the last element of the vector
    T& back() {
        return m_ptr[m_size - 1];
    }

    // Get the last element of the vector (const)
    const T& back() const {
        return m_ptr[m_size - 1];
    }

    // Get the pointer to the underlying array
    T* data() {
        return m_ptr;
    }

    // Get the pointer to the underlying array (const)
    const T* data() const {
        return m_ptr;
    }

    // Swap the contents of two vectors
    void swap(vector& other) {
        std::swap(m_ptr, other.m_ptr);
        std::swap(m_size, other.m_size);
    }

    // Output operator
    friend std::ostream& operator<<(std::ostream& out, const vector& v) {
        out << "[ ";
        for (size_t i = 0; i < v.m_size; i++) {
            out << v[i] << ' ';
        }
        out << ']';
        return out;
    }

    // Equality operator
    bool operator==(const vector& other) const {
        if (m_size != other.m_size) {
            return false;
        }
        for (size_t i = 0; i < m_size; i++) {
            if (m_ptr[i] != other.m_ptr[i]) {
                return false;
            }
        }
        return true;
    }

    // Inequality operator
    bool operator!=(const vector& other) const {
        return !(*this == other);
    }


};

}

#endif // VECTOR_HPP