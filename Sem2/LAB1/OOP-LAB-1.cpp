#include <iostream>
#include <math.h>
using namespace std;

// Q1 Write a program that take input of your roll number along with the marks obtained in five subjects and display the total marks obtained and the percentage.
void Q1()
{
    int Marks = 0;
    int totalMarks = 0;
    float perc = 0.0;
    string RollNo;
    cout << "what is your roll number : ";
    cin >> RollNo;
    for (int i = 0; i < 5; i++)
    {
        cout << "Marks for " << i + 1 << " subject: ";
        cin >> Marks;
        totalMarks = totalMarks + Marks;
    }
    cout << "total marks : " << totalMarks << endl;
    perc = ((float)totalMarks / 500) * 100;
    cout << "percentage : " << perc;
}

void Q2()
{
    
}

void Q3()
{
    float tempinC;
    float tempinF;
    cout << "enter temp in F : ";
    cin >> tempinF;
    tempinC = (tempinF - 32) / 1.8;
    cout << "Temp in C is : " << tempinC;
}

void Q4Surface_Area(float r){


}
int main()
{
    Q3();
}