#include <iostream>
#include <vector>
using namespace std;

class Person{
    public:
    string Name;
    string PhoneNum;
    string Email;

    void PurchaseParkingPass();
};


class Address{
    public:
    Person* person[1];
    string Street;
    string City;
    string State;
    string PostalCode;
    string Country;

    private:
    bool Validate(){}

    public:
    string OutputAsLabel(){}
};


class Professor : public Person{
    private:
    vector<Student> students;
    int Salary;
    int YearsOfService;
    

    protected:
    int StaffNumber;

    public:
    int NoOfClasses;

};

class Student :public Person{
    public:
    Professor* professors[5];
    int StudentMark;
    int AvgMark;

    bool IsEligibleToEnroll(string Value){}
    int GetSeminarsTaken(){}
};


int main(){
  return 0;
}