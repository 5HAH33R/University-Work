#include <iostream>
#include <math.h>
using namespace std;



class Vector{
    private:
    int X;
    int Y;

    public:
    Vector(int x , int y) : X(x) , Y(y) {}

    Vector operator+(const Vector &obj){
        Vector newVec(0,0);
        newVec.X = obj.X + X;
        newVec.Y = obj.Y + Y;
        return newVec;
    }

    Vector operator-(const Vector &obj){
        Vector newVec(0,0);
        newVec.X = obj.X - X;
        newVec.Y = obj.Y - Y;
        return newVec;
    }

    Vector operator*(int ScalarValue){
        Vector newVec(0,0);
        newVec.X = ScalarValue * X;
        newVec.Y = ScalarValue * Y;
        return newVec;
    }

    Vector operator/(int ScalarValue){
        Vector newVec(0,0);
        newVec.X = X/ScalarValue;
        newVec.Y = Y/ScalarValue;
        return newVec;
    }

    float Magnitude(){
        return sqrt(pow(X,2)+pow(Y,2));
    }

    void Print(){
        cout << X << " " << Y << endl;
    }

};
int main(){
    Vector V1(3,4);
    Vector V2(6,8);

    Vector V3 = V1 + V2;
    V3.Print();
    Vector V4 = V1*2;
    V4.Print();

    Vector V5 = V2/2;
    V5.Print();

    cout << V1.Magnitude();
  return 0;
}