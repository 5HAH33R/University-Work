#include <iostream>
#include <cstdlib>
#include <random>
#include <time.h>
using namespace std;

class Game
{
private:
    double Players = 0;
    int Player_HitCounter = 0;
    int Enemy_HitCounter = 0;

public:
    void GenerateTeam()
    {
        if (rand() % 10 != 0)
        {
            Players = rand() % 10;
        }
        else
        {
            Players = rand() % 100;
        }
    }

    double Getplayers()
    {
        return Players;
    }

    int RandNum()
    {
        return rand() % 10;
    }

    string SuccessMessage()
    {
        return "You hit the enemy team";
    }

    string FailureMessage()
    {
        return "You got hit by the enemy";
    }

    void PlayerHit()
    {
        Player_HitCounter++;
    }
    void EnemyHit()
    {
        Enemy_HitCounter++;
    }

    void CheckWinner()
    {
        if (Enemy_HitCounter < Player_HitCounter)
        {
            cout << "Enemy Wins";
        }
        else
        {
            cout << "Player Wins";
        }
    }
};

int main()
{
    srand(time(0));

    Game Game;

    Game.GenerateTeam();
    int Players = Game.Getplayers();
    int i = 0;
    cout << "total number of players in your team are " << Players << endl;
    int Num1 = 0, Num2 = 0;
    while (i < Players)
    {
        cout << " \n Pair of numbers generated is " << endl;
        Num1 = Game.RandNum();
        cout << "Number 1 : " << Num1 << endl;
        Num2 = Game.RandNum();
        cout << "Number 2 : " << Num2 << endl;

        if (Num1 == Num2)
        {
            cout << Game.SuccessMessage() << endl;
            Game.EnemyHit();
        }
        else
        {
            cout << Game.FailureMessage() << endl;
            Game.PlayerHit();
        }
        i++;
    }
    cout << endl;
    Game.CheckWinner();

    return 0;
}
