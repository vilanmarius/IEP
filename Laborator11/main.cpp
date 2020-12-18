/* 
Enunt problema:
Programare Generica
-------------------
Considerand clasa de baza figura, construiti 3 clase derivate care sa implementeze figuri geometrice si perimetrul acestora (cu numar diferit de laturi).
Fiecare figura contine un vector (sau lista) de puncte.
Clasa punct detine coordonatele unui punct in axele x si y.
Se va folosi o functie template pentru a afla panta dreptei formata din oricare doua puncte ale unei figuri geometrice 
- se poate face pentru primele doua puncte din lista de puncte a figurii
Se va crea clasa singleton cerc, cu o raza specificata si un punct de origine. 
O functie template va fi implementata pentru a determina daca o figura se afla pe cerc (verificam daca punctele ce creaza figura, de forma (X,Y)
, satisfac relatia matematica (x-a)^2+ (y-b)^2=R^2, unde a si b sunt coordonatele centrului C(a,b)-daca satisfac relatia atunci se afla pe cerc). 
Crearea unui nou cerc va arunca o eroare ce va fi prinsa pentru ca iesirea din program sa nu fie brusca.
In main se va crea un meniu care va permite adaugarea de figuri geometrice de tipurile alese, adaugarea de puncte, modificarea punctelor, afisarea pantei dreptei pe o figura aleasa, crearea unui cerc, verificarea daca o figura are puncte pe cerc.
*/
#include <iostream>
#include <list>
#include <string>
#include <math.h>
using namespace std;
#define _USE_MATH_DEFINES
class Punct
{
    private:
        float x;
        float y;
    public:
        Punct(){;};
        Punct(float x, float y)
        {
            this->x=x;
            this->y=y;
        }
        float getX()
        {
            return x;
        }
        float getY()
        {
            return y;
        }
        void setPunct(float x, float y)
        {
            this->x=x;
            this->y=y;
        }
};
class Figura
{
    private:
    list<Punct>listaPuncte;
    public:
    float calculeazaMuchie(Punct a, Punct b)
    {
        return sqrt(pow((b.getX()-a.getX()),2)+((b.getY()-a.getY()),2));
    }
    float perimetru()
    {
        float perimetru=0;
        Punct aux=listaPuncte.back();
        for(list<Punct>::iterator i=listaPuncte.begin();i!=listaPuncte.end();i++)
        {
            perimetru+=calculeazaMuchie(aux,*i);
            aux=*i;
        }
        return perimetru;
    }
    void adaugaPunct(Punct punct)
    {
        listaPuncte.push_back(punct);
    }
    void afisarePuncte()
    {
        int j=0;
        cout<<"Punctele sunt: "<<endl;
        for(list<Punct>::iterator i=listaPuncte.begin();i!=listaPuncte.end();i++)
        {
            cout<<++j<<". ("<<i->getX()<<","<<i->getY()<<");"<<endl;
        }
    }
    void adaugaCoordonate(float x,float y)
    {
        Punct *p=new Punct(x,y);
        listaPuncte.push_back(*p);
    }
    list<Punct> getLista()
    {
        return listaPuncte;
    }
};
class Triunghi : public Figura
{
    public:
    Triunghi(){;};
    Triunghi(Punct a, Punct b, Punct c)
    {
        adaugaPunct(a);
        adaugaPunct(b);
        adaugaPunct(c);
    }
};
class Dreptunghi : public Figura
{
    public:
    Dreptunghi(){;};
    Dreptunghi(Punct a, Punct b, Punct c, Punct d)
    {
        adaugaPunct(a);
        adaugaPunct(b);
        adaugaPunct(c);
        adaugaPunct(d);
    }
};
class Pentagon : public Figura
{
    public:
    Pentagon(){;};
    Pentagon(Punct a, Punct b, Punct c, Punct d,Punct e)
    {
        adaugaPunct(a);
        adaugaPunct(b);
        adaugaPunct(c);
        adaugaPunct(d);
        adaugaPunct(e);
    }
};
class Cerc : public Figura
{
    private:
    float r;
    static Cerc* instance;
    public:
    Cerc(){;};
    Cerc(Punct o,float r)
    {
        this->r=r;
        adaugaPunct(o);
    }
    static Cerc* getInstance(Punct o,float r)
    {
        try
        {
            if(instance==NULL)
            {
                instance=new Cerc(o,r);
            }
            else
            {
                throw "Avem deja un cerc!";
            }
            return instance;
        }
        catch(const char *e)
        {
            cout<<e<<endl;
        }
        
    }
    float perimetru()
    {
        return 2*M_PI*r;
    }
    float getRaza()
    {
        return r;
    }
};
template <class Figura>
float panta(Figura figura)
{
    list<Punct>listaPuncte=figura.getLista();
    Punct p1=listaPuncte.begin();
    Punct p2=next(listaPuncte.begin());
    return (p2.getY()-p1.getY())/(p2.getX()-p1.getX());
}
//(x-a)^2+ (y-b)^2=R^2, unde a si b sunt coordonatele centrului C(a,b)
template <class Figura>
bool verificaAp(Cerc cerc,Figura figura)
{
    bool check=true;
    float r=cerc.getRaza();
    list<Punct>lista=cerc.getLista();
    float  x1,y1;
    for(list<Punct>::iterator i=lista.begin();i!=lista.end();i++)
    {
        x1=i->getX();
        y1=i->getY();
    }
    Punct p1(x1,y1);
    float a=p1.getX();
    float b=p1.getY();
    float Tdr=pow(r,2);
    float x=0;
    float y=0;
    float Tst=0;
    list<Punct>listaPuncte=figura.getLista();
    for(list<Punct>::iterator i=listaPuncte.begin();i!=listaPuncte.end();i++)
    {
        x=i->getX();
        y=i->getY();
        Tst=pow(x-a,2)+pow(y-b,2);
        if(Tst!=Tdr)
        {
            check=false;
            break;
        }
    }
    return check;
}
Cerc* Cerc::instance=NULL;
int main()
{
    bool goBack=false;
    bool loop=true;
    int optiune;
    Punct *pp;
    Triunghi *t;
    Dreptunghi *d;
    Pentagon *p;
    Cerc *c;
    int optiune2;
    while(loop)
    {
        cout<<"Meniu:"<<endl;
        cout<<"1. Adaugare triunghi"<<endl;
        cout<<"2. Adaugare dreptunghi"<<endl;
        cout<<"3. Adaugare pentagon"<<endl;
        cout<<"4. Creeaza cerc"<<endl;
        cout<<"5. Afisare panta triunghi + puncte"<<endl;
        cout<<"6. Afisare panta dreptunghi + puncte"<<endl;
        cout<<"7. Afisare panta pentagon + puncte"<<endl;
        cout<<"8. Verifca puncte pe cerc"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"Alege optiune:"<<endl;
        cin>>optiune;
        switch(optiune)
        {
            case 0:
            {
                cout<<"Bye-bye!"<<endl;
                loop=false;
                break;
            }
            case 1:
            {
                t=new Triunghi();
                int j=1;
                float x,y;
                for(int i=0;i<3;i++)
                {
                    cout<<"Da-mi coordonatele punctului pentru triunghiului: "<<endl;
                    cin>>x;
                    cin>>y;
                    t->adaugaCoordonate(x,y);
                }
                break;
            }
            case 2:
            {
                d=new Dreptunghi();
                int j=1;
                float x,y;
                for(int i=0;i<4;i++)
                {
                    cout<<"Da-mi coordonatele punctului pentru dreptunghiului: "<<endl;
                    cin>>x;
                    cin>>y;
                    d->adaugaCoordonate(x,y);
                }
                break;
            }
            case 3:
            {
                p=new Pentagon();
                int j=1;
                float x,y;
                for(int i=0;i<5;i++)
                {
                    cout<<"Da-mi coordonatele punctului pentru pentagonului: "<<endl;
                    cin>>x;
                    cin>>y;
                    p->adaugaCoordonate(x,y);
                }
                break;
            }
            case 4:
            {
                float r,x,y;
                cout<<"Da-mi raza: "<<endl;
                cin>>r;
                cout<<"Da-mi punctul de origine al cercului: "<<endl;
                cin>>x;
                cin>>y;
                Punct origine(x,y);
                c=Cerc::getInstance(origine,r);
                break;
            }
            case 5:
            {
                cout<<"Panta triunghi: "<<t->perimetru()<<endl;
                t->afisarePuncte();
                break;
            }
            case 6:
            {
                cout<<"Panta dreptunghi: "<<d->perimetru()<<endl;
                d->afisarePuncte();
                break;
            }
            case 7:
            {
                cout<<"Panta pentagon: "<<p->perimetru()<<endl;
                p->afisarePuncte();
                break;
            }
            case 8:
            {
                goBack=true;
                while(goBack)
                {
                    cout<<" Selecteaza optiune:"<<endl;
                    cout<<" 1. Verifica triunghi"<<endl;
                    cout<<" 2. Verifica dreptunghi"<<endl;
                    cout<<" 3. Verifica pentagon"<<endl;
                    cout<<" 0. Inapoi"<<endl;
                    cout<<" ";
                    cin>>optiune2;
                    switch(optiune2)
                    {
                        case 0:
                        {
                            goBack=false;
                            break;
                        }
                        case 1:
                        {
                            if(verificaAp(*c,*t))
                            {
                                cout<<"Da, triungiul apartine!"<<endl;
                            }
                            else
                            {
                                cout<<"Nu, triunghiul nu apartine!"<<endl;
                            }
                            break;
                        }
                        case 2:
                        {
                            if(verificaAp(*c,*d))
                            {
                                cout<<"Da, dreptunghiul apartine!"<<endl;
                            }
                            else
                            {
                                cout<<"Nu, dreptunghiul nu apartine!"<<endl;
                            }
                            break;
                        }
                        case 3:
                        {
                            if(verificaAp(*c,*p))
                            {
                                cout<<"Da, pentagonul apartine!"<<endl;
                            }
                            else
                            {
                                cout<<"Nu, pentagonul nu apartine!"<<endl;
                            }
                            break;
                        }   
                }
                }
                break;
            }
        }
    }
    return 0;
}