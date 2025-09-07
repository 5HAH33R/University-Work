#include <iostream>
using namespace std;

class Character
{
private:
    int *phealth;
    int *pAttackPower;
    int *pDefense;

public:
    Character(void)
    {
        phealth = new int;
        *phealth = 100;
        pAttackPower = new int;
        *pAttackPower = 10;
        pDefense = new int;
        *pDefense = 10;
    }
    Character(int health, int AttackPower, int Defense)
    {
        phealth = new int;
        *phealth = health;
        pAttackPower = new int;
        *pAttackPower = AttackPower;
        pDefense = new int;
        *pDefense = Defense;
    }
    Character(Character &Type)
    {
        phealth = new int;
        pAttackPower = new int;
        pDefense = new int;

        *phealth = *Type.phealth;
        *pAttackPower = *Type.pAttackPower;
        *pDefense = *Type.pDefense;
    }

    void setHealth(int health)
    {
        *phealth = health;
    }

    void setAttackPower(int AttackPower)
    {
        *pAttackPower = AttackPower;
    }

    void setDefense(int Defense)
    {
        *pDefense = Defense;
    }

    void GetInfo()
    {
        cout << "Health : " << *phealth << endl;
        cout << "Attack Power : " << *pAttackPower << endl;
        cout << "Defence : " << *pDefense << endl;
    }

    ~Character()
    {
        delete phealth, pAttackPower, pDefense;
    }
};
int main()
{
    Character C1(100, 50, 45);
    Character C2(C1);
    C1.setDefense(80);
    C1.GetInfo();
    cout << endl;
    C2.GetInfo();
    return 0;
}