/**
 * @file    allocator.cpp
 * @brief   This file contains the declaration of the memory allocator class.
 * @author  Mert Ozer
 * @date    01.10.2023
 * @version 1.0
 */

#include "allocator.hpp"

namespace mozer{

Allocator::Allocator(size_t size) {
    memoryStart = ::operator new(size, std::nothrow); // Allocate a large block of memory
    if (!memoryStart) {
        throw AllocationException(); // Throw exception if memory allocation fails
    }

    freeListHead = reinterpret_cast<FreeBlock*>(memoryStart);
    freeListHead->size = size;
    freeListHead->next = nullptr;
}

Allocator::~Allocator() {
    ::operator delete(memoryStart); // Free the large block of memory
}

void* Allocator::allocate(size_t size) {
    FreeBlock** prevNext = &freeListHead;
    FreeBlock* current = freeListHead;
    unsigned long blockSize = sizeof(FreeBlock);

    while (current != nullptr) {
        if (current->size >= size) {
            if (current->size > size + blockSize) {
                // Split the block
                FreeBlock* nextBlock = reinterpret_cast<FreeBlock*>(reinterpret_cast<char*>(current) + size);
                nextBlock->size = current->size - size - blockSize;
                nextBlock->next = current->next;

                *prevNext = nextBlock; // Update the previous block's next pointer
            } else {
                // Use the entire block
                *prevNext = current->next;
            }

            return reinterpret_cast<void*>(current);
        }

        prevNext = &current->next;
        current = current->next;
    }

    throw AllocationException(); // Throw exception if no suitable block is found
}

void Allocator::deallocate(void* pointer) {
    // Check if the pointer is within the allocated memory range
    if (pointer < memoryStart || pointer >= static_cast<char*>(memoryStart) + freeListHead->size) {
        throw DeallocationException(); // Throw exception if pointer is invalid
    }

    FreeBlock* block = reinterpret_cast<FreeBlock*>(pointer);
    block->next = freeListHead;
    freeListHead = block;
}

} // namespace mozer
