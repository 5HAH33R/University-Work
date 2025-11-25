#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int,int> freq;
    for(auto i : nums){
        freq[i]++;
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minheap;

    for(auto const& pair : freq){
        int num = pair.first;
        int count = pair.second;
        
        minheap.push({count, num});
        if(minheap.size() > k){
            minheap.pop();
        }
    }

    vector<int> result;
    while(!minheap.empty()){
        result.push_back(minheap.top().second);
        minheap.pop();
    }
    return result;
}

int main(){
    vector<int> nums = {1, 1, 1, 2, 2, 3, 4, 4, 4, 4};
    int k = 2;

    vector<int> Result = topKFrequent(nums, k);

    for(int element : Result){
        cout << element << " ";
    }
    cout << endl;

    return 0;
}