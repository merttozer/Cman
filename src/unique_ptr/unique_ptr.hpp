/**
 * @file    unique_ptr.hpp
 * @brief   This file contains the declaration of the unique_ptr class.
 * @author  Mert Ozer
 * @date    15.01.2024
 * @version 1.0
 */
#ifndef UNIQUE_PTR_HPP
#define UNIQUE_PTR_HPP

#include <algorithm> // For std::swap
#include <iostream>

namespace mozer
{
    
// Simplified implementation of unique_ptr
template<typename T>
class unique_ptr {
public:
    // Default constructor
    unique_ptr() noexcept : ptr(nullptr) {}

    // Constructor with resource
    explicit unique_ptr(T* resource) noexcept : ptr(resource) {}

    // Destructor
    ~unique_ptr() noexcept {
        delete ptr;
    }

    // Move constructor
    unique_ptr(unique_ptr&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }

    // Move assignment operator
    unique_ptr& operator=(unique_ptr&& other) noexcept {
        if (this != &other) {
            delete ptr; // Free the existing resource
            ptr = other.ptr; // Transfer ownership
            other.ptr = nullptr; // Release ownership from moved object
        }
        return *this;
    }

    // Deleted copy constructor and copy assignment operator
    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;

    // Resource access
    T* get() const noexcept { return ptr; }
    T& operator*() const { return *ptr; }
    T* operator->() const noexcept { return ptr; }

    // Resource release
    T* release() noexcept {
        T* temp = ptr;
        ptr = nullptr;
        return temp;
    }

    // Resource reset
    void reset(T* resource = nullptr) noexcept {
        T* old = ptr;
        ptr = resource;
        delete old;
    }

    // Swap
    void swap(unique_ptr& other) noexcept {
        std::swap(ptr, other.ptr);
    }

private:
    T* ptr; // Managed resource
};

// Helper function for swapping two unique_ptr instances
template<typename T>
void swap(unique_ptr<T>& lhs, unique_ptr<T>& rhs) noexcept {
    lhs.swap(rhs);
}

} // namespace mozer

#endif // UNIQUE_PTR_HPP