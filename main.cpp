#include <iostream>
#include <memory>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

class Clinica
{
    private:
        Clinica() {}
        static Clinica _clinica;
        string Nume="Clinica";
    public:
        Clinica(const Clinica&) = delete;
        static Clinica& get_clinica()
        {
            return _clinica;
        }
        string NumeClinica()
        {
            return Nume;
        }
};

Clinica Clinica::_clinica;


template<typename T>
class Gestiune
{
    private:
        vector<T> v;
    public:
        void Construire(vector<T> aux)
        {
            for(auto i=aux.begin();i!=aux.end();i++)
            {
                v.push_back(*i);
            }
        }
        void Afisare()
        {
            for(auto it=v.begin();it!=v.end();it++)
                cout<<(**it)<<" ";
            cout<<"\n";
        }
        int Cautare(T x)
        {
            int semafor=0;
            for(auto it=v.begin();it!=v.end()&&semafor!=1;it++)
                if((*it)==x)
                    return 1;
            return 0;
        }
        void Stergere(T x)
        {
            int semafor=0;
            for(auto it=v.begin();it!=v.end()&&semafor!=1;it++)
                if((*it)==x)
                {
                    v.erase(it);
                    semafor=1;
                }
            if(semafor==0)
                cout<<"Valoarea cautata nu este inregistrata."<<"\n";
        }

};

class Afisare
{
    private:
        virtual string getClassName()=0;
        virtual void AfisareDate()=0;
    public:
        virtual ~Afisare() {}
};

class Cadru_medical
{
    protected:
        string Cod;
        string Adresa_email;
        string Telefon;
        string Tura_noapte;
        int Ani_vechime;
        double Salariu;
    public:
        //////////////getteri/////////////////
        string getCod() const
        {
            return Cod;
        }
        string getTelefon() const
        {
            return Telefon;
        }
        string getAdresa_email() const
        {
            return Adresa_email;
        }
        string getTura_noapte() const
        {
            return Tura_noapte;
        }
        int getAni_vechime() const
        {
            return Ani_vechime;
        }
        double getSalariu() const
        {
            return Salariu;
        }
        ////////////////setteri///////////////
        void setCod(string cod)
        {
            Cod=cod;
        }
        void setTelefon(string telefon)
        {
            Telefon=telefon;
        }
        void setAdresa_email(string adresa_email)
        {
            Adresa_email=adresa_email;
        }
        void setTura_noapte(string tura_noapte)
        {
            Tura_noapte=tura_noapte;
        }
        void setAniVechime(int ani_vechime)
        {
            Ani_vechime=ani_vechime;
        }
        void setSalariu(double salariu)
        {
            if(salariu<0)
                throw "Nu se poate inregistra acest salariu";
            Salariu=salariu;
        }
        /////////////////constructori/////////////////
        Cadru_medical() : Cod("cod"), Adresa_email("adresa_email"), Telefon("telefon"),Tura_noapte("nu"),Ani_vechime(0),Salariu(0){}
        Cadru_medical(string cod, string adresa_email, string telefon, string tura_noapte, int ani_vechime, double salariu) :
        Cod(cod), Adresa_email(adresa_email), Telefon(telefon), Tura_noapte(tura_noapte),Ani_vechime(ani_vechime)
        {
            if(salariu<0)
                throw "Nu se poate inregistra acest salariu";
            Salariu=salariu;
        }
        //////////////alte metode/////////////////////
        virtual void Marire_salariu()
        {
            if(Ani_vechime%5==0)
                cout<<"Salariul creste cu 15% pentru medici si cu 10% pentru asistenti medicali"<<"\n";
            else
                cout<<"Salariul nu se mareste"<<"\n";
        }
        virtual ~Cadru_medical() {}
};


