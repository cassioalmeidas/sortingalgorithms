#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "algorithms.h"

using namespace std;


int main(){
	long n;
	int *vet, i, j, a, o;
	long assig, comp = 0;

	do {
		printf("Enter with the number of vector elements: ");
		scanf("%ld", &n);
		printf("List of sorting algorithm: \n\n");
		printf(" 0 - BubbleSort\n 1 - SelectSort\n 2 - QuickSort\n 3 - InsertSort\n 4 - ShellSort\n 5 - Exit \n\n");
		printf("Choose one: ");
		scanf("%d", &a);
		printf("In what order is the vector?\n\n");
		printf(" 0 - Increscent\n 1 - Decreasing\n 2 - Random\n\n");
		printf("Choose one: ");
		scanf("%d", &o);


		vet = new int [n];
		
		switch(o){
			case 0:
				for(i=0;i<n;i++)
					vet[i] = i;	
				break;
			case 1:
				for(i=0,j=n-1;i<n;i++,j--)
					vet[i] = j;
				break;
			case 2: 
				srand(time(NULL));
				for(i=0;i<n;i++)
					vet[i] = i;
				for(i=n-1;i>0;i--){
					int w = rand()%i;
					int t = vet[i];
					vet[i] = vet[w];
					vet[w] = t;
				}
				break;
			default:
				printf("invalid option.");

		}

		switch(a){
			case 0:
				bubbleSort(vet, n, comp, assig);
				printf("Number of comparisons: %ld\n", comp);		
				printf("Number of assignments: %ld\n", assig);		
				break;
			case 1:
				selectSort(vet, n, comp, assig);
				printf("Number of comparisons: %ld\n", comp);
				printf("Number of assignments: %ld\n", assig);
				break;
			case 2:
				comp = assig = 0;
				quickSort(vet, 0, n,comp, assig);
				printf("Number of comparisons: %ld\n", comp);
				printf("Number of assignments: %ld\n", assig);
				break;
			case 3:
				insertSort(vet, n, comp, assig);
				printf("Number of comparisons: %ld\n", comp);
				printf("Number of assignments: %ld\n", assig);
				break;
			case 4:
			 	shellSort(vet, n, comp, assig);
				printf("Number of comparisons: %ld\n",comp);
				printf("Number of assignments: %ld\n", assig);
				break;
			case 5:
				printf("By...\n");
				exit(EXIT_FAILURE);
			default: 
				printf("invalid option.");
		}

	} while(a != 5);

	
	delete[] vet;
	return 0;
}