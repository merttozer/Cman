#include<iostream>
#include"unique_ptr/unique_ptr.hpp"
using namespace std;

int main() {
    
    mozer::unique_ptr<int> ptr1(new int(10));
    std::cout << "ptr1: " << *ptr1 << std::endl;

    mozer::unique_ptr<int> ptr2 = std::move(ptr1); // Transfer ownership
    std::cout << "ptr2: " << *ptr2 << std::endl;

    // ptr1 is now empty
    if (!ptr1.get()) {
        std::cout << "ptr1 is now empty" << std::endl;
    }

    return 0;
}

/*
1) RAII and move semantics - implement unique_ptr
2) Operator overloading - implement complex
3) Raw arrays and pointers - implement vector
4) Memory management and intro to atomics - implement shared_ptr and weak_ptr
5) Unions and pointers and c-style strings - implement string with small string optimization
6) Bit operations - implement bitset
7) Memory allocation strategies - implement allocator
8) Template metaprogramming - implement tuple
9) Algorithms - implement sort
10) Multithreading, concurrency, locks, condition variables - implement future and async
11) Exceptions - discuss the various exception safety guarantees and how to fulfill them when implementing the above features.
12) Cache friendly structures - have student use/measure std::map and std::unordered_map. Implement map as a sorted array. 
    Implement unordered_map using various hashing strategies - measure performance and discuss tradeoffs.
*/