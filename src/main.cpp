#include<iostream>
#include"unique_ptr/unique_ptr.hpp"
#include"complex/complex.hpp"
#include"vector/vector.hpp"
#include"shared_ptr/shared_ptr.hpp"
#include"string/string.hpp"
#include"bitset/bitset.hpp"
#include"allocator/allocator.hpp"

int main() {

    try{
        //-------------ALLOCATOR--------------  
        mozer::Allocator allocator(1024);
        void* allocatedMemory = allocator.allocate(256);
        if (allocatedMemory) {
            std::cout << "Memory allocated successfully." << std::endl;
            allocator.deallocate(allocatedMemory); // Deallocate memory
            std::cout << "Memory deallocated successfully." << std::endl;
        }
        //--------------BITSET----------------    
        mozer::Bitset myBitset(10);
        myBitset.setBit(2);
        myBitset.setBit(5);
        std::cout << "Bit at position 2 is: " << (myBitset.testBit(2) ? "set" : "not set") << std::endl;
        std::cout << "Bit at position 3 is: " << (myBitset.testBit(3) ? "set" : "not set") << std::endl;

        myBitset.clearBit(2);
        std::cout << "Bit at position 2 after clearing is: " << (myBitset.testBit(2) ? "set" : "not set") << std::endl;

        myBitset.flipBit(5);
        std::cout << "Bit at position 5 after flipping is: " << (myBitset.testBit(5) ? "set" : "not set") << std::endl;

        //--------------STRING----------------    
        mozer::String myString("Hello, World!");

        std::cout << "Original string: " << myString.c_str() << std::endl;

        myString[7] = 'W';
        myString[8] = 'o';
        myString[9] = 'r';
        myString[10] = 'l';
        myString[11] = 'd';

        std::cout << "Modified string: " << myString.c_str() << std::endl;
        std::cout << "Character at index 6: " << myString[6] << std::endl;

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
        std::cout << "Finished succesfully." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        std::cout << "Finished with error!" << std::endl;
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