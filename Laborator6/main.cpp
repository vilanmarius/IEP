#include <iostream>
#include <tr1/memory>
#include <String>
using namespace std;

class Vehicle{
	public:
	Vehicle(const int& yearOfFab, const int& km)
    :
    yearOfFab(yearOfFab), km(km)
    {}
	Vehicle(const Vehicle& vehicle)
    :
    yearOfFab(vehicle.yearOfFab), km(vehicle.km)
    {}
	virtual ~Vehicle(){}
	Vehicle& operator=(const Vehicle& vehicle)
	{
		return *this;
    }
	protected:
		int yearOfFab;
		long km;

};

class Car:public Vehicle{
	public:
	Car(const int& yearOfFab, const int& km, const string& brand, const string& model)
	:
    Vehicle(yearOfFab,km),
    brand(brand),
    model(model)
    {}
	~Car()
	{
		cout<<"Destruct!";
	}
	void printCar()
	{
		cout<<"Car: "<<brand<<" "<<model<<yearOfFab<<" with "<<km<<" km."<<endl;
	}
	private:
	Car& operator=(const Car&);
	Car(const Car&);
	string brand;
	string model;
};
int main()
{
    Car *c1=new Car(2019,24000,"Audi","A5");
    Car *c2=new Car(2017,89000,"BMW","M5");
    Car *c3=new Car(2005,280000,"VW","Golf 5");
    std::tr1::shared_ptr<Car> pt1(c1);
    std::tr1::shared_ptr<Car> pt2(c2);
    std::tr1::shared_ptr<Car> pt3(c3);
	pt1.get()->printCar();
	pt2.get()->printCar();
	pt3.get()->printCar();
	return 0;
}
