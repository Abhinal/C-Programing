/***

Name: Abhinav Agarwal
Dept: CSE 2nd Year
Roll: 01
WAP in C to implement Merge sort.

***/


#include<stdio.h>

void quicksort(int arr[100],int first,int last) {
   int i, j, pivot, temp;
	if(first<last) {
      for(pivot=first, i=first, j=last; i<j;) {
      	for(; arr[i]<=arr[pivot] && i<last; i++) {}
      	for(; arr[j]>arr[pivot]; j--) {}
        if(i<j){ 
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
         }
      }

      temp=arr[pivot];
      arr[pivot]=arr[j];
      arr[j]=temp;
      quicksort(arr,first,j-1);
      quicksort(arr,j+1,last);
   }
}

int main(){
   int i, n, arr[100];

   printf("Enter total number of elements: ");
   scanf("%d",&n);

   printf("Enter elements:\n");
   for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

   quicksort(arr,0,n-1);

   printf("Results of quick sort: ");
   for(i=0;i<n;i++)
      printf("%d ",arr[i]);
   printf("\n");

   return 0;
}
