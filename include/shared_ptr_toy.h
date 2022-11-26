#include <iostream>
#include "Toy.h"
#include <vector>
#pragma once;

class Shared_ptr_toy {
private:
   std::vector < Toy* > obj;
   Toy* toyObj;
public:
    Shared_ptr_toy (){
        std::cout << "Constructor spt" << this << std::endl;
    }
    Shared_ptr_toy(Toy *oth){
        std::cout << "Constructor spt" << this << std::endl;
        toyObj = oth;
        obj.push_back (toyObj);

    }
    Shared_ptr_toy(std::string name){
        std::cout << "Constructor spt" << this << std::endl;
        toyObj = new Toy (name);
        obj.push_back (toyObj);
    }
    Shared_ptr_toy(const Shared_ptr_toy & spt){
        std::cout << "Const copy " << this << std::endl;
        toyObj = new Toy (*spt.toyObj);

        obj.resize (spt.obj.size());
        for (int i = 0; i <  spt.obj.size(); i++){
            obj [i] = spt.obj[i];
        }
    }

    Shared_ptr_toy& operator = (const Shared_ptr_toy& oth){
        if (this == &oth){
            this->obj.push_back (toyObj);
            return *this;
        }else if (obj.size() > 0 && toyObj != nullptr){
            obj.resize (0);
            delete toyObj;
        }
        toyObj = oth.toyObj;
        obj.resize (oth.obj.size());
        for (int i = 0; i <  oth.obj.size(); i++){
            obj [i] = oth.obj[i];
        }
        }
    ~Shared_ptr_toy (){
    std::cout << "Destructor spt" << this << std::endl;
    if (obj.size() > 1) {
        obj.pop_back ();
    }
    else {
        obj.resize (0);
        delete toyObj;
        toyObj = nullptr;
        delete this;
    }
    }

    /*
    Shared_ptr_toy(std::string inName){
        obj = new Toy(inName);
    }
    Shared_ptr_toy(const Shared_ptr_toy& oth){
        obj = new Toy(*oth.obj);
    }


    }
     */
};

Shared_ptr_toy& make_shared_toy (std::string inName){
        Toy *temp = new Toy(inName);
        Shared_ptr_toy *tempS = new Shared_ptr_toy(temp) ;
        return *tempS;
}

Toy& make_shared_toy (Toy *oth){
    Toy *temp = new Toy(*oth);
    return *temp;
}