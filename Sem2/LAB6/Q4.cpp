#include <iostream>
using namespace std;

class Person
{
protected:
    string Name;
    string Occupation;

public:
    Person() {}
    Person(string occupation) : Occupation(occupation) {}

    virtual void Draw()
    {
        cout << "A person can draw in many ways";
    }
};

class Artist : public Person
{
public:
    Artist() : Person("Artist") {}

    void Draw()
    {
        cout << "An artist can draw with a paint brush";
    }
};

class Gunman : public Person
{
public:
    Gunman() : Person("Gunman") {}

    void Draw()
    {
        cout << "A gunman draws a gun to shoot";
    }
};

int main()
{
    Person* P[10];
    P[0] = new Person();
    P[1] = new Artist();
    P[2] = new Gunman();

    P[0]->Draw();
    cout << endl;
    P[1]->Draw();
    cout << endl;
    P[2]->Draw();

    return 0;
}