class Persoana
{
    protected:
        string Nume;
        string Prenume;
        string Sex;
        int Varsta;
    public:
        string getNume() const
        {
            return Nume;
        }
        string getPrenume() const
        {
            return Prenume;
        }
        string getSex() const
        {
            return Sex;
        }
        int getVarsta() const
        {
            return Varsta;
        }
        void setNume(string nume)
        {
            Nume=nume;
        }
        void setPrenume(string prenume)
        {
            Prenume=prenume;
        }
        void setSex(string sex)
        {
            Sex=sex;
        }
        void setVarsta(int varsta)
        {
            if(varsta<0)
                throw "Nu se poate inregistra aceasta varsta";
            Varsta=varsta;
        }
        Persoana() : Nume("nume"), Prenume("prenume"), Sex("sex"), Varsta(0){}
        Persoana(string nume, string prenume, string sex, int varsta) : Nume(nume), Prenume(prenume), Sex(sex)
        {
            if(varsta<0)
                throw "Nu se poate inregistra aceasta varsta";
        }
        virtual void Afisare_profil()
        {
            cout<<"Nume:"<<Nume<<" Prenume:"<<Prenume<<" Sex:"<<Sex<<" Varsta:"<<Varsta<<"\n";
        }
        virtual ~Persoana() {}

};

class Medic : public Cadru_medical, public Persoana
{
    private:
        string Specialitate;
        string Grad;
        static int n;
        static int suma;
        static double medie;
    public:
        /////getteri//////
        string getSpecialitate() const
        {
            return Specialitate;
        }
        string getGrad() const
        {
            return Grad;
        }
        /////setteri//////
        void setSpecialitate(string specialitate)
        {
            Specialitate=specialitate;
        }
        void setGrad(string grad)
        {
            Grad=grad;
        }
        ////constructori//////
        Medic() : Cadru_medical() , Persoana()
        {
            Specialitate="specialitate";
            Grad="grad";
            n++;
            suma=suma+Salariu;
        }
        Medic(string cod, string telefon, string adresa_email, double salariu, string nume, string prenume, string sex, int varsta, string specialitate, string grad, string tura_noapte, int ani_vechime)
        : Cadru_medical(cod, telefon, adresa_email,tura_noapte, ani_vechime, salariu), Persoana(nume, prenume, sex, varsta)
        {
            Specialitate=specialitate;
            Grad=grad;
            n++;
            suma=suma+Salariu;
        }
        //////metode//////////
        bool operator ==(const Medic &m) const
        {
            if((Nume==m.Nume) && (Prenume==m.Prenume) && (Sex==m.Sex) && (Cod==m.Cod))
                return true;
            else
                return false;
        }
        void operator =(const Medic &m)
        {
            Nume=m.Nume;
            Prenume=m.Prenume;
            Cod=m.Cod;
            Sex=m.Sex;
            Telefon=m.Telefon;
            Varsta=m.Varsta;
            Specialitate=m.Specialitate;
            Grad=m.Grad;
            Salariu=m.Salariu;
        }
        void Afisare_profil()
        {
            cout<<"Nume:"<<Nume<<" Prenume:"<<Prenume<<" Cod:"<<Cod<<" Sex:"<<Sex<<" Varsta:"<<Varsta<<" Specialitate:"<<Specialitate<<" Grad:"<<Grad<<"\n";
        }
        void Marire_salariu()
        {
            if(Ani_vechime%5==0)
                {
                    cout<<"Salariul vechi este de "<<Salariu<<"\n";
                    Salariu=Salariu+Salariu*15/100;
                    cout<<"Noul salariu este de "<<Salariu<<"\n";
                }
            else
                cout<<"Salariul nu se mareste"<<"\n";
        }
        //////metode statice//////
        static int Numar_medici()
        {
            return n;
        }
        static void Medie_salarii()
        {
            medie=suma/n;
            cout<<medie<<"\n";
        }
        ~Medic() {}
        friend ostream & operator << (ostream &out, const Medic &m);

};

int Medic::n=0;
int Medic::suma=0;
double Medic::medie=0;

ostream & operator << (ostream & out, const Medic &m)
{
    out<<"Nume:"<<m.Nume<<" "<<m.Prenume<<"\n";
    return out;
}

