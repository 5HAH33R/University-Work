#include <iostream>
using namespace std;

class vehicle
{
private:
    string TypeOfCar;
    string Make;
    int Model = 0;
    string Color;
    int Year = 0;
    int MilesDriven = 0;

public:
    vehicle(string typeOfCar, string make, int model, string color, int year, int milesDriven) : TypeOfCar(typeOfCar), Make(make), Model(model), Color(color), Year(year), MilesDriven(milesDriven) {}

    void displayVehicle(){
        cout << "Type of Car: " << TypeOfCar << endl;
        cout << "Make: " << Make << endl;
        cout << "Model: " << Model << endl;
        cout << "Color: " << Color << endl;
        cout << "Year: " << Year << endl;
        cout << "Miles Driven: " << MilesDriven << endl;
    }
};

class GasVehicle : virtual public vehicle
{
private:
    int FuelTankSize;

public:
    GasVehicle(int fueltanksize, string typeOfCar, string make, int model, string color, int year, int milesDriven) : FuelTankSize(fueltanksize), vehicle(typeOfCar, make, model, color, year, milesDriven) {}

    void displayGasVehicle(){
        cout << "Fuel Tank Size: " << FuelTankSize << endl;
    }
};

class ElectricVehicle :virtual public vehicle
{
private:
    string EnergyStorage;

public:
    ElectricVehicle(string typeOfCar, string make, int model, string color, int year, int milesDriven, string energyStorage) : vehicle(typeOfCar, make, model, color, year, milesDriven), EnergyStorage(energyStorage) {}

    void displayElectricVehicle(){
        cout << "Energy Storage: " << EnergyStorage << endl;
    }
};

class HeavyVehicle : virtual public ElectricVehicle, virtual public GasVehicle
{
private:
    int MaxWeight;
    int NoOfWheels;
    int Length;

public:
    HeavyVehicle(string typeOfCar, string make, int model, string color, int year, int milesDriven, string energyStorage, int fuelTankSize, int maxWeight, int noOfWheels, int length) : vehicle(typeOfCar, make, model, color, year, milesDriven) , ElectricVehicle(typeOfCar, make, model, color, year, milesDriven, energyStorage), GasVehicle(fuelTankSize, typeOfCar, make, model, color, year, milesDriven), MaxWeight(maxWeight), NoOfWheels(noOfWheels), Length(length) {}

    void displayHeavyVehicle(){
        vehicle::displayVehicle();
        displayElectricVehicle(); 
        displayGasVehicle();
        cout << "Max Weight: " << MaxWeight << endl;
        cout << "Number of Wheels: " << NoOfWheels << endl;
        cout << "Length: " << Length << endl;
    }
};

class HighPerformance : public GasVehicle
{
    int HorsePower;
    int TopSpeed;

public:
    HighPerformance(int fueltanksize, string typeOfCar, string make, int model, string color, int year, int milesDriven, int horsepower, int topspeed) : vehicle(typeOfCar, make, model, color, year, milesDriven), GasVehicle(fueltanksize, typeOfCar, make, model, color, year, milesDriven), HorsePower(horsepower), TopSpeed(topspeed){}

    void displayHighPerformance(){
        displayGasVehicle();
        cout << "Horse Power: " << HorsePower << endl;
        cout << "Top Speed: " << TopSpeed << endl;
    }

};


class SportsCar: public HighPerformance{
    public:
    string Gearbox(){
        return "Gearbox Called";
    }

    string DriveSystem(){
        return "Drive System Called";
    }

    void displaySportsCar(){
        displayHighPerformance();
        cout << Gearbox() << endl;
        cout << DriveSystem() << endl;
    }
};

class ConstructionTruck : public HeavyVehicle{
    public:
    string Cargo(){
        return "Cargo Called";
    }

    void displayConstructionTruck(){
        displayHeavyVehicle();
        cout << Cargo() << endl;
    }
};

class Bus : public HeavyVehicle{
    private:
    int NoOfSeats;

    public:
    Bus(string typeOfCar, string make, int model, string color, int year, int milesDriven, string energyStorage, int fueltanksize, int maxWeight, int noOfWheels, int length , int noofseats) : vehicle(typeOfCar, make, model, color, year, milesDriven), HeavyVehicle(typeOfCar, make, model, color, year, milesDriven , energyStorage , fueltanksize , maxWeight , noOfWheels ,  length) , NoOfSeats(noofseats) , ElectricVehicle(typeOfCar, make, model, color, year, milesDriven, energyStorage) , GasVehicle(fueltanksize, typeOfCar, make, model, color, year, milesDriven){}

    void display(){
        displayHeavyVehicle(); 
        cout << "Number of Seats: " << NoOfSeats << endl;
    }
    
};
int main()
{
    Bus B1("type" , "make" , 100 , "color" , 400 , 500 , "string" , 600 , 700 ,800 , 900 , 1000);
    B1.display();
    return 0;
}