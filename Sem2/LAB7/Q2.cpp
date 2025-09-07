#include <iostream>
#include "Q1.cpp"

using namespace std;

void ArrTwoD::Question2Implementation(int target){
  int r = 0;
  bool found = false;
  for(r = 0; r<rows ; r++){
    if(Data[r][0] > target){
      break;
    }
  }

  for(int i = 0; i < cols ; i++){
    if(Data[r-1][i] == target){
      cout << "TRUE";
      break;
    }
  }
}


int main(){

  ArrTwoD A1(3,4);
  A1.ChangeData(0,0,1);
  A1.ChangeData(0,1,3);
  A1.ChangeData(0,2,5);
  A1.ChangeData(0,3,7);
  A1.ChangeData(1,0,10);
  A1.ChangeData(1,1,11);
  A1.ChangeData(1,2,16);
  A1.ChangeData(1,3,20);
  A1.ChangeData(2,0,23);
  A1.ChangeData(2,1,30);
  A1.ChangeData(2,2,34);
  A1.ChangeData(2,3,60);

  A1.Question2Implementation(23);
  

    
  return 0;
}