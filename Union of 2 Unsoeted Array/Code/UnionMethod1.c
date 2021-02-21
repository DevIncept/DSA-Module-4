#include <stdio.h>

int printUnion(int[],int[],int,int);
int printIntersection(int[],int[],int,int);

int main() {
	int arr1[] = {1,2,4,5,6};
	int arr2[] = {2,3,5,7};
	int m = sizeof(arr1) / sizeof(arr1[0]);
	int n = sizeof(arr2) / sizeof(arr2[0]);
	//printf("%d%d",m,n);
	printf("\nPrint the union of both array");
	printUnion(arr1,arr2,m,n);
	printf("\nPrint the intersection of both the array");
	printIntersection(arr1,arr2,m,n);
}

int printUnion(int arr1[],int arr2[], int m,int n)
{
    int i=0, j=0; //initialize 2 variable to 0
    while(i < m && j < n)
    {
        if(arr1[i] < arr2[j]) {
            printf(" %d",arr1[i++]);
        }
        else if(arr1[i] > arr2[j]) {
            printf(" %d",arr2[j++]);
        }
        else {
           printf(" %d",arr2[j++]);
           i++;
        }
    }
    
    //Print the remaining element of larger array
    while(i<m) {
        printf(" %d",arr1[i++]);
    }
    while(j<n) {
        printf(" %d",arr2[j++]);
    }
    
}

int printIntersection(int arr1[],int arr2[],int m, int n)
{
    int i=0,j=0;
    while(i < m && j < n)
    {
        if(arr1[i] < arr2[j]) {
          i++;
        }
        else if(arr1[i] > arr2[j]) {
            j++;
        }
        else {  /* if(arr1[i] == arr2[j] */
            printf(" %d",arr2[j++]);
            i++;
        }
    }
    
}
