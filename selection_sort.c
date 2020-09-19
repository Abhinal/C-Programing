/***

Name: Abhinav Agarwal
Dept: CSE 2nd Year
Roll: 01
WAP in C to implement Selection sort.

***/


#include <stdio.h>
int main() {
    int arr[100], number, i, j, temp;

    printf("Enter the total Number of Elements  :  ");
    scanf("%d", &number);

    printf("Enter the Array Elements\n");
    for(i = 0; i < number; i++)
        scanf("%d", &arr[i]);

    for(i = 0; i < number; i++) {
        for(j = i + 1; j < number; j++) {
            if(arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Results of Selection sort : ");
    for(i = 0; i < number; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

