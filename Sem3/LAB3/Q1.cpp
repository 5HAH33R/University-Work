#include <iostream>
using namespace std;

class Node{
    public:
    Node* next;
    int data;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

class CircularQ{
    private:
    Node* front;
    Node* rear;

    public:
    CircularQ(){
        front = nullptr;
        rear = nullptr;
    }    

    void enqueue(int val){
        Node* newNode = new Node(val);
        if(front == nullptr){
            front = rear = newNode;
            rear->next = front;
        }
        else{
            Node* temp = rear;
            rear =  newNode;
            rear->next = front;
            temp->next = rear;
        }

    }

    void dequeue(){
        if(front == nullptr){
            cout << "Queue is empty";
        }
        Node* temp = front;
        front = front->next;
        rear->next = front;
        delete temp;
    }
    void print(){
        Node* temp = front;
        do
        {
            cout << temp->data << "->";
            temp = temp->next;
        } while (temp != front);
        cout << "NULL";
        
    }


};
int main(){
    CircularQ myQ;
    myQ.enqueue(21);
    myQ.enqueue(32);
    myQ.enqueue(44);
    myQ.dequeue();
    myQ.print();


  return 0;
}