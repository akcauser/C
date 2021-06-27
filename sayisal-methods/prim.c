//
//  main.c
//  prim
//
//  Created by ertuğrul gazi akça on 20.12.2018.
//  Copyright © 2018 ertuğrul gazi akça. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>

#define infinity 9999
#define MAX 20

int G[MAX][MAX],MST[MAX][MAX],n;
int prims()
{
    int cost[MAX][MAX];
    int u,v,min_distance,distance[MAX],from[MAX];
    int visited[MAX],no_of_edges,i,min_cost,j;
    
    //grafı kullanarak cost matrisini olusturuyoruz ve MST initialize ediyoruz
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {    if(G[i][j]==0)
            cost[i][j]=infinity;
            // i-j arası cost u sonsuz yaptım cünkü i-j arasıda bir edge gercekte yok,
            //ve biz algoritmada edge secerken minimum olanı sececegiz
        else
            cost[i][j]=G[i][j];
            MST[i][j]=0; // 0 ile initialize ettik
        }
    
    //initialise visited[],distance[] and from[]
    //0. dugumden baslamayı sectim
    distance[0]=0;
    visited[0]=1;
    
    for(i=1;i<n;i++) //kalan dugumler 1den n e kadar olanlar(0 ı zaten ziyaret etmistim)
    {   distance[i]=cost[0][i];
        from[i]=0;
        visited[i]=0;
    }
    
    min_cost=0;        //baslangıcta MST nin cost u 0
    no_of_edges=n-1;
    
    while(no_of_edges>0) //teorem geregi n-1 tane edge olması gerekiyordu
    {   //elimizdeki dugumlerden gidebilecegimiz min cost u olan edge i bulalım
        min_distance=infinity;
        for(i=1;i<n;i++)
            if(visited[i]==0 && distance[i]<min_distance)
            {   v=i;
                min_distance=distance[i];
            }
        //min cost ile v. dugume gidebilirim
        u=from[v];
        
        //MST'ye ekliyorum
        MST[u][v]=distance[v];
        MST[v][u]=distance[v];
        no_of_edges--;
        visited[v]=1;
        
        //updated the distance[] array
        for(i=1;i<n;i++)
            if(visited[i]==0 && cost[i][v]<distance[i])
            {   distance[i]=cost[i][v];
                from[i]=v;
            }
        min_cost=min_cost+cost[u][v]; //MST nin costunu güncelledim
    }
    return min_cost;
}

void printTree()
{   int i,j,cost=0;
    printf("\n------------------------------\n");
    printf("MST'de bulunan linkler:");
    
    for(i=0;i<n;i++)
    {   for(j=i;j<n;j++)
        if(MST[i][j]!=0){
            printf("\n\t%d-%d arasi link\t(cost:%d)", i,j,MST[i][j]);
            cost=cost+MST[i][j];
        }
    }
    
    printf("\n------------------------------\n");
    printf("Total cost=%d\n",cost);
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
    
    prims();
    printTree();
    
    return 0;
}
