#include <stdio.h>


int main()
{   
    FILE *fp1;
    int id1;

    //dosya yazma modunda açma
    if ((fp1 = fopen ("dosya1.txt", "w")) == NULL) {
        printf("Dosya açma hatası!");

    }

    //dosyaya veri yazma işlemi
    for (id1 = 0; id1 < 10; id1++)
    {
        fputc('a', fp1);
    }
    fclose(fp1);    

    //Dosyayı okuma modunda açma
    if((fp1 = fopen ("dosya1.txt", "r")) == NULL) {
        printf("Dosya açma hatası");
    }

    for(id1 = 0; id1 < 10; id1++)
    {
        printf("%c", getc(fp1));
    }
    fclose(fp1);
    

    return 0;
}
