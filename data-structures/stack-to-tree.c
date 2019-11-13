//
//  main.c
//  veri_yapilari_odev
//
//
//  Created by ertuğrul gazi akça on 19.10.2018.
//  Copyright © 2018 ertuğrul gazi akça. All rights reserved.
//
//Ertuğrul Gazi AKÇA
//
//

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20

typedef struct stack {
    int top;
    int arr[MAXSIZE];
}STACK;

//key değeri düğümün alacağı değerdir.
//Her düğümün 2 çocuğu olabileceği için left ve right işaretçilerini almıştır
struct node
{
    int key;
    struct node *left, *right;
};

// Bu fonksiyon verilen değerde düğüm oluşturur.
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    //Her yeni eklenen düğüm leaf durumunda olduğundan sol ve sağ işaretçiler null değerini gösterir
    temp->left = temp->right = NULL;
    return temp;
}


//Ağacı ile alakalı fonksiyonlar
struct node* insert(struct node* node, int key);
void inorder(struct node *root);
void moveToTree(STACK *stack);

//ilk ağacımızı oluşturduk.
struct node* node = NULL;

//Yığıt ile ilgili fonksiyonlar
void isEmpty(STACK *stack); //stack boş mu değil mi kontrolü-dolu mu değil mi kontrolü
void push(STACK *stack, int value); // stack e eleman ekleme fonksiyonu
void pop(STACK *stack); //stack ten eleman çıkarma fonksiyonu
void reading(STACK stack); // stack teki elemanları okuma fonksiyonu


//MAIN fonksiyonu
int main(int argc, const char * argv[]) {
    
    //yığın oluşturuldu
    STACK stack;
    //top değeri başlanıgıçta -1 olarak atandı
    stack.top = -1;
    
    //Ağaç oluşturudu il değer atandı.
    
    
    //her zaman true dönen bir while döngüsü ile programın hiç kapanmaması sağlandı.
    while (1) {
        int kullanici_secimi = 0;
        
        printf("\n***********-***********\n\n");
        printf("\t 1 ---> Yığıta eleman ekle\n");
        printf("\t 2 ---> Yığıttan eleman çıkar\n");
        printf("\t 3 ---> Yığıttaki elemanları yazdır\n");
        printf("\t 4 ---> Yığıttaki elemanları ikili ağaca taşı\n\n");
        printf("***********-***********\n");
        printf("SEÇİM YAPINIZ:\n");
        scanf("%d",&kullanici_secimi);
        switch (kullanici_secimi) {
            case 1:
                if (stack.top == MAXSIZE-1) {
                    printf("%s","Yığıt dolu!\n");
                    break;
                }
                printf("Eklenecek sayıyı giriniz: \n");
                int eklenecek_sayi;
                scanf("%d",&eklenecek_sayi);
                push(&stack, eklenecek_sayi);
                break;
            case 2:
                if(stack.top == -1){
                    printf("%s","Yığıt boş!\n");
                    break;
                }
                pop(&stack);
                break;
            case 3:
                if(stack.top == -1){
                    printf("%s","Yığıt boş!\n");
                    break;
                }
                reading(stack);
                break;
            case 4:
                moveToTree(&stack);
                inorder(node);
                break;
            default:
                break;
        }
    }
    
    
    return 0;
}//END MAIN FUNCTION

//Yığıta eleman eklediğimiz fonksiyon
void push(STACK *stack,int value){
    stack -> arr[++(stack -> top)] = value;
    
    /*   if (node == NULL) {
     node = insert(node, value);
     }else{
     insert(node, value);
     }
     */
}

//Yığıttan eleman çektiğimiz fonksiyon
void pop(STACK *stack){
    printf("çıkarılan eleman: %d\n",stack->arr[stack->top]);
    stack -> top -= 1;
}

//Yığıttaki elemanları listelediğimiz fonksiyon
void reading(STACK stack){
    printf("*********\n");
    while (stack.top != -1) {
        printf("%d\n",stack.arr[stack.top]);
        
        stack.top -= 1;
    }
    
}
//Yığıttaki elemanları ağaca taşıdığımız fonksiyon
void moveToTree(STACK *stack){
    if (stack->top != -1) {
        node = NULL;
    }
    while (stack->top != -1) {
        if (node == NULL) {
            node = insert(node, stack->arr[stack->top]);
        }else{
            insert(node, stack->arr[stack->top]);
        }
        stack->top -= 1;
    }
}

//özyinelemeli ldr traverse etttiğimiz fonksiyon
void inorder(struct node *root){
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d - \t", root->key);
        inorder(root->right);
    }
    //  printf("\n");
}

// ekleme yapan esas fonksiyonumuz
struct node* insert(struct node* node, int key){
    /* Eğer düğüm NULL ise doğru konum demektir ve insert işlemi burada yapılır */
    if (node == NULL) return newNode(key);
    
    /* NULL değeri bulunamadıysa yeni düğümler gerektiği gibi oluşturulur. */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    
    /* değiştirilmemiş düğümü return eder */
    return node;
}