class Asistent_medical : protected Cadru_medical, public Persoana
{
    private:
        string Grad;
    public:
        /////getteri//////
        string getGrad() const
        {
            return Grad;
        }
        //////setteri////////
        void setGrad(string grad)
        {
            Grad=grad;
        }
        ////constructori/////////
        Asistent_medical() : Cadru_medical(), Persoana()
        {
            Grad="grad";
        }
        Asistent_medical(string cod, string telefon, string adresa_email, double salariu, string nume, string prenume, string sex, int varsta, string grad, string tura_noapte, int ani_vechime)
        : Cadru_medical(cod, telefon, adresa_email,tura_noapte, ani_vechime, salariu), Persoana(nume, prenume, sex, varsta)
        {
            Grad=grad;
        }
        /////alte metode/////
        void operator =(const Asistent_medical &a)
        {
            Nume=a.Nume;
            Prenume=a.Prenume;
            Sex=a.Sex;
            Telefon=a.Telefon;
            Varsta=a.Varsta;
            Salariu=a.Salariu;
            Grad=a.Grad;
        }
        void Afisare_profil()
        {
            cout<<"Nume:"<<Nume<<" Prenume:"<<Prenume<<" Varsta:"<<Varsta<<" Grad:"<<Grad<<"\n";
        }
        void Marire_salariu()
        {
            if(Ani_vechime%5==0)
                {
                    cout<<"Salariul vechi este de "<<Salariu<<"\n";
                    Salariu=Salariu+Salariu*10/100;
                    cout<<"Noul salariu este de "<<Salariu<<"\n";
                }
            else
                cout<<"Salariul nu se mareste"<<"\n";
        }
       ~Asistent_medical() {}

};


class Pacient : public Persoana
{
    private:
        string Telefon;
        string Asigurare_medicala;
        string Abonament;
        double Greutate;
        double Inaltime;
        int Cod;
        static vector<int> coduri;
    public:
        ///////getteri////////
        string getTelefon() const
        {
            return Telefon;
        }
        int getCod() const
        {
            return Cod;
        }
        string getAsigurare_medicala() const
        {
            return Asigurare_medicala;
        }
        string getAbonament() const
        {
            return Abonament;
        }
        double getGreutate() const
        {
            return Greutate;
        }
        double getInaltime() const
        {
            return Inaltime;
        }
        static void Afis_cod()
        {
            for(auto i=coduri.begin();i!=coduri.end();i++)
                cout<<(*i)<<" ";
        }
        /////setteri///////
        void setTelefon(string telefon)
        {
            Telefon=telefon;
        }
        void setCod(int cod)
        {
            Cod=cod;
        }
        void setAsigurare_medicala(string asigurare_medicala)
        {
            Asigurare_medicala=asigurare_medicala;
        }
        void setAbonament(string abonament)
        {
            Abonament=abonament;
        }
        void setGreutate(double greutate)
        {
            Greutate=greutate;
        }
        void setInaltime(double inaltime)
        {
            Inaltime=inaltime;
        }
        ///////constructori////////
        Pacient() : Persoana()
        {
            Telefon="telefon";
            Cod=0;
            Asigurare_medicala="asigurare_medicala";
            Abonament="abonament";
            Greutate=0;
            Inaltime=0;
        }
        Pacient(string nume, string prenume, string sex, int varsta, string telefon, string asigurare_medicala, string abonament, double greutate, double inaltime)
        : Persoana(nume, prenume, sex, varsta)
        {
            Telefon=telefon;
            Asigurare_medicala=asigurare_medicala;
            Abonament=abonament;
            Greutate=greutate;
            Inaltime=inaltime;
            std::random_device rd;
            std::uniform_int_distribution<int> dist(1,10000);
            int sem=0;
            while(sem==0)
            {
                int aux=1;
                int nr=dist(rd);
                for(auto i=coduri.begin();i!=coduri.end();i++)
                    if(nr==(*i))
                        aux=0;
                if(aux==1)
                    {
                        sem=1;
                        coduri.push_back(nr);
                        Cod=nr;
                    }
            }
        }
        ///////alte metode//////
        bool Verif_asig()
        {
            if (Asigurare_medicala==string("Asigurat"))
                return true;
            else
                return false;
        }
        bool Verif_abonament()
        {
            if(Abonament==string("Abonat"))
                return true;
            else
                return false;
        }
        void operator = (const Pacient &p)
        {
            Nume=p.Nume;
            Prenume=p.Prenume;
            Sex=p.Sex;
            Telefon=p.Telefon;
            Varsta=p.Varsta;
            Cod=p.Cod;
            Asigurare_medicala=p.Asigurare_medicala;
            Abonament=p.Abonament;
            Greutate=p.Greutate;
            Inaltime=p.Inaltime;
        }
        void Afisare_profil()
        {
            cout<<"Nume:"<<Nume<<" Prenume:"<<Prenume<<" Cod:"<<Cod<<" Asigurare medicala:"<<Asigurare_medicala<<" Abonament:"<<Abonament<<"\n";
        }
        static void Sortare_coduri()
        {
            std::sort(coduri.begin(),coduri.end());
        }
        ~Pacient() {}
};

