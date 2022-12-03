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
   bool srt = false;
public:
    Shared_ptr_toy ();

    Shared_ptr_toy(Toy *oth);

    Shared_ptr_toy(std::string name);

    Shared_ptr_toy(const Shared_ptr_toy & spt);

    Shared_ptr_toy& operator = (Shared_ptr_toy& oth);

    void reset ();

    ~Shared_ptr_toy ();

};

Shared_ptr_toy& make_shared_toy (std::string inName);
