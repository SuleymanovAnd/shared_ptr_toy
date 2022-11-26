#include <iostream>
#pragma once
class Toy {
    std::string name;
public:
    Toy(std::string inName) :name (inName){
        std::cout << "Constructor Toy" << this << std::endl;
    };
    Toy(): name ("SomeToy") {
        std::cout << "Constructor Toy" << this << std::endl;
    };
    ~Toy(){
        std::cout << "Destructor Toy" << this << std::endl;
    }
};