vector<int> Pacient::coduri;

class Medic_existent : public exception
{
    private:
        string Nume_medic;
    public:
        void setNume_medic(string nume_medic)
        {
            Nume_medic=nume_medic;
        }
        string getNume_medic()
        {
            return Nume_medic;
        }

};

class Salon
{
    private:
        int Ani_utilizare;
        double Pret_intretinere;
        double Pret_materiale;
        vector<Pacient> Pacienti;
        vector<Medic> Medici;
    protected:
        static int Id;
        int Cod;
        int Viz;
        void Afisare_istoric_pacienti()
        {
            for (auto i = Pacienti.begin(); i != Pacienti.end(); ++i)
                cout << (*i).getNume() << " ";
            cout<<"\n";
        }
        void Afisare_istoric_medici()
        {
            for (auto i = Medici.begin(); i != Medici.end(); ++i)
                cout << (*i).getNume() << " ";
            cout<<"\n";
        }

    public:
        void Adaugare_istoric_pacienti(Pacient p)
        {
            Pacienti.push_back(p);
        }
        void Adaugare_istoric_medici(Medic m)
        {
            int semafor=0;
            for(auto i = Medici.begin(); i != Medici.end(); ++i)
                if(m==*i)
                    semafor=1;
            if(semafor==1)
            {
                Medic_existent* medic=new Medic_existent();
                medic->setNume_medic(m.getNume());
                throw medic;
            }
            Medici.push_back(m);
        }
        int getAni_utilizare()
        {
            return Ani_utilizare;
        }
        double getPret_intretinere()
        {
            return Pret_intretinere;
        }
        double getPret_materiale()
        {
            return Pret_materiale;
        }
        Salon(): Ani_utilizare(0), Pret_intretinere(0), Pret_materiale(0) {Cod=Id; Id++;}
        Salon(int ani_utilizare, double pret_intretinere, double pret_materiale): Ani_utilizare(ani_utilizare)
        {
            if(pret_intretinere<0)
                throw "Nu se poate inregistra acest pret";
            if(pret_materiale<0)
                throw "Nu se poate inregistra acest pret";
            Pret_intretinere=pret_intretinere;
            Pret_materiale=pret_materiale;
            Cod=Id;
            Id++;
        }
        virtual double Calcul_intretinere()=0;
        virtual void Numar_utilizari()=0;
        virtual double Proportie_utilizari_costuri()=0;
        virtual void Renovari()=0;
        virtual void Descriere_utilizare()=0;
        virtual ~Salon() {}
};

int Salon::Id=0;

