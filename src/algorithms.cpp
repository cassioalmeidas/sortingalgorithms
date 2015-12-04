#include <stdlib.h>
#include "algorithms.h"

void bubbleSort(int *vet, long n, long & comp,  long & assig){
  long  i, j;
  int aux = 0 ;

  comp = assig = 0; // initializing

  for(i=0; i < n-1; i++) {          
    for(j=0; j < n - i - 1; j++) {
      comp++;          
      if(vet[j] > vet[j+1]) {
        aux = vet[j];
        vet[j] = vet[j+1];
        vet[j+1] = aux;      
        assig+=3;  // three assignments
      }
    }
  }
}

void selectSort(int *vet, long n, long & comp, long & assig){
   long c, d, position, swap;

   comp = assig  = 0; // initializing 
  
   for ( c = 0 ; c < ( n - 1 ) ; c++ ){
      position = c;
 
      for ( d = c + 1 ; d < n ; d++ ){
        comp++;
         if ( vet[position] > vet[d] ){
            position = d;
            assig++;
         }
      }

      comp++;
      if ( position != c ){
         swap = vet[c];
         vet[c] = vet[position];
         vet[position] = swap;
         assig++;
      }
   }
}


// source http://www.algolist.net/Algorithms/Sorting/Quicksort
void quickSort(int *arr, long left, long right, long & comp, long & assig) {
    long i = left, j = right;
    int tmp;
    long pivot = arr[(left + right) / 2];
    assig = comp  = 0;

    /* partition */
    while (i <= j) {
    comp++;
        while (arr[i] < pivot){
            comp++;
            i++;
            assig++;
        }comp++;
        while (arr[j] > pivot){
            comp++;
            j--;
            assig++;
        }comp++;
        comp++;
        if (i <= j) {
          tmp = arr[i];
          arr[i] = arr[j];
          arr[j] = tmp;
          i++;
          j--;
          assig += 5;
        }
    }comp++;

    /* recursion */
    comp++;
    if (left < j)
        quickSort(arr, left, j, comp, assig);

    comp++;
    if (i < right)
        quickSort(arr, i, right, comp, assig);
}




void insertSort(int *vet, long n, long & comp, long & assig){
  long c, d, t;
  comp = assig = 0;

  for (c = 1 ; c <= n - 1; c++) {
    d = c;
    assig++;
    while ( d > 0 && vet[d] < vet[d-1]) {
      comp++;
      t          = vet[d];
      vet[d]   = vet[d-1];
      vet[d-1] = t;
      d--;
      assig += 4; // four assignments
    }comp++;
  }
}


void shellSort(int *vet, long n, long & comp, long & assig){
 long  i,j,k,tmp;
 comp = assig = 0;

  for(i=n/2; i>0; i=i/2){
   for(j=i; j<n; j++){
     for(k=j-i; k>=0; k=k-i){
        comp++;
        if(vet[k+i]>=vet[k])
            break;
        else{
            tmp=vet[k];
            vet[k]=vet[k+i];
            vet[k+i]=tmp;
            assig += 3;
        }
     }
   }
 }
}