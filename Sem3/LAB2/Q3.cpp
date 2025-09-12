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

  Node* get_head(){
    return head;
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

  int at(int index){
    Node* temp = head;
    int i = 0;
    if(index == 0){
      return temp->data;
    }
    while(i != index){
      temp = temp->next;
      i++;
      if(temp == nullptr){ return -1;}
    }
    return temp->data;
  }

};

Node* Merge(Node* LeftList , Node* RightList){

  Node* tempNode = new Node(-1);
  Node* temp = tempNode;

  while(LeftList != nullptr && RightList != nullptr){
    if(LeftList->data > RightList->data){
      temp->next = RightList;
      temp = temp->next;
      RightList= RightList->next; 
    }
    else{
      temp->next = LeftList;
      temp = temp->next;
      LeftList= LeftList->next; 
    }
  }
  if(LeftList == nullptr){
    temp->next = RightList;
  }
  if(RightList == nullptr){
    temp->next = LeftList;
  }

  return tempNode->next;
  
}

Node* FindMiddle(Node* head){
  Node* slow = head;
  Node* fast = head->next;

  while(fast != nullptr and fast->next != nullptr){
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;

}


Node* MergeSort(Node* headtosort){
  if(headtosort == nullptr || headtosort->next == nullptr ){ return headtosort;}
  Node* mid = FindMiddle(headtosort);
  Node* right = mid->next;
  mid->next = nullptr;
  Node* left = headtosort;
  left = MergeSort(left);
  right = MergeSort(right);
  return Merge(left,right);
}


int main(){

  LL list;
  list.insert(2);
  list.insert(6);
  list.insert(4);
  list.insert(8);
  list.insert(7);
  list.insert(1);
  MergeSort(list.get_head());
  list.display();



  return 0;
}