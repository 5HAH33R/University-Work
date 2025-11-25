#include <bits/stdc++.h>
#include <windows.h>
using namespace std;


int partition(int l, int r, vector<int> &arr){
    int i = l;
    int j = r;
    int pivot = arr[i];
    while(i<j){
        while(arr[i] <= pivot && i <= r){
            i++;
        }
        while(arr[j] > pivot && j >= l){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[l],arr[j]);
    return j;
}

void PrintArr(vector<int> arr){
    for(auto i: arr){
        cout << i << " ";
    }
    cout<< endl;
}
int main(){
    vector<int> arr = {3,4,5,2,9,8,1,7,6};
    int l = 0;
    int r = arr.size() - 1;
    
    stack<pair<int, int>> st;
    st.push({l, r});

    while (!st.empty()) {
        pair<int, int> current = st.top();
        st.pop();

        int curL = current.first;
        int curR = current.second;

        int pivotPos = partition(curL, curR, arr);

        if (curL < pivotPos - 1) {
            st.push({curL, pivotPos - 1});
        }

        if (pivotPos + 1 < curR) {
            st.push({pivotPos + 1, curR});
        }
    }

    PrintArr(arr);



  return 0;
}