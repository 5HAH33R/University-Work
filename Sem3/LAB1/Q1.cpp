#include <iostream>
using namespace std;

#define ROWS 3
#define COLS 3

void printArr(int** arr , int rows , int cols){
    for(int i = 0 ; i < rows ; i++){    
        cout << endl;
        for(int j = 0; j< cols ; j++){
            cout << arr[i][j] << " ";
        }
    }
}

int main(){
    int** arr = new int*[ROWS];

    for(int i =0; i<5 ; i++){
        arr[i] = new int[COLS];
    }

    for(int i = 0 ; i < ROWS ; i++){
        for(int j = 0; j< COLS ; j++){
            cout << "enter value to insert : ";
            cin >> arr[i][j];
        }
    }

    cout << "This is your Matrix: " << endl;
    printArr(arr,ROWS,COLS);

    int* copyarr = new int[ROWS*COLS];
    int it = 0;
    for(int i = 0 ; i < ROWS ; i++){
        for(int j = 0; j< COLS ; j++){
            copyarr[it] = arr[j][i];
            it++;
        }
    }

    cout  << endl << "After copying to 1D array" << endl;
    for (int i = 0 ; i < ROWS*COLS ; i++){
        cout << copyarr[i] << " ";
    }

  return 0;
}