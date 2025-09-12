#include <iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* next;

  Node(int val){
    this->data = val;
    this->next = nullptr;
  }
};

class LL{
  private:
  Node* head;

  public:
  LL(){
    head = nullptr;
  }

  void insert(int val){
    Node* temp = head;
    Node* newNode = new Node(val);
    if(head == nullptr){
      head = newNode;
    }
    else{
      while(temp->next != nullptr){
        temp = temp->next;
      }
      temp->next = newNode;
    }
  }

  void deleteNode(int val){
    Node* temp = head;
    Node* prev = nullptr;
    if(temp != nullptr && temp->data == val){
      head = temp->next;
      delete temp;
      return;
    }
    while(temp->data != val && temp != nullptr){
      prev = temp;
      temp = temp->next;
    }
    if(temp == nullptr){
      cout << "Data not in LL";
      return;
    }
    prev->next = temp->next;
    delete temp;
  }

  bool search(int val){
    Node* temp = head;
    while(temp->data != val && temp != nullptr){
      temp = temp->next;
    }
    if(temp == nullptr){
      return false;
    }
    return true;
  }

  void display(){
    Node* temp = head;
    while(temp != nullptr){
      cout << temp->data << "-->";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }

  // Q2
  void RemoveDups(){
    Node* temp = head->next;
    Node* prev = head;
    while (temp != nullptr)
    {
        if(temp->data == prev->data){
            this->deleteNode(temp->data);
        }
        prev = temp;
        temp = temp->next;

    }
    
  }
};

int main(){
    LL list;
    list.insert(1);
    list.insert(1);
    list.insert(1);
    list.insert(2);
    list.insert(2);
    list.insert(3);
    list.insert(3);
    list.insert(3);
    list.insert(3);
    list.insert(4);

    list.RemoveDups();
    list.display();


    return 0;
}