#include <bits/stdc++.h>
#include <windows.h>
using namespace std;


void merge(int low , int high,int mid, vector<int>&arr){
    int left = low;
    int right = mid+1;
    vector<int> temp;
    while(left <=mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left <=mid){
        temp.push_back(arr[left]);
        left++;       
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;       
    }
    for(int i = 0 ; i <= temp.size() ; i++){
        arr[low+i] = temp[i];
    }

}


void PrintArr(vector<int> arr){
    for(auto i: arr){
        cout << i << " ";
    }
    cout<< endl;
}

void iterMergeSort(vector<int> &arr,int size){
    for(int curSize = 1 ; curSize <= size-1; curSize*=2){
        for(int left = 0 ; left < size; left += 2*curSize){ //left pointer that jumps to each subarrays start
            int mid = min(left+(curSize-1) , size-1); //also the Left end of the subarray
            int Rend = min(left+(2*curSize-1),size-1); // Right end
            if(mid < Rend){ //only call merge if a valid 2nd subarray exists
                merge(left,Rend,mid,arr);
            }
            
            
        }
    }


}

int main(){
    vector<int> arr = {1,8,9,4,6,3,7};
    int size = arr.size();
    iterMergeSort(arr,size);
    PrintArr(arr);

  return 0;
}