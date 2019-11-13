//newton ralphson teoremi c programı 
//Ertuğrul Gazi AKÇA tarafından oluşturuldu.

#include <stdio.h>
#include <math.h>
double e = 2.71;
double fx(double x){
    double sonuc = exp(x) + pow(2, -1*x) + (2*cos(x)) -6;
    return sonuc;
}

double fxTurev(double x){
    double sonuc = -pow(2, -1*x)*(0.6931471806) + exp(x) - (2*sin(x));
    return sonuc;
} 

double nextXValue(double x1){
    double x2 = x1 - (fx(x1) / fxTurev(x1));
    return x2;
}


int main(int argc, char const *argv[])
{
    int kontrol = 0;
    double hataPayi = 0.001;
    double x1 = 1.5;

    printf("step    x\n");
    int i = 1;
    while(1){

        double x2 = nextXValue(x1);
        printf(" %d    %lf\n",i,x1);


        if(fx(x1) == 0){
            printf("kök değeri: %lf", x1);
            break;
        }
        if (kontrol == 1) {
            break;
        }

        if(x2-x1 < hataPayi){
            kontrol = 1;
        }
    
        x1 = x2;
        i++;

    }
    
    

    
    return 0;
}

