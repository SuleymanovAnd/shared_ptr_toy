#include "iostream"
#include "shared_ptr_toy.h"
class Dog {
std::string name;
Shared_ptr_toy lovelyToy;
public:
Dog(std::string inName, Shared_ptr_toy& toy):name (inName)
{
    lovelyToy = toy;
}
~Dog()= default;
};