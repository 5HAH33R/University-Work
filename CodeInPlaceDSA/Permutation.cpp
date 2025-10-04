#include <iostream>
#include<set>
using namespace std;


void permutation(string q , set<string> &s , int idx){
    if(idx == q.size()){
        s.insert(q);
        return;
    }

    for(int i = 0; i < q.size() ; i++){
        swap(q[idx] , q[i]);
        permutation(q,s,idx+1);
        swap(q[idx],q[i]);
    }


}

int main(){
    set<string> s;  
    string q;
    cin >> q;
    cout << endl;
    permutation(q,s,0);
    cout << s.size() << endl;
    for(auto i : s){
        cout << i << endl;
    }
    return 0;
}