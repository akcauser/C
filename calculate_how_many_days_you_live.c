//
//  main.c
//  odevVize
//
//  Created by ertuğrul gazi akça on 25.11.2017.
//  Copyright © 2017 iosDev. All rights reserved.
//


#include <stdio.h>

int main() {
    // insert code here...
    int dayToday;
    int monthToday;
    int yearToday;
    int dayBirthday;
    int monthbBirthday;
    int yearBirthday;
    int dogum = 0 ;
    int suan = 0;
    int yasanilanGun = 0;
    
    
    // dizi üzerinde ayları tanımladık. 
    int aylar[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    
        
    
    
    printf("Bugünün tarihini gün,ay,yıl şeklinde giriniz : ");
    scanf("%d,%d,%d",&dayToday,&monthToday,&yearToday);
    
    printf("Doğum tarihinizi gün,ay,yıl şeklinde giriniz : ");
    scanf("%d,%d,%d",&dayBirthday,&monthbBirthday,&yearBirthday);
    
    
    
      
    
    if (yearBirthday % 400 == 0)  {
        aylar[1] = 29;
    } else if (yearBirthday % 100 == 0 ){
        aylar[1] = 28;
    }else if (yearBirthday % 4 == 0 ){
        aylar[1] = 29;
    }    
    
    
    

    
    
    dogum = ((yearBirthday-1)*365) + ((yearBirthday-1)/4);
    dogum = dogum - (yearBirthday-1/100)+(yearBirthday-1/400);
    
    for (int i=0; i < monthbBirthday-1; i++) {
        dogum += aylar[i];
    }
    
    dogum += dayBirthday;
    
    
    
    if (yearToday % 400 == 0)  {
        aylar[1] = 29;
    } else if (yearToday % 100 == 0 ){
        aylar[1] = 28;
    }else if (yearToday % 4 == 0 ){
        aylar[1] = 29;
    } 
    
    
    
    suan = ((yearToday-1)*365) + ((yearToday-1)/4);
    suan = suan - (yearToday-1/100)+(yearToday-1/400);
    
    for (int i=0; i < monthToday-1; i++) {
        suan += aylar[i];
    }
    
    suan += dayToday;
    
    yasanilanGun = suan - dogum;
    
    
    printf("%d gün yaşadınız.", yasanilanGun);
   
    
    getchar();
    return 0;
}
