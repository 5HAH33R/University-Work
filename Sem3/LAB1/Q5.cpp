#include <iostream>
using namespace std;

int** CreateMatrix(int rows, int cols){
    int** arr = new int*[rows];

    for(int i =0; i<rows ; i++){
        arr[i] = new int[cols];
    }

    for(int i = 0 ; i < rows ; i++){
        for(int j = 0; j< cols ; j++){
            cout << "enter value to insert: ";
            cin >> arr[i][j];
        }
    }
    return arr;

}

void printMatrix(int** arr , int rows , int cols){
    for(int i = 0 ; i < rows ; i++){    
        cout << endl;
        for(int j = 0; j< cols ; j++){
            cout << arr[i][j] << " ";
        }
    }
}

bool BinarySearch2D(int** arr ,int right, int left, int rows,  int target){
    while(left <= right){
        int mid = (left +right)/2;
        int row = mid/rows;
        int col = mid%rows;
        if(arr[row][col] == target){
            return true;
        }
        else if(arr[row][col] < target){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return false;
}

int main(){
    int rows;
    int cols;
    cout << "Enter rows and cols (# #): ";
    cin >> rows >> cols;
    int left = 0;
    int right = (rows*cols)-1;

    int** arr = CreateMatrix(rows,cols);

    printMatrix(arr , rows, cols);

    int target;
    while(1){    
        cout << " \n Insert target to find (-1 to exit) : ";
        cin >> target;
        if(target == -1){
            break;
        }
        bool ans = BinarySearch2D(arr ,right , left , rows, target);
        if(ans == true){
            cout << "Element was found";
        }
        else{
            cout << "Not Found";
        }
    }







  return 0;
}