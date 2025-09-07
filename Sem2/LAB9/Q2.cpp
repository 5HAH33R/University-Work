#include <iostream>
using namespace std;

class BillCalculator {
protected:
    double total;

public:
    BillCalculator(double bill) : total(bill) {}

    virtual double calculateBill() = 0;


};

class ImtiazStore : public BillCalculator {
public:
    ImtiazStore(double bill) : BillCalculator(bill) {}

    double calculateBill() override {
        return total - (0.07*total);
    }
};

class BinHashimStore : public BillCalculator {
public:
    BinHashimStore(double bill) : BillCalculator(bill) {}

    double calculateBill() override {
        return total - (0.05*total);
    }
};

int main() {
    double totalBill;

    cout << "Enter the total bill: ";
    cin >> totalBill;

    ImtiazStore imtiazStore(totalBill);
    BinHashimStore binHashimStore(totalBill);

    cout << "bill for ImtiazStore: " << imtiazStore.calculateBill() << endl;
    cout << "bill for BinHashimStore: " << binHashimStore.calculateBill() << endl;

    return 0;
}
