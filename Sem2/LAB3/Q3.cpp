#include <iostream>
using namespace std;

class tollbooth
{
private:
    int carCount;
    double totalMoney;

public:
    tollbooth(void)
    {
        carCount = 0;
        totalMoney = 0;
    }

    void PayingCar()
    {
        carCount++;
        totalMoney = totalMoney + 0.50;
    }

    void PrintInfo()
    {
        cout << "Cars : " << carCount << endl;
        cout << "Money : " << totalMoney << endl;
    }
};
int main()
{
    tollbooth t1;
    int i = 0;
    while (i < 50)
    {
        t1.PayingCar();
        i++;
    }

    t1.PrintInfo();

    return 0;
}