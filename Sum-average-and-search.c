#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, i, sum = 0;
    float average;
    int *arr;

    printf("Enter the number of elements: ");
    scanf("%d", &num);

    arr = (int *)malloc(num * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (i = 0; i < num; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    average = (float)sum / num;
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);

    int searchNum;
    printf("Enter a number to search: ");
    scanf("%d", &searchNum);
    int found = 0;

    for (i = 0; i < num; i++) {
        if (arr[i] == searchNum) {
            printf("Number %d found at index %d\n", searchNum, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Number %d not found in the array\n", searchNum);
    }

    free(arr);
    return 0;
}