class Cabinet : public Salon
{
    private:
        string Specializare;
    public:
        Cabinet() : Salon()
        {
            Specializare="specializare";
            Viz=0;
        }
        Cabinet(string specializare,int ani_utilizare, double pret_intretinere, double pret_materiale) : Salon(ani_utilizare,pret_intretinere,pret_materiale)
        {
            Specializare=specializare;
            Viz=0;
        }
        double Calcul_intretinere()
        {
            double suma;
            suma=getPret_intretinere()+getPret_materiale();
            return suma;
        }
        void Numar_utilizari()
        {
            Viz++;
        }
        double Proportie_utilizari_costuri()
        {
            double suma, proportie;
            suma=getPret_intretinere()+getPret_materiale();
            proportie=suma/Viz;
            return proportie;
        }
        void Renovari()
        {
            if(Viz==10000)
                {
                    cout<<"Cabinetul are nevoie de renovari"<<"\n";
                    Viz=0;
                }
            else
                cout<<"Cabinetul nu are nevoie de renovari"<<"\n";
        }
        void Descriere_utilizare()
        {
            cout<<"Cabinetul cu Id-ul "<<Id<<" are specializarea "<<Specializare<<" si serveste la efectuarea consultatiilor medicale."<<"\n";
        }
        void Afisare_istoric()
        {
            cout<<"Pacienti:"<<"\n";
            Afisare_istoric_pacienti();
            cout<<"Medici:"<<"\n";
            Afisare_istoric_medici();
        }
        ~Cabinet() {}

};

class Sala_internare : public Salon
{
    private:
        string Specializare;
        int Capacitate;
        int Numar_max_zile;
        double Pret_intretinere_pacient;
    public:
        Sala_internare() : Salon()
        {
            Specializare="specializare";
            Capacitate=0;
            Numar_max_zile=0;
            Pret_intretinere_pacient=0;
            Viz=0;
        }
        Sala_internare(string specializare, int capacitate, int numar_max_zile, double pret_intretinere_pacient,int ani_utilizare, double pret_intretinere, double pret_materiale):
    Salon(ani_utilizare,pret_intretinere,pret_materiale)
    {
        Specializare=specializare;
        Capacitate=capacitate;
        Numar_max_zile=numar_max_zile;
        Pret_intretinere_pacient=pret_intretinere_pacient;
        Viz=0;
    }
        double Calcul_intretinere()
        {
            double suma;
            suma=getPret_intretinere()+getPret_materiale()+Pret_intretinere_pacient;
            return suma;
        }
        void Numar_utilizari()
        {
            Viz=Viz+Numar_max_zile;
        }
        double Proportie_utilizari_costuri()
        {
            double suma, proportie;
            suma=getPret_intretinere()+getPret_materiale()+Pret_intretinere_pacient;
            proportie=suma/Viz;
            return proportie;
        }
        void Renovari()
        {
            if(Viz==100)
                {
                    cout<<"Salonul are nevoie de renovari"<<"\n";
                    Viz=0;
                }
            else
                cout<<"Salonul nu are nevoie de renovari"<<"\n";
        }
        void Descriere_utilizare()
        {
            cout<<"Cabinetul cu Id-ul "<<Id<<" are specializarea "<<Specializare<<" si serveste la internarea pacientilor cu scopul tratarii afectiunilor de sanatate."<<"\n";
        }
        ~Sala_internare() {}
};


class Vizita_medicala
{
    private:
        string Data;
        Medic M;
    protected:
        double Pret;
        Pacient P;
    public:
        //////////getteri/////////
        string getData() const
        {
            return Data;
        }
        double getPret() const
        {
            return Pret;
        }
        /////////setteri//////////
        void setData(string data)
        {
            Data=data;
        }
        void setPret(double pret)
        {
            Pret=pret;
        }
        ///////constructori/////////
        Vizita_medicala() : Data("data"), Pret(0){}
        Vizita_medicala(string data ,Medic m,double pret, Pacient p) : Data(data), M(m), Pret(pret), P(p){}
        ///////metode//////////////
        virtual void Calcul_pret()
        {
            if(P.getAsigurare_medicala()=="asigurat")
                Pret=0;
            else
                if(P.getAbonament()=="abonat")
                    Pret=Pret-Pret*30/100;
            cout<<"Pretul este "<<Pret<<" ron"<<"\n";
        }
        virtual ~Vizita_medicala() {}

};

