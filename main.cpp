#include <iostream>
#include <vector>
#include <exception>

using namespace std;

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
        virtual void Spor_tura_noapte()
        {
            if(Tura_noapte=="da")
                cout<<"Cadrul medical cu codul "<<Cod<<" lucreaza in tura de noapte, deci primeste un spor de 10% daca este asistent medical si de 20% daca este medic"<<"\n";
            else
                cout<<"Cadrul medical cu codul "<<Cod<<" nu lucreaza in tura de noapte"<<"\n";
        }
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
        /////////////getteri//////////////
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
        ///////////setteri////////////////
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
        /////////////constructori//////////
        Persoana() : Nume("nume"), Prenume("prenume"), Sex("sex"), Varsta(0){}
        Persoana(string nume, string prenume, string sex, int varsta) : Nume(nume), Prenume(prenume), Sex(sex)
        {
            if(varsta<0)
                throw "Nu se poate inregistra aceasta varsta";
        }
        ////////////alte metode////////////
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
            cout<<"Medic inregistrat!"<<"\n";
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
        void Spor_tura_noapte()
        {
            if(Tura_noapte=="da")
                {
                    double spor=Salariu*20/100;
                    cout<<"Medicul "<<Nume<<" "<<Prenume<<" are un spor de "<<spor<<"\n";
                }
            else
                cout<<"Medicul "<<Nume<<" "<<Prenume<<" nu lucreaza in tura de noapte"<<"\n";
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
        static void Numar_medici()
        {
            cout<<"Numar medici:"<<n<<"\n";
        }
        static void Medie_salarii()
        {
            medie=suma/n;
            cout<<medie<<"\n";
        }
        ~Medic() {}

};

int Medic::n=0;
int Medic::suma=0;
double Medic::medie=0;

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
        void Spor_tura_noapte()
        {
            if(Tura_noapte=="da")
                {
                    double spor=Salariu*10/100;
                    cout<<"Asistentul medical "<<Nume<<" "<<Prenume<<" are un spor de "<<spor<<"\n";
                }
            else
                cout<<"Asistentul medical "<<Nume<<" "<<Prenume<<" nu lucreaza in tura de noapte"<<"\n";
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
        string Cod;
        string Asigurare_medicala;
        string Abonament;
        double Greutate;
        double Inaltime;
    public:
        ///////getteri////////
        string getTelefon() const
        {
            return Telefon;
        }
        string getCod() const
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
        /////setteri///////
        void setTelefon(string telefon)
        {
            Telefon=telefon;
        }
        void setCod(string cod)
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
            Cod="cod";
            Asigurare_medicala="asigurare_medicala";
            Abonament="abonament";
            Greutate=0;
            Inaltime=0;
        }
        Pacient(string nume, string prenume, string sex, int varsta, string telefon, string cod, string asigurare_medicala, string abonament, double greutate, double inaltime)
        : Persoana(nume, prenume, sex, varsta)
        {
            Telefon=telefon;
            Cod=cod;
            Asigurare_medicala=asigurare_medicala;
            Abonament=abonament;
            Greutate=greutate;
            Inaltime=inaltime;
            cout<<"Pacientul a fost inregistrat!"<<"\n";
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
        ~Pacient() {}
};

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
                    cout<<"Cabinetul are nevoie de renovari";
                    Viz=0;
                }
            else
                cout<<"Cabinetul nu are nevoie de renovari";
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
                    cout<<"Cabinetul are nevoie de renovari";
                    Viz=0;
                }
            else
                cout<<"Cabinetul nu are nevoie de renovari";
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
        int nr_medici;
        Medic* medici;
    public:
        Departament()
        {
            medici=NULL;
            nr_medici=0;
        }
        Departament(int numar,string denumire)
        {
            nr_medici=numar;
            medici=new Medic[nr_medici];
        }
        int getNr_medici() const
        {
            return nr_medici;
        }
        Departament(const Departament &d)
        {
            nr_medici=d.nr_medici;
            for(int i=0;i<nr_medici;i++)
                medici[i]=d.medici[i];
        }
        ~Departament()
        {
            if(medici!=NULL)
            {
                delete[] medici;
                medici=nullptr;
            }
        }
        void Marire_salariu()
        {
            int i;
            for(i=0;i<nr_medici;i++)
            {
                double salariu_nou=medici[i].getSalariu()+(medici[i].getSalariu())* 10/100;
                medici[i].setSalariu(salariu_nou);
            }
        }
        Medie_salariu()
        {
            int i;
            double sum=0;
            for(i=0;i<nr_medici;i++)
                sum=sum+medici[i].getSalariu();
            sum=sum/nr_medici;
            return sum;

        }
        void Adaugare_medic(Departament &d, Medic &m)
         {
            if(d.medici==NULL)
            {
                d.nr_medici=1;
                d.medici=new Medic[1];
                d.medici[0]=m;
            }
            else
            {
                int i;
                for(i=0;i<d.nr_medici;i++)
                    if(medici[i]==m)
                        throw "Medicul a fost deja inregistrat";
                d.nr_medici=d.nr_medici+1;
                Medic* aux;
                aux= new Medic[d.nr_medici];
                for(i=0;i<d.nr_medici-1;i++)
                    aux[i]=d.medici[i];
                aux[i]=m;
                delete[] d.medici;
                d.medici=aux;
            }
        }
        void Eliminare_medic(Departament &d, Medic &m)
        {
            int semafor=0, i, j;
            if(d.nr_medici>=1)
            {
                for(i=0; i<d.nr_medici && semafor==0;i++)
                    if(d.medici[i]==m)
                {
                    semafor=1;
                    Medic* aux;
                    d.nr_medici=d.nr_medici-1;
                    aux=new Medic[d.nr_medici];
                    for(j=0;j<i;j++)
                        aux[j]=d.medici[j];
                    for(j=i;j<=d.nr_medici-1;j++)
                        aux[j]=d.medici[j+1];
                    delete[] d.medici;
                    d.medici=aux;
                }
            }
        }
        string getClassName()
        {
            return "Departament";
        }
        void AfisareDate()
        {
            cout<<"In departament lucreaza "<<nr_medici<<" medici."<<"\n";
        }
};



