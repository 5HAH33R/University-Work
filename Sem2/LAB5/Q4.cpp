#include <iostream>
using namespace std;


class Item{
    protected:
    string Name;
    int Quantity;

    public:
    Item(string name, int quantity) : Name(name), Quantity(quantity) {};
};

class BakedGoods : public Item{
    protected:
    float Discount = 0.1;

    public:
    BakedGoods(string name , int quantity) : Item(name,quantity){}
};

class Cakes : public BakedGoods{
    protected:
    float price = 600;

    public:
    Cakes(string name, int quantity) : BakedGoods(name,quantity){}

    float CalculateTotal(){
        return ((Quantity*price) - (Quantity*price*Discount));
    }
};

class Bread : public BakedGoods{
    protected:
    float price = 200;

    public:
    Bread(string name, int quantity) : BakedGoods(name,quantity){}

    float CalculateTotal(){
        return ((Quantity*price) - (Quantity*price*Discount));
    }
};

class Drinks : public Item{
    protected:
    float price = 100;
    float discount = 0.05;

    public:
    Drinks(string name, int quantity) : Item(name,quantity){}

    float CalculateTotal(){
        return ((Quantity*price) - (Quantity*price*discount));
    }
};



int main(){
    float total;
    Cakes C1("Brownie",3);
    Bread B1("Brown Bread", 2);
    Drinks D1("7UP" , 5);
    total = C1.CalculateTotal() + B1.CalculateTotal() + D1.CalculateTotal();
    cout << total;
  return 0;
}