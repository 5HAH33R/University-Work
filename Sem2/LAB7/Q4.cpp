#include <string>
#include <iostream>
using namespace std;

class employee;

class Payroll {
public:
    void UpdateSalary(employee& emp, int updated);  // Defined in employee class
};

class employee {
private:
    string Name;
    int ID;
    string Designation;
    int Salary;

public:
    employee(){}
    employee(string name, int id, string designation, int salary) : Name(name), ID(id), Designation(designation), Salary(salary) {}

    friend void Payroll::UpdateSalary(employee& emp, int updated); // so we can access Salary while implementing

    int getSalary(){
        return Salary;
    }
};

void Payroll::UpdateSalary(employee& emp, int updated) {
    emp.Salary = updated;
}

int main() {
    employee emp1("Shaheer", 001, "UI/UX Designer", 30000);
    Payroll payroll;

    cout << "Before update:" << emp1.getSalary() << endl;
    
    payroll.UpdateSalary(emp1, 85000);
    
    cout << "After update:" << emp1.getSalary() << endl;

    emp1.getSalary();

    return 0;
}