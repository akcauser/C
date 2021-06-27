//
//  main.c
//  kruskal
//
//  Created by ertuğrul gazi akça on 20.12.2018.
//  Copyright © 2018 ertuğrul gazi akça. All rights reserved.
//

#include<stdio.h>
#define MAX 30

// STRUCT VE DEĞİŞKENLER //
struct edge
{  int u,v,w;
};

struct edgelist
{
    struct edge data[MAX];
    int n;
};

struct edgelist elist; //sıralı olmayan linklerin tutulacagı liste (graftaki elemanlar ile doldurulacak)
int n;
int G[MAX][MAX];
struct edgelist MST;

// FONKSİYONLAR //
void union1(int belongs[],int c1,int c2)
{
    int i;
    for(i=0;i<n;i++)
        if(belongs[i]==c2)
            belongs[i]=c1;
}

void sortEdges() //elist yani unsorted edge listesindeki edgeleri cost'a göre sıralar
{
    int i,j;
    struct edge temp;
    "
    for(i=1;i<elist.n;i++)
        for(j=0;j<elist.n-1;j++)
            if(elist.data[j].w>elist.data[j+1].w)
            {   //swap işlemi yapılıyor yani j. ve j+1. elemanlar kendi arasında yer değiştiriyor
                temp=elist.data[j];
                elist.data[j]=elist.data[j+1];
                elist.data[j+1]=temp;
            }
}

void printTree()
{   printf("\n------------------------------\n");
    printf("MST'de bulunan linkler:");
    int i,cost=0;
    
    for(i=0;i<MST.n;i++)
    {
        printf("\n\t%d-%d arasi link\t(cost:%d)",MST.data[i].u,MST.data[i].v,MST.data[i].w);
        cost=cost+MST.data[i].w;
    }
    
    printf("\n------------------------------\n");
    printf("Total cost=%d\n",cost);
}

void kruskal()
{
    int belongs[MAX],i,j,cno1,cno2;
    elist.n=0;
    
    for(i=1;i<n;i++)  //graftaki tüm edgeleri listeye ekliyorum (unsorted sekilde)
        for(j=0;j<i;j++)
        {   if(G[i][j]!=0)
            {   //u-v arasında olan ve cost u w olan edge
                elist.data[elist.n].u=i;
                elist.data[elist.n].v=j;
                elist.data[elist.n].w=G[i][j];
                elist.n++; //listedeki edge count'u güncelledim
            }
        }
    
    sortEdges(); //edgeleri costlarına göre sırala
    
    for(i=0;i<n;i++)
        belongs[i]=i;
    
    MST.n=0; //baslangıcta MST de edge yok dolayısıyla edge sayısı n=0
    
    for(i=0;i<elist.n;i++) //sıralı listedeki tüm edgeleri gez
    {
        cno1=belongs[elist.data[i].u];
        cno2=belongs[elist.data[i].v];
        
        //cycle olusturmuyorsa ekle cycle olusturuyorsa bir sonraki tura(edge e ) gec
        if(cno1!=cno2)
        {
            MST.data[MST.n]=elist.data[i];
            MST.n=MST.n+1;
            union1(belongs,cno1,cno2);
        }
    }
}


// MAIN //
int main()
{
    int i,j;
    //kullanıcıdan alınan dugum sayısı ve komsuluk matrisi
    //örnek olması acısından alttaki degerleri almıs olsun
    n=4; //dugum sayisi
    int matrix[4][4]={   { 0, 10, 6, 5}, {10,  0, 0, 15}, { 6,  0, 0, 4}, { 5, 15, 4, 0} };
    
    //NOT: graf undirected oldugu icin simetrik olacak yani A'dan B'ye olan cost ile B'den A'ya olan cost aynı
    printf("\nKomsuluk matrisi:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            G[i][j]=matrix[i][j];
            printf("\t%d\t",G[i][j]);}
        printf("\n");
    }
    kruskal();
    printTree();
    return 0;
}

