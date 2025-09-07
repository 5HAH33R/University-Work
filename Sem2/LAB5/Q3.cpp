#include <iostream>
using namespace std;


class Weapons{
    public:
    void WeaponsDescription(){
        cout << "Weapons are used to fight Wars\n";
    }
};

class HotWeapons : public Weapons{
    public:
    void HotWeaponsDescription(){
        cout << "Hot Weapons use gunpowder and explode\n";
    }


};

class Bombs : public HotWeapons{
    public:
    void BombsDescription(){
        cout << "Bombs cause explosions in a certain radius\n";

    }
};

class NuclearBombs : public Bombs{
    public:
    void NuclearBombsDescription(){
        cout << "nuclear Bombs cause massive explosions that can wipe out countries , use nuclear fusion\n";
    }
};

int main(){
    NuclearBombs N1;
    N1.WeaponsDescription();
    N1.HotWeaponsDescription();
    N1.BombsDescription();
    N1.NuclearBombsDescription();
  return 0;
}