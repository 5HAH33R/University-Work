#include <iostream>
using namespace std;

// scenario : making a constant product price for items in a store

class Product{
    private:

    string name;
    const int price;

    public:
    Product(string Name, int Price) : name(Name) , price(Price){}

    void printData() const {
        cout << "Product Name: " << name << endl;
        cout << "Product Price: " << price << endl;
    }
};

int main(){
    Product P1("Milk",600);
    P1.printData();
  return 0;
}