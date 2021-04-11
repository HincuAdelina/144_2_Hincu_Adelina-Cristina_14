#include <iostream>
#include<string>
#include <vector>

using namespace std;


class Proces
{
protected:
    int nrProces;
    string reclamant;
    string reclamat;
public:
    Proces(): nrProces(0) {reclamant = ""; reclamat = "";}
    Proces(int nr_proces, string nume1, string nume2)   //constructor parametrizat
    {
        nrProces = nr_proces;
        reclamant = nume1;
        reclamat = nume2;
    }
    Proces(Proces &proces)      //constructor de copiere
        : nrProces(proces.nrProces), reclamant(proces.reclamant), reclamat(proces.reclamat) {}
    virtual ~Proces()
    {
        nrProces = 0;
        reclamant = "";
        reclamat = "";
    }

    friend std::istream& operator >>(std::istream& in,  Proces& proces);
    friend std::ostream& operator <<(std::ostream& out, const Proces& proces);
    Proces& operator=(const Proces& proces)
    {
        nrProces = proces.nrProces;
        reclamant = proces.reclamant;
        reclamat = proces.reclamat;
        return *this;
    }
    virtual int GetNrProces(){return  nrProces;}
    virtual void Afisare()
    {
        cout<<"PROCES:\nNumar proces: "<<nrProces<<"\nReclamant: "<<reclamant<<"\nReclamat: "<<reclamat<<endl;
    }

    virtual istream &Citire(istream& in)
    {
        cout<<"Numar proces: ";
        in>>nrProces;
        cout<<"Reclamant: ";
        in>>reclamant;
        cout<<"Reclamat: ";
        in>>reclamat;

        return in;
    }
};

std::istream& operator >>(std::istream& in,  Proces& proces)
{
    return proces.Citire(in);
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
    Proces_civil(): Proces(), dauneMorale(0), dauneMateriale(0), nrMartori(0), stadiu(0) {}
    Proces_civil(int nr_proces, string nume1, string nume2, double DauneMorale, double DauneMateriale, int NrMartori)
        :Proces(nr_proces, nume1, nume2)  //constructor parametrizat
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
        : Proces(proces_c.nrProces, proces_c.reclamant, proces_c.reclamat),
        dauneMorale(proces_c.dauneMorale), dauneMateriale(proces_c.dauneMateriale), nrMartori(proces_c.nrMartori) {}
    ~Proces_civil()
    {
        nrProces = 0;
        reclamant = "";
        reclamat = "";
        dauneMorale = 0;
        dauneMateriale = 0;
        nrMartori = 0;
        stadiu = 0;
    }
    int GetNrProces(){return  nrProces;}
    void setStadiuCivil(bool stadiu)
    {
        this->stadiu = stadiu;
    }
    bool getStadiu(){return stadiu;}

    friend std::istream& operator >>(std::istream& in,  Proces_civil& proces_c);
    friend std::ostream& operator <<(std::ostream& out, Proces_civil& proces_c);
    Proces_civil& operator=(const Proces_civil& proces_c)
    {
        nrProces = proces_c.nrProces;
        reclamant = proces_c.reclamant;
        reclamat = proces_c.reclamat;
        dauneMorale = proces_c.dauneMorale;
        dauneMateriale = proces_c.dauneMateriale;
        nrMartori = proces_c.nrMartori;
        stadiu = proces_c.stadiu;

        return *this;
    }
    void Afisare()
    {
        Proces::Afisare();
        cout<<"Daune morale: "<<dauneMorale<<"\nDaune materiale: "<<dauneMateriale<<"\nNumar martori: "<<nrMartori<<"\nStadiu: "<<stadiu<<endl;
    }

    istream &Citire(istream& in)
    {
        cout<<"Numar proces: ";
        in>>nrProces;
        cout<<"Reclamant: ";
        in>>reclamant;
        cout<<"Reclamat: ";
        in>>reclamat;
        cout<<"Daune morale: ";
        in>>dauneMorale;
        cout<<"Daune materiale: ";
        in>>dauneMateriale;
        cout<<"Numar martori: ";
        in>>nrMartori;

        if(nrMartori>5)
            stadiu=1;
        else
            stadiu=0;

        return in;
    }

        double taxaTimbru()
    {
        return (0.1*dauneMorale + 0.1*dauneMateriale);
    }

};

std::istream& operator >>(std::istream& in,  Proces_civil& proces_c)
{
    return proces_c.Citire(in);
}
std::ostream& operator <<(std::ostream& out, Proces_civil& proces_c)
{

    out<<"PROCES CIVIL:\nNumar proces: "<<proces_c.nrProces<<"\nReclamant: "<<proces_c.reclamant<<"\nReclamat:"<<proces_c.reclamat<<"\nDaune morale: "
    <<proces_c.dauneMorale<<"\nDaune materiale: "<<proces_c.dauneMateriale<<"\nNumar martori: "<<proces_c.nrMartori<<"\nStadiu: "<<proces_c.stadiu<<"\n";

    return out;
}



