#include <iostream>
#include <set>
#include <vector>

using namespace std;

void printArr(vector<int> &arr){
    for(auto i : arr){
        cout << i << " ";
    }
    cout << endl;



}
int main(){
    set<vector<int>> ans;
    ans.insert({1,2,2});
    ans.insert({2,1,2});
    for(auto i : ans){
        printArr(i);
    }

  return 0;
}