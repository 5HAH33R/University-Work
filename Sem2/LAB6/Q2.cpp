#include <iostream>
using namespace std;

class Calculator
{
private:
    int Num1;
    int Num2;
    int Num3;

public:
    Calculator()
    {
        cout << "Enter Value for num 1: " << endl;
        cin >> Num1;
        cout << "Enter Value for num 2: " << endl;
        cin >> Num2;
        cout << "Enter Value for num 3: " << endl;
        cin >> Num3;
        cout << endl;
    }

    void Add(int a, int b)
    {
        if (a > 3 || b > 3 || a < 0 || b < 0)
        {
            cout << "wrong inputs";
        }
        else
        {
            if (a == 1 && b == 2)
            {
                cout << Num1 + Num2 << endl;
            }
            else if (a == 2 && b == 3)
            {
                cout << Num2 + Num3 << endl;
            }
            else
            {
                cout << Num1 + Num3;
            }
        }
    }

    void Add(int a, int b, int c)
    {
        if (a > 3 || b > 3 || a < 0 || b < 0 || c > 3 || c < 0)
        {
            cout << "wrong inputs";
        }
        else
        {
            cout << Num1 + Num2 + Num3 << endl;
        }
    }

    void Sub(int a, int b)
    {
        if (a > 3 || b > 3 || a < 0 || b < 0)
        {
            cout << "wrong inputs";
        }
        else
        {
            if (a == 1 && b == 2)
            {
                cout << Num1 - Num2 << endl;
            }
            else if (a == 2 && b == 3)
            {
                cout << Num2 - Num3 << endl;
            }
            else
            {
                cout << Num1 - Num3 << endl;
            }
        }
    }

    void Sub(int a, int b, int c)
    {
        if (a > 3 || b > 3 || a < 0 || b < 0 || c > 3 || c < 0)
        {
            cout << "wrong inputs";
        }
        else
        {
            cout << Num1 - Num2 - Num3 << endl;
        }
    }

    void Mul(int a, int b)
    {
        if (a > 3 || b > 3 || a < 0 || b < 0)
        {
            cout << "wrong inputs";
        }
        else
        {
            if (a == 1 && b == 2)
            {
                cout << Num1 * Num2 << endl;
            }
            else if (a == 2 && b == 3)
            {
                cout << Num2 * Num3 << endl;
            }
            else
            {
                cout << Num1 * Num3 << endl;
            }
        }
    }

    void Mul(int a, int b, int c)
    {
        if (a > 3 || b > 3 || a < 0 || b < 0 || c > 3 || c < 0)
        {
            cout << "wrong inputs";
        }
        else
        {
            cout << Num1 * Num2 * Num3 << endl;
        }
    }

    void Div(int a, int b)
    {
        if (a > 3 || b > 3 || a < 0 || b < 0)
        {
            cout << "wrong inputs";
        }
        else
        {
            if (a == 1 && b == 2)
            {
                cout << float(Num1) / float(Num2) << endl;
            }
            else if (a == 2 && b == 3)
            {
                cout << float(Num2) / float(Num3) << endl;
            }
            else
            {
                cout << float(Num1) / float(Num3) << endl;
            }
        }
    }

    void Div(int a, int b, int c)
    {
        if (a > 3 || b > 3 || a < 0 || b < 0 || c > 3 || c < 0)
        {
            cout << "wrong inputs";
        }
        else
        {
            cout << float(Num1 / Num2 / Num3) << endl;
        }
    }
};
int main()
{
    Calculator C1;
    C1.Add(1,2);
    C1.Mul(1,2,3);
    C1.Sub(2,3);
    C1.Div(1,2);
    C1.Add(5,6);
    return 0;
}