#include <bits/stdc++.h>
#include <windows.h>
using namespace std;


void printArr(vector<int> arr){
    cout << endl;
    for(auto i : arr){
        cout << i << " ";
    }
    cout << endl;
}

vector<int> BubbleSort(vector<int> &arr){
    for(int i = 0; i < arr.size() ; i++){
        bool isSwap = false;
        for(int j = 0 ; j < arr.size()-i ; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j] , arr[j+1]);
                isSwap = true;
            }
        }
        if(!isSwap){
            break;
        }
    }
    return arr;
}
int main(){
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(0);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(0);

    BubbleSort(arr);
    printArr(arr);
  return 0;
}