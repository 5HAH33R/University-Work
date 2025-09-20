#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int d){
        data=d;
        next=NULL;
        prev=NULL;
    }
};

class DoublyLinkedList{
    private:
        Node* head; 
    
    public:

    DoublyLinkedList(): head(NULL) {}
    
    void insertAtFront(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        newNode->prev = NULL;

        if(head != NULL){
            head->prev = newNode;
        }
        head = newNode;
        
    }
    Node* gethead(){
        return head;
    }
    
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        newNode->next = NULL;
        if(head == NULL) {
            newNode->prev = NULL;
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        
        temp->next = newNode;
        newNode->prev = temp;
        
        
    }
    
    void deleteNode(int value) { 
        Node* temp = head;
        while (temp != NULL && temp->data != value) {
            temp = temp->next;
        }
    
        if (temp == NULL) { 
            cout << "Not Found" <<endl;
            return;
        }
    
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;
        }
    
        if (temp->next  = NULL) {
            temp->next->prev = temp->prev;
        }
    
        delete temp;
    }
    
    void displayForward() const {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data <<"->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    
    void displayBackward() const {
        Node* temp = head;
        if (temp == NULL) return;

        while (temp->next != NULL) {
            temp = temp->next;
        }
        
        while (temp != NULL) {
            cout << temp->data <<"->";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
        
    }
    
};

//function  for Q3
DoublyLinkedList MergeList(DoublyLinkedList &list1 , DoublyLinkedList &list2){ 
    DoublyLinkedList newlist;
    Node* temp = list1.gethead();
    while(temp != nullptr){
        newlist.insertAtFront(temp->data);
        temp = temp->next;
    }
    temp = list2.gethead();
    while(temp != nullptr){
        newlist.insertAtEnd(temp->data);
        temp = temp->next;
    }

    return newlist;


}

//function for Q4
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

  while(fast != nullptr && fast->next != nullptr){
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


int main() {
    // code for Q3
    DoublyLinkedList E;
    E.insertAtFront(2);
    E.insertAtFront(4);
    E.insertAtFront(6);
    E.insertAtFront(8);
    E.insertAtFront(10);
    DoublyLinkedList M;
    M.insertAtFront(1);
    M.insertAtFront(3);
    M.insertAtFront(5);
    M.insertAtFront(7);
    M.insertAtFront(9);
    
    DoublyLinkedList Merged = MergeList(E,M);
    cout << "Answer for Q3 (merged) : ";
    Merged.displayForward();

    // code for Q4

    MergeSort(Merged.gethead());
    cout << "Answer for Q4 (sorted) : ";
    Merged.displayForward();
    



    

    return 0;
}