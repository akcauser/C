//
//  Sally.cpp
//  operator_overloading
//
//  Created by ertuğrul gazi akça on 14.03.2018.
//  Copyright © 2018 ertuğrul gazi akça. All rights reserved.
//

#include "Sally.hpp"

Sally::Sally()
{}
Sally::Sally(int a){
    num = a;
}
Sally Sally::operator+(Sally aso){
    Sally brandNew;
    brandNew.num = num + aso.num;
    return brandNew;
}
