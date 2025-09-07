#include <iostream>
using namespace std;

class BookType
{
private:
  string Title;
  string Authors[4];
  string Publisher;
  int YOP;
  long ISBN;
  float Price;
  int InStock;
  int NoOfAuthors;

public:
  BookType()
  {
    Title = "Default Title";
    Authors[0] = "Empty";
    Authors[1] = "Empty";
    Authors[2] = "Empty";
    Authors[3] = "Empty";
    Publisher = "Default Publisher";
    YOP = 0;
    ISBN = 00000000;
    Price = 0.00;
    InStock = 0;
    NoOfAuthors = 0;
  }

  string getTitle()
  {
    return this->Title;
  }
  void setTitle(string Title)
  {
    this->Title = Title;
  }

  string getPublisher()
  {
    return this->Publisher;
  }
  void setPublisher(string Publisher)
  {
    this->Publisher = Publisher;
  }

  int getYOP()
  {
    return this->YOP;
  }
  void setYOP(int YOP)
  {
    this->YOP = YOP;
  }

  long getISBN()
  {
    return this->ISBN;
  }
  void setISBN(long ISBN)
  {
    this->ISBN = ISBN;
  }

  float getPrice()
  {
    return this->Price;
  }
  void setPrice(float Price)
  {
    this->Price = Price;
  }

  int getInStock()
  {
    return this->InStock;
  }
  void setInStock(int InStock)
  {
    this->InStock = InStock;
  }

  void setAuthors(string Name1, string Name2, string Name3, string Name4)
  {
    Authors[0] = Name1;
    Authors[1] = Name2;
    Authors[2] = Name3;
    Authors[3] = Name4;
  }
  void setAuthors(string Name1, string Name2, string Name3)
  {
    Authors[0] = Name1;
    Authors[1] = Name2;
    Authors[2] = Name3;
  }
  void setAuthors(string Name1, string Name2)
  {
    Authors[0] = Name1;
    Authors[1] = Name2;
  }
  void setAuthors(string Name1)
  {
    Authors[0] = Name1;
  }

  void getAuthors()
  {
    int i = 0;
    while (1)
    {
      if (Authors[i] == "Empty")
      {
        break;
      }
      else{
        cout << Authors[i] << " ";
      }
      i++;
    }
  }

  int getNoOfAuthors()
  {
    int j = 0;
    while (1)
    {
      if (j > 4 || Authors[j] == "Empty")
      {
        cout << j << endl;
        break;
      }
      j++;
    }
  }

  void PrintInfo(){
    cout << "Title : " << Title << endl;
    cout << "Authors : ";
    getAuthors();
    cout << endl;
    cout << "Number of Authors : ";
    getNoOfAuthors();
    cout <<"Publisher : " << Publisher << endl;
    cout << "Year of Publishing : " << YOP << endl;
    cout << "ISBN Number : " << ISBN << endl;
    cout << "Price : " << Price << endl;
    cout << "Number of books in stock : " << InStock;
  }

};

int main()
{
  BookType Book[100];
  Book[24].setISBN(1456783);
  Book[24].setTitle("Atomic Habits");
  Book[24].setPrice(25.00);
  Book[24].setAuthors("James Clear");
  Book[24].setInStock(6);
  Book[24].setPublisher("Penguin Random House");
  Book[24].setYOP(2018);
  
  cout << "Search by Title \n\n";
  for(int i = 0; i < 100; i++){
    if(Book[i].getTitle() == "Atomic Habits"){
      Book[i].PrintInfo();
    }
  }

  Book[24].setInStock(20);

  cout << "\n\nSearch by ISBN and  No of copies changed to 20\n\n";
  for(int i = 0; i < 100; i++){
    if(Book[i].getISBN() == 1456783){
      Book[i].PrintInfo();
    }
  }
  
  return 0;
}