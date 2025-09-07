#include <iostream>
using namespace std;

class Admin
{
private:
    static int UserCount;
    int AdminID;
    static int IdGenerator;
    string FirstName;
    string LastName;
    string Country;
    int Age;

public:
    Admin(string firstName, string lastName, int age, string country) : FirstName(firstName), LastName(lastName), Age(age), Country(country)
    {
        AdminID = IdGenerator;
        IdGenerator++;
    }
    string getFirstName()
    {
        return this->FirstName;
    }

    void setFirstName(string FirstName)
    {
        this->FirstName = FirstName;
    }

    string getLastName()
    {
        return this->LastName;
    }

    void setLastName(string LastName)
    {
        this->LastName = LastName;
    }

    string getCountry()
    {
        return this->Country;
    }

    void setCountry(string Country)
    {
        this->Country = Country;
    }

    int getAge()
    {
        return this->Age;
    }

    void setAge(int Age)
    {
        this->Age = Age;
    }

    int TotalUsers()
    {
        return UserCount;
    }

    static void incUserCount()
    {
        UserCount++;
    }
};

class DataScientist
{
private:
    static int IdGenerator;
    int UserID;
    string HighestEducation;
    string FirstName;
    string LastName;
    string Country;
    int Age;
    int NoOfAnswers;
    int NoOfQuestions;

public:
    DataScientist(int DigitsFromRollNo, string firstName, string lastName, string highestEdu, int age, string country) : FirstName(firstName), LastName(lastName), HighestEducation(highestEdu), Age(age), Country(country) ,NoOfAnswers(0) ,NoOfQuestions(0)
    {
        UserID = DigitsFromRollNo + IdGenerator;
        IdGenerator++;
        Admin::incUserCount();
    }

    int GetId()
    {
        return UserID;
    }

    string getFirstName()
    {
        return this->FirstName;
    }

    void setFirstName(string FirstName)
    {
        this->FirstName = FirstName;
    }

    string getLastName()
    {
        return this->LastName;
    }

    void setLastName(string LastName)
    {
        this->LastName = LastName;
    }

    string getCountry()
    {
        return this->Country;
    }

    void setCountry(string Country)
    {
        this->Country = Country;
    }

    int getAge()
    {
        return this->Age;
    }

    void setAge(int Age)
    {
        this->Age = Age;
    }

    void AskQuestion()
    {
        NoOfQuestions++;
    }

    void AnswerProblem()
    {
        NoOfAnswers++;
    }

    int GetAskedQuestions()
    {
        return NoOfQuestions;
    }

    int GetAnsweredQuestions()
    {
        return NoOfAnswers;
    }
};

int DataScientist::IdGenerator = 0;
int Admin::UserCount = 0;
int Admin::IdGenerator= 0;
int main()
{
    int RollNoDigits;
    string tempSubStr;
    cout << "Enter your roll no in the format (CT-#####) : ";
    cin >> tempSubStr;
    RollNoDigits = tempSubStr[4] - '0';
    RollNoDigits = (RollNoDigits * 10) + (tempSubStr[7] - '0');

    DataScientist D1(RollNoDigits, "D1First", "D1Last", "D1HighestEdu", 21, "D1Country");
    DataScientist D2(RollNoDigits, "D2First", "D2Last", "D2HighestEdu", 34, "D2Country");
    DataScientist D3(RollNoDigits, "D3First", "D3Last", "D3HighestEdu", 44, "D3Country");

    Admin A1("A1First", "A1Last", 22, "A1Country");

    D1.AskQuestion();
    D2.AskQuestion();
    D3.AskQuestion();
    D3.AskQuestion();
    D3.AskQuestion();
    D1.AnswerProblem();
    D1.AnswerProblem();
    D1.AnswerProblem();

    cout << "Total users from admin : " << A1.TotalUsers() << endl;
    cout << "ID of D1 : " << D1.GetId() << endl;
    cout << "D1 Q asked : " << D1.GetAskedQuestions() << endl;
    cout << "D1 Q answered : " << D1.GetAnsweredQuestions() << endl;
    cout << "ID of D2 : " << D2.GetId() << endl;
    cout << "D2 Q asked : " << D2.GetAskedQuestions() << endl;
    cout << "D2 Q answered : " << D2.GetAnsweredQuestions() << endl;
    cout << "ID of D3 : " << D3.GetId() << endl;
    cout << "D3 Q asked : " << D3.GetAskedQuestions() << endl;
    cout << "D3 Q answered : " << D3.GetAnsweredQuestions() << endl;

    return 0;
}