//
//  main.cpp
//  sorting_function
//
//  Created by ertuğrul gazi akça on 7.03.2018.
//  Copyright © 2018 iosDev. All rights reserved.
//

#include <iostream>

using namespace std;

void sorting_big_to_small(int[],int);
void sorting_small_to_big(int[],int);


int main() {
    // insert code here...
    
    int array[5];
    cout << "sayılari giriniz" << endl ;
    
    for (int i = 0; i < 5; i++) {
        cin >> array[i];
    }
    
    cout << endl;
    
    sorting_big_to_small(array,5);
    
    for (int i = 0 ; i < 5 ; i++) {
        cout << array[i] ;
    }
    cout << endl;
    sorting_small_to_big(array, 5);
    
    for (int i = 0 ; i < 5 ; i++) {
        cout << array[i] ;
    }
    return 0;
}

void sorting_big_to_small(int dizi[], int count) {
    for (int i = 0 ; i < 5 ; i++) {
        for (int j = 0 ; j < 5 ; j++) {
            if (dizi[i] > dizi[j]) {
                swap(dizi[i], dizi[j]);
            }
        }
    }
}
void sorting_small_to_big(int dizi[], int count) {
    for (int i = 0 ; i < 5 ; i++) {
        for (int j = 0 ; j < 5 ; j++) {
            if (dizi[i] < dizi[j]) {
                swap(dizi[i], dizi[j]);
            }
        }
    }
}


