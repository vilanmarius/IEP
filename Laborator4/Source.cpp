#include <iostream>
#include <string.h>
using namespace std;
class Car{
private:
    string brand;
    string model;
    int year;
public:
    Car(const string& brand,const string& model,const int& year) // default constructor
    : brand(brand), model(model),year(year)
    {};
    Car(Car& car) // copy constructor is called
    {
        this->brand=car.brand;
        this->model=car.model;
        this->year=car.year;
    };
    ~Car() // default destructor
    {
        cout<<"Destructor is called!"<<endl;
    };
    Car& operator=(const Car& car) // assignment constructor is called
    {
        this->brand=car.brand;
        this->model=car.model;
        this->year=car.year;
        return *this;
    };
    void printCar() // print car brand, model and year
    {
        cout<<this->brand<<"\t"<<this->model<<"\t"<<this->year<<endl;
    }

};
int main(int argc, char * argv [])
{
    // Cars init
    Car *car1=new Car("Audi","A4",2019);
    Car *car2=new Car("Audi","A5",2012);
    Car *car3=new Car("BMW","M3",2017);
    Car *car4=new Car("VW","GOLF 4",2005);
    Car *car5=new Car("VW","GOLF 5",2006);
    Car *car5Dup=new Car("Noname","Noname",2006);
    // print 4/6 cars
    car1->printCar();
    car2->printCar();
    car3->printCar();
    car4->printCar();
    // assign car5Dup - car5 and print 
    *car5Dup=*car5;
    car5Dup->printCar();

    //destruct cars
    cout<<endl<<"DESTRUCT: "<<endl<<endl;
    
    delete car1;
    delete car2;
    delete car3;
    delete car4;
    delete car5Dup;
    delete car5;
    return 0;
}