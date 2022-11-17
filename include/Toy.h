#include <iostream>
#pragma once
class Toy {
    std::string name;
public:
    Toy(std::string inName) :name (inName){};
    Toy(): name ("SomeToy") {};
};

