//
//  main.cpp
//  Cikti
//
//  Created by ertuğrul gazi akça on 20.11.2017.
//  Copyright © 2017 iosDev. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>


using namespace std;

int main() {
    // insert code here...
    cout << "Hello, World!\n";
    
    double array[30];
    double sum=0;
    double average =0;
    double standartSapma=0;
    double ortalamaIleFarkiGecisDegeriToplami=0;
    double normalizeOrtalama = 0;
    double normalizeSum = 0;
    double normalMemberCount = 0 ;
   
    
    
     srand(time(NULL));
    
    
    for (int i=0; i<30; i++) {
        
        
        array[i]= rand()%100 + 1;
        cout << array[i] << endl;
        sum += rand()%100 + 1; 
    }
    
    average = sum / 30; 
     
    cout << "Bu sayılar için ortalama : " << average << endl;
    
    for (int i=0; i<30; i++) {
       ortalamaIleFarkiGecisDegeriToplami += (average - array[i])*(average - array[i]);
      
    }
    
    standartSapma = sqrt(ortalamaIleFarkiGecisDegeriToplami/29);
    
    
    cout << "Bu sayılar için standart sapma : " << standartSapma << endl;

    
    
    for (int i = 0; i < 30 ; i++) {
        if (array[i] < (average - standartSapma)||array[i]> (average + standartSapma)) {
            cout <<i<<". indexteki :"<< array[i] << endl;
        }else{
            normalizeSum += array[i];
            normalMemberCount++;
        }
            
    }
    
    
    normalizeOrtalama = normalizeSum / normalMemberCount ; 
    
    
    cout << "Normalize sayılar için ortalama : " << normalizeOrtalama << endl;

   
    
    
    
    
}
