#include <iostream>
using namespace std;

class Student{
    private:
    string Name;
    int Roll_no;
    int Semester;
    char Section;

    public:
    Student(string Name, int Roll_no , int Semester , char Section){
        this->Name = Name;
        this->Roll_no= Roll_no;
        this->Semester= Semester;
        this->Section= Section;
    }

    char GetSection(){
        return Section;
    }

    string GetName(){
        return Name;
    }

};

int main(){
    Student S1("Name1" , 123 , 3 , 'A');
    Student S2("Name2" , 456 , 5 , 'B');
    Student S3("Name3" , 789 , 3 , 'A');
    Student S4("Name4" , 112 , 2 , 'C');

    Student Arr[4] = {S1,S2,S3,S4};

    for (int  i = 0; i < 4; i++)
    {
        if(Arr[i].GetSection() == 'A' ){
            cout << "Student : " << Arr[i].GetName() << " is from Section " << Arr[i].GetSection() << endl;
        }
        else{
            continue;
        }

    }
    

    return 0;
}