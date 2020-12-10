#include <iostream>
#include <list>
using namespace std;
class Pasare
{
    public:
    virtual void zboara()=0;
    virtual void sunet()=0;
    Pasare &operator+ (const Pasare& pasare);
};
class Papagal : Pasare
{
    public:
    Papagal(int distantaZbor, string sunetPapagal)
    {
        this->sunetPapagal=sunetPapagal;
        this->distantaZbor=distantaZbor;
    }
    Papagal &operator+(const Pasare& pasare)
    {
        return *this;
    }
    void zboara()
    {
        cout<<"Papagalul zboara!"<<endl;
    }
    void adaugaCuvant(string cuvant)
    {
        this->cuvinte.push_back(cuvant);
    }
    void afiseazaCuvinte()
    {
        cout<<"Cuvintele pe care papagalul le stie sunt: "<<endl;
        for(list<string>::iterator i=cuvinte.begin();i!=cuvinte.end();i++)
        {
            cout<<*i<<" ";
        }
        cout<<endl;
    }
    void afiseazaDistZbor()
    {
        cout<<"Papagalul poate sa zboare: "<<distantaZbor<<" km."<<endl;
    }
    void sunet()
    {
        cout<<"Sunetul papagalului este: "<<sunetPapagal<<"!"<<endl;
    }  
    int getDistanta()
    {
        return distantaZbor;    
    }
    string getSunet()
    {
        return sunetPapagal;    
    }
    list<string> getCuvinte()
    {
        return cuvinte;
    }
    private:
    list <string> cuvinte;
    string sunetPapagal;
    int distantaZbor;
};
class Gaina : Pasare
{
    public:
    Gaina(int distantaZbor,string sunetGaina)
    {
        if(nrGaini<30 && distantaZbor<10)
        {
            this->distantaZbor=distantaZbor;
            this->sunetGaina=sunetGaina;
            nrGaini++;
        }
        else
        {
            cout<<"Nu se mai pot adauga gaini!"<<endl;
            exit(-1);
        }
        
    }
    ~Gaina()
    {
        nrGaini--;
    }
    Gaina &operator+ (const Pasare& pasare)
    {
        return *this;
    }
    void setDistanta(int distantaZbor)
    {
        this->distantaZbor=distantaZbor;
    }
    void setSunet(string sunetGaina)
    {
        this->sunetGaina=sunetGaina;
    }
    void sunet()
    {
        cout<<"Sunetul gainii este: "<<sunetGaina<<"."<<endl;
    }
    void zboara()
    {
        cout<<"Aceasta gaina zboara pe o distanta de: "<<distantaZbor<<" m."<<endl;
    }
    static void afiseazaNrGaini()
    {
        cout<<"Avem: "<<nrGaini<<" gaini."<<endl;
    }
    static void kill()
    {
        nrGaini--;
    }
    private:
    int distantaZbor;
    string sunetGaina;
    static int nrGaini;
};
class Strut : Pasare
{
    public:
    Strut(string sunetStrut)
    {
        this->sunetStrut=sunetStrut;
    }
    static Strut *getInstance(string sunetStrut)
    {
        if(!instance)
        {
            instance=new Strut(sunetStrut);
            instance->nrGaini=0;
        }
        return instance;
    }
    Strut &operator+(const Gaina& pasare)
    {
        pasare.kill();
        nrGaini++;
        return *this;
    }
    void sunet()
    {
        cout<<"Sunetul strutului este: "<<sunetStrut<<"."<<endl;
    }
    void zboara()
    {
        cout<<"Fuge!"<<endl;
    }
    void afiseazaNrGaini()
    {
        cout<<nrGaini<<endl;
    }
    private:
    static Strut *instance;
    string sunetStrut;
    int nrGaini;
};
int Gaina::nrGaini;
Strut *Strut::instance=NULL;
int main()
{
    list <string> cuvinte1 = {"abc","bca","cab"};
    Papagal p1(20,"papa");
    p1.sunet();
    p1.adaugaCuvant("yea");
    p1.adaugaCuvant("neah");
    p1.adaugaCuvant("lol");
    p1.afiseazaCuvinte();
    p1.afiseazaDistZbor();
    Gaina g1(8,"cotc");
    Gaina g2(9,"zzz");
    Gaina g3(7,"bla");
    Gaina g4(7,"poc");
    Gaina g5(7,"cop");
    Gaina g6(8,"cotc");
    Gaina g7(9,"zzz");
    Gaina g8(7,"bla");
    Gaina g9(7,"poc");
    g1.sunet();
    g1.zboara();
    Gaina::afiseazaNrGaini();
    Gaina::kill();
    Gaina::afiseazaNrGaini();
    Strut * instance=Strut::getInstance("Oleee!");
    instance->sunet();
    instance->zboara();
    *instance=*instance+g1;
    *instance=*instance+g2;
    *instance=*instance+g3;
    instance->afiseazaNrGaini();
    Gaina::afiseazaNrGaini();
    return 0;
}