class Proces_penal: public Proces
{
    int dovezi;
    bool stadiu;
    static int s_nrProcesePenale;
public:
    Proces_penal(): Proces(), dovezi(0), stadiu(0) {s_nrProcesePenale++;}
    Proces_penal(int nr_proces, string nume1, string nume2, int Dovezi)
        :Proces(nr_proces, nume1, nume2)     //constructor parametrizat
    {
        dovezi=Dovezi;

        if(dovezi>25)
            stadiu=1;
        else
            stadiu=0;
        s_nrProcesePenale++;
    }
    Proces_penal(Proces_penal &proces_p)      //constructor de copiere
        : Proces(proces_p.nrProces, proces_p.reclamant, proces_p.reclamat), dovezi(proces_p.dovezi) {s_nrProcesePenale++;}
    ~Proces_penal()
    {
        nrProces = 0;
        reclamant = "";
        reclamat = "";
        dovezi = 0;
        stadiu = 0;

        s_nrProcesePenale--;
    }
    int GetNrProces(){return  nrProces;}
    void setStadiuPenal(bool stadiu)
    {
        this->stadiu = stadiu;
    }
    bool getStadiu(){return stadiu;}

     void Afisare()
    {
        Proces::Afisare();
        cout<<"Dovezi: "<<dovezi<<"\nStadiu: "<<stadiu<<endl;
    }

    istream &Citire(istream& in)
    {
        cout<<"Numar proces: ";
        in>>nrProces;
        cout<<"Reclamant: ";
        in>>reclamant;
        cout<<"Reclamat: ";
        in>>reclamat;
        cout<<"Dovezi: ";
        in>>dovezi;

        if(dovezi > 25)
            stadiu = 1;
        else
            stadiu = 0;

        return in;
    }
    friend std::istream& operator >>(std::istream& in,  Proces_penal& proces_p);
    friend std::ostream& operator <<(std::ostream& out, Proces_penal& proces_p);
    Proces_penal& operator=(const Proces_penal& proces_p)
    {
        nrProces = proces_p.nrProces;
        reclamant = proces_p.reclamant;
        reclamat = proces_p.reclamat;
        dovezi = proces_p.dovezi;
        stadiu = proces_p.stadiu;

        return *this;
    }
    static int GetNrProcesePenale() {return s_nrProcesePenale;}
};
int Proces_penal::s_nrProcesePenale = 0;


std::istream& operator >>(std::istream& in,  Proces_penal& proces_p)
{
    return proces_p.Citire(in);
}
std::ostream& operator <<(std::ostream& out, Proces_penal& proces_p)
{

    out<<"PROCES PENAL:\nNumar proces: "<<proces_p.nrProces<<"\nReclamant: "<<proces_p.reclamant<<"\nReclamat: "<<proces_p.reclamat
    <<"\nDovezi: "<<proces_p.dovezi<<"\nStadiu: "<<proces_p.stadiu<<"\n";

    return out;
}

Proces_civil taxaMaxima()
{
    Proces_civil proces_taxa_maxima;
    cout<<"Introduceti numarul de procese civile: ";
    int n;
    cin >> n;
    Proces_civil proces;
    for(int i=0;i<n;i++)
    {
        cin>>proces;
        if(proces.taxaTimbru() > proces_taxa_maxima.taxaTimbru())
            proces_taxa_maxima = proces;
    }
    return proces_taxa_maxima;
}

Proces * citireProces()
{
    int tipProces;
    Proces * proces;
    cout<<"\n1.Proces civil\n2.Proces penal\nIntroduceti tipul procesului: \n";

    cin >> tipProces;
    if(tipProces == 1) {
        Proces_civil *proces_c = new Proces_civil();
        proces_c -> Citire(cin);
        proces = proces_c;
    }
    else if(tipProces == 2) {
        Proces_penal *proces_p = new Proces_penal();
        proces_p -> Citire(cin);
        proces = proces_p;
    }
    else
        cout<<"Introduceti 1 sau 2.\n";

    return proces;
}

vector<Proces *> citesteNProcese()
{
    cout<<"Introduceti numarul de procese: ";
    int n;
    cin >> n;

    vector<Proces *> procese;

    for(int i=0; i<n; i++)
    {
        procese.push_back(citireProces());
    }

    return procese;
}

