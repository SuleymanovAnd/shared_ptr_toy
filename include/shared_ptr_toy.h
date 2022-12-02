#include <iostream>
#include "Toy.h"
#include <vector>
#pragma once

class Shared_ptr_toy {
private:
    std::vector < Toy* > obj;
    Toy* toyObj;
    int strongRefs;
   bool sharedPtrUser = false;
   Shared_ptr_toy* source = nullptr;
public:
    Shared_ptr_toy (){
        std::cout << "Constructor spt" << this << std::endl;
        toyObj = new Toy("Some name");
        strongRefs =0;
    }
    Shared_ptr_toy(Toy *oth){
        std::cout << "Constructor spt  " << this << std::endl;
        toyObj = oth;
        strongRefs = 0;
    }
    Shared_ptr_toy(std::string name){
        std::cout << "Constructor spt  " << this << std::endl;
        toyObj = new Toy (name);
        strongRefs = 0;
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

    Shared_ptr_toy& operator = (Shared_ptr_toy& oth){
        std::cout << "Const = " << this << std::endl;
        if (this == nullptr){
            delete this;
        }else {
            if (oth.toyObj == nullptr){
                std::cout << "Toy reset";
            }else {

                if (this == &oth) {
                    this->obj.push_back(toyObj);
                    strongRefs++;
                    return *this;
                    *source = oth;
                    oth.strongRefs++;
                    oth.obj.push_back(toyObj);

                } else {
                    if(toyObj!=nullptr)  delete toyObj;
                    strongRefs = oth.strongRefs;
                    toyObj = oth.toyObj;
                    obj.resize(oth.obj.size());
                    for (int i = 0; i < oth.obj.size(); i++) {
                        obj[i] = oth.obj[i];
                    }
                    obj.push_back(toyObj);
                    oth.obj.push_back(toyObj);
                    strongRefs++;
                    oth.strongRefs++;
                    sharedPtrUser = true;
                    source = &oth;
                    return *this;

                }
            }
        }
    }

    void reset (){
        delete toyObj;
        toyObj = nullptr;
    }

    ~Shared_ptr_toy (){
    std::cout << "Destructor spt" << this << std::endl;
    if(strongRefs == 0) {
        delete toyObj;
        toyObj = nullptr;
        delete source;
        source = nullptr;
    }
    if (strongRefs > 0 && sharedPtrUser) {
        obj.pop_back ();
       strongRefs--;
       source->obj.pop_back();
       source->strongRefs--;
    }
    else {
        if (this != nullptr) {
            delete source;
            obj.resize(0);
            delete toyObj;
            toyObj = nullptr;
        }
    }
    }

};

Shared_ptr_toy& make_shared_toy (std::string inName){
        Toy *temp = new Toy(inName);
        Shared_ptr_toy *tempS = new Shared_ptr_toy(temp) ;
        return *tempS;
}
