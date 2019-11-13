//
//  main.cpp
//  operator_overloading
//
//  Created by ertuğrul gazi akça on 14.03.2018.
//  Copyright © 2018 ertuğrul gazi akça. All rights reserved.
//

#include <iostream>
#include "Sally.hpp"

using namespace std;


int main() {
    
    Sally a(34);
    Sally b(21);
    Sally c;
    
    c = a + b;
    
    cout << c.num ;
    
    return 0;
}