void OptiuniMeniu()
{
    cout<< "0. Oprire." <<endl;
    cout<< "1. Cititi un proces." <<endl;
    cout<< "2. Cititi un proces civil si afisati taxa de timbru." <<endl;
    cout<< "3. Cititi si memorati n procese." <<endl;
    cout<< "4. Afisati cele n procese." <<endl;
    cout<< "5. Afisati procesul civil cu taxa de timbru cea mai mare." <<endl;
    cout<< "6. Modificati stadiul procesului cu un anumit numar." <<endl;
    cout<< "7. Afisati stadiile proceselor." <<endl;
    cout<< "8. Stergeti procesul cu un anumit numar." <<endl;
    cout<< "9. Inserati un proces." <<endl;
    cout<< "10.Afisati numarul de procese penale."<<endl;
    cout<< endl;
}

void MeniuInteractiv()
{
    vector<Proces*> procese;
    cout<< "Alegeti o optiune: " <<endl;
    OptiuniMeniu();
    int optiune = 0;
    int stop = 0;

    cin>>optiune;
    while(optiune != stop)
    {
        if(optiune == 1)
        {
            Proces* proces = citireProces();
            proces->Afisare();
        }
        else if(optiune == 2)
        {
            Proces_civil proces_c;
            cin>>proces_c;
            cout<<"Taxa de timbru: "<<proces_c.taxaTimbru()<<endl;
        }
        else if(optiune == 3)
        {
            for(int i=0; i<procese.size(); i++) delete procese[i];
            procese = citesteNProcese();
            cout<<endl;
        }
        else if(optiune==4)
        {
            for(int i=0;i<procese.size();i++)
            {
                procese[i]->Afisare();
                cout<<endl;
            }
        }
        else if(optiune == 5)
        {
            double taxaMax=0;
            Proces_civil* proces_taxa_maxima;
            for(int i=0;i<procese.size();i++)
                if(Proces_civil *proces_c = dynamic_cast<Proces_civil *>(procese[i]))
                {
                    if(proces_c->taxaTimbru() > taxaMax)
                    {
                        proces_taxa_maxima = proces_c;
                        taxaMax=proces_c->taxaTimbru();
                    }
                }
            cout<<*proces_taxa_maxima<<"Taxa timbru: "<<taxaMax<<endl;;
        }
        else if(optiune == 6)
        {
            int nr;
            bool s;
            cout<<"Introduceti numarul procesului: ";
            cin>>nr;
            cout<<"\nIntroduceti stadiul: ";
            cin>>s;
            for(int i=0;i<procese.size();i++)
                if(nr == procese[i]->GetNrProces())
                    if(Proces_civil *proces_c = dynamic_cast<Proces_civil *>(procese[i]))
                    {
                        proces_c -> setStadiuCivil(s);
                    }
                    else if(Proces_penal *proces_p = dynamic_cast<Proces_penal *>(procese[i]))
                    {
                        proces_p -> setStadiuPenal(s);
                    }
        }
        else if(optiune == 7)
        {
            for(int i=0;i<procese.size();i++)
                if(Proces_civil *proces_c = dynamic_cast<Proces_civil *>(procese[i]))
                    {
                        cout<<"Stadiul procesului "<<proces_c->GetNrProces()<<" este: "<<proces_c -> getStadiu()<<endl;
                    }
                else if(Proces_penal *proces_p = dynamic_cast<Proces_penal *>(procese[i]))
                    {
                        cout<<"Stadiul procesului "<<proces_p->GetNrProces()<<" este: "<< proces_p -> getStadiu()<<endl;
                    }
        }
        else if(optiune == 8)
        {
            int nr;
            cout<<"Introduceti numarul procesului de sters: ";
            cin>>nr;
            for(int i=0;i<procese.size();i++)
                if(nr == procese[i]->GetNrProces())
                {
                    delete procese[i];
                    procese.erase(procese.begin() + i);
                }
        }
        else if(optiune == 9)
        {
            Proces * proces = citireProces();
            procese.push_back(proces);
        }
        else if(optiune == 10)
        {
            cout<<"Numarul proceselor penale: "<<Proces_penal::GetNrProcesePenale()<<endl;
        }
        else
            cout<<"Optiunea nu exista!"<<endl;
        OptiuniMeniu();
        cin>>optiune;
    }
    for(int i=0; i<procese.size(); i++) delete procese[i];
}

void downcasting_and_static()
{
    Proces *proces = new Proces_civil(1,"Ana","Cristina",2.5,7,3);
    //Proces *proces = new Proces_penal(2,"Ioana","Maria",10);


    if(Proces_civil *proces_c = dynamic_cast<Proces_civil *>(proces))
    {
        proces_c -> Afisare();
    }

    if(Proces_penal *proces_p = dynamic_cast<Proces_penal *>(proces))
    {
        proces_p -> Afisare();
    }

    cout<<"Numarul proceselor penale: "<<Proces_penal::GetNrProcesePenale();
}

int main()
{
    //downcasting_and_static();
    MeniuInteractiv();
    return 0;
}
