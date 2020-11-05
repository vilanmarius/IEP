#include <iostream>
#include <string.h>
using namespace std;
class Vehicle
{
    protected:
    string brand;
    string typeOfVeh;
    Vehicle(const string& brand, const string& typeOfVeh)
    :
    brand(brand),typeOfVeh(typeOfVeh)
    {};
    ~Vehicle(){};
    public:
    Vehicle(const Vehicle&);
    Vehicle& operator=(const Vehicle&);
    void printVehicle()
    {
        cout<<brand<<"\t"<<typeOfVeh<<"\t";
    }
    void speedUp()
    {
        cout<<"Speed Up"<<endl;
    }
};
class Car : public Vehicle
{
    protected:
    int year;
    float HP;
    public:
    Car(const string& brand, const int& year, const string& typeVehicle, const float& HP)
    :
    Vehicle(brand,typeVehicle),year(year),HP(HP)
    {};
    void printCar()
    {
        printVehicle();
        cout<<year<<"\t"<<HP;
    }
    void turnRadioOn()
    {
        cout<<"RADIO ON"<<endl;
    }
    void turnRadioOff()
    {
        cout<<"RADIO OFF"<<endl;
    } 
};
class Audi : public Car
{
    public:
    Audi(const string& brand, const int& year, const string& typeVehicle, const float& HP)
    :
    Car(brand,year,typeVehicle,HP)
    {};
    void turnOnSportMode()
    {
        cout<<"Sport mode activated!"<<endl;
    }
};
class Bus : public Vehicle
{
    protected:
    int nrOfseats;
    public:
    Bus(const string& brand, const int& nrOfseats, const string& typeVehicle)
    :
    Vehicle(brand,typeVehicle),nrOfseats(nrOfseats)
    {};
    void printBus()
    {
        printVehicle();
        cout<<nrOfseats;
    }
    void openDoors()
    {
        cout<<"The doors are open"<<endl;
    }
    void closeDoors()
    {
        cout<<"The doors are colsed!"<<endl;
    }
};
int main(int argc, char *argv[])
{
    Audi a1("Audi",2005,"B",1.9);
    a1.printCar();
    cout<<":"<<endl;
    a1.speedUp();
    a1.turnRadioOn();
    a1.turnRadioOff();
    a1.turnOnSportMode();
    Bus b1("VW",100,"D");
    b1.printBus();
    cout<<":"<<endl;
    b1.speedUp();
    b1.openDoors();
    b1.closeDoors();
    return 0;
}