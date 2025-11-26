#include<bits/stdc++.h>

using namespace std;

class MaxHeap{
    private:
    vector<int> heap;

    int parent(int idx){ return (idx-1)/2;}
    int left(int idx){ return (2*idx+1);}
    int right(int idx){ return (2*idx+2);}

    void heapifyUp(int idx){
        while(idx > 0 && heap[parent(idx)] < heap[idx]){
            swap(heap[parent(idx)],heap[idx]);
            idx = parent(idx);
        }

    }

    void heapifyDown(int idx){
        int size = heap.size();

        while(left(idx) < size){
            int largestidx = left(idx);
            if(right(idx) < size && heap[right(idx)] > heap[left(idx)]){
                largestidx = right(idx);
            }
            if(heap[idx] < heap[largestidx]){
                swap(heap[idx],heap[largestidx]);
                idx = largestidx;
            }
            else{
                break;
            }
        }
    }

    public:
    void insert(int val){
        heap.push_back(val);
        heapifyUp(heap.size()-1);
    }

    int Delete(){
        int deleted = heap[0];
        heap[0]= heap[heap.size()-1];
        heap.pop_back();
        heapifyDown(0);
        return deleted;

    }

};

int main(){
    vector<int> arr = {1,5,8,2,3,4,9,12,0};
    MaxHeap heap;
    for(int i = 0 ; i< arr.size(); i++){
        heap.insert(arr[i]);
    }
    vector<int> ans;
    for(int i = 0 ; i< arr.size(); i++){
        ans.push_back(heap.Delete());
    }
    reverse(ans.begin(),ans.end());
    for(auto i : ans){
        cout << i << " ";
    }
}