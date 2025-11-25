#include <iostream>
using namespace std;

class CDQ {
private:
    int* data;
    int front = 0;
    int rear = 0;
    int size = 0;
    int capacity = 0;

public:
    CDQ(int s) : capacity(s) {
        data = new int[capacity];
    }

    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
    
    bool insertRear(int val) {
        if (!isFull()) {
            rear = (rear + 1) % capacity;
            data[rear] = val;
            size++;
            if (size == 1) {
                front = rear;
            }
            return true;
        } else {
            cout << "Queue is full\n";
            return false;
        }
    }
    
    bool insertFront(int val) {
        if (!isFull()) {
            front = (front - 1 + capacity) % capacity;
            data[front] = val;
            size++;
            if (size == 1) {
                rear = front;
            }
            return true;
        } else {
            cout << "Queue is full\n";
            return false;
        }
    }
    
    bool DeleteFront() {
        if (!isEmpty()) {
            front = (front + 1) % capacity;
            size--;
            return true;
        } else {
            cout << "Queue is Empty\n";
            return false;
        }
    }
    
    bool DeleteRear() {
        if (!isEmpty()) {
            rear = (rear - 1 + capacity) % capacity;
            size--;
            return true;
        } else {
            cout << "Queue is Empty\n";
            return false;
        }
    }
    
    int getRear() {
        if (!isEmpty()) {
            return data[rear];
        }
        return -1;
    }
    
    int getFront() {
        if (!isEmpty()) {
            return data[front];
        }
        return -1;
    }


    ~CDQ() {
        delete[] data;
    }
};

int main() {
    CDQ* DEQ = new CDQ(3);
    cout << DEQ->insertRear(1)<< endl;
    cout << DEQ->insertRear(2)<< endl;
    cout << DEQ->insertFront(3)<< endl;
    cout << DEQ->insertFront(4)<< endl;
    cout << DEQ->getRear() << endl;
    cout << DEQ->isFull()<< endl;
    cout << DEQ->DeleteRear()<< endl;
    cout << DEQ->insertFront(4)<< endl;
    cout << DEQ->getFront()<< endl;


    

    delete DEQ;
    return 0;
}