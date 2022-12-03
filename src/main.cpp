#include <iostream>
#include "Dog.h"

int main() {
    Shared_ptr_toy boll = make_shared_toy("boll");
    Shared_ptr_toy bone = make_shared_toy("bone");
    Dog a ("sharik",boll);
    Dog b ("Izume",boll);
    Dog c ("Venik",bone);
    boll.reset();
    Dog e ("MrGaf",boll);

}
