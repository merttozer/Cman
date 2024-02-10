#include<iostream>
#include"unique_ptr/unique_ptr.hpp"
#include"complex/complex.hpp"
#include"vector/vector.hpp"
#include"shared_ptr/shared_ptr.hpp"

int main() {

    //--------------SHARED_PTR----------------    
    mozer::shared_ptr<int> sp1(new int(10));
    std::cout << "sp1 value: " << *sp1 << std::endl;

    mozer::shared_ptr<int> sp2 = sp1;
    std::cout << "sp2 value: " << *sp2 << std::endl;

    mozer::shared_ptr<double> sp3(new double(2.4));

    mozer::shared_ptr<double> sp4 = sp3;

    //--------------VECTOR----------------
    mozer::vector<int> v1(5, 10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    std::cout << "v1: " << v1 << std::endl;
    
    //--------------COMPLEX----------------    
    mozer::Complex c1(3, 4);
    mozer::Complex c2(2, 6);

    mozer::Complex c3 = c1 + c2;
    std::cout << c3 << "\n";

    //--------------UNIQUE_PTR----------------    
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