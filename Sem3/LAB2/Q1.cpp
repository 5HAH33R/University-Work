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

  // Q1
  void mergeLL(LL* list2){
    Node* temp1 = this->head;
    Node* temp2 = list2->head;
    LL merged;


    while(temp1 != nullptr && temp2 != nullptr){
      if(temp1->data == temp2->data){
        merged.insert(temp1->data);
        merged.insert(temp2->data);
      }
      if(temp1->data > temp2->data){
        merged.insert(temp2->data);
        merged.insert(temp1->data);
      }
      else if(temp1->data < temp2->data){
        merged.insert(temp1->data);
        merged.insert(temp2->data);
      }
      temp1 = temp1->next;
      temp2 = temp2->next;
    }
    if(temp1 == nullptr){
      while(temp2 != nullptr){
        merged.insert(temp2->data);
        temp2 = temp2->next;
      }
    }

    if(temp2 == nullptr){
      while(temp1 != nullptr){
        merged.insert(temp1->data);
        temp1 = temp1->next;
      }
    }
    cout << "Merged List : ";
    merged.display();
    
  }


};


int main(){
  LL list1;
  LL list2;

  list1.insert(1);
  list1.insert(2);
  list1.insert(4);

  list2.insert(1);
  list2.insert(3);
  list2.insert(4);

  list1.mergeLL(&list2);
  



  return 0;
}