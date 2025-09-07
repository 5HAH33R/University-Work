/*
    BCIT
    Muhammad Shaheer CT-182

*/

#include <iostream>
using namespace std;


class Transaction
{
private:
    string ProdId;
    string SalesPersonId;
    int ProdPrice;
    int RevenuePerTransaction;
    static int TotalRevenue;
    static int transaction_no;

public:
    Transaction()
    {
        ProdId = "";
        SalesPersonId = "";
        ProdPrice=0;
        RevenuePerTransaction = 0;
    }

    Transaction(string pid, string spid, int pp, int rpt)
    {
        ProdId = pid;
        SalesPersonId = spid;
        ProdPrice = pp;
        RevenuePerTransaction = rpt;
    }

    void PrintInfo() const
    {
        cout << "transaction_no" << transaction_no << endl;
        cout << "SalesPerson_id: " << SalesPersonId << endl;
        cout << "Product_id: " << ProdId << endl;
        cout << "Cost: " << ProdPrice << endl;
        cout << "Revenue Per transaction =  " << RevenuePerTransaction << "rs" << endl;
        cout << "\n\n";
    }

    void AddtoTotal()
    {
        TotalRevenue += RevenuePerTransaction;
    }

    static auto GetTotalRev()
    {
        return TotalRevenue;
    }

    static auto IncTransaction()
    {
        transaction_no++;
    }
};

int Transaction::TotalRevenue = 0;
int Transaction::transaction_no = 0;

int main()
{
    Transaction arr[10];
    arr[0] = Transaction("Dairy01", "Babar01", 1500, 200);
    arr[1] = Transaction("Dairy01", "Asim01", 2000, 300);
    arr[2] = Transaction("Dairy01", "Ali01", 3000, 120);
    arr[3] = Transaction("Dairy01", "Huzaifa01", 4500, 100);
    arr[4] = Transaction("CarPart01", "Asim01", 600, 500);
    arr[5] = Transaction("Canned01", "Ali01", 800, 230);
    arr[6] = Transaction("Electronic01", "Babar01", 350, 135);
    arr[7] = Transaction("Kitchenware01", "Babar01", 15000, 150);
    arr[8] = Transaction("Laundry01", "Asim01", 4000, 150);
    arr[9] = Transaction("Cosmetic01", "Huzaifa01", 1200, 350);

    for (int i = 0; i < 10; i++)
    {
        arr[i].IncTransaction();
        arr[i].AddtoTotal();
        arr[i].PrintInfo();
    }

    cout << "Total Revenue generated:  " << Transaction::GetTotalRev() << endl;

    return 0;
}

//note : i could not understand what was meant by "constant product price" , does it mean there is only 1 constant price or the price is constant for each object? , therefore i have made this code according to my understanding and because of the fact that there is a "product_id" i concluded that there would be multiple products with different prices. the ProdPrice is not declared as a constant because it will be different for each product but there are no setters for it and even the print function is made const so the ProdPrice cannot be changed once the object is made.



/*
    void add(int Num , int Balance){
        AccArr.push_back(Account(Num,Balance));
    }
    void remove(int Num){
        for(int i = 0 ; i < AccArr.size() ; i++){
            if(AccArr[i].getNumber() == Num){
                AccArr.erase(AccArr.begin()+i);
                cout << "Removed" << Num;
            }
            else{
                cout << "Removing Failed or Wrong Input";
            }
        }
    }


        void add(string name, string address, int id){
        clientArr.push_back(Client(name,address,id));
    }
    void remove(string Name){
        for(int i = 0 ; i < clientArr.size() ; i++){
            if(clientArr[i].getName() == Name){
                clientArr.erase(clientArr.begin()+i);
                cout << "Removed" << Name;
            }
            else{
                cout << "Removing Failed or Wrong Input";
            }
        }
    }





*/