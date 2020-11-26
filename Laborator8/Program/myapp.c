#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>

MODULE_DESCRIPTION("My module with Cars!");
MODULE_AUTHOR("Marius Vilan");
MODULE_LICENSE("GPL");

int i=1;
typedef struct Vehicle {
    int yearOfFab;
    long Km;
} Vehicle;

typedef struct Car {
    Vehicle * veh;
    char *brand;
} Car;

void Construct(Vehicle * vehicle , int year,long km){
    printk(KERN_INFO "Construct car!");
    vehicle->yearOfFab = year;
    vehicle->Km = km;
}

void Copy(Vehicle * vehicle1 , Vehicle *vehicle2){
    vehicle1->yearOfFab=vehicle2->yearOfFab;
    vehicle1->Km=vehicle2->Km;
}

void setYear(Vehicle *vehicle, int x)
{
    vehicle->yearOfFab=x;
}

void setKm(Vehicle *vehicle, long x)
{
    vehicle->Km=x;
}

void printVehicleInfo(Vehicle * vehicle){
        printk(KERN_INFO "%d	%ld\n", vehicle->yearOfFab,vehicle->Km);
}

void printCarInfo(Car *car)
{
    printk(KERN_INFO "%d. %s\t",i,car->brand);
    printVehicleInfo(car->veh);
    i++;
}

void carIgnition(Car *car)
{
    printk(KERN_INFO "%s start engine.\n",car->brand);
}

static int my_init(void)
{
	Vehicle vehicle1;
    	Vehicle vehicle2;
    	Car car1;
    	Car car2;
	printk(KERN_INFO "Hello, this is my init:\n");
   	 //-----------------------------------------------
    	car1.brand="Audi";
    	car2.brand="BMW";
    	//-----------------------------------------------
    	Construct(&vehicle1, 2017,5555);
    	Construct(&vehicle2, 2017,100000);
    	car1.veh=&vehicle1;
    	car2.veh=&vehicle2;
    	//-----------------------------------------------
    	Copy(&vehicle1,&vehicle2);
    	setKm(&vehicle1,990000);
    	//printVehicleInfo(&vehicle1);
    	printCarInfo(&car1);
    	printCarInfo(&car2);
	return 0;
}

static void my_exit(void)
{
	Vehicle vehicle1;
    	Vehicle vehicle2;
    	Car car1;
    	Car car2;
	printk(KERN_INFO "Hello, this is my exit:\n");
 	//-----------------------------------------------
    	car1.brand="VW";
    	car2.brand="Dacia";
    	//-----------------------------------------------
    	Construct(&vehicle1, 2005,217000);
    	Construct(&vehicle2, 1998,1000000);
    	car1.veh=&vehicle1;
    	car2.veh=&vehicle2;
    	//-----------------------------------------------
    	carIgnition(&car1);
    	carIgnition(&car2);
}

module_init(my_init);
module_exit(my_exit);
