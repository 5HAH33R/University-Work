#include <iostream>
using namespace std;

class Media{
    protected:
    string Name;
    int Published;

    public:
    Media(){} // Default Constructor
    Media(string name , int published) : Name(name) , Published(published){}

    void Borrow(){
        cout << Name << "Borrowed" << endl;
    }

    void Return(){
        cout << Name << "Returned" << endl;
    }

    virtual void Display() = 0;

};

class Book : public Media{
    protected:
    string Author;

    public:

    Book(){}
    Book(string name , int published , string author) : Media(name,published) , Author(author){}

    void Display(){
        cout << "Name : " << Name << endl;
        cout << "Published on : " << Published << endl;
        cout << "Author: " << Author << endl;
        
    }
};

class DVD : public Media{
    protected:
    string Director;

    public:

    DVD(){}
    DVD(string name , int published , string director) : Media(name,published) , Director(director){}

    void Display(){
        cout << "Name : " << Name << endl;
        cout << "Published on : " << Published << endl;
        cout << "Director: " << Director << endl;
        
    }
};

class Magazine : public Media{
    protected:
    int IssueNo;

    public:

    Magazine(){}
    Magazine(string name , int published , int issue_no) : Media(name,published) , IssueNo(issue_no){}

    void Display(){
        cout << "Name : " << Name << endl;
        cout << "Published on : " << Published << endl;
        cout << "Issue Number: " << IssueNo << endl;
        
    }
};


int main(){
  return 0;
}