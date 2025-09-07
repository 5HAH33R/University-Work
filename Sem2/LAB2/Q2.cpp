#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

class Bank
{
private:
    float Balance;
    int Transactions;
    float interest;

public:
    Bank(float Balance, int Transactions)
    {
        this->Balance = Balance;
        this->Transactions = Transactions;
    }

    void Deposit(double Num)
    {
        Balance = Balance + Num;
        Transactions++;
    }

    void Withdraw(double Num)
    {
        Balance = Balance - Num;
        Transactions++;
    }

    double GetBalance()
    {
        return Balance;
    }

    int GetTransactions()
    {
        return Transactions;
    }
};

int main()
{
    int NumChosen;
    int Deposit;
    int Withdraw;
    int interestRate = 0 , yrs = 0;
    Bank MyBank(0, 0);
    while (NumChosen != 6)
    {
        cout << "\nPlease Choose a Number :- \n 1. Display the account balance \n 2. Display the number of transactions \n 3. Display interest earned for this period \n 4. Make a deposit \n 5. Make a withdrawal \n 6. Exit the program" << endl;

        cin >> NumChosen;

        switch (NumChosen)
        {
        case 1:
            cout << "Account Balance is ";
            cout << MyBank.GetBalance() << endl;
            break;
        case 2:
            cout << "No of Transactions is : ";
            cout << MyBank.GetTransactions() << endl;
        case 3:
            cout << "enter your interest rate (in %) : ";
            cin >> interestRate;
            cout << "enter the time (in yrs) : ";
            cin >> yrs;
            cout << MyBank.GetBalance()*(interestRate*0.01)*yrs;
            break;
        case 4:
            cout << "enter the amount : ";
            cin >> Deposit;
            MyBank.Deposit(Deposit);
            break;
        case 5:
            cout << "enter the amount : ";
            cin >> Withdraw;
            MyBank.Withdraw(Withdraw);
            break;
        case 6:
            cout << "exited successfully";
        default:
            break;
        };
    };
    return 0;
}
