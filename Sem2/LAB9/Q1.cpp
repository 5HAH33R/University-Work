#include <iostream>
#include <vector>
using namespace std;


class ArrayMultiplier{
    public:
    virtual void calculate(vector<int> arr , vector<int> arr2) = 0;
    virtual void calculate(vector<vector<int>>& arr1, vector<vector<int>>& arr2) = 0;

};


class One_D_Multiplier : public ArrayMultiplier{
    public:
    void calculate(vector<vector<int>>& arr1, vector<vector<int>>& arr2){}
    void calculate(vector<int> arr , vector<int> arr2) override{
        int Product;
        if(arr.size() == arr2.size()){
            for(int i = 0 ; i < arr.size() ; i++){
                Product += arr[i] * arr2[i];
            }
            cout << " Ans = " << Product << endl;
        }
        else{
            cout << "Both array sizes should be the same" << endl;
        }

    }
};

class Two_D_Multiplier : public ArrayMultiplier{
    public:
    void calculate(vector<int> arr , vector<int> arr2){}
    void calculate( vector<vector<int>>& arr1, vector<vector<int>>& arr2) override{ // Vector inside a Vector = 2d array
        int rows1 = arr1.size();
        int cols1 = arr1[0].size();
        int rows2 = arr2.size();
        int cols2 = arr2[0].size();
        
        if (cols1 != rows2) {
            cout << "Number of columns of the  first array must equal the number of rows in the second array" << endl;
        }
        else{
            vector<vector<int>> result(rows1, vector<int>(cols2, 0));
            for (int i = 0; i < rows1; ++i) {
                for (int j = 0; j < cols2; ++j) {
                    for (int k = 0; k < cols1; ++k) {
                        result[i][j] += arr1[i][k] * arr2[k][j];
                    }
                }
            }


            for ( auto &row : result) { // auto is used to automatically detect the variable Type
                for (int val : row) { //for value in row
                    cout << val << " ";
                }
                cout << endl;
            }
        }
    }
};


int main(){
    Two_D_Multiplier classname;
    vector<vector<int>> Arr1 = {{1, 2}, {3, 4}};
    vector<vector<int>> Arr2 = {{5, 6}, {7, 8}};
    classname.calculate(Arr1, Arr2);
  return 0;
}
