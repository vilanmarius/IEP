#include <iostream>
#include <String>
using namespace std;
struct nrOfGears{//item 18
	explicit nrOfGears(int nrOfGears)
	: val(nrOfGears) {}
	int val;
};
string convertGear(int x)
{
    if(x==0)
        return "";
    else{
        return "+1";
    }
}
class Vehicle{
	public:
	Vehicle(const int& yearOfFab, const int& km, const nrOfGears& gears)
    :
    yearOfFab(yearOfFab), km(km), gears(gears.val <= 7 ? gears.val : 0)
    {}
	Vehicle(const Vehicle& vehicle)
    :
    yearOfFab(vehicle.yearOfFab), km(vehicle.km), gears(gears)
    {}
	virtual ~Vehicle(){}
	Vehicle& operator=(const Vehicle& vehicle)
	{
	    yearOfFab=vehicle.yearOfFab;
	    km=vehicle.km;
	    gears=vehicle.gears;
		return *this;
    }
    int getYearOfFab() const // item 22
    {
        return yearOfFab;
    }
    long getKm() const // item 22
    {
        return km;
    }
    void seteazaKm(long kmNoi)
    {
        km=kmNoi;
    }
    nrOfGears getNrOfGears() // item 22
    {
        return gears;
    }
	private: //item 22
		int yearOfFab;
		long km;
        nrOfGears gears; // item 18
};

class Car:public Vehicle{
	public:
	Car(const int& yearOfFab,const int& km,const nrOfGears& gears, const string& brand, const string& model)
	:
    Vehicle(yearOfFab,km,gears),
    brand(brand),
    model(model)
    {}
	~Car()
	{
		cout<<"Destruct!";
	}
	void printCar()
	{
		cout<<"Car: "<<brand<<" "<<model<<" "<<this->getYearOfFab()<<" with "<<(this->getNrOfGears().val<=7 && this->getNrOfGears().val>0 ?  this->getNrOfGears().val-1 : 0)<<convertGear(this->getNrOfGears().val)<<" gears and "<<this->getKm()<<" km."<<endl;
	}
	string getBrand() const // item 22
	{
	    return brand;
	}
	string getModel() const // item 22
	{
        return model;
	}
	private: //item 22
	Car& operator=(const Car&);
	Car(const Car&);
	string brand;
	string model;
};
void destroyCar(const Car& car) // item 20
{
    if(2020-car.getYearOfFab()>25 || car.getKm()>1000000)
    {
        cout<<"This car can't be use anymore, you should destroy it!"<<endl;
    }
    else
    {
        cout<<"Your car can be use!"<<endl;
    }
}
int main()
{
    Car *c1=new Car(2019,24000,nrOfGears(6),"Audi","A5");
    c1->printCar();
    destroyCar(*c1);// item 20
    c1->seteazaKm(1000001);
    c1->printCar();
    destroyCar(*c1);// item 20
	return 0;
}
