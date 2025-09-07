#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

class Radiator{
    private:
    int RadiatorID;

    public:
    Radiator(){
        string tempSubStr;
        cout << "Enter your roll no in the format (CT-#####) : ";
        cin >> tempSubStr;
        RadiatorID = stoi(tempSubStr.substr(5,7));
    }

    void getRadiatorID(){
        cout << RadiatorID;
    }
    void Heats(class Room* room);
};
class Room{
    private:
    string roomName;
    int SeatingCapacity;
    int NumRadiators;
    vector<Radiator*> radiatorsInRoom;


    public:
    Room(string RoomName) : roomName(RoomName) , SeatingCapacity(12){}

    bool IsHeatedBy(Radiator *rad){
        if(radiatorsInRoom.size() == 2){
            cout << "Cannot Add , Already Max num of Radiators";
            return false;
        }
        else{
            cout << "Successfully Added Radiator" << endl;
            radiatorsInRoom.push_back(rad);
            return true;    
        }
        for(int i = 0 ; i < radiatorsInRoom.size() ; i++){
            if(rad == radiatorsInRoom[i]){
                cout << "Radiator already in room" << endl;
                return false;
            }
        }  
    }
};

void Radiator::Heats(Room* room){
    room->IsHeatedBy(this);
}

int main(){
    Radiator R1;
    Radiator R2;
    Room room("My Room");

    R1.Heats(&room);
    cout << endl;
    R2.Heats(&room);
    cout << endl;
    R2.Heats(&room);
    cout << endl;

  return 0;
}