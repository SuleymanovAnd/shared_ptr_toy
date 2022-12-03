#include "shared_ptr_toy.h"

Shared_ptr_toy::Shared_ptr_toy (){
    std::cout << "Constructor spt" << this << std::endl;
    toyObj = new Toy("Some name");
    strongRefs =0;
}

Shared_ptr_toy::Shared_ptr_toy(Toy *oth){
    std::cout << "Constructor spt  " << this << std::endl;
    toyObj = oth;
    strongRefs = 0;
    srt = true;
}

Shared_ptr_toy::Shared_ptr_toy(std::string name){
    std::cout << "Constructor spt  " << this << std::endl;
    toyObj = new Toy (name);
    strongRefs = 0;
}

Shared_ptr_toy::Shared_ptr_toy(const Shared_ptr_toy & spt){
    std::cout << "Const copy " << this << std::endl;
    toyObj = spt.toyObj;
    strongRefs = spt.strongRefs;
    obj.resize (spt.obj.size());
    for (int i = 0; i <  spt.obj.size(); i++){
        obj [i] = spt.obj[i];
    }
    delete &spt;
}
Shared_ptr_toy& Shared_ptr_toy:: operator = (Shared_ptr_toy& oth){
    std::cout << "Const = " << this << std::endl;
    if (oth.toyObj == nullptr){
        std::cout << "Toy reset\n";
    }else {

        if (this == &oth) {
            this->obj.push_back(toyObj);
            strongRefs++;
            *source = oth;
            oth.strongRefs++;
            oth.obj.push_back(toyObj);
            return *this;
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
void Shared_ptr_toy:: reset (){
    delete toyObj;
    toyObj = nullptr;
}

Shared_ptr_toy::~Shared_ptr_toy (){
    std::cout << "Destructor spt" << this << std::endl;
    if(strongRefs == 0 && !srt) {
        if(toyObj!=nullptr) {
            delete toyObj;
            toyObj = nullptr;
        }
        if(source != nullptr) {
            delete source;
            source = nullptr;
        }
    }
    if (strongRefs > 0 && sharedPtrUser) {
        obj.pop_back ();
        strongRefs--;
        source->obj.pop_back();
        source->strongRefs--;

    }
}

Shared_ptr_toy& make_shared_toy (std::string inName){
    Toy *temp = new Toy(inName);
    Shared_ptr_toy *tempS = new Shared_ptr_toy(temp) ;
    return *tempS;
}