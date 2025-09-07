#include <iostream>
using namespace std;


int BinarySearch(int arr[] , int left , int right , int target){
    while(left <= right){
        int mid = (left+right)/2;
        if(arr[mid] == target){
            return mid;
        }
        if(arr[mid] < target){
            left = mid+1;
        }
        else if(arr[mid] > target){
            right = mid-1;
        }

    }
    return -1;

}
int main(){
    int size = 0;
    cout << "Enter the size of the array : ";
    cin >> size;

    int* arr = new int[size];
    int arrStatic[] = {0,1,2,3,4,5,6,7,8};

    for(int i = 0 ; i < size ; i++){
        cout << "Enter Array element " << i <<": ";
        cin >> arr[i];
    }

    // Print array
    // for(int i = 0 ; i < size ; i++){
    //     cout << arr[i] << " ";
    // }

    int left = 0;
    int right = size;
    int target = 0;
    cout << "enter target to find : ";
    cin >> target;
    
    cout << " Binary search result : " << BinarySearch(arr, left , right-1 , target);
    cout << " element : " << arr[BinarySearch(arr, left , right-1 , target)];


    
    return 0;
}