#include <bits/stdc++.h>
#include <windows.h>
using namespace std;


class MaxHeap{
    private:
    vector<int> heap;
    public:
    void heapifyUp(int val){ // insertion
        heap.push_back(val);
        int idx = heap.size()-1;
        while(idx > 0  && heap[(idx-1)/2] < heap[idx]){ // parent < child
            swap(heap[(idx-1)/2], heap[idx]);
            idx = (idx-1)/2;
        }
    }

    int heapifyDown() { 
        int idx = 0;
        int size = heap.size();

        if (size == 0) return 0;
        int deleted = heap[0];
        heap[0] = heap[size - 1];
        heap.pop_back();

        size = heap.size(); 

        while (true) {
            int LCidx = 2 * idx + 1;
            int RCidx = 2 * idx + 2;
            int largestidx = idx;

            if (LCidx < size && heap[LCidx] > heap[largestidx]) {
                largestidx = LCidx;
            }

            if (RCidx < size && heap[RCidx] > heap[largestidx]) {
                largestidx = RCidx;
            }

            if (largestidx != idx) {
                swap(heap[idx], heap[largestidx]);
                idx = largestidx;
            } else {
                break;
            }
        }
        return deleted;
    }
void heapsort(vector<int> &arr){
        for(int i = 0 ; i < arr.size() ; i++){
            heapifyUp(arr[i]);
        }
        
        int OGsize = arr.size();
        
        arr.clear(); 
        
        for(int i = 0 ; i < OGsize; i++){
            arr.push_back(heapifyDown()); 
        }
    }
};


int main(){
    MaxHeap obj;
    vector<int> arr = {2,6,7,3,5,1};
    obj.heapsort(arr);
    for(auto i : arr){
        cout << i << " ";
    }
  return 0;
}