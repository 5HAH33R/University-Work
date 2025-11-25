#include <iostream>
#include <vector>
using namespace std;


class ProductOfStream{
    private:
    vector<int> arr;

    public:
    ProductOfStream(){}

    void add(int x){
        arr.push_back(x);
    }

    void getProduct(int k){
        int prod = 1;
        if(k == arr.size()){
            cout << "0" << endl;
        }
        for(int i = (arr.size()- k) ; i < arr.size(); i++){
            prod = prod* arr[i];

        }
        cout << "product : " << prod << endl;
    }
};
int main(){

    ProductOfStream* pr = new ProductOfStream();
    pr->add(3);
    pr->add(0);
    pr->add(2);
    pr->add(5);
    pr->add(4);
    pr->getProduct(2);
    pr->getProduct(3);
    pr->getProduct(4);
    pr->add(8);
    pr->getProduct(2);


  return 0;
}