class Consultatie : public Vizita_medicala
{
    private:
        string Diagnostic;
        string Ora;
        Cabinet C;
    public:
        /////getteri//////
        string getDiagnostic() const
        {
            return Diagnostic;
        }
        string getOra() const
        {
            return Ora;
        }
        /////setteri//////
        void setDiagnostic(string diagnostic)
        {
            Diagnostic=diagnostic;
        }
        void setOra(string ora)
        {
            Ora=ora;
        }
        ////constructori////////
        Consultatie() : Vizita_medicala()
        {
            Diagnostic="diagnostic";
            Pret=0;
        }
        Consultatie(string data, string ora, string diagnostic, double pret, Medic m, Cabinet c, Pacient p) : Vizita_medicala(data, m,pret, p)
        {
            Diagnostic=diagnostic;
            Ora=ora;
            C=c;
        }
        ///////metode/////////
        void Calcul_pret()
        {
            if(P.getAsigurare_medicala()=="asigurat")
                Pret=0;
            else
                if(P.getAbonament()=="abonat")
                    Pret=Pret-Pret*30/100;
            cout<<"Pretul este "<<Pret<<" ron"<<"\n";
        }
        ~Consultatie() {}
};

class Internare : public Vizita_medicala
{
    private:
        string Data_externare;
        int Nr_zile;
        Sala_internare I;
    public:
        /////////getteri////////
        string getData_externare() const
        {
            return Data_externare;
        }
        ///////setteri//////////
        void setData_externare(string data_externare)
        {
            Data_externare=data_externare;
        }
        void setPret(double pret)
        {
            Pret=pret;
        }
        /////constructori////////
        Internare() : Vizita_medicala()
        {
            Data_externare="data_externare";
            Nr_zile=0;
        }
        Internare(string data, string data_externare, double pret, int nr_zile, Medic m, Sala_internare i, Pacient p) : Vizita_medicala(data, m, pret, p)
        {
            Data_externare=data_externare;
            Nr_zile=nr_zile;
            I=i;
        }
        void Calcul_pret()
        {
            if(P.getAsigurare_medicala()=="asigurat")
                Pret=0;
            else
                if(P.getAbonament()=="abonat")
                    Pret=Pret-Pret*30/100;
            Pret=Pret*Nr_zile;
            cout<<"Pretul este "<<Pret<<" ron"<<"\n";
        }
        ~Internare() {}
};

class Analize_medicale : public Vizita_medicala
{
    private:
        string Tip_analize;
        string Ora;
        double Nr_probe;
    public:
        /////getteri//////
        string getTip_analize() const
        {
            return Tip_analize;
        }
        //////setteri/////////
        void setTip_analize(string tip_analize)
        {
            Tip_analize=tip_analize;
        }
        /////constructori///////
        Analize_medicale() : Vizita_medicala()
        {
            Tip_analize="tip_analize";
            Nr_probe=0;
        }
        Analize_medicale(string data, string ora, string tip_analize, double pret, int nr_probe, Medic m, Pacient p) : Vizita_medicala(data, m, pret, p)
        {
            Tip_analize=tip_analize;
            Ora=ora;
            Nr_probe=nr_probe;
        }
        ///////metode///////
        void Calcul_pret()
        {
            if(P.getAsigurare_medicala()=="asigurat")
                Pret=0;
            else
                if(P.getAbonament()=="abonat")
                    Pret=Pret-Pret*30/100;
            Pret=Pret*Nr_probe;
            cout<<"Pretul este "<<Pret<<" ron"<<"\n";
        }
        ~Analize_medicale() {}
};

