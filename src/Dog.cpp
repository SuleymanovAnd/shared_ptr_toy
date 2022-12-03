#include "Dog.h"

Dog::Dog(std::string inName, Shared_ptr_toy& toy):name (inName)
        {
                lovelyToy = toy;
        }

        /*void Dog:: copy_lovelyToy (const Dog &oth){
        lovelyToy = oth.lovelyToy    // не понял, как реализовать
         }*/
