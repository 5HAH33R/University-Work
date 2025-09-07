#include <iostream>
#include<vector>
using namespace std;


class Vehicle{
    protected:
    int CarID;
    string Brand;
    int Model;
    bool Available = true;

    Vehicle(int carid , string brand , int model) : CarID(carid) , Brand(brand) , Model(model){}

    public:
    Vehicle(){}
    virtual bool IsAvailable() = 0;
    virtual void rent(string RorR) = 0;  // RorR = Rent Or Returned
};

class Car : public Vehicle{

    public:
    Car(){}
    Car(int carid , string brand , int model) : Vehicle(carid , brand , model){}

    bool IsAvailable() override {
        if(Available == true){
            cout << "Yes , Available";
            return true;
        }
        else{
            cout << "No , Rented Already";
            return false;
        }
    }

    void rent(string RorR) override {
        if(RorR == "Rent" || RorR  == "rent"){
            Available = false;
            cout << "\nRented";
        }
        else if(RorR == "Return" || RorR  == "return"){
            Available = true;
            cout << "\nReturned" << endl;
        }
        else{
            cout << "wrong Rent Function parameter , only (rent) or (return) allowed" << endl;
        }
    }

};

class RentalSystem{
    public:
    void rentVehicle(Vehicle &obj){
        if(obj.IsAvailable()){
            obj.rent("rent");  
        }
        
    }
    void ReturnVehicle(Vehicle &obj){
        obj.rent("return");

    }


};

class Customer{
    private:
    RentalSystem &R;
    public:

    Customer(RentalSystem &r) : R(r) {}


    void rentVehicle(Vehicle &obj){
        R.rentVehicle(obj);
    }

    void ReturnVechicle(Vehicle &obj){
        R.ReturnVehicle(obj);
    }

};


int main(){
    RentalSystem Rsys;
    Customer cust(Rsys);


    Vehicle* vehicle = new Car[2];

    vehicle[0] = Car(101, "brandName" , 2014);
    vehicle[1] = Car(102 , "brandName2" , 2021);

    vehicle[0].IsAvailable();
    vehicle[0].rent("rent");
    vehicle[0].rent("return");





    


  return 0;
}