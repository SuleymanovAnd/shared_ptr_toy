#include <iostream>
#include "Toy.h"
class Shared_ptr_toy {
private:
    Toy* obj;
    int strong_refs;
public:
    Shared_ptr_toy (){
        obj = new Toy ("SomeToy");
    }
    Shared_ptr_toy(Toy *oth){
        obj = oth;
    }


    /*
    Shared_ptr_toy(std::string inName){
        obj = new Toy(inName);
    }
    Shared_ptr_toy(const Shared_ptr_toy& oth){
        obj = new Toy(*oth.obj);
    }
    Shared_ptr_toy& operator = (const Shared_ptr_toy& oth){
        if(this == &oth){
            return *this;
        }
        if(obj != nullptr){
            delete obj;
            obj = new Toy(*oth.obj);
            return *this;
        }

    }
     */
};

Toy& make_shared_toy (std::string inName){
        Toy *temp = new Toy(inName);
        return *temp;
}

Toy& make_shared_toy (Toy *oth){
    Toy *temp = new Toy(*oth);
    return *temp;
}