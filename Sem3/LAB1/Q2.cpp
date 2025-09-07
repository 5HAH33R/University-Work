#include <iostream>
using namespace std;

#define ROWS 5
#define COLS 5


int main(){
    double** arr = new double*[ROWS];

    for(int i =0; i<5 ; i++){
        arr[i] = new double[COLS];
    }

    // for(int i = 0 ; i < ROWS ; i++){
    //     for(int j = 0; j < COLS ; j++){
    //         cout << "enter value to insert : ";
    //         cin >> arr[i][j];
    //     }
    // }

    // Ali
    arr[0][0] = 3.66;
    arr[0][1] = 3.33;
    arr[0][2] = 4;
    arr[0][3] = 3;
    arr[0][4] = 2.66;

    // Hiba
    arr[1][0] = 3.33;
    arr[1][1] = 3;
    arr[1][2] = 3.66;
    arr[1][3] = 3;
    arr[1][4] = 0; 

    // Asma
    arr[2][0] = 4;
    arr[2][1] = 3.66;
    arr[2][2] = 2.66;
    arr[2][3] = 0;
    arr[2][4] = 0;

    // Zain
    arr[3][0] = 2.66;
    arr[3][1] = 2.33;
    arr[3][2] = 4.0;
    arr[3][3] = 0;
    arr[3][4] = 0;

    // Faisal
    arr[4][0] = 3.33;
    arr[4][1] = 3.66;
    arr[4][2] = 4;
    arr[4][3] = 3;
    arr[4][4] = 3.33;

    
    int choice = 10;
    bool flag = true;
    while(!(choice < 5 && choice > -1)){
        cout << "Choose a student to get their gpa (0-5) \n 0. Ali \n 1.Hiba \n 2.Asma \n 3.Zain \n 4.Faisal" <<endl;
        cin >> choice;
        if(cin.fail()){
            cout << "cin failed, you didnt enter a number.";
            flag = false;
            break;
        }
    }

    float avg = 0;
    for(int j = 0 ; j < COLS ; j++){
        avg += arr[choice][j];
    }

    switch (choice)
    {
    case 0:
        avg = avg/5;
        break;
    case 1:
        avg = avg/4;
        break;
    case 2:
        avg = avg/3;
        break;
    case 3:
        avg = avg/3;
        break;
    case 4:
        avg = avg/5;
        break;
    default:
        cout << "switch error";
        break;
    }

    if(flag){
        cout << "GPA is : " << avg << endl;
    }
    

  return 0;
}