#include <stdio.h>
#include <math.h>

double fx(double x)
{
    double y = exp(x);
    return y;
}

double trapez(double alt, double ust, double n)
{   
    double h = (ust - alt) / n;    
    double integralDegeri = 0;    

    for(int i = 0 ; i < n ; i++)
        integralDegeri += fx(alt + (i * h)); 

    integralDegeri = 2 * integralDegeri;

    integralDegeri = h / 2 * ( (integralDegeri + fx(alt) + fx(ust) ) );

    return integralDegeri;
}
double simpson(double alt, double ust, double n)
{   
    double h = (ust - alt) / n;
    double integralDegeri = 0;

    integralDegeri += fx(alt) + fx(ust);

    double temp = 0;
    for(int i = 1 ; i <= n-1 ; i += 2)
         temp += fx( alt + (i*h) );

    integralDegeri += (4 * temp);

    temp = 0;
    for(int i = 2 ; i <= n - 2 ; i += 2 )
         temp += fx( alt + (i*h) );

    integralDegeri += (2 * temp);

    integralDegeri = integralDegeri / 3;

    integralDegeri = h * integralDegeri;
    
    return integralDegeri;
}

double simpsonThreeEight(double alt, double ust, double n)
{    
   
    double h = (ust - alt) / n;
    double x0 = fx(alt);
    double x1 = fx(alt + h);
    double x2 = fx(alt + 2*h);
    double x3 = fx(ust);

    double integralDegeri = 0;

    integralDegeri = (ust-alt)*( ( (x0 + (3*x1) + (3*x2) +x3 ) ) / 8 );
    
    
    return integralDegeri;
}

double boole(double alt, double ust, double n)
{   
    double h = (ust - alt) / n;
    double x0 = fx(alt);
    double x1 = fx(alt + h);
    double x2 = fx(alt + 2*h);
    double x3 = fx(alt + 3*h);
    double x4 = fx(ust);

    double integralDegeri = ( 2 * h * ( (7*x0) + (32*x1) + (12*x2) + (32*x3) + (7*x4) ) ) / 45;

    return integralDegeri;
}

int main()
{   
    //sonuçlarda hata payını azaltmak için trapez kuralında n=6 aldım.
    printf("n=6 için trapez : %lf \n", trapez(0, 4, 6));
    //simpson 1-3 de n değerini arttırdıkça hata payımız azalır.
    printf("simpson 1-3 : %lf \n", simpson(0, 4, 2));
    //Simpson 3-8    n=3
    printf("simpson 3-8 : %lf \n", simpsonThreeEight(0, 4, 3));
    //Boole  n=4
    printf("boole : %lf \n", boole(0, 4, 4));
    
    return 0;
}
