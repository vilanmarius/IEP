#include <iostream>
#include "header.h"
using namespace std;
int main(int argv, char *argc[]){
	if(argv<3)
	{
		cout<<"You need to number as arguments to run Add,Sub,Mul,Div!"<<endl;
		return 0;
	}
	else{
		int x1=atoi(argc[1]);
		int x2=atoi(argc[2]);
		cout<<"Add: "<<add(x1,x2)<<endl;
		cout<<"Sub: "<<sub(x1,x2)<<endl;
		cout<<"Mul: "<<mul(x1,x2)<<endl;
		cout<<"Div: "<<divv(x1,x2)<<endl;
		return 0;
	}
}

