#include <bits/stdc++.h>

using namespace std;

string frequencySort(string s) {
    map<char,int> freq;

    for(char i : s){
        freq[i]++;
    }        

    priority_queue<pair<int,char>> maxheap;

    for(auto const& mapentry : freq){
        maxheap.push({mapentry.second, mapentry.first});
    }

    string result;
    pair<int,char> p;
    while(!maxheap.empty()){
        p = maxheap.top();
        for(int i= 0 ;i < p.first; i++){
            result.push_back(p.second);
        }
        maxheap.pop();
    }
    return result;
}

int main() {

    string teststr = "tree";
    string res = frequencySort(teststr);
    
    cout << "Original String: " << teststr << endl;
    cout << "Sorted by Frequency: " << res << endl; 
    
    return 0;
}