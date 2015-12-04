#include <stdlib.h>
#include "algorithms.h"

void bubbleSort(int *vet, long n, long & comp){
  long  i, j;
  int aux = 0 ;

  comp = 0; // initializing

  for(i=0; i < n-1; i++) {          
    for(j=0; j < n - i - 1; j++) {
      comp++;          
      if(vet[j] > vet[j+1]) {
        aux = vet[j];
        vet[j] = vet[j+1];
        vet[j+1] = aux;      
      }
    }
  }
}

void selectSort(int *vet, long n, long & comp){
   long c, d, position, swap;

   comp = 0; // initializing 
  
   for ( c = 0 ; c < ( n - 1 ) ; c++ ){
      position = c;
 
      for ( d = c + 1 ; d < n ; d++ ){
        comp++;
         if ( vet[position] > vet[d] ){
            position = d;
         }
      }

      if ( position != c ){
         swap = vet[c];
         vet[c] = vet[position];
         vet[position] = swap;
      }
   }
}

long auxcomp = 0;

int cmpfunc (const void * a, const void * b){
  auxcomp++;
  return ( *(int*)a - *(int*)b );
}


void quickSort(int *vet, long n, long & comp) {
    qsort(vet, n, sizeof(int), cmpfunc);
    comp = auxcomp;
}




void insertSort(int *vet, long n, long & comp){
  long c, d, t;
  comp = 0;

  for (c = 1 ; c <= n - 1; c++) {
    d = c;
    while ( d > 0 && vet[d] < vet[d-1]) {
      comp++;
      t          = vet[d];
      vet[d]   = vet[d-1];
      vet[d-1] = t;
      d--;
    }comp++;
  }
}


void shellSort(int *vet, long n, long & comp){
 long  i,j,k,tmp;
 comp = 0;

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
        }
     }
   }
 }
}