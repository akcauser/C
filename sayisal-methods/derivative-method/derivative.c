#include <stdio.h>

double ileri(double x, double xArtiBir, double xArtiIki, double h){
    double deger = ( ( (4 * xArtiBir) - (3 * x) - xArtiIki ) / (2 * h) );
    return deger;   
}
double merkez(double xEksiBir, double xArtiBir, double h){
    double deger = ( (xArtiBir - xEksiBir) / (2 * h));
    return deger;
}
double geri(double xEksiIki, double xEksiBir, double x, double h){
    double deger = ( (xEksiIki - (4 * xEksiBir) + (3 * x)) / (2 * h) );
    return deger;
}

int main()
{   
     // Dosyadan gerekli verilerin okuma işlemi yapılıyor.
    FILE *fp1;
    int noktaSayisi = 0;
    double requestValue = 0;
    
    if((fp1 = fopen ("data.txt", "r")) == NULL) {
        printf("Dosya açma hatası!");
    }

    fscanf(fp1, "%d", &noktaSayisi);

    double x[noktaSayisi];
    double y[noktaSayisi];
    double turevler[noktaSayisi];  

    int i = 0;
    while(!feof(fp1)){  
        
        fscanf(fp1, "%lf %lf", &x[i], &y[i]);
        i++;
    }
    fclose(fp1);

    //veri geliyor mu diye test yaptık
    /*
    for(int i = 0; i < 3; i++)
    {
        printf("%lf %lf\n", x[i], y[i]);
    }
    */

    // dosyadan verileri aldık ve dizilere koyduk.
    // Türevleri hesaplayıp turevler dizisine ekleme yapacağız.
    double h = x[1] - x[0]; 
    int sayac = 0;
    while (sayac < noktaSayisi){

        if (sayac == 0) 
        {
            turevler[sayac] = geri(y[sayac ], y[sayac + 1], y[sayac + 2], h);
        }
        else if( sayac == noktaSayisi-1)
        {
            turevler[sayac] = ileri(y[sayac - 2], y[sayac - 1], y[sayac], h);
        }
        else //if( sayac == (noktaSayisi / 2) )
        {   
            turevler[sayac] = merkez(y[sayac - 1], y[sayac + 1], h);
        }


        sayac++;
    }
    
    for(int i = 0; i < noktaSayisi; i++)
    {
        printf("%lf için türev %lf\n", x[i], turevler[i]);
    }






    return 0;
}
