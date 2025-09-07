#include <iostream>
using namespace std;

const float Pi = 3.14;

float SArea(float r)
{
    return Pi * (r * r);
}

float Volume(float r, float h)
{
    return Pi * (r * r) * h;
}

int main()
{
    int radius = 0;
    int height = 0;
    cout << "What is the radius of the cirlce : ";
    cin >> radius;
    cout << "What is the height of the cirlce : ";
    cin >> height;

    cout << SArea(radius) << endl;
    cout << Volume(radius, height);

    return 0;
}