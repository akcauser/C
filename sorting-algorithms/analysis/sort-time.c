//
//  main.c
//  
//
//  Created by ertuğrul gazi akça on 11.11.2018.
//  Copyright © 2018 ertuğrul gazi akça. All rights reserved.
//
//
//Ertuğrul Gazi AKÇA

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int *xp, int *yp);
void insertionSort(int arr[], int n);
void boubleSort(int arr[], int n);
void selectionSort(int arr[], int n);


int main () {
    int array_size = 1000;
    
    //time_t variable
    time_t t;
    double diff;
    clock_t start;
    
    //test
    /* Intializes random number generator */
    srand((unsigned) time(&t));
    
    int myArray[array_size];
    int a = 0;
    
    //create a different array
    for (int i = 0; i < array_size ; i++ ) {
        myArray[i] = (rand() % 1000);
    }
    //timer start
    start = clock();
    
    //selection sort
    selectionSort(myArray, array_size);
    
    //calculate and print difference
    diff = clock() - start;
    printf("Selection Sort Time for 1000 element = %.5f seconds \n",diff/CLOCKS_PER_SEC);
    
    
//AGAİN
    
    //again create a different array
    for (int i = 0; i < array_size; i++) {
        myArray[i] = (rand() % 1000);
    }
    //timer start
    start = clock();
    
    //insertion sort
    insertionSort(myArray, array_size);
    
    //calculate and print difference
    diff = clock() - start;
    printf("İnsertion Sort Tİme for 1000 element = %.5f seconds \n",diff/CLOCKS_PER_SEC );
    
//AGAİN
    
    //again create a different array
    for (int i = 0; i < array_size; i++) {
        myArray[i] = (rand() % 1000);
    }
    //timer start
    start = clock();
    
    //bouble sort()
    boubleSort(myArray, array_size);
    
    //calculate and print difference
    diff = clock() - start;
    printf("Bouble Sort Time for 1000 element = %.5f seconds \n",diff/CLOCKS_PER_SEC);
    
    
   
    /*
     for (int i = 0; i < array_size; i++) {
     printf("%d\n",myArray[i]);
     }
     */
    
    
    return(0);
}



void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i-1;
        
        /* Move elements of arr[0..i-1], that are
         greater than key, to one position ahead
         of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}
void selectionSort(int arr[], int n){
    int min;
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = (i + 1) ; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(&arr[i], &arr[min]);
    }
}
void boubleSort(int arr[], int n){
    
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}
