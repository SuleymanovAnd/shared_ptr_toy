#include <iostream>
#include "Toy.h"
#include <vector>
#pragma once

class Shared_ptr_toy {
private:
    static std::vector < Toy* > obj;
    Toy* toyObj;
   static int strongRefs;
   bool sharedPtruUser = false;
public:
    Shared_ptr_toy (){
        std::cout << "Constructor spt" << this << std::endl;
        toyObj = new Toy("Some name");
    }
    Shared_ptr_toy(Toy *oth){
        std::cout << "Constructor spt" << this << std::endl;
        toyObj = oth;


    }
    Shared_ptr_toy(std::string name){
        std::cout << "Constructor spt" << this << std::endl;
        toyObj = new Toy (name);

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

    Shared_ptr_toy& operator = (const  Shared_ptr_toy& oth){
        std::cout << "Const = " << this << std::endl;

        if (this == &oth){
            this->obj.push_back (toyObj);
            strongRefs ++;
            return *this;
        }else {
            if(toyObj != nullptr)delete toyObj;
            strongRefs=oth.strongRefs;
            toyObj = oth.toyObj;
            obj.resize (oth.obj.size());
            for (int i = 0; i <  oth.obj.size(); i++){
                obj [i] = oth.obj[i];
        }
            obj.push_back(toyObj);
            strongRefs ++;
            sharedPtruUser = true;
            return *this;

        }
        }
        void reset (){

    }
    ~Shared_ptr_toy (){
    std::cout << "Destructor spt" << this << std::endl;
    if(strongRefs == 0) {
        delete toyObj;
        toyObj = nullptr;
    }
    if (strongRefs > 0 && sharedPtruUser) {
        obj.pop_back ();
       strongRefs--;
    }
    else {
        obj.resize (0);
        delete toyObj;
        toyObj = nullptr;

    }
    }

};
int Shared_ptr_toy::strongRefs = 0;
std::vector <Toy*>  Shared_ptr_toy::obj;

Shared_ptr_toy& make_shared_toy (std::string inName){
        Toy *temp = new Toy(inName);
        Shared_ptr_toy *tempS = new Shared_ptr_toy(temp) ;
        return *tempS;
}
