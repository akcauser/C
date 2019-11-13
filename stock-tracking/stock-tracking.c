#include <stdio.h>

int civataSayisi = 100;
int pulSayisi = 100;
int somunSayisi = 100;

void stokEkle()
{   
    int urunSecimi;
    printf("1-Civata\n");
    printf("2-Pul\n");
    printf("3-Somun\n");
    printf("Stok eklemek istediğiniz ürünü seçiniz:\nSeçilen ürün : ");
    scanf("%d", &urunSecimi);

    int eklenecekMiktar;
    printf("Eklenecek stok miktarını giriniz:\nGirilen miktar : ");
    scanf("%d", &eklenecekMiktar);

    if (urunSecimi == 1)
    {   
        civataSayisi+=eklenecekMiktar;
        printf("Civata stok güncellendi -> %d\n", civataSayisi);
    }
    else if (urunSecimi == 2)
    {
        pulSayisi+=eklenecekMiktar;
        printf("Pul stok güncellendi -> %d\n", pulSayisi);
    }
    else if (urunSecimi == 3)
    {   
        somunSayisi+=eklenecekMiktar;
        printf("Somun stok güncellendi -> %d\n", somunSayisi);
    }
    else
    {
        printf("Geçersiz ürün!");
    }
}

void stokKullan()
{   
    int urunSecimi;
    printf("1-Civata\n");
    printf("2-Pul\n");
    printf("3-Somun\n");
    printf("Azaltmak istediğiniz ürünü seçiniz:\nSeçilen ürün : ");
    scanf("%d", &urunSecimi);

    int eksilenMiktar;
    printf("Kullanılacak stok miktarını giriniz:\nGirilen miktar : ");
    scanf("%d", &eksilenMiktar);

    if (urunSecimi == 1)
    {   
        if(civataSayisi < eksilenMiktar){
            printf("Stokta yeterli miktarda civata yok. Önce ekleme yapınız!\n");
        }else{
            civataSayisi-=eksilenMiktar;
            printf("Civata stok güncellendi -> %d\n", civataSayisi);
        }
        
    }
    else if (urunSecimi == 2)
    {   
        if(pulSayisi < eksilenMiktar){
            printf("Stokta yeterli miktarda pul yok. Önce ekleme yapınız!\n");
        }else{
            pulSayisi-=eksilenMiktar;
            printf("Pul stok güncellendi -> %d\n", pulSayisi);
        }
        
    }
    else if (urunSecimi == 3)
    {      
        if(somunSayisi < eksilenMiktar){
            printf("Stokta yeterli miktarda somun yok. Önce ekleme yapınız!\n");
        }else{
            somunSayisi-=eksilenMiktar;
            printf("Somun stok güncellendi -> %d\n", somunSayisi);
        }
        
    }
    else
    {
        printf("Geçersiz ürün!");
    }
    if(civataSayisi < 50){
        printf("Civata sayısı kritik seviyededir lütfen ekleme yapınız!\n");
    }
    if(pulSayisi < 50){
        printf("Pul sayısı kritik seviyededir lütfen ekleme yapınız!\n");
    }
    if(somunSayisi < 50){
        printf("Somun sayısı kritik seviyededir lütfen ekleme yapınız!\n");
    }
}


void stokGoster()
{
    printf("Civata Sayısı -> %d\n", civataSayisi);
    printf("Pul Sayısı -> %d\n", pulSayisi);
    printf("Somun Sayısı -> %d\n", somunSayisi);
    if(civataSayisi < 50){
        printf("Civata sayısı kritik seviyededir lütfen ekleme yapınız!\n");
    }
    if(pulSayisi < 50){
        printf("Pul sayısı kritik seviyededir lütfen ekleme yapınız!\n");
    }
    if(somunSayisi < 50){
        printf("Somun sayısı kritik seviyededir lütfen ekleme yapınız!\n");
    }
}

int main()
{

    int secim;
    do
    {
        printf("Yapacağınız işlemi seçiniz:\n");
        printf("---------------------------\n");
        printf("1-Stok Ekle\n");
        printf("2-Stok Kullan\n");
        printf("3-Stok Görüntüle\n");
        printf("4-Çıkış\nSeçiminiz : ");
        scanf("%d", &secim);

        switch (secim)
        {
        case 1:
            stokEkle();
            break;
        case 2:
            stokKullan();
            break;
        case 3:
            stokGoster();
            break;
        case 4:
            printf("Çıkış Yapılıyor...bye\n");
            break;

        default:
            printf("Seçiminiz geçersizdir!\n");
            break;
        }
        printf("**************************************************\n");
    } while (secim != 4);

    return 0;
}
