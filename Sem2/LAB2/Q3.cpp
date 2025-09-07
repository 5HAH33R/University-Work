#include <iostream>
#include <string.h>
using namespace std;


class Employee{
    private:
    char* FirstName;
    string LastName;
    int MonthlySalary;

    public:
    Employee(){
        FirstName = new char[100];
    }
    void SetFirstName(const char* FirstName){
        strcpy(this->FirstName, FirstName);
    }

    void SetLastName(string LastName){
        this->LastName = LastName;
    }

    void SetSalary(int MonthlySalary){
        if(MonthlySalary < 0){
            this->MonthlySalary = 0;
        }
        else{
            this->MonthlySalary = MonthlySalary;
        }
    }

    int GetSalary(){
        return MonthlySalary;
    }

    char* GetFirstName(){
        return FirstName;
    }

    string GetLastName(){
        return LastName;
    }

    void IncreaseSalary(float Percent){
        MonthlySalary += MonthlySalary * Percent/100;
    }


    ~Employee(){
        delete[] FirstName;
    }




};
int main(){

    Employee E1;
    E1.SetFirstName("Jotaro");
    E1.SetLastName("khan");
    E1.SetSalary(75000);
    cout <<"the monthly salary for " <<E1.GetFirstName() <<" is " << E1.GetSalary() << endl;
    E1.IncreaseSalary(10);
    cout <<"the monthly salary for " <<E1.GetFirstName() <<" after a 10 % raise is " << E1.GetSalary() << endl;

    Employee E2;
    E2.SetFirstName("Josuke");
    E2.SetLastName("khan");
    E2.SetSalary(66000);
    cout <<"the monthly salary for " <<E2.GetFirstName() <<" is " << E2.GetSalary() << endl;
    E2.IncreaseSalary(10);
    cout <<"the monthly salary for " <<E2.GetFirstName() <<" after a 10 % raise is " << E2.GetSalary() << endl;


  return 0;
}