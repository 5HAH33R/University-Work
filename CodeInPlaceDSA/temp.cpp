#include<iostream>
#include<set>
#include<vector>
#include<stack>
#include<sstream>

using namespace std;

bool isPrime(int n){
    int div = 0;
    if(n <= 1){
        return false;
    }
    for(int i = 0 ; i < n ; i++){
        if(n % i == 0 ){
            div++;
        }
        if(div > 2){
            return false;
        }
    }
    return true;
}

int nextPrime(int n){
    int ans = n+1;
    while(isPrime(ans) != true){
        ans = ans +1;
    }
    return ans;
    
}

vector<int> waiter(vector<int> numbers , int q){
    int count = 1;
    int prime = 2;
    vector<int> answer;
    vector<int> A;
    vector<int> B;

    while(count != q){
        if(count == 1){
            for(auto i : numbers){
                if(prime % i == 0){
                    B.push_back(i);
                }
                else{
                    A.push_back(i);
                }

            }
        }
        else{
            for(auto i : A){
                if(prime % i == 0){
                    B.push_back(i);
                    A.pop_back();
                }

            }
        
        }
        count++;
        for(auto i : B){
            answer.push_back(i);
            B.pop_back();
        }
    }
    for(auto i : A){
        answer.push_back(i);
    }
    return answer;
}


int main(){
    string line;
    int n = 0 , q = 0;
    int num;
    vector<int> numbers;
    getline(cin, line);
    stringstream ss1(line);
    ss1 >> n >> q;
    getline(cin , line);
    stringstream ss(line);
    while(ss >> num){
        numbers.push_back(num);
    }

    vector<int> answer = waiter(numbers,q);
    for(auto i : answer){
        cout << i <<" ";
    }

}