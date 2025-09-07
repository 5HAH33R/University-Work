#include <iostream>
using namespace std;


class MedianFinder{
    private:
    int* arr;
    int size;

    public:
    MedianFinder(){
        arr = new int[520];
        size = 0;
    }

    void addnum(int num){
        arr[size] = num;
        size++;
    }

    float findmedian(){
        if(size % 2 == 0){
            return (((float)arr[size/2] + (float)arr[(size/2)-1])/2);
        }
        else{
            return arr[size/2];
        }
    }

    ~MedianFinder(){
        delete[] arr;
    }
};

int main(){
    MedianFinder* obj = new MedianFinder();
    obj->addnum(1);
    obj->addnum(2);
    obj->addnum(3);
    obj->addnum(4);
    obj->addnum(6);
    obj->addnum(8);
    obj->addnum(10);
    obj->addnum(12);
    obj->addnum(14);
    obj->addnum(15);
    obj->addnum(18);
    cout << obj->findmedian();
    return 0;
}