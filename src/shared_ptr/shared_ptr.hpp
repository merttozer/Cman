/**
 * @file    shared_ptr.hpp
 * @brief   This file contains the declaration of the shared_ptr class.
 * @author  Mert Ozer
 * @date    30.01.2024
 * @version 1.0
 */
#ifndef SHARED_PTR_HPP
#define SHARED_PTR_HPP

#include <iostream>
#include <atomic>

namespace mozer
{

template<typename T>
class shared_ptr {
public:
    // Default constructor
    shared_ptr() : ptr(nullptr), ref_count(new std::atomic<int>(0)) {}

    // Constructor with object
    explicit shared_ptr(T* p) : ptr(p), ref_count(new std::atomic<int>(1)) {}

    // Destructor
    ~shared_ptr() {
        release();
    }

    // Copy constructor
    shared_ptr(const shared_ptr& other) : ptr(other.ptr), ref_count(other.ref_count) {
        ref_count->fetch_add(1, std::memory_order_relaxed);
    }

    // Move constructor
    shared_ptr(shared_ptr&& other) noexcept : ptr(other.ptr), ref_count(other.ref_count) {
        other.ptr = nullptr;
        other.ref_count = nullptr;
    }

    // Copy assignment operator
    shared_ptr& operator=(const shared_ptr& other) {
        if (this != &other) {
            release();
            ptr = other.ptr;
            ref_count = other.ref_count;
            ref_count->fetch_add(1, std::memory_order_relaxed);
        }
        return *this;
    }

    // Move assignment operator
    shared_ptr& operator=(shared_ptr&& other) noexcept {
        if (this != &other) {
            release();
            ptr = other.ptr;
            ref_count = other.ref_count;
            other.ptr = nullptr;
            other.ref_count = nullptr;
        }
        return *this;
    }

    // Dereference operator
    T& operator*() const { return *ptr; }

    // Arrow operator
    T* operator->() const { return ptr; }

    // Get underlying pointer
    T* get() const { return ptr; }

    // Release and delete resources if needed
    void release() {
        if (ref_count && ref_count->fetch_sub(1, std::memory_order_acq_rel) == 1) {
            delete ptr;
            delete ref_count;
        }
    }

private:
    T* ptr;
    std::atomic<int>* ref_count;
};


} // namespace mozer

#endif // SHARED_PTR_HPP