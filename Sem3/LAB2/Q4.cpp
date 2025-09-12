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

    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
  
    bool isPalindrome(Node* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        Node* slow = head;
        Node* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* secondHalf = reverseList(slow->next);
        Node* firstHalf = head;
        
        while (secondHalf != nullptr) {
            if (firstHalf->data != secondHalf->data) {
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return true;
    }

};

int main(){
    LL list;
    list.insert(1);
    list.insert(2);
    list.insert(2);
    list.insert(1);

    cout << list.isPalindrome(list.get_head());
}