#include <iostream>
#include "Dog.h"

int main() {
    Shared_ptr_toy boll = make_shared_toy("boll");
    Dog ("sharik",boll);
    Dog ("Izume",boll);
}
