#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Call {
private:
    int callId;
    string customerName;
    int duration;
    string issue;

public:
    Call(int id, string name, int callDuration, string callIssue) 
        : callId(id), customerName(name), duration(callDuration), issue(callIssue) {}


    void displayCallInfo() const {
        cout << "Call ID: " << callId << endl;
        cout << "Customer: " << customerName << endl;
        cout << "Duration: " << duration << " mins";
        cout << "Issue: " << issue << endl;
    }

    int getCallId(){
        return callId;
    }
    string getCustomerName(){
        return customerName;
    }
};

class CallCenter {
private:
    int totalCSR;
    vector<bool> csrAvailability;
    queue<Call> waitingCalls;
    int nextCallId;

public:
    CallCenter(int numCSR) : totalCSR(numCSR), nextCallId(1) {
        csrAvailability.resize(totalCSR, true);
    }

    void receiveCall(string customerName, int duration, string issue) {
        Call newCall(nextCallId++, customerName, duration, issue);
        waitingCalls.push(newCall);
        cout << "New call received from " << customerName << endl;
        assignCalls();
    }

    void assignCalls() {
        while (!waitingCalls.empty()) {
            int availableCSR = findAvailableCSR();
            if (availableCSR == -1) {
                cout << "No CSRs available. Calls waiting: " << waitingCalls.size() << endl;
                return;
            }

            Call currentCall = waitingCalls.front();
            waitingCalls.pop();
            csrAvailability[availableCSR] = false;

            cout << "Call ID " << currentCall.getCallId() 
                 << " assigned to CSR " << availableCSR + 1 
                 << " Customer: " << currentCall.getCustomerName() << endl;
        }
    }

    int findAvailableCSR() {
        for (int i = 0; i < totalCSR; i++) {
            if (csrAvailability[i]) {
                return i;
            }
        }
        return -1;
    }

    void completeCall(int csrIndex) {
        if (csrIndex < 0 || csrIndex >= totalCSR) {
            cout << "Invalid CSR index!" << endl;
            return;
        }
        if (csrAvailability[csrIndex]) {
            cout << "CSR " << csrIndex + 1 << " is already available!" << endl;
            return;
        }

        csrAvailability[csrIndex] = true;
        cout << "CSR " << csrIndex + 1 << " is now available." << endl;
        assignCalls();
    }

    void displayStatus() {
        cout << "\n------Status-------"<< endl;
        cout << "Total CSRs: " << totalCSR << endl;
        cout << "Available CSRs: ";
        for (int i = 0; i < totalCSR; i++) {
            cout << "CSR" << i + 1 << ":" << (csrAvailability[i] ? "Available" : "Busy");
            if (i < totalCSR - 1) cout << " | ";
        }
        cout << "\nWaiting calls: " << waitingCalls.size() << endl;
        
        if (!waitingCalls.empty()) {
            cout << "Next call in queue: ";
            waitingCalls.front().displayCallInfo();
        }
    }

    int getAvailableCSRCount() {
        int count = 0;
        for (bool available : csrAvailability) {
            if (available) count++;
        }
        return count;
    }

    int getWaitingCallsCount() {
        return waitingCalls.size();
    }
};

int main() {
    CallCenter center(3);

    center.displayStatus();

    center.receiveCall("Alice", 5, "Billing Issue");
    center.receiveCall("Bob", 8, "Technical Support");
    center.receiveCall("Charlie", 3, "Product Information");
    center.receiveCall("Diana", 6, "Complaint");
    
    center.displayStatus();

    center.completeCall(0);
    center.displayStatus();

    center.completeCall(1);
    center.displayStatus();

    center.receiveCall("Eve", 4, "Account Setup");
    center.displayStatus();

    center.completeCall(2);
    center.completeCall(0);
    
    center.displayStatus();

    return 0;
}