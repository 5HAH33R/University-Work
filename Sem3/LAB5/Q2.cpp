#include <iostream>
using namespace std;

class Node {
    public:
    Node* next;
    int data;

    Node(int value){
        this->next = nullptr;
        this->data = value;
    }
};

class CLL {
private:
    Node* head;

public:
    CLL(){
        head = nullptr;
    }

    void print() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* current = head;
        do {
            cout << current->data << " -> ";
            current = current->next;
        } while (current != head);
        cout << "(back to head)" << endl;
    }

    void insert(int data) {
        Node* newNode = new Node(data);

        if (head == NULL) {
            head = newNode;
            head->next = head;
        } else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head;
        }
    }

    void MoveHead(){
        head = head->next;
    }
    int getheaddata(){
        return head->data;
    }

    void deleteNode() {
        int key = head->data;
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node* prev = head;
            while (prev->next != head) {
                prev = prev->next;
            }
            prev->next = head->next;
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        cout << "Deleted " << key << endl;
        return;
    }
};


int findTheWinner(int n, int k) {
    CLL list;
    for(int i = 1 ; i < n+1; i++){
        list.insert(i);
    }
    int players = n;

    while(players > 1){
        for(int i = 1 ; i < k ; i++){
            list.MoveHead();
        }
        list.deleteNode();
        players -= 1;

    }
    return list.getheaddata();
}


int main() {
    
    int n, k;
    cout << "Enter number of players (n): ";
    cin >> n;
    cout << "Enter counting interval (k): ";
    cin >> k;
    
    int winner = findTheWinner(n, k);
    cout << "The winner is: " << winner << endl;
    
    return 0;
}