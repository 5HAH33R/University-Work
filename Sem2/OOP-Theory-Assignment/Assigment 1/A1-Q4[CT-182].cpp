#include <iostream>
using namespace std;

class Movie
{
private:
    string MovieName;
    string ShowTime;
    int TicketsBought = 0;

public:
    Movie(string Name, string showTime) : MovieName(Name) , ShowTime(showTime){}


    void GetInfo()
    {
        cout << "Movie name : " << MovieName << endl;
        cout << "Show Time : " << ShowTime << endl;
    }

    void TicketBought(){
        TicketsBought++;
    }
};

class Ticket{
private:
    static int IdGenerator;
    int TicketID;
    int RowNo;
    char SeatNo;
    bool Sold;

public:
    void BuyTicket(int Id){
        TicketID = Id + IdGenerator;
        IdGenerator++;
        cout << "Choose a row between 1-9: ";
        cin >> RowNo;
        cout << "Choose a seat between A-F: ";
        cin >> SeatNo;
    }
    bool IsSold()
    {
        if (Sold == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void SetSold()
    {
        Sold = true;
    }

    void DisplayInfo()
    {
        cout << "Ticket ID : " << TicketID << endl;
        cout << "Row No : " << RowNo << endl;
        cout << "Seat No : " << SeatNo << endl;
        if (Sold == true)
        {
            cout << "Seat Sold? : Yes" << endl;
        }
        else
        {
            cout << "Seat Sold? : No" << endl;
        }
    }
};

int Ticket::IdGenerator = 0;

int main()
{
    //for Roll no to Digits
    int RollNoDigits;
    string tempSubStr;
    cout << "Enter your roll no in the format (CT-#####) : ";
    cin >> tempSubStr;
    RollNoDigits = stoi(tempSubStr.substr(3,2));
    //

    Ticket tickets[100];
    int nextTicket = 0;

    Movie M1("Movie name 1" , "9:30 - 11:30");
    Movie M2("Movie name 2" , "11:30 - 1:00");
    Movie M3("Movie name 3" , "1:00 - 2:30");
    
    cout << "1.";
    M1.GetInfo();
    cout << "2.";
    M2.GetInfo();
    cout << "3.";
    M3.GetInfo();
    while(nextTicket < 100){
        cout << "Which movie would you like to buy a ticket for (1-3) : ";
        int Choice;
        cin >> Choice;
        if(Choice == 1){
            tickets[nextTicket].BuyTicket(RollNoDigits);
            tickets[nextTicket].SetSold();
            cout << "Successfully Purchased ticket , Details Below : \n\n";
            tickets[nextTicket].DisplayInfo();
            M1.GetInfo();
            M1.TicketBought();
            nextTicket++;
        }
        else if(Choice == 2){
            tickets[nextTicket].BuyTicket(RollNoDigits);
            tickets[nextTicket].SetSold();
            cout << "Successfully Purchased ticket , Details Below : \n\n";
            tickets[nextTicket].DisplayInfo();
            M2.GetInfo();
            M2.TicketBought();
            nextTicket++;
        }
        else{
            tickets[nextTicket].BuyTicket(RollNoDigits);
            tickets[nextTicket].SetSold();
            cout << "Successfully Purchased ticket , Details Below : \n\n";
            tickets[nextTicket].DisplayInfo();
            M1.GetInfo();
            M1.TicketBought();
            nextTicket++;
        }
    }

    



    return 0;
}