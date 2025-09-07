#include <iostream>
using namespace std;

void swap(int *numA, int *numB)
{
    int temp = *numA;
    *numA = *numB;
    *numB = temp;
}

int main()
{
    int num1, num2, num3;

    cout << "enter three numbers: ";
    cin >> num1 >> num2 >> num3;

    cout << "Before swapping: " << num1 << "," << num2 << "," << num3 << endl;

    swap(&num1, &num2);
    swap(&num2, &num3);

    cout << "After swapping: " << num1 << "," << num2 << "," << num3 << endl;

    return 0;
}
