#include "Toy.h"

Toy::Toy(std::string inName) :name (inName){
        std::cout << "Constructor Toy  " << this << std::endl;
};
Toy::Toy(): name ("SomeToy") {
    std::cout << "Constructor Toy  " << this << std::endl;
};
Toy::~Toy(){
    std::cout << "Destructor Toy  " << this << std::endl;
}