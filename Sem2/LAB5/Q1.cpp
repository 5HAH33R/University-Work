#include <iostream>
using namespace std;


class BaseClass{
    private:
    int PrivateInt = 0;
    protected:
    int ProtectedInt = 0;
    public:
    int PublicInt = 0;

    int getPrivateInt(){
        return PrivateInt;
    }
    int getPublicInt(){
        return PublicInt;
    }
    int getProtectedInt(){
        return ProtectedInt;
    }

    void setPrivateInt(int value){
        PrivateInt = value;
    }
    void setPublicInt(int value){
        PublicInt = value;
    }
    void setProtectedInt(int value){
        ProtectedInt = value;
    }
};

class PrivateChild : private BaseClass {
};

class PublicChild : public BaseClass {  
};

class ProtectedChild : protected BaseClass{
};
int main(){
    PrivateChild privChild;
    cout << "private Child: \n";
    cout << "no direct acces or getter and setter access\n\n";
    PublicChild publChild;
    cout << "Public Child: \n";
    publChild.getPrivateInt();
    publChild.getProtectedInt();
    publChild.getPublicInt();
    publChild.PublicInt = 10;
    publChild.setPrivateInt(10);
    publChild.setProtectedInt(5);
    publChild.setPublicInt(5);
    cout << "all setters and getter and publicInt variable could be accessed\n\n";
    ProtectedChild ProtChild;
    cout << "Protected Child: \n";
    cout << "no setter or getter or any variable can be accessed";




  return 0;
}