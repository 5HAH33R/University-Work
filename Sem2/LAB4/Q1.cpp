#include <iostream>
using namespace std;

class Employee{
  private:
  const char* EmployeeName;
  const int EmployeeID;

  public:
  Employee(const char* Name , int Id ) : EmployeeID(Id) , EmployeeName(Name) {} // const char* imitates a string

  void getName(){
    int i = 0;
    while (EmployeeName[i] != '\0'){  // accessing the string using arrays
      cout << EmployeeName[i];
      i++;
    }
  }

  int getID(){
    cout << EmployeeID;
  }

  void setName(const char* Name){ // changing the pointer to point to the new name
    EmployeeName = Name;
  }

};


int main(){
  Employee Emp1("Jack",12);
  Emp1.getName();
  cout << " ";
  Emp1.getID();
  Emp1.setName("Jackson");
  cout << endl;
  Emp1.getName();
  cout << " ";
  Emp1.getID();

  return 0;
}