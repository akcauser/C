//
//  main.c
//  veriyapilari
//
//  Created by ertuğrul gazi akça on 25.10.2018.
//  Copyright © 2018 ertuğrul gazi akça. All rights reserved.
//
//Ertuğrul Gazi AKÇA
//
//
#include <stdio.h>
#include <stdlib.h>

struct treeNode {
    int data;
    struct treeNode *left;
    struct treeNode *right;
};

struct treeNode* myTree = NULL;

int myArray[] = malloc(sizeof(int[]))
int counter = 0;
//Fonksiyonların prototiplerinin oluşturulması
struct treeNode *newNode(int item);
struct treeNode* insert(struct treeNode *node,int item);

void ldr(struct treeNode *node){
    
   
    
    if (node != NULL) {
        if (node->left==NULL && node->right == NULL) {
            myArray[counter] = node->data
            counter++;
        }
        ldr(node->left);
        ldr(node->right);
    }
}

int main(int argc, const char * argv[]) {
    while (1) {
        printf("******** ********\n");
        printf("\t1->Eleman Ekle\n");
        printf("\t2->Yaprak Düğümleri Görüntüle\n");
        printf("\t3->Exit\n");
        printf("******** ********\n");
        int selection;
        int value = 0;
        printf("Lütfen Seçim yapınız:");
        scanf("%d",&selection);
        switch (selection) {
            case 1:
                printf("Eklenecek elemanı giriniz:");
                scanf("%d",&value);
                if (myTree == NULL) {
                    myTree = insert(myTree, value);
                }else{
                    insert(myTree, value);
                }
                for (int i = 0; i<counter; i++) {
                    printf("%d \t",myArray[i]);
                }
                break;
            case 2:
                if (myTree == NULL) {
                    printf("Görüntülenecek ağaç yok");
                }else{
                    ldr(myTree);
                }
                break;
            case 3:
                return 0;
                break;
                
            default:
                break;
            }
    }
    return 0;
}


struct treeNode *newNode(int item){
    
    struct treeNode *temp = (struct treeNode *)malloc(sizeof(struct treeNode));
    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
struct treeNode* insert(struct treeNode *node,int item){
    
    if (node == NULL) {
        return newNode(item);
    }
    
    if (item < node->data) {
        node->left = insert(node -> left, item);
    }else{
        node->right = insert(node -> right, item);
    }
    return node;
}
