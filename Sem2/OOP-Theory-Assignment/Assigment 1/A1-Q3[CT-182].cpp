#include <iostream>
#include <vector>
using namespace std;

class HeartRates{
    private:
        string FirstName;
        int ID;
        int Day;
        int Year;
        string Month;
        
    public:
    HeartRates(int id , string firstName , int day , string month , int year) : ID(id) , FirstName(firstName) , Day(day) , Month(month) , Year(year) {}
        
    string getFirstName()
    {
        return this->FirstName;
    }

    void setFirstName(string FirstName)
    {
        this->FirstName = FirstName;
    }

    int getID()
    {
        return this->ID;
    }

    void setID(int ID)
    {
        this->ID = ID;
    }

    int getDay()
    {
        return this->Day;
    }

    void setDay(int Day)
    {
        this->Day = Day;
    }

    int getYear()
    {
        return this->Year;
    }

    void setYear(int Year)
    {
        this->Year = Year;
    }

    string getMonth()
    {
        return this->Month;
    }

    void setMonth(string Month)
    {
        this->Month = Month;
    }    

    int GetAge(){
        return 2025-Year;
    }

    int GetMaxHeartRate(){
        return 220-(2025-Year);
    }

    vector<float> GetTargetHeartRate(){ //returns an array with 0th index at 50%  max heartrate and 1st index at 85% max heartRate
        vector<float> Target;
        Target.push_back(0.5*(220-(2025-Year)));
        Target.push_back(0.85*(220-(2025-Year)));
        return Target;
    }
    

};

int main(){
    // for 3rd digit of roll no
    int RollNoDigits;
    string tempSubStr;
    cout << "Enter your roll no in the format (CT-#####) : ";
    cin >> tempSubStr;
    RollNoDigits = tempSubStr[4] - '0';
    //

    string FirstName;
    int Day;
    int Year;
    string Month;
    cout << "Please Enter your  first Name : ";
    cin >>  FirstName;
    cout << "Please enter your birth Day : ";
    cin >> Day;
    cout << "Please enter your birth Month : ";
    cin >> Month;
    cout << "Please enter your birth Year : ";
    cin >> Year;

    HeartRates H1(RollNoDigits, FirstName , Day , Month , Year);

    cout << "Person info \n\n";
    cout << H1.getFirstName() << endl;
    cout << "Date of birth : " << H1.getDay() << "/" << H1.getMonth() << "/" << H1.getYear() << endl;
    cout << "Age : " << H1.GetAge() << endl;
    cout << "Max Heart Rate : " << H1.GetMaxHeartRate() << endl;

    vector<float> HoldRange;
    HoldRange = H1.GetTargetHeartRate();
    cout << "Target heart Range : " << HoldRange[0] << " to " << HoldRange[1];

    

  return 0;
}