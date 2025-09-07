#include <iostream>
#include <string>

using namespace std;

class Character {
protected:
    string name;
    int level;
    int health;

public:
    Character(string name, int level, int health) : name(name), level(level), health(health) {}

};

class Warrior : virtual public Character {
private:
    int strength;
    string meleeWeaponProficiency;

public:
    Warrior(string name, int level, int health, int strength, string meleeWeaponProficiency) : Character(name, level, health), strength(strength), meleeWeaponProficiency(meleeWeaponProficiency) {}

    void slash(){
        cout <<"perform a powerful slash" << endl;
    }

};

class Mage : virtual public Character {
private:
    int intelligence;
    string spellCastingProficiency;

public:
    Mage(string name, int level, int health, int intelligence, string spellCastingProficiency) : Character(name, level, health), intelligence(intelligence), spellCastingProficiency(spellCastingProficiency) {}

    void fireball(){
        cout << name << " cast a  fireball" << endl;
    }
};

class Archer : public Character {
private:
    int dexterity;
    string rangedWeaponProficiency;

public:
    Archer(string name, int level, int health, int dexterity, string rangedWeaponProficiency) : Character(name, level, health), dexterity(dexterity), rangedWeaponProficiency(rangedWeaponProficiency) {}

    void rapidShot(){
        cout <<" fires rapid arrows" << endl;
    }

};

class NPC : public Character {
private:
    string movementPattern;
    string scriptedDialogue;

public:
    NPC(string name, int level, int health, string movementPattern, string scriptedDialogue) : Character(name, level, health), movementPattern(movementPattern), scriptedDialogue(scriptedDialogue) {}


    void speak(){
        cout << scriptedDialogue << endl;
    }
};

class Mighty : virtual public Warrior, virtual  public Mage {
public:
    Mighty(string name, int level, int health, int strength, string meleeWeaponProficiency, int intelligence, string spellCastingProficiency) : Character(name, level, health), Warrior(name, level, health, strength, meleeWeaponProficiency), Mage(name, level, health, intelligence, spellCastingProficiency) {}
};

int main() {

    
    return 0;
}
