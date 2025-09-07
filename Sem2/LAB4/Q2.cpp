#include <iostream>
using namespace std;

class DynamicArray{
    private:
    int size = 0;
    int* arr;
    public:
    DynamicArray(int size) : size(size) {
        arr = new int[size]();
    }

    void Push(int num){
        int i = size;
        bool flag = false;
        while(!flag && i >= 0){
            if(arr[i] == 0){
                arr[i] = num;
                flag = true;
            }
            else{
                i--;
            }

        }
    }

    void PrintArray(){
        for(int i =0 ; i < size ; i++){
            cout << arr[i];
        }

    }

    int Size(){
        return size;
    }

    ~DynamicArray(){
        delete[] arr;
    }

};
int main(){
    DynamicArray arrName(5);
    arrName.PrintArray();
    cout << endl;
    arrName.Push(2);
    arrName.PrintArray();
    cout << endl;
    arrName.Push(4);
    arrName.PrintArray();
    cout << endl;

    cout << "the size of the array is "  << arrName.Size() << endl;
    return 0;
}