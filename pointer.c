//
//  main.c
//  dfghj
//
//  Created by ertuğrul gazi akça on 17.05.2018.
//  Copyright © 2018 ertuğrul gazi akça. All rights reserved.
//

#include <stdio.h>



int main(){
    
    int a=10;
    
    int *p;
    
    p=&a;
    
    printf(“%dn”,*p); // p’nin gösterdiği yeri basar
    
    printf(“%dn”,p); // p’nin değerini yani, p’nin gösterdiği yerin adresini basar
    
    printf(“%dn”,a); // a’nın değerini basar
    
    printf(“%dn”,&a); //a’nın adresini basar
    
    printf(“%dn”,&p); //p’nin adresini basar
    
    return 0;
}
