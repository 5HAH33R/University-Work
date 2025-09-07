#include <iostream>
using namespace std;

class ArrTwoD{
    private:
    int **Data;

    public:
    int rows;
    int cols;
    ArrTwoD(){
        rows = 0;
        cols = 0;
    }
    ArrTwoD(int numRows, int numCols) : rows(numRows), cols(numCols) {
        Data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            Data[i] = new int[cols];
           }
    }

    ArrTwoD(const ArrTwoD &objToCopy): rows{objToCopy.rows} , cols{objToCopy.cols} {
        Data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            Data[i] = new int[cols];
            for (int j = 0; j < cols; ++j) {
                Data[i][j] = objToCopy.Data[i][j];
            }
        }
    }

    void ChangeData(int i , int j , int value){
        this->Data[i][j] = value;
    }
    int GetData(int i , int j){
        return this->Data[i][j];
    }
    void Question2Implementation(int target);

    
    ArrTwoD& operator=(ArrTwoD& other) { //ArrTwoD& is for referencing , doesnt mean address is being returned
        
        rows = other.rows;
        cols = other.cols;
        Data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            Data[i] = new int[cols];
            for (int j = 0; j < cols; ++j) {
                Data[i][j] = other.Data[i][j];
            }
        }
        
        return *this; //this is the dereferenced obj returned , thats why we used ArrTwoD& as the return type
    }
    
    ArrTwoD operator+( ArrTwoD& other){
        if (rows != other.rows || cols != other.cols) {
            cout << "Arrays dont have same dimensions" << endl;
            ArrTwoD EmptyArr;
            return EmptyArr;
        }
        
        ArrTwoD result(rows, cols); 
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.Data[i][j] = this->Data[i][j] + other.Data[i][j];
            }
        }
        return result;
    }
    ArrTwoD operator-( ArrTwoD& other){
        if (rows != other.rows || cols != other.cols) {
            cout << "Arrays dont have same dimensions" << endl;
            ArrTwoD EmptyArr;
            return EmptyArr;
        }
        
        ArrTwoD result(rows, cols); 
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.Data[i][j] = this->Data[i][j] - other.Data[i][j];
            }
        }
        return result;
    }
    
    ArrTwoD operator*( ArrTwoD& other){
        if (rows != other.rows || cols != other.cols) {
            cout << "Arrays dont have same dimensions" << endl;
            ArrTwoD EmptyArr;
            return EmptyArr;
        }
        
        ArrTwoD result(rows, cols); 
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.Data[i][j] = this->Data[i][j] * other.Data[i][j];
            }
        }
        return result;
    }

    int* operator[](int row){
        if(row <  0 || row > rows){
            cout<< "Out of bounds";
        }
        else{
            return Data[row];
        }

    }

    void PrintArr(){
        cout << "\n---\n";
        for (int i = 0; i < this->rows; ++i) {
            for (int j = 0; j < this->cols; ++j) {
                cout << this->Data[i][j] << " ";
            }
            cout << endl;
        }
        cout << "---\n";
    }
    
    ~ArrTwoD(){
        for (int i = 0; i < rows; ++i) {
            delete[] Data[i];
        }
         
        delete[] Data;
    }
    
};

// int main(){
    
//     ArrTwoD Arr1(2, 3);
//     ArrTwoD Arr2(2, 3);
//     int value = 0;
    
//     for (int i = 0; i < Arr1.rows; ++i) {
//         for (int j = 0; j < Arr1.cols; ++j) {
//             Arr1[i][j] = value; // using "[]" overloading
//             Arr2[i][j] = value;
//             value++;
//         }
//     }

//     Arr1.PrintArr();

//     ArrTwoD ArrCopy;
//     ArrCopy = Arr1; // using "=" overloading

//     ArrCopy.PrintArr();

//     ArrTwoD Arr3;

//     (Arr1+Arr2).PrintArr(); // printing directly because assignment operator is overloaded (using + - * overloading Below)

//     (Arr1-Arr2).PrintArr();

//     (Arr1+Arr2).PrintArr();

//   return 0;
// }