int main()
{
    ////////constructori/////////
    Asistent_medical a1("21","0786876765","@",3500,"Alecu","Ruxandra","feminin",45,"avansat","da",20);
    Asistent_medical a2("22","0712432565","@",3000,"Aleca","Tudor","masculin",35,"experimentat","nu",12);
    Medic m1("001","0711111111","@",4000,"Aron","Marta","feminin",40,"oftalmologie","specialist","nu",10);
    Medic m2("002","0788888888","@",4500,"Marcu","Maria","feminin",30,"oftalmologie","specialist","da",5);
    Medic m3("003","0799999999","@",5000,"Pavel","Iuliana","feminin",55,"dermatologie","specialist","da",15);
    Medic m4("004","0722222222","@",6000,"Matei","Pavel","masculin",28,"dermatologie","specialist","da",3);
    Medic m5("005","0733333333","@",3000,"Barbu","Alexandru","masculin",39,"pediatrie","primar","da",17);
    Medic m6("006","0744444444","@",4400,"Constantin","Diana","feminin",35,"pediatrie","specialist","nu",5);
    Medic m7("007","0755555555","@",5000,"Sandu","Raluca","feminin",47,"chirurgie","specialist","da",20);
    Medic m8("008","0766666666","@",5500,"Alecu","Cristian","masculin",57,"chirurgie","specialist","da",20);
    Medic m9("009","0777777777","@",3500,"Moise","Tania","feminin",34,"infectioase","primar","nu",7);
    Medic m10("010","0723333333","@",6500,"Eni","Bogdan","masculin",60,"infectioase","specialist","nu",25);
    Medic::Numar_medici();
    Medic::Medie_salarii();
    ////////try...catch/////////////
    try
    {
        Medic m11("011","0754365789","@",-100,"Darius","Darian","masculin",56,"infectioase","specialist","nu",30);
    }
    catch(const char* exceptie)
    {
        cout<<"Exceptie: "<<exceptie<<"\n";
    }
    //////////constructori///////////
    Pacient p1("Andrei", "Maria", "feminin",20, "0766666654", "1", "asigurat", "neabonat", 50, 1.60);
    Pacient p2("Busoi", "Alexandru", "masculin",39, "0755446565", "2", "neasigurat", "abonat", 80, 1.70);
    Pacient p3("Marcu", "Iulia", "feminin",40, "0744342343", "4", "asigurat", "abonat", 45, 1.55);
    Pacient p4("Iliescu", "Tania", "feminin",35, "0765334234","5", "asigurat", "neabonat", 70, 1.65);
    Pacient p5("Zarnescu","Matei","masculin",60,"0788987656","6","asigurat","neabonat",0,0);
    Pacient p6("Mircea","Diana","feminin",39,"0756453423","7","neasigurat","abonat",0,0);
    Pacient p7("Mironov","Stefania","feminin",27,"0765676545","8","neasigurat","neabonat",0,0);
    Pacient p8("Matei","Denisa","feminin",45,"0765643423","9","neasigurat","abonat",50,1.60);
    Pacient p9("Marinescu","Dana","feminin",60,"0756453423","10","asigurat","neabonat",40,1.50);
    Pacient p10("Busoiu","Mihaela","feminin",47,"0712233445","11","neasigurat","neabonat",70,1.80);
    //////////try...catch////////////
    try
    {
        Pacient p11("Calin","Anca","feminin",-1,"0785643765","12","neasigurat","neabonat",70,1.60);
    }
    catch(const char* exceptie)
    {
        cout<<"Exceptie: "<<exceptie<<"\n";
    }
    try
    {
        m1.setSalariu(-100);
    }
    catch(const char* exceptie)
    {
        cout<<"Exceptie: "<<exceptie<<"\n";
    }
    try
    {
        p1.setVarsta(-1);
    }
    catch(const char* exceptie)
    {
        cout<<"Exceptie: "<<exceptie<<"\n";
    }
    Departament dermatologie;
    dermatologie.Adaugare_medic(dermatologie, m3);
    dermatologie.Adaugare_medic(dermatologie, m4);
    try
    {
    dermatologie.Adaugare_medic(dermatologie, m3);
    }
    catch(const char* exceptie)
    {
        cout<<"Exceptie: "<<exceptie<<"\n";
    }
    Cabinet c1("dermatologie",0,100,100);
    try
    {
        Cabinet c2("dermatologie",0,-1,100);
    }
    catch(const char* exceptie)
    {
        cout<<"Exceptie: "<<exceptie<<"\n";
    }
    ///////metode protected////////
    Cabinet c2("oftalmologie",5,200,300);
    c2.Adaugare_istoric_medici(m1);
    c2.Adaugare_istoric_medici(m2);
    c2.Adaugare_istoric_pacienti(p1);
    c2.Adaugare_istoric_pacienti(p2);
    c2.Afisare_istoric();
    ////////constructori/////////
    Sala_internare i1("infectioase", 5, 10, 200, 3, 300, 300 );
    Internare int1("20 mai", "25 mai", 200, 5, m1, i1, p1);
    Consultatie cons1("20 mai", "8:00", "exemplu1", 100, m1, c2, p2);
    Analize_medicale an1("20 mai", "7:00", "sange", 150, 1, m1, p4);
    ///////destructor virtual////////////
    Cadru_medical *_p1=new Medic();
    delete _p1;
    ///////interfata////////////
    cout<<dermatologie.getClassName()<<"\n";
    dermatologie.AfisareDate();
    //////clasa abstracta//////////
    cout<<c2.Calcul_intretinere()<<"\n";
    c2.Numar_utilizari();
    cout<<c2.Proportie_utilizari_costuri()<<"\n";
    c2.Renovari();
    c2.Descriere_utilizare();
    cout<<i1.Calcul_intretinere()<<"\n";
    i1.Numar_utilizari();
    cout<<i1.Proportie_utilizari_costuri()<<"\n";
    i1.Renovari();
    i1.Descriere_utilizare();
    ////////////polimorfism la executie////////
    Vizita_medicala* _p2=&cons1;
    Vizita_medicala* _p3=&int1;
    Vizita_medicala* _p4=&an1;
    _p2->Calcul_pret();
    _p3->Calcul_pret();
    _p4->Calcul_pret();
    Persoana*_p5=&m1;
    Persoana*_p6=&p1;
    _p5->Afisare_profil();
    _p6->Afisare_profil();
    Cadru_medical* _p7=&m2;
    _p7->Spor_tura_noapte();
    Cadru_medical* _p8=&m3;
    _p8->Marire_salariu();
    /////upcasting/////
    Cadru_medical* _p9=new Medic("012","0786765654","@",5500,"Bogdan","Marius","masculin",55,"cardiovasculare","specialist","da",30);
    _p9->Spor_tura_noapte();
    Persoana* _p10=new Medic("013","0786546745","@",5500,"Andrei","Marius","masculin",60,"cardiovasculare","specialist","da",32);
    _p10->Afisare_profil();
    Vizita_medicala* _p11=new Consultatie("20 mai", "7:00","bolnav",150,m4,c2,p3);
    _p11->Calcul_pret();
    ////downcasting/////
    Salon* _p13=new Cabinet();
    Salon* _p14=new Sala_internare();
    Cabinet* _p15=dynamic_cast<Cabinet*>(_p13);
    if(_p15!=NULL)
        cout<<"Variabila este de tip cabinet"<<"\n";
    else
        cout<<"Variabila nu este de tip cabinet"<<"\n";
    Cabinet* _p16=dynamic_cast<Cabinet*>(_p14);
    if(_p16!=NULL)
        cout<<"Variabila este de tip cabinet"<<"\n";
    else
        cout<<"Variabila nu este de tip cabinet"<<"\n";
    /////try...catch///////
    Cabinet cab("s",2,200,200);
    Medic med("001","0711111111","@",4000,"Aron","Marta","feminin",40,"oftalmologie","specialist","nu",10);
    cab.Adaugare_istoric_medici(m1);
    try
    {
        cab.Adaugare_istoric_medici(med);
    }
    catch(Medic_existent* m)
    {
        cout<<"Medicul "<<m->getNume_medic()<<" a fost adaugat deja."<<"\n";
    }


    return 0;

}

