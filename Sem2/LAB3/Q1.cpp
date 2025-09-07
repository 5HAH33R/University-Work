#include <iostream>
using namespace std;

class ComplexNum
{

public:
    int *px;
    int *py;
    ComplexNum(int x, int y)
    {
        px = new int;
        py = new int;
        *px = x;
        *py = y;
    }

    ComplexNum(ComplexNum &Type)
    {
        px = new int;
        py = new int;
        *px = *Type.px;
        *py = *Type.py;
    }

    void GetInfo()
    {
        cout << "X = " << *px << endl;
        cout << "Y = " << *py << endl;
    }
};

int main()
{
    ComplexNum C(6, 7);
    C.GetInfo();
    ComplexNum F(C);
    *(F.px) = 9;
    *(F.py) = 10;
    F.GetInfo();

    return 0;
}