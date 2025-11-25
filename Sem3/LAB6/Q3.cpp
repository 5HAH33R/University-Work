#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

class Sort{
    private:
    int cmp = 0;
    int swp = 0;
    vector<int> arr;
    string whichSort;
    public:
    Sort(vector<int> array , string sort) : whichSort(sort) , arr(array){}
    Sort(vector<int> array) : arr(array){}
    
    vector<int> BubbleSort(){
        for(int i = 0; i < arr.size() ; i++){
            bool isSwap = false;
            for(int j = 0 ; j < arr.size()-i ; j++){
                cmp++;
                if(arr[j] > arr[j+1]){
                    swap(arr[j] , arr[j+1]);
                    swp++;
                    isSwap = true;
                }
            }
            if(!isSwap){
                break;
            }
        }
        return arr;
    }

    vector<int> InsertionSort(){
        for(int i = 1 ; i < arr.size() ; i++){
            int toInsert = arr[i];
            int j = i-1;
            cmp++;
            while(j >=0 && arr[j] > toInsert){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = toInsert;
            swp++;
        }
        return arr;

    }

    vector<int> SelectionSort(){
        for(int i = 0 ; i < arr.size() ; i++){
            int smallestidx = i;
            for(int j = i+1 ; j < arr.size() ; j++){
                cmp++;
                if(arr[j] < arr[smallestidx]){
                    smallestidx = j;
                }
            }
            swap(arr[i], arr[smallestidx]);
            swp++;

        }
        return arr;
    }
    void Analyse(){
        cout <<endl;
        this->InsertionSort();
        cout << "Insertion Sort --> Comparisons : " << cmp << " Swaps : "<< swp <<endl;
        cmp = 0; swp = 0;
        this->BubbleSort();
        cout << "Bubble sort --> Comparisons : " << cmp << " Swaps : "<< swp <<endl;
        cmp = 0; swp = 0;
        this->SelectionSort();
        cout << "Selection sort --> Comparisons : " << cmp << " Swaps : "<< swp <<endl;
        cmp = 0; swp = 0;
    }

};

void printArr(vector<int> arr){
    for(auto i : arr){
        cout << i << " ";
    }
    cout << endl;
}
int main(){
    // srand(time(0));
    vector<int> arr;
    // int exit =0;
    int input =0;
    cout << "Choose numbers for an array (-1 to exit) :" << endl;
    while(true){
        cout << "enter number : ";
        cin >> input;
        if(input == -1){
            break;
        }
        arr.push_back(input);
    }
    cout << "which sort do you want to perform : ";
    string sort;
    cin >> sort;
    while(true){
        if(sort == "insertion" || sort == "Insertion"){
            Sort s(arr,sort);
            arr = s.InsertionSort();
            cout << "your array after " << sort << " sort is :"; printArr(arr);
            break;
        }
        else if(sort == "bubble" || sort == "Bubble"){
            Sort s(arr,sort);
            arr = s.InsertionSort();
            cout << "your array after " << sort << " sort is :"; printArr(arr);
            break;
        }
        else if(sort == "selection" || sort == "Selection"){
            Sort s(arr,sort);
            arr = s.InsertionSort();
            cout << "your array after " << sort << " sort is :"; printArr(arr);
            break;
        }
        else{
            cout << "wrong choice" << endl;
            break;
        }
    }


    cout << "Would you like to perform analysis using all sorting?(1 for yes/ 0 for no) : ";
    cin >> input;
    if(input){
        Sort s(arr);
        s.Analyse();
    }


    // for(int i = 0 ; i < 10; i++){
    //     arr.push_back(rand() % 101);
        
    // }

  return 0;
}