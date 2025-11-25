#include <bits/stdc++.h>

using namespace std;

// Global multisets to simulate the two heaps
multiset<long long, greater<long long>> small_half;
multiset<long long> large_half;

void rebalance() {
    if (small_half.size() < large_half.size()) {
        small_half.insert(*large_half.begin());
        large_half.erase(large_half.begin());
    }
    if (small_half.size() > large_half.size() + 1) {
        large_half.insert(*small_half.begin());
        small_half.erase(small_half.begin());
    }
}

void insert(int num) {
    if (small_half.empty() || num <= *small_half.begin()) {
        small_half.insert(num);
    } else {
        large_half.insert(num);
    }
    rebalance();
}

void remove(int num) {
    auto it_s = small_half.find(num);
    if (it_s != small_half.end()) {
        small_half.erase(it_s);
    } else {
        large_half.erase(large_half.find(num));
    }
    rebalance();
}

double getMedian() {
    if (small_half.empty()) return 0.0;

    if (small_half.size() == large_half.size()) {
        return ((double)*small_half.begin() + *large_half.begin()) / 2.0;
    } else {
        return (double)*small_half.begin();
    }
}

vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    small_half.clear();
    large_half.clear();
    vector<double> result;
    int n = nums.size();

    for (int i = 0; i < k; ++i) {
        insert(nums[i]);
    }
    result.push_back(getMedian());

    for (int i = k; i < n; ++i) {
        insert(nums[i]);
        remove(nums[i - k]);
        result.push_back(getMedian());
    }

    return result;
}

int main() {
    vector<int> nums1 = {1, 3, -1, -3, 5, 3, 6, 7};
    int k1 = 3;
    vector<double> output1 = medianSlidingWindow(nums1, k1);
    
    cout << "Input: [1,3,-1,-3,5,3,6,7], k=3" << endl;
    cout << "Output: [";
    for (size_t i = 0; i < output1.size(); ++i) {
        cout << fixed << setprecision(5) << output1[i];
        if (i < output1.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}