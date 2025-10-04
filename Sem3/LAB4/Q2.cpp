#include <iostream>
using namespace std;




int main(){
    string s = "ab#c";
    string t = "ad#c";
    cout << "String 1 : ";
    cin  >>s;
    cout << "String 2 : ";
    cin  >>t;
    int it = 0;
    for(auto i : s){
        if(i == '#'){
            if(it == 0 || s.size() == 1){
                s.erase(it,1);
            }
            else{

                s.erase(it-1,2);
            }
        }   
        it++;     
    }
    it = 0;
    for(auto i : t){
        if(i == '#'){
            if(it == 0 || t.size() == 1){
                t.erase(it,1);
            }
            else{

                t.erase(it-1,2);
            }
        }   
        it++;     
    }
    if(t == s){
        cout << "True";
    }
    else{
        cout << "False";
    }

    
  return 0;
}