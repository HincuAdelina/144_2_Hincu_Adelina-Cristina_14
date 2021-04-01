#include <iostream>
#include<string>
using namespace std;


class Proces
{
    int nrProces;
    string reclamant;
    string reclamat;
public:
    Proces() {}
    Proces(int nr_proces, string nume1, string nume2)   //constructor parametrizat
    {
        nrProces = nr_proces;
        reclamant = nume1;
        reclamat = nume2;
    }
    Proces(Proces &proces)      //constructor de copiere
        : nrProces(proces.nrProces), reclamant(proces.reclamant), reclamat(proces.reclamat) {}
    ~Proces()
    {
        nrProces = NULL;
        reclamant = "";
        reclamat = "";
    }

    friend std::istream& operator >>(std::istream& in,  Proces& proces);
    friend std::ostream& operator <<(std::ostream& out, const Proces& proces);

    void print()
    {
        cout<<nrProces<<reclamant<<reclamat;
    }
};

std::istream& operator >>(std::istream& in,  Proces& proces)
{

    cout<<"Numar proces: ";
    in>>proces.nrProces;
    cout<<"Reclamant: ";
    in>>proces.reclamant;
    cout<<"Reclamat: ";
    in>>proces.reclamat;

    return in;
}
std::ostream& operator <<(std::ostream& out, const Proces& proces)
{

    out<<"Numar proces: "<<proces.nrProces<<"\nReclamant: "<<proces.reclamant<<"\nReclamat:"<<proces.reclamat<<"\n";
    return out;
}



class Proces_civil: public Proces
{
    double dauneMorale;
    double dauneMateriale;
    int nrMartori;
    bool stadiu;
public:
    Proces_civil() {}
    Proces_civil(double DauneMorale, double DauneMateriale,int NrMartori)   //constructor parametrizat
    {
        dauneMorale = DauneMorale;
        dauneMateriale = DauneMateriale;
        nrMartori = NrMartori;

        if(nrMartori>5)
            stadiu=1;
        else
            stadiu=0;
    }
    Proces_civil(Proces_civil &proces_c)      //constructor de copiere
        : Proces(), dauneMorale(proces_c.dauneMorale), dauneMateriale(proces_c.dauneMateriale), nrMartori(proces_c.nrMartori) {}
    ~Proces_civil() {}
    void setStadiuCivil(bool stadiu)
    {
        this->stadiu = stadiu;
    }
    double taxaTimbru()
    {
        return (0.1*dauneMorale + 0.1*dauneMateriale);
    }
    friend std::istream& operator >>(std::istream& in,  Proces_civil& proces_c);
    friend std::ostream& operator <<(std::ostream& out, Proces_civil& proces_c);

};

std::istream& operator >>(std::istream& in,  Proces_civil& proces_c)
{
    cout<<"Daune morale: ";
    in>>proces_c.dauneMorale;
    cout<<"Daune materiale: ";
    in>>proces_c.dauneMateriale;
    cout<<"Numar martori: ";
    in>>proces_c.nrMartori;

    if(proces_c.nrMartori>5)
        proces_c.stadiu=1;
    else
        proces_c.stadiu=0;

    return in;
}
std::ostream& operator <<(std::ostream& out, Proces_civil& proces_c)
{

    out<<"Daune morale: "<<proces_c.dauneMorale<<"\nDaune materiale: "<<proces_c.dauneMateriale<<"\nNumar martori: "<<proces_c.nrMartori<<"\nStadiu: "<<proces_c.stadiu<<"\n";

    return out;
}



class Proces_penal: public Proces
{
    int dovezi;
    bool stadiu;
public:
    Proces_penal()
    {
    }
    Proces_penal(int Dovezi)   //constructor parametrizat
    {
        dovezi=Dovezi;
        if(dovezi>25)
            stadiu=1;
        else
            stadiu=0;
    }
    Proces_penal(Proces_penal &proces_p)      //constructor de copiere
        :  Proces(), dovezi(proces_p.dovezi) {}
    ~Proces_penal() {}

    void setStadiuPenal(bool stadiu)
    {
        this->stadiu = stadiu;
    }

    friend std::istream& operator >>(std::istream& in,  Proces_penal& proces_p);
    friend std::ostream& operator <<(std::ostream& out, Proces_penal& proces_p);
};


std::istream& operator >>(std::istream& in,  Proces_penal& proces_p)
{

    cout<<"Dovezi: ";
    in>>proces_p.dovezi;

    if(proces_p.dovezi > 25)
        proces_p.stadiu = 1;
    else
        proces_p.stadiu = 0;

    return in;
}
std::ostream& operator <<(std::ostream& out, Proces_penal& proces_p)
{

    out<<"Dovezi: "<<proces_p.dovezi<<"\nStadiu: "<<proces_p.stadiu<<"\n";

    return out;
}

int main()
{
    Proces_penal p1,p2(28);
     cin>>p1;
p1.setStadiuPenal(1);
cin>>p2;
//p2.setStadiuPenal(0);
cout<<p1<<endl;
    cout<<p2;

    return 0;
}
