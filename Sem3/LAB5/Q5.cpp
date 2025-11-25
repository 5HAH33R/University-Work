#include <iostream>
#include <vector>
using namespace std;


class DataStream{
    public:
    vector<int> arr;
    int k;
    int val;

    public:
    DataStream(int vv , int kk) : val(vv) , k(kk){}

    bool consec(int vv){
        arr.push_back(vv);
        bool flag = true;
        int prev = val;
        if(arr.size() < k){
            return false;
        }
        for(int i = (arr.size() - k) ; i < arr.size() ; i++){
            if(arr[i] != prev){
                flag = false;
                break;
            }
            prev = arr[i];

        }
        return flag;
    }
};
int main(){
    DataStream* d = new DataStream(4,3);
    cout << d->consec(4)<< endl;
    cout << d->consec(4) << endl;
    cout << d->consec(4) << endl;
    cout << d->consec(3) << endl;
  return 0;
}