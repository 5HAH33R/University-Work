#include <iostream>
#include <vector>
using namespace std;

class Client{
    protected:
        string Name;
        string Address;
        int ID;

        public:
        Client(string name, string address , int id) : Name(name) , Address(address) , ID(id){}

        string getName(){
            return Name;
        }
        string getAddress(){
            return Address;
        }
        int getID(){
            return ID;
        }
    
    
};

class Account{
    protected:
    vector<Client>* ManyClients;
    int Number = 0;
    float Balance = 0;
    void compose(){}

    public:
    Account(int Num, float Bal) : Number(Num) , Balance(Bal) {}
    void credit(float x){
        Balance -= x;
    }
    void debit(float x){
        Balance += x;
    }
    int getNumber(){
        return Number;
    }
    float getBalance(){
        return Balance;
    }



};


class AccountCollection{
    private:
    vector<Account>* AccArr;
    public:
    void add(){}
    void remove();
};

class ClientCollection{
    private:
    vector<Client>* ClientArr;
    public:
    void add(){}
    void remove(){}
};


class Bank{
    private:
    AccountCollection* Accounts;
    ClientCollection* Clients;
    public:
    void addAccount(){}
    void removeAccount(){}
    void addClient(){}
    void removeClient(){}
    void credit(){}
    void debit(){}
    
    
};

class Saving : public Account{
    public:
    void interest(){}
};

int main(){

  return 0;
};