#include <iostream>
#include <string>
using namespace std;


class EncryptionTechnique{

    public:
    virtual long long int encrypt(string Data) = 0;

};

class EncryptionTechnique1 : public EncryptionTechnique{
    public:

    long long int encrypt(string Data){
        long long int converted = 0;
        for(char i : Data){
            converted += int(i);
            converted = converted*100;
        }
        return converted/100;
    }
};

class EncryptionTechnique2 : public EncryptionTechnique{
    public:

    long long int encrypt(string Data){
        long long int converted = 0;
        for(char i : Data){
            converted += int(i);
            converted  = converted +2;
            converted  = converted*100;
        }
        return converted/100;
    }
};


int main(){
    EncryptionTechnique1 E1;
    EncryptionTechnique2 E2;
    cout << E1.encrypt("HELLO");
    cout << "\n";
    cout << E2.encrypt("HELLO");

  return 0;
}