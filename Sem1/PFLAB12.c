#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int main()
{
    int size, i, sum = 0;
    float average;
    int *arr;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    arr = (int *)malloc(size * sizeof(int));

    printf("Enter the numbers:\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }


    average = sum / size;


    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);

    for (i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Sorted array:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}