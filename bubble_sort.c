/***

Name: Abhinav Agarwal
Dept: CSE 2nd Year
Roll: 01
WAP in C to implement Bubble sort.

***/


#include <stdio.h>
int main() {
    int arr[100], number, i, j, temp;

    printf("Enter the total Number of Elements  :  ");
    scanf("%d", &number);

    printf("Enter the Array Elements\n");
    for(i = 0; i < number; i++)
        scanf("%d", &arr[i]);

    for(i = 0; i < number - 1; i++) {
        for(j = 0; j < number - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Results of Bubble sort : ");
    for(i = 0; i < number; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