class Departament : public Afisare
{
    private:
        vector<Medic>medici;
    public:
        int getNr_medici() const
        {
            return medici.size();
        }
        ~Departament()
        {
        }
        void Marire_salariu()
        {
            for(auto i=medici.begin();i!=medici.end();i++)
            {
                double salariu_nou=(*i).getSalariu()+((*i).getSalariu()*10/100);
                (*i).setSalariu(salariu_nou);
            }
        }
        double Medie_salariu()
        {
            double sum=0;
            for(auto i=medici.begin();i!=medici.end();i++)
            {
                sum=sum+(*i).getSalariu();
            }
            sum=sum/medici.size();
            return sum;

        }
        void Adaugare_medic(Medic m)
         {
            for(auto i=medici.begin();i!=medici.end();i++)
            {
                if(*i==m)
                    {
                        Medic_existent* medic=new Medic_existent();
                        medic->setNume_medic(m.getNume());
                        throw medic;
                    }
            }
            medici.push_back(m);
         }
        void Eliminare_medic(Medic m)
        {
            int semafor=0;
            if(medici.size()>=1)
            {
                for(auto i=medici.begin();i!=medici.end()&&semafor==0;i++)
                {
                    if(*i==m)
                    {
                        medici.erase(i);
                        semafor=1;
                    }
                }
            }
        }
        void Afisare_medici()
        {
            for(auto i=medici.begin();i!=medici.end();i++)
                cout<<(*i).getNume()<<"\n";
        }
        string getClassName() override
        {
            return "Departament";
        }
        void AfisareDate() override
        {
            cout<<"In departament lucreaza "<<medici.size()<<" medici."<<"\n";
        }
};

template<typename T>
void eliberare_memorie(vector<T*>&v)
{
    for(auto it=v.begin();it!=v.end();it++)
        {
            delete *it;
        }
    v.clear();
}
template<>
void eliberare_memorie(vector<Medic*>&v)
{
    for(auto it=v.begin();it!=v.end();it++)
        {
            (**it).setTura_noapte("liber");
        }
    v.clear();
}

