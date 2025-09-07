#include <iostream>
using namespace std;

class employee{
    private:
    string Name;
    int ID;
    string Designation;
    int Salary;

    public:
    employee();
    employee(string name , int id , string designation , int salary) : Name(name) , ID(id) , Designation(designation) , Salary(salary){}

    void setSalary(int salary){
        Salary = salary;
    }

    int getSalary(){
        return Salary;
    }
    
};

class Payroll{
    public:
    void UpdateSalary(employee &empObj , int updated){  // reference from employee object is taken
        empObj.setSalary(updated);
    }

};

int main(){
    employee e1("Shaheer" ,  001 , "UI/UX Designer" , 25000);
    Payroll p1;

    cout << "before updating\n" << e1.getSalary();
    p1.UpdateSalary(e1, 85000);

    cout << "\nafter updateing\n" << e1.getSalary();
  return 0;
}