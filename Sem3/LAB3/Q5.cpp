#include <iostream>
using namespace std;

class Node{
    public:
    string data;
    Node* next;

    Node(string val){
        data = val;
        next = NULL;
    }
};

class BrowserHistory {
    Node* head;
    Node* tail;
    Node* temp;
    public:
    BrowserHistory(string homepage) {
        Node* FirstNode = new Node(homepage);
        head = tail = FirstNode;

    }
    
    void visit(string url) {
        Node* NewNode = new Node(url);
        tail->next = NewNode;
        tail = NewNode;
        
    }
    
    string back(int steps) {
        int size = 0;
        temp = head;

        while(temp != tail){
            temp = temp->next;
            size++;
        }

        if(size - steps < 0){
            tail = head;
            return head->data;
        }

        temp = head;
        for(int i = 0 ; i < (size-steps) ; i++){
            temp = temp->next;
        }

        tail = temp;
        // tail->next = NULL;

        return tail->data;
    }
    
    string forward(int steps) {
        for(int i = 0 ; i < steps ; i++){
            if(tail->next == NULL){
                return tail->data;
            }
            else{
                tail = tail->next;
            }
        }
        return tail->data;
   
    }
};

int main(){
    BrowserHistory* chrome = new BrowserHistory("homepage");

    chrome->visit("google.com");
    chrome->visit("facebook.com");
    chrome->visit("youtube.com");

    cout << chrome->back(1) << endl;     
    cout << chrome->back(1) << endl;  
    cout << chrome->forward(1) << endl;

    chrome->visit("linkedin.com");

    cout << chrome->forward(2) << endl;
    cout << chrome->back(2) << endl;
    cout << chrome->back(7) << endl;    

    return 0;
}
