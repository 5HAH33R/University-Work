#include <iostream>
#include <stack>
using namespace std;



int main(){
    string s;
    cout << "Enter a string" << endl;
    cin >> s;
    
    string rev;
    stack<char> st;
    for(auto x : s){
        st.push(x);
    }

    while(!st.empty()){
        rev.push_back(st.top());
        st.pop();
    }

    if(rev == s){
        cout << "palindrome";
    }
    else{
        cout << "Not a Palindrome";
    }



  return 0;
}