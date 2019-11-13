//
//  Sally.hpp
//  operator_overloading
//
//  Created by ertuğrul gazi akça on 14.03.2018.
//  Copyright © 2018 ertuğrul gazi akça. All rights reserved.
//

#ifndef Sally_hpp
#define Sally_hpp

#include <stdio.h>


class Sally
{
public:
    int num;
    Sally();
    Sally(int);
    Sally operator+(Sally);
};


#endif /* Sally_hpp */