int main()
{
    ///singleton
    cout<<Clinica::get_clinica().NumeClinica()<<"\n";
    ///evidentiere random prin generare de coduri distincte pentru pacienti
    Pacient p1("Andrei", "Maria", "feminin",20, "0766666654", "asigurat", "neabonat", 50, 1.60);
    Pacient p2("Busoi", "Alexandru", "masculin",39, "0755446565", "neasigurat", "abonat", 80, 1.70);
    Pacient p3("Marcu", "Iulia", "feminin",40, "0744342343", "asigurat", "abonat", 45, 1.55);
    Pacient p4("Iliescu", "Tania", "feminin",35, "0765334234", "asigurat", "neabonat", 70, 1.65);
    Pacient p5("Zarnescu","Matei","masculin",60,"0788987656","asigurat","neabonat",0,0);
    Pacient p6("Mircea","Diana","feminin",39,"0756453423","neasigurat","abonat",0,0);
    cout<<p1.getCod()<<"\n";
    cout<<p2.getCod()<<"\n";
    cout<<p3.getCod()<<"\n";
    cout<<p4.getCod()<<"\n";
    cout<<p5.getCod()<<"\n";
    cout<<p6.getCod()<<"\n";
    Pacient::Afis_cod();
    cout<<"\n";
    Pacient::Sortare_coduri();
    Pacient::Afis_cod();
    cout<<"\n";
    ///smart pointers
    ///unique pointers
    vector<unique_ptr<Pacient>> pacienti;
    pacienti.emplace_back(make_unique<Pacient>(p1));
    pacienti.emplace_back(make_unique<Pacient>(p2));
    pacienti.emplace_back(make_unique<Pacient>(p3));
    pacienti.emplace_back(make_unique<Pacient>(p4));
    pacienti.emplace_back(make_unique<Pacient>(p5));
    for(auto i=pacienti.begin();i!=pacienti.end();i++)
        cout<<(**i).getNume()<<" ";
    cout<<"\n";
    ///shared pointers
    Cabinet c1("Dermatologie",5,100,50);
    Cabinet c2("Oftalmologie",10,200,300);
    Cabinet c3("Pediatrie",8,100,100);
    Cabinet c4("Cardiologie",7,200,200);
    Cabinet c5("Medicina_interna",10,100,150);
    Sala_internare si1("Cardiologie",3,100,200,10,200,300);
    Sala_internare si2("Cardiologie",2,150,300,15,200,300);
    Sala_internare si3("Medicina_interna",2,175,200,5,300,300);
    Sala_internare si4("Medicina_interna",1,100,300,10,250,250);
    Sala_internare si5("Oftalmologie",3,75,100,5,300,300);
    vector<shared_ptr<Salon>> saloane;
    saloane.emplace_back(make_shared<Cabinet>(c1));
    saloane.emplace_back(make_shared<Cabinet>(c2));
    saloane.emplace_back(make_shared<Cabinet>(c3));
    saloane.emplace_back(make_shared<Cabinet>(c4));
    saloane.emplace_back(make_shared<Cabinet>(c5));
    saloane.emplace_back(make_shared<Sala_internare>(si1));
    saloane.emplace_back(make_shared<Sala_internare>(si2));
    saloane.emplace_back(make_shared<Sala_internare>(si3));
    saloane.emplace_back(make_shared<Sala_internare>(si4));
    saloane.emplace_back(make_shared<Sala_internare>(si5));
    for(auto i=saloane.begin();i!=saloane.end();i++)
    {
        cout<<(**i).Calcul_intretinere()<<"\n";
        (**i).Renovari();
    }
    ///template
    Medic m1("001","0711111111","@",4000,"Aron","Marta","feminin",40,"oftalmologie","specialist","liber",10);
    Medic m2("002","0788888888","@",4500,"Marcu","Maria","feminin",30,"oftalmologie","specialist","liber",5);
    Medic m3("003","0799999999","@",5000,"Pavel","Iuliana","feminin",55,"dermatologie","specialist","liber",15);
    Medic m4("004","0722222222","@",6000,"Matei","Pavel","masculin",28,"dermatologie","specialist","liber",3);
    Medic m5("005","0733333333","@",3000,"Barbu","Alexandru","masculin",39,"pediatrie","primar","liber",17);
    Medic m6("006","0744444444","@",4400,"Constantin","Diana","feminin",35,"pediatrie","specialist","liber",5);
    Medic m7("007","0755555555","@",5000,"Sandu","Raluca","feminin",47,"chirurgie","specialist","liber",20);
    Medic m8("008","0766666666","@",5500,"Alecu","Cristian","masculin",57,"chirurgie","specialist","liber",20);
    Medic m9("009","0777777777","@",3500,"Moise","Tania","feminin",34,"infectioase","primar","liber",7);
    Medic m10("010","0723333333","@",6500,"Eni","Bogdan","masculin",60,"infectioase","specialist","liber",25);
    vector<Medic*> medici_tura_noapte;
    medici_tura_noapte.emplace_back(&m1);
    medici_tura_noapte.emplace_back(&m2);
    medici_tura_noapte.emplace_back(&m3);
    medici_tura_noapte.emplace_back(&m4);
    medici_tura_noapte.emplace_back(&m5);
    medici_tura_noapte.emplace_back(&m6);
    medici_tura_noapte.emplace_back(&m7);
    medici_tura_noapte.emplace_back(&m8);
    medici_tura_noapte.emplace_back(&m9);
    medici_tura_noapte.emplace_back(&m10);
    for(auto i=medici_tura_noapte.begin();i!=medici_tura_noapte.end();i++)
    {
        (**i).setTura_noapte("ocupat");
    }
    Gestiune<Medic*> t;
    t.Construire(medici_tura_noapte);
    t.Afisare();
    if(t.Cautare(&m1)==1)
        cout<<"Medicul lucreaza in tura de noapte"<<"\n";
    else
        cout<<"Medicul nu lucreaza in tura de noapte"<<"\n";
    cout<<m1.getTura_noapte()<<"\n";
    eliberare_memorie(medici_tura_noapte);
    cout<<m1.getTura_noapte()<<"\n";
    return 0;

}

