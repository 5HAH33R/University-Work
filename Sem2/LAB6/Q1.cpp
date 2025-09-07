#include <iostream>
using namespace std;

#define Pi 22 / 7

class Shape
{
protected:
    int NumOfSides;
    float Area;

public:
    Shape(int Sides, float area) : NumOfSides(Sides), Area(area) {}

    int getNumOfSides()
    {
        return this->NumOfSides;
    }

    void setNumOfSides(int NumOfSides)
    {
        this->NumOfSides = NumOfSides;
    }

    float getArea()
    {
        return this->Area;
    }

    void setArea(float Area)
    {
        this->Area = Area;
    }
};

class Rectangle : public Shape
{
protected:
    int Length;
    int Width;

public:
    Rectangle(int length, int width) : Length(length), Width(width), Shape(4, 0) {}

    void GenerateArea()
    {
        Area = Length * Width;
        cout << "Area is " << Area;
    }
};

class Circle : public Shape
{
private:
    float Radius;

public:
    Circle(float radius) : Radius(radius), Shape(0, 0) {}

    void GenerateArea()
    {
        Area = (Pi) * (Radius * Radius);
        cout << "Area is " << Area;
    }
};

class Triangle : public Shape
{
private:
    int Base;
    int Height;

public:
    Triangle(int base, int height) : Base(base), Height(height), Shape(3, 0) {}

    void GenerateArea()
    {
        Area = (Height * Base) / 2;
        cout << "Area is " << Area;
    }
};

class Square : public Rectangle
{
private:
    int OneSide;

public:
    Square(int oneSide) : OneSide(oneSide), Rectangle(oneSide, oneSide) {}

    void CheckSides()
    {
        if (Length == Width)
        {
            cout << "Equal" << endl;
        }
        else
        {
            cout << "not Equal" << endl;
        }
    }
};

int main()
{
    return 0;
}