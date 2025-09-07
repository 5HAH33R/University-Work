#include <iostream>
#include <string.h>
using namespace std;

class Teacher
{
protected:
    string name;
    int age;
    string institute;

public:
    Teacher(string Name, int Age, string Institute) : name(Name), age(Age), institute(Institute) {}

    string getName()
    {
        return this->name;
    }

    void setName(string name)
    {
        this->name = name;
    }

    int getAge()
    {
        return this->age;
    }

    void setAge(int age)
    {
        this->age = age;
    }

    string getInstitute()
    {
        return this->institute;
    }

    void setInstitute(string institute)
    {
        this->institute = institute;
    }
};

class HumanitiesTeacher : public Teacher
{
private:
    string Department;
    string CourseName;
    string Designation;

public:
    HumanitiesTeacher(string name, int age, string institute, string Dept, string courseName, string designation) : Department(Dept), CourseName(courseName), Designation(designation), Teacher(name, age, institute) {}

    string getDepartment()
    {
        return this->Department;
    }

    void setDepartment(string Department)
    {
        this->Department = Department;
    }

    string getCourseName()
    {
        return this->CourseName;
    }

    void setCourseName(string CourseName)
    {
        this->CourseName = CourseName;
    }

    string getDesignation()
    {
        return this->Designation;
    }

    void setDesignation(string Designation)
    {
        this->Designation = Designation;
    }
};

class ScienceTeacher : public Teacher
{
private:
    string Department;
    string CourseName;
    string Designation;

public:
    ScienceTeacher(string name, int age, string institute, string Dept, string courseName, string designation) : Department(Dept), CourseName(courseName), Designation(designation), Teacher(name, age, institute) {}
    string getDepartment()
    {
        return this->Department;
    }

    void setDepartment(string Department)
    {
        this->Department = Department;
    }

    string getCourseName()
    {
        return this->CourseName;
    }

    void setCourseName(string CourseName)
    {
        this->CourseName = CourseName;
    }

    string getDesignation()
    {
        return this->Designation;
    }

    void setDesignation(string Designation)
    {
        this->Designation = Designation;
    }
};

class MathsTeacher : public Teacher
{
private:
    string Department;
    string CourseName;
    string Designation;

public:
    MathsTeacher(string name, int age, string institute, string Dept, string courseName, string designation) : Teacher(name, age, institute), Department(Dept), CourseName(courseName), Designation(designation) {}

    string getDepartment()
    {
        return this->Department;
    }

    void setDepartment(string Department)
    {
        this->Department = Department;
    }

    string getCourseName()
    {
        return this->CourseName;
    }

    void setCourseName(string CourseName)
    {
        this->CourseName = CourseName;
    }

    string getDesignation()
    {
        return this->Designation;
    }

    void setDesignation(string Designation)
    {
        this->Designation = Designation;
    }
};

int main()
{

    string TempName;
    int TempAge;
    string stringAge;
    string TempInstitute;
    string TempCourseName;
    string TempDesignation;

    cout << "Name of Science Teacher: " << endl;
    getline(cin,TempName); // to handle spaces while inserting strings , cin counts space as a delimiter
    cout << "Age of Science Teacher: " << endl;
    getline(cin,stringAge);
    TempAge = stoi(stringAge); // converting string age to int age
    cout << "Institute of Science Teacher: " << endl;
    getline(cin,TempInstitute);
    cout << "Course Name of Science Teacher: " << endl;
    getline(cin,TempCourseName);
    cout << "Designation of Science Teacher: " << endl;
    getline(cin,TempDesignation);
    ScienceTeacher S1(TempName, TempAge, TempInstitute, "Science", TempCourseName, TempDesignation);
    cout << "\n\n";

    cout << "Name of Humanities Teacher: " << endl;
    getline(cin,TempName);
    cout << "Age of Humanities Teacher: " << endl;
    getline(cin,stringAge);
    TempAge = stoi(stringAge);
    cout << "Institute of Humanities Teacher: " << endl;
    getline(cin,TempInstitute);
    cout << "Course Name of Humanities Teacher: " << endl;
    getline(cin,TempCourseName);
    cout << "Designation of Humanities Teacher: " << endl;
    getline(cin,TempDesignation);
    HumanitiesTeacher H1(TempName, TempAge, TempInstitute, "Humanities", TempCourseName, TempDesignation);
    cout << "\n\n";

    cout << "Name of Maths Teacher: " << endl;
    getline(cin,TempName);
    cout << "Age of Maths Teacher: " << endl;
    getline(cin,stringAge);
    TempAge = stoi(stringAge);
    cout << "Institute of Maths Teacher: " << endl;
    getline(cin,TempInstitute);
    cout << "Course Name of Maths Teacher: " << endl;
    getline(cin,TempCourseName);
    cout << "Designation of Maths Teacher: " << endl;
    getline(cin,TempDesignation);
    MathsTeacher M1(TempName, TempAge, TempInstitute, "Maths", TempCourseName, TempDesignation);
    cout << "\n\n";

    cout << H1.getName() << " " << H1.getAge() << " " << H1.getCourseName() << endl;
    cout << S1.getName() << " " << S1.getAge() << " " << S1.getCourseName() << endl;
    cout << M1.getName() << " " << M1.getAge() << " " << M1.getCourseName() << endl;



    return 0;
}