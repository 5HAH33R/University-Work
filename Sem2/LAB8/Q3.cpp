#include <iostream>
using namespace std;

class Account{
    protected:
    int Balance = 0;

    public:

    Account(int balance) : Balance(balance){}
    Account(){} // default constructor

    void Deposit(double value){
        Balance = Balance + value;
        cout << "Deposit Successful";

    }

    void Withdraw(double value){
        Balance = Balance - value;
        cout << "Withdraw Successful";

    }

    int CheckBalance(){
        return Balance;
    }
};

class InterestAccount : virtual public Account{
    protected:
    double Interest;

    public:
    InterestAccount(int balance , double interest) : Account(balance) , Interest(interest) {}
    InterestAccount(){}
    void Deposit(double value){
        Balance = Balance + (value + ((Interest * 0.01) *value));
        cout << "\nDeposit Successful\n";

    }
};

class ChargingAccount : virtual public Account{
    protected:
    int Fee = 25;

    
    public:
    void Withdraw(double value){
        Balance = Balance - value - Fee;
        cout << "\nWithdraw Successful\n";
    }
    ChargingAccount() {}
    ChargingAccount(int balance , int fee) :Account(balance),  Fee(fee){}
};

class ACI : virtual public ChargingAccount , virtual public InterestAccount { 
    public:
    void Transfer(double value , Account &AccName){
        AccName.Deposit(value);
    }

    void Transfer(double value , InterestAccount &AccName){
        AccName.Deposit(value);

    }

    void Transfer(double value , ChargingAccount &AccName){
        AccName.Deposit(value);
    }
};

int main(){
    Account A1(32000);
    InterestAccount I1(32000,30);
    ChargingAccount C1(32000,25);
    A1.Deposit(1000);
    I1.Deposit(1000);
    C1.Deposit(1000);
    cout << "\n";

    cout << "A1 : " << A1.CheckBalance() << endl;
    cout << "I1 : " << I1.CheckBalance() << endl;
    cout << "C1 : " << C1.CheckBalance() << endl;
    
    A1.Withdraw(1000);
    I1.Withdraw(1000);
    C1.Withdraw(1000);
    
    cout << "A1 : " << A1.CheckBalance() << endl;
    cout << "I1 : " << I1.CheckBalance() << endl;
    cout << "C1 : " << C1.CheckBalance() << endl;

    ACI aci;
    aci.Transfer(1000, A1);
    aci.Transfer(1000,I1);
    aci.Transfer(1000,C1);

    cout << "A1 : " << A1.CheckBalance() << endl;
    cout << "I1 : " << I1.CheckBalance() << endl;
    cout << "C1 : " << C1.CheckBalance() << endl;
    

  return 0;
}