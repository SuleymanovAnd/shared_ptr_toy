#include <iostream>
#include "Toy.h"
#include <vector>
#pragma once;

class Shared_ptr_toy {
private:
   std::vector < Toy* > obj;
   Toy* toyObj;
   int* strongRefs;
public:
    Shared_ptr_toy (){
        std::cout << "Constructor spt" << this << std::endl;
        strongRefs = new int (0);
        toyObj = new Toy("Some name");
    }
    Shared_ptr_toy(Toy *oth){
        std::cout << "Constructor spt" << this << std::endl;
        toyObj = oth;
        strongRefs = new int (0);
    }
    Shared_ptr_toy(std::string name){
        std::cout << "Constructor spt" << this << std::endl;
        toyObj = new Toy (name);
        strongRefs = new int (0);
    }
    Shared_ptr_toy(const Shared_ptr_toy & spt){
        std::cout << "Const copy " << this << std::endl;
        toyObj = spt.toyObj;
        strongRefs = spt.strongRefs;
        obj.resize (spt.obj.size());
        for (int i = 0; i <  spt.obj.size(); i++){
            obj [i] = spt.obj[i];
        }
    }

    Shared_ptr_toy& operator = (const Shared_ptr_toy& oth){
        std::cout << "Const = " << this << std::endl;

        if (this == &oth){
            this->obj.push_back (toyObj);
            strongRefs++;
            return *this;
        }else {
            if(toyObj != nullptr)delete toyObj;
            if(strongRefs!=nullptr) delete strongRefs;

            toyObj = oth.toyObj;
            obj.resize (oth.obj.size());
            for (int i = 0; i <  oth.obj.size(); i++){
                obj [i] = oth.obj[i];
        }

        }
        }
    ~Shared_ptr_toy (){
    std::cout << "Destructor spt" << this << std::endl;
    if (*strongRefs > 1) {
        obj.pop_back ();
    }
    else {
        obj.resize (0);
        delete toyObj;
        delete strongRefs;
        strongRefs = nullptr;
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