#include "iostream"
#include "shared_ptr_toy.h"
class Dog {
std::string name;
Shared_ptr_toy lovelyToy;
public:
Dog(std::string inName, Shared_ptr_toy& toy);

/*void copy_lovelyToy (const Dog &oth);*/

~Dog()= default;
};