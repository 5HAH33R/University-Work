#include <iostream>
using namespace std;

int Buy(int arr[] , int size , int amount){
    int total = 0;
    int j = 0;
    for(int i = 0; i < size-1 ; i++){
        total+= arr[i];
        j++;
        if(total > amount){
            break;
        }

    }
    return j;

}

int main(){
    int n = 7;
    int arr[] = {1,12,5,111,200,1000,10};
    int amount = 50;
    int ans = Buy(arr,n,amount);
    cout << ans;
  return 0;
}