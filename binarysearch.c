/***

Name: Abhinav Agarwal
Dept: CSE 2nd Year
Roll: 01
WAP in C to implement Binary search (non-recursively).

***/


#include <stdio.h>

int binarysearch(int arr[], int low, int high, int element) { 
  while (low <= high) { 
    int mid = low + (high-low)/2; 
  
    // Check if element is present at mid 
    if (arr[mid] == element)  
        return mid;   
  
    // If element greater, ignore left half   
    if (arr[mid] < element)  
        low = mid + 1;  
  
    // If element is smaller, ignore right half  
    else 
         high = mid - 1;  
  } 
  
  // if we reach here, then element was not present 
  return -1;  
} 


int main(void){
   int n, array[100], element;
   printf("Enter the total no. of elements : ");
   scanf("%d",&n);
   printf("Enter the sorted array elements\n");
   for (int i =0; i<n; i++)
       scanf("%d",&array[i]);
   printf("Enter the search element : ");
   scanf("%d",&element);
   int found_index = binarysearch(array, 0, n-1, element);
   if(found_index == -1 ) {
      printf("Element not found in the array\n");
   }
   else {
      printf("Element found at index : %d\n",found_index);
   }
   return 0;
}
