#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int main()
{
    int arr[10] = {1, 8, 5, 7, 9, 3, 2, 6, 10, 4};
    int mid = 9;
    int pivot = arr[5];
    int Temp;
    Temp = arr[9];
    arr[9] = pivot;
    arr[5] = Temp;
    int ItemFromLeft,ItemFromRight;
    int j = 8;
    int i = 0;
    while(i<j){
        ItemFromLeft = arr[i];
        ItemFromRight = arr[j];
        if(ItemFromLeft > pivot && ItemFromRight < pivot){
            Temp =  arr[i];
            arr[i] = arr[j];
            arr[j] = Temp;
        }
        j--;
        i++;
    }
    Temp =  arr[i-1];
    arr[i-1] = arr[9];
    arr[9] = Temp;

    for(int i = 0 ; i < 10; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
