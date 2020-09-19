/***

Name: Abhinav Agarwal
Dept: CSE 2nd Year
Roll: 01
WAP in C to implement Insertion sort.

***/


#include<stdio.h>
int main() {
    int arr[100], number, i, j, temp;

    printf("Enter the total Number of Elements : ");
    scanf("%d", &number);

    printf("Enter the Array Elements\n");
    for(i=0; i < number; i++){
        scanf("%d", &arr[i]);
        }
	
    for(i=1;i<number;i++){
      temp=arr[i];
      j = i-1;
      while((temp < arr[j]) && (j >= 0)){
         arr[j+1]=arr[j];
         j--;
      }
      arr[j+1]=temp;
   }

   printf("Result of insertion sort: ");
   for(i=0;i<number;i++)
      printf("%d ",arr[i]);

   return 0;
}
