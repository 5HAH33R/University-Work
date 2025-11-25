#include <bits/stdc++.h>

using namespace std;

double MinCostKWorker(vector<int>& quality, vector<int>& wage, int k) {
    vector<pair<double, int>> workers;
    int n = quality.size();

    for(int i = 0; i < n; i++){
        workers.push_back({(double)wage[i] / quality[i], quality[i]});
    } 
    
    sort(workers.begin(), workers.end());

    double ans = DBL_MAX;
    double qualsum = 0;
    
    priority_queue<int> maxheap;
    
    for(auto worker : workers){
        double ratio = worker.first;
        int current_quality = worker.second;
        
        qualsum += current_quality;
        maxheap.push(current_quality);
        
        if(maxheap.size() > k){
            qualsum -= maxheap.top();
            maxheap.pop();
        }
        
        if(maxheap.size() == k){
            ans = min(ans, qualsum * ratio);
        }
    }

    return ans;
}

int main() {
    vector<int> quality = {10, 20, 5};
    vector<int> wage = {70, 50, 30};
    int k = 2;
    
    cout << fixed << setprecision(5) << MinCostKWorker(quality, wage, k) << endl; 

    return 0;
}