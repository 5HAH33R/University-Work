#include <iostream>
#include <vector>
using namespace std;

class BookFormat{
};

class BookStatus{
};

class Date {
    private:
        int Day;
        int Month;
        int Year;
    
    public:
        Date(int day, int month, int year) :Day(day) , Month(month), Year(year) {}
};

class Author{
    private:
    vector<Book>* books;
    string Name;
    string Description;

    public:
    string GetName(){}

};

class Book{
    private:
    vector<Author>* authors;
    string ISBN;
    string Title;
    string Subject;
    string Publisher;
    string Language;
    int NoOfPages;

    public:
    string GetTitle(){}
};

class BookItem :public Book{
    private:
    string Barcode;
    bool IsReferenceOnly;
    Date Borrowed;
    Date DueDate;
    double Price;
    BookFormat Format;
    BookStatus Status;
    Date DateOfPurchase;
    Date PublicationDate;

    public:
    bool Checkout(){}
};

class Rack{
    private:
    vector<BookItem>* bookitems;
    int Number;
    string LocationIdentifier;

    public:

};


class Address{};

class Library{
    private:
    vector<BookItem> Books;
    string Name;
    Address address;

    public:
    Address GetAddress(){}
};



int main(){
  return 0;
}