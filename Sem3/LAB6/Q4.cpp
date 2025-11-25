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
void ReverseSubArr(vector<int>&arr ,int k){
    stack<int> s;
    for(int i = 0; i <= k;i++){
        s.push(arr.at(i));
    }
    int j = 0;
    while(!s.empty()){
        arr[j] = s.top();
        s.pop();
        j++;
    }

}

vector<int> pancakeflip(vector<int>&arr){
    vector<int> ans;
    for(int i = arr.size()-1; i > 0 ; i--){
        int largestIdx = i;
        int j = 0;
        while(j <= i){
            if(arr[j] > arr[largestIdx]){
                largestIdx = j;
            }   
            j++;
        }
        if(largestIdx != i){
            if(largestIdx == 0){
                ReverseSubArr(arr,i);
                ans.push_back(i+1);                
            }
            else{

                ReverseSubArr(arr,largestIdx);
                ans.push_back(largestIdx+1);
                ReverseSubArr(arr,i);
                ans.push_back(i+1);
            }
        }
    }
    return ans;
}
int main(){
    
    vector<int> arr;
    vector<int> sorted;
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(2);
    sorted = pancakeflip(arr);
    printArr(sorted);
    printArr(arr);
    

    // ReverseSubArr(arr,arr.size());
    // printArr(arr);
  return 0;
}
