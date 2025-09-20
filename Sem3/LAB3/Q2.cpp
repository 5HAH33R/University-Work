#include <iostream>
using namespace std;

class Node{
    public:
    Node* prev;
    Node* next;
    int data;

    Node(int val){
        prev = nullptr;
        next = nullptr;
        data = val;
    }
};

class DoubleEndedQueue{
    public:
    Node* front;
    Node* rear;
    

    public:
        DoubleEndedQueue(){
            front = nullptr;
            rear = nullptr;
        }
    void Insertatfront(int val){
        Node* newNode = new Node(val);
        if(front == nullptr){
            front = rear =  newNode;
        }
        else{
            Node* temp = front;
            front = newNode;
            front->next = temp;
            temp->prev = front;
        }
    }
    void Insertatrear(int val){
        Node* newNode = new Node(val);
        if(rear == nullptr){
            rear = newNode;
        }
        else{
            Node* temp = rear;
            rear = newNode;
            rear->prev = temp;
            temp->next = rear;
        }

    }

    void Deleteatfront(){
        if(front == nullptr){
            cout << "empty" << endl;
        }
        else{
            Node* temp = front;
            front = front->next;
            front->prev = nullptr;
            delete temp;
        }
    }

    void Deleteatrear(){
        if(rear == nullptr){
            cout << "empty";
        }
        else{
            Node* temp = rear;
            rear = rear->prev;
            rear->next = nullptr;
            delete temp;
        }
    }

    void print(){
        Node* temp = front;
        while(temp != nullptr){
            cout << temp->data << "<->";
            temp = temp->next;
        }
        cout << "NULL";
    }
    
};

int main(){
    DoubleEndedQueue D;
    D.Insertatfront(22);
    D.Insertatfront(12);
    D.Insertatfront(115);
    D.Insertatrear(23);
    D.Insertatrear(450);
    D.Deleteatfront();
    D.Deleteatrear();
    D.print();
  return 0;
}