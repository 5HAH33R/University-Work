#include <iostream>
using namespace std;


class HotelCustomer{
    private:
    string CustomerName;
    int DaysSpent;
    const float PerDayPrice = 1000.85;
    float rent;

    public:
    HotelCustomer(string Name, int Days) : CustomerName(Name) , DaysSpent(Days) {};

    void CalculateRent(){
        if(DaysSpent > 0){
            rent = DaysSpent*PerDayPrice;
        }
        else{
            cout << "Please Input the correct number of days";
        }
    }
    
    void ApplyDiscount(){
         
        if(DaysSpent>=0 && DaysSpent<=7){
            cout << "No Discount\n";
        }
        else if(DaysSpent > 7){
            cout << "you got a discount for 1000.85\n";
            rent = (DaysSpent-1)*PerDayPrice;
        }
    }

    void PrintData(){
        if(DaysSpent<0){
            cout << "Wrong data Entered";
        }
        else{
            cout << "Customer Name: " << CustomerName << endl;
            cout << "Days: " << DaysSpent << endl;
            cout << "Rent: " << rent << "\n\n";
        }


    }

};
int main(){
    HotelCustomer H1("harry" , 6);
    H1.CalculateRent();
    H1.ApplyDiscount();
    H1.PrintData();

    HotelCustomer H2("James", 10);
    H2.CalculateRent();
    H2.ApplyDiscount();
    H2.PrintData();


    return 0;
}