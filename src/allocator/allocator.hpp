/**
 * @file    allocator.hpp
 * @brief   This file contains the declaration of the memory allocator class.
 * @author  Mert Ozer
 * @date    01.10.2023
 * @version 1.0
 */
#ifndef ALLOCATOR_HPP
#define ALLOCATOR_HPP

#include <cstddef>
#include <exception>

namespace mozer{

class Allocator {
public:
    Allocator(size_t size);
    ~Allocator();

    void* allocate(size_t size);
    void deallocate(void* pointer);

    // Custom exception classes
    class AllocationException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Memory allocation failed!";
        }
    };

    class DeallocationException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Memory deallocation failed!";
        }
    };

private:
    struct FreeBlock {
        size_t size;
        FreeBlock* next;
    };

    FreeBlock* freeListHead;
    void* memoryStart;
};

} // namespace mozer

#endif // ALLOCATOR_HPP
