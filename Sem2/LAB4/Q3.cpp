#include <iostream>
using namespace std;


class Account{
    private:
    int account_no;
    int account_bal;
    int security_code;
    static int NumOfObjects;

    public:

    Account(){
        NumOfObjects++;
    }

    void Initialise(int AccountNum , int AccountBal , int SecurityCode){
        account_no = AccountNum;
        account_bal = AccountBal;
        security_code = SecurityCode;
    }

    void printData(){
        cout << "----------------"<< endl;
        cout << "Account No: " << account_no << endl;
        cout << "Account Balance: " << account_bal << endl;
        cout << "Security Code: " << security_code << endl;
        cout << "----------------"<< endl;
    }

    static void printNoOfObjects(){
        cout << "No of objects = " << NumOfObjects << endl;
    }

};

int Account::NumOfObjects = 0;
int main(){
    Account A1;
    A1.Initialise(1234,5000,6689);
    A1.printData();
    Account A2;
    A2.Initialise(1235,30000,5423);
    A2.printData();
    Account A3;
    A3.Initialise(1236,20000,5987);
    A3.printData();
    Account::printNoOfObjects();

  return 0;
}