#include <stdio.h>


int main()
{   
    // Dosyadan gerekli verilerin okuma işlemi yapılıyor.
    FILE *fp1;
    double id1;
    int veriSayisi = 0;
    double requestValue = 0;
    
    printf("Dosyanızda kaç tane x değeri var giriniz: ");
    scanf("%d", &veriSayisi);

    double x[veriSayisi];
    double y[veriSayisi];

    
    double katsayilar[veriSayisi];

    if((fp1 = fopen ("data.txt", "r")) == NULL) {
        printf("Dosya açma hatası!");
    }

    int i = 0;
    while(!feof(fp1)){  
        fscanf(fp1, "%lf %lf", &x[i], &y[i]);
        i++;
    }
    
    fclose(fp1);

    // İstenilen değeri kullanıcıdan alıyorum.
    printf("istenilen değeri giriniz");
    scanf("%lf", &requestValue);

    // Lagrange metodunu yazmaya başladım.
    for(int t = 0 ; t< veriSayisi; t++){
        
        double pay = 1;
        double payda = 1;
        double katsayi = 0;
        
        //pay ve payda hesaplama
        for(i = 0; i < veriSayisi; i++){
            if (i == t) {
                continue;
            }
            pay = pay * (requestValue - x[i]);   
            payda = payda * (x[t] - x[i]); 
                    
        }  

        katsayi = pay / payda;  
        katsayilar[t] = katsayi; 
        
      
        //katsayi hesaplama
        

    }

    for(int i = 0; i < veriSayisi; i++)
    {
        printf("L%d : %lf\n", i, katsayilar[i]);
    }
      
    return 0;
}
