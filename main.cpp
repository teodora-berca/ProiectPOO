#include <iostream>

using namespace std;

class String
{
    private:
        char* m_ptr;
        int m_size;
    public:
        int getSize() const
        {
            return m_size;
        }
        char* getPtr() const
        {
            return m_ptr;
        }
        int strlen(const char* Start)
        {
            const char* End=Start;
            for(;*End!='\0';++End);
            return End-Start;

        }
        String() : m_ptr(nullptr), m_size(0)
        {

        }
        String(const char* s) : m_size(strlen(s))
        {
            m_ptr=new char[m_size+1];
            for(int i=0;i<m_size;i++)
            {
                m_ptr[i]=s[i];
            }
            m_ptr[m_size]='\0';
        }
        String(const String &s) : m_size(s.m_size)
        {
            m_ptr=new char[m_size+1];
            for(int i=0;i<m_size;i++)
            {
                m_ptr[i]=s.m_ptr[i];
            }
            m_ptr[m_size]='\0';
        }
        friend ostream & operator <<(ostream &os, const String&s)
        {
            os<<s.m_ptr;
            return os;
        }
        ~String()
        {
            delete[] m_ptr;
            m_ptr=nullptr;
        }
        bool operator ==(const String & s) const
        {
            if(m_size!=s.m_size)
                return false;
            for(int i=0;i<s.m_size;i++)
            {
                if(m_ptr[i]!=s.m_ptr[i])
                    return false;
            }
            return true;
        }
        String& operator = (const String &s)
        {
            if(this==&s)
                return *this;
            delete[] m_ptr;
            m_ptr=new char[s.m_size+1];
            m_size=s.m_size;
            for(int i=0;i<m_size;i++)
            {
                m_ptr[i]=s.m_ptr[i];
            }
            m_ptr[m_size]='\0';
            return *this;
        }
        String &operator =(const char* &s)
        {
            String aux(s);
            *this=aux;
            return *this;
        }


};

class Pacient
{
    private:
        String Nume;
        String Prenume;
        String Sex;
        String Telefon;
        double Varsta;
        double Cod_pacient;
        String Asigurare_medicala;
        String Abonament;
        double Greutate;
        double Inaltime;
    public:
        Pacient()
        {
            Nume="nume";
            Prenume="prenume";
            Sex="sex";
            Telefon="telefon";
            Varsta=0;
            Cod_pacient=0;
            Asigurare_medicala="stare_asigurare_medicala";
            Abonament="abonament";
            Greutate=0;
            Inaltime=0;
        }
        Pacient(String nume, String prenume, String sex, String telefon, double varsta, double cod_pacient, String asigurare_medicala, String abonament, double greutate, double inaltime)
        {
            Nume=nume;
            Prenume=prenume;
            Sex=sex;
            Telefon=telefon;
            Varsta=varsta;
            Cod_pacient=cod_pacient;
            Asigurare_medicala=asigurare_medicala;
            Abonament=abonament;
            Greutate=greutate;
            Inaltime=inaltime;
        }
        String getNume() const
        {
            return Nume;
        }
        String getPrenume() const
        {
            return Prenume;
        }
        String getSex() const
        {
            return Sex;
        }
        String getTelefon() const
        {
            return Telefon;
        }
        double getVarsta() const
        {
            return Varsta;
        }
        double getCod_pacient() const
        {
            return Cod_pacient;
        }
        String getAsigurare_medicala() const
        {
            return Asigurare_medicala;
        }
        String getAbonament() const
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
        void setNume(String nume)
        {
            Nume=nume;
        }
        void setPrenume(String prenume)
        {
            Prenume=prenume;
        }
        void setSex(String sex)
        {
            Sex=sex;
        }
        void setTelefon(String telefon)
        {
            Telefon=telefon;
        }
        void setVarsta(double varsta)
        {
            Varsta=varsta;
        }
        void setCod_pacient(double cod_pacient)
        {
            Cod_pacient=cod_pacient;
        }
        void setAsigurare_medicala(String asigurare_medicala)
        {
            Asigurare_medicala=asigurare_medicala;
        }
        void setAbonament(String abonament)
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
        bool Verif_asig()
        {
            if (Asigurare_medicala==String("Asigurat"))
                return true;
            else
                return false;
        }
        bool Verif_abonament()
        {
            if(Abonament==String("Abonat"))
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
            Cod_pacient=p.Cod_pacient;
            Asigurare_medicala=p.Asigurare_medicala;
            Abonament=p.Abonament;
            Greutate=p.Greutate;
            Inaltime=p.Inaltime;
        }
        friend ostream & operator <<(ostream &out, const Pacient &p);
};

ostream & operator << (ostream & out, const Pacient &p)
{
    out<<"Nume:"<<p.Nume<<"\n";
    out<<"Prenume:"<<p.Prenume<<"\n";
    out<<"Sex:"<<p.Sex<<"\n";
    out<<"Telefon:"<<p.Telefon<<"\n";
    out<<"Varsta:"<<p.Varsta<<"\n";
    out<<"Cod_pacient:"<<p.Cod_pacient<<"\n";
    out<<"Asigurare_medicala:"<<p.Asigurare_medicala<<"\n";
    out<<"Greutate:"<<p.Greutate<<"\n";
    out<<"Inaltime:"<<p.Inaltime<<"\n";
    return out;
}

class Medic
{
    private:
        String Nume;
        String Prenume;
        String Cod;
        String Sex;
        String Telefon;
        double Varsta;
        String Specialitate;
        String Grad;
        double Salariu;
    public:
        Medic()
        {
            Nume="nume";
            Prenume="prenume";
            Cod="cod";
            Sex="sex";
            Telefon="telefon";
            Varsta=0;
            Specialitate="specialitate";
            Grad="grad";
            Salariu=0;
        }
        Medic(String nume, String prenume, String cod, String sex, String telefon, double varsta, String specialitate, String grad, double salariu)
        {
            Nume=nume;
            Prenume=prenume;
            Cod=cod;
            Sex=sex;
            Telefon=telefon;
            Varsta=varsta;
            Specialitate=specialitate;
            Grad=grad;
            Salariu=salariu;
        }
        String getNume() const
        {
            return Nume;
        }
        String getPrenume() const
        {
            return Prenume;
        }
        String getCod() const
        {
            return Cod;
        }
        String getSex() const
        {
            return Sex;
        }
        String getTelefon() const
        {
            return Telefon;
        }
        double getVarsta() const
        {
            return Varsta;
        }
        String getSpecialitate() const
        {
            return Specialitate;
        }
        String getGrad() const
        {
            return Grad;
        }
        double getSalariu() const
        {
            return Salariu;
        }
        void setNume(String nume)
        {
            Nume=nume;
        }
        void setPrenume(String prenume)
        {
            Prenume=prenume;
        }
        void setCod(String cod)
        {
            Cod=cod;
        }
        void setSex(String sex)
        {
            Sex=sex;
        }
        void setTelefon(String telefon)
        {
            Telefon=telefon;
        }
        void setVarsta(double varsta)
        {
            Varsta=varsta;
        }
        void setSpecialitate(String specialitate)
        {
            Specialitate=specialitate;
        }
        void setGrad(String grad)
        {
            Grad=grad;
        }
        void setSalariu(double salariu)
        {
            Salariu=salariu;
        }
        friend ostream & operator << (ostream &out, const Medic &m);
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
};

ostream & operator << (ostream & out, const Medic &m)
{
    out<<"Nume:"<<m.Nume<<"\n";
    out<<"Prenume:"<<m.Prenume<<"\n";
    out<<"Cod:"<<m.Cod<<"\n";
    out<<"Sex:"<<m.Sex<<"\n";
    out<<"Telefon:"<<m.Telefon<<"\n";
    out<<"Varsta:"<<m.Varsta<<"\n";
    out<<"Specialitate:"<<m.Specialitate<<"\n";
    out<<"Grad:"<<m.Grad<<"\n";
    out<<"Salariu:"<<m.Salariu<<"\n";
    return out;
}


class Asistent_medical
{
    private:
        String Nume;
        String Prenume;
        String Sex;
        String Telefon;
        double Varsta;
        double Salariu;
        String Grad;
    public:
        Asistent_medical()
        {
            Nume="nume";
            Prenume="prenume";
            Sex="sex";
            Telefon="telefon";
            Varsta=0;
            Salariu=0;
            Grad="grad";
        }
        Asistent_medical(String nume, String prenume, String sex, String telefon, double varsta, double salariu, String grad)
        {
            Nume=nume;
            Prenume=prenume;
            Sex=sex;
            Telefon=telefon;
            Varsta=varsta;
            Salariu=salariu;
            Grad=grad;
        }
        String getNume() const
        {
            return Nume;
        }
        String getPrenume() const
        {
            return Prenume;
        }
        String getSex() const
        {
            return Sex;
        }
        String getTelefon() const
        {
            return Telefon;
        }
        double getVarsta() const
        {
            return Varsta;
        }
        double GetSalariu() const
        {
            return Salariu;
        }
        String getGrad() const
        {
            return Grad;
        }
        void setNume(String nume)
        {
            Nume=nume;
        }
        void setPrenume(String prenume)
        {
            Prenume=prenume;
        }
        void setSex(String sex)
        {
            Sex=sex;
        }
        void setTelefon(String telefon)
        {
            Telefon=telefon;
        }
        void setVarsta(double varsta)
        {
            Varsta=varsta;
        }
        void setSalariu(double salariu)
        {
            Salariu=salariu;
        }
        void setGrad(String grad)
        {
            Grad=grad;
        }
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
        friend ostream & operator << (ostream & out, const Asistent_medical &a);
};

ostream & operator <<(ostream &out, const Asistent_medical &a)
{
    out<<"Nume:"<<a.Nume<<"\n";
    out<<"Prenume:"<<a.Prenume<<"\n";
    out<<"Sex:"<<a.Sex<<"\n";
    out<<"Telefon:"<<a.Telefon<<"\n";
    out<<"Varsta:"<<a.Varsta<<"\n";
    out<<"Salariu:"<<a.Salariu<<"\n";
    out<<"Grad:"<<a.Grad<<"\n";
    return out;
}

class Cabinet
{
    private:
        String Specialitate;
        String Denumire;
    public:
        Cabinet()
        {
            Specialitate="specialitate";
            Denumire="denumire";
        }
        Cabinet(String specialitate, String denumire)
        {
            Specialitate=specialitate;
            Denumire=denumire;
        }
        String getSpecialitate() const
        {
            return Specialitate;
        }
        String getDenumire() const
        {
            return Denumire;
        }
        void setSpecialitate(String specialitate)
        {
            Specialitate=specialitate;
        }
        void setDenumire(String denumire)
        {
            Denumire=denumire;
        }
        Cabinet(Cabinet &c)
        {
            Specialitate=c.Specialitate;
            Denumire=c.Denumire;
        }
        void operator = (const Cabinet &c)
        {
            Specialitate=c.Specialitate;
            Denumire=c.Denumire;
        }
        friend ostream & operator << (ostream &out, const Cabinet &c);
};

ostream & operator << (ostream &out, const Cabinet &c)
{
    out<<"Specialitate:"<<c.Specialitate<<"\n";
    out<<"Denumire:"<<c.Denumire<<"\n";
    return out;
}

class Consultatie
{
    private:
        String Data;
        double Pret;
        Pacient P;
        Medic M;
        Cabinet C;
        String Diagnostic;
    public:
        Consultatie()
        {
            Data="data";
            Pret=0;
            Diagnostic="diagnostic";
        }
        Consultatie(String data, double pret, Pacient p, Medic m, Cabinet c, String diagnostic)
        {
            Data=data;
            Pret=pret;
            P=p;
            M=m;
            C=c;
            Diagnostic=diagnostic;
        }
        void setData(String data)
        {
            Data=data;
        }
        void setPret(double pret)
        {
            Pret=pret;
        }
        void setDiagnostic(String diagnostic)
        {
            Diagnostic=diagnostic;
        }
        String getData() const
        {
            return Data;
        }
        double getPret() const
        {
            return Pret;
        }
        String getDiagnostic()const
        {
            return Diagnostic;
        }
        void Reducere_asigurare()
        {
            if (P.getAsigurare_medicala()==String("asigurat"))
                Pret=0;
        }
        void Reducere_abonament()
        {
            if (P.getAbonament()==String("abonat"))
                    Pret=Pret-Pret*30/100;
        }
};

class Departament
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
        Departament(int numar)
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
        friend void Adaugare_medic(Departament &d, Medic &m);
        friend void Eliminare_medic(Departament &d, Medic &m);
        friend double Medie_salariu(Departament&d);
        friend void Marire_salariu(Departament&d);
        ~Departament()
        {
            delete[] medici;
            medici=nullptr;
        }
};

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
double Medie_salariu(Departament &d)
{
    int i;
    double sum=0;
    for(i=0;i<d.nr_medici;i++)
        sum=sum+d.medici[i].getSalariu();
    sum=sum/d.nr_medici;
    return sum;
}

void Marire_salariu(Departament &d)
{
    int i;
    for(i=0;i<d.nr_medici;i++)
    {
        double salariu_nou=d.medici[i].getSalariu()+(d.medici[i].getSalariu())* 10/100;
        d.medici[i].setSalariu(salariu_nou);
    }
}


int main()
{
    Departament dermatologie, oftalmologie, pediatrie, cardiologie;
    Medic m1("Aron", "Matei","001", "masculin", "0745339678", 45, "dermatolog", "specialist", 4000);
    Medic m2("Bucur", "Andra","002", "feminin", "0755134256", 30, "dermatolog", "primar", 3500);
    Medic m3("Danila", "Corina","003", "feminin", "0786554876", 55, "dermatolog", "specialist", 5000);
    Medic m4("Tudor", "Alina", "004","feminin", "0788443554", 35, "dermatolog", "primar", 4000);
    Medic m5("Codrea", "Bogdan","005", "masculin", "0786554367", 55, "dermatolog", "specialist", 5500);
    Adaugare_medic(dermatologie, m1);
    Adaugare_medic(dermatologie, m2);
    Adaugare_medic(dermatologie, m3);
    Adaugare_medic(dermatologie, m4);
    Adaugare_medic(dermatologie, m5);
    cout<<"Medie salariu dermatologie:"<<Medie_salariu(dermatologie)<<"\n";
    Marire_salariu(dermatologie);
    cout<<"Medie salariu dermatologie dupa marire:"<<Medie_salariu(dermatologie)<<"\n";
    cout<<"Numarul de medici de la dermatologie este:"<<dermatologie.getNr_medici()<<"\n";
    Eliminare_medic(dermatologie, m5);
    cout<<"Numarul de medici de la dermatologie nou este:"<<dermatologie.getNr_medici()<<"\n";
    Medic m6("Ionescu","Pavel","006","masculin", "0788553421", 47, "oftalmolog", "specialist", 6000);
    Medic m7("Popescu","Marcela", "007", "feminin", "0799867564", 30, "oftalmolog", "primar", 3500);
    Medic m8("Dobrovat", "Marta", "008", "feminin", "0786545676", 60, "oftalmolog", "specialist", 5500);
    Adaugare_medic(oftalmologie, m6);
    Adaugare_medic(oftalmologie, m7);
    Adaugare_medic(oftalmologie, m8);
    cout<<"Medie salariu oftalmologie:"<<Medie_salariu(oftalmologie)<<"\n";
    Medic m9("Marcu", "Matei", "009", "masculin", "0788888676", 50, "pediatrie", "specialist", 6000);
    Medic m10;
    m10.setNume("Aleca");
    m10.setPrenume("Diana");
    m10.setCod("010");
    m10.setSex("feminin");
    m10.setTelefon("0711110786");
    m10.setVarsta(42);
    m10.setSpecialitate("pediatrie");
    m10.setGrad("specialist");
    m10.setSalariu(4000);
    Adaugare_medic(pediatrie, m9);
    Adaugare_medic(pediatrie, m10);
    cout<<m10;
    Medic m11("Dobrot", "Ana", "011", "feminin", "0722222333", 60, "cardiologie", "specialist", 5000);
    Adaugare_medic(cardiologie, m11);
    Pacient p1("Andrei", "Maria", "feminin", "0766666654", 20, 1, "asigurat", "neabonat", 50, 1.60);
    if(p1.Verif_asig())
        cout<<"Pacientul "<<p1.getNume()<<" "<<p1.getPrenume()<<"este asigurat"<<"\n";
    else
        cout<<"Pacientul "<<p1.getNume()<<" "<<p1.getPrenume()<<" nu este asigurat"<<"\n";
    Pacient p2("Busoi", "Alexandru", "masculin", "0755446565", 39, 2, "neasigurat", "abonat", 80, 1.70);
    if(p1.Verif_abonament())
        cout<<"Pacientul "<<p1.getNume()<<" "<<p1.getPrenume()<<"este abonat"<<"\n";
    else
        cout<<"Pacientul "<<p1.getNume()<<" "<<p1.getPrenume()<<" nu este abonat"<<"\n";
    Pacient p3;
    p3.setNume("Banu");
    p3.setPrenume("Andrada");
    p3.setSex("feminin");
    p3.setTelefon("0799898988");
    p3.setVarsta(67);
    p3.setCod_pacient(3);
    p3.setAsigurare_medicala("asigurat");
    p3.setAbonament("neabonat");
    p3.setGreutate(60);
    p3.setInaltime(1.80);
    cout<<p3;
    Pacient p4("Marcu", "Iulia", "feminin", "0744342343", 40, 4, "asigurat", "abonat", 45, 1.55);
    cout<<"Datele initiale din p4"<<"\n";
    cout<<p4;
    Pacient p5("Iliescu", "Tania", "feminin", "0765334234", 35, 5, "asigurat", "neabonat", 70, 1.65);
    p4=p5;
    cout<<"Am mutat p5 in p4"<<"\n";
    cout<<p4;
    Asistent_medical a1("Bucur", "Ilinca", "feminin", "0752076543", 40, 2500, "sef");
    Asistent_medical a2("Costache", "Ana", "feminin", "0765087698", 50, 3000, "sef");
    cout<<a1.getNume()<<" "<<a1.getPrenume()<<"\n";
    cout<<a2;
    Cabinet c1("oftalmologie", "cabinet_1");
    Cabinet c2("oftalmologie", "cabinet_2");
    Cabinet c3("oftalmologie", "cabinet_3");
    Cabinet c4("dermatologie", "cabinet_4");
    Cabinet c5("dermatologie", "cabinet_5");
    Cabinet c6("pediatrie", "cabinet_6");
    Cabinet c7("cardiologie", "cabinet_7");
    Cabinet c8;
    c8.setSpecialitate("pediatrie");
    c8.setDenumire("cabinet_8");
    cout<<c1;
    Cabinet c9;
    c9=c7;
    c9.setDenumire("cabinet_9");
    cout<<c9;
    Consultatie consultatie1("10/05/2023", 250, p1, m1, c4, "diagnostic");
    Consultatie consultatie2("10/05/2023", 300, p2, m6, c3, "diagnostic");
    cout<<consultatie2.getPret()<<"\n";
    consultatie2.Reducere_abonament();
    cout<<consultatie2.getPret()<<"\n";
    cout<<consultatie1.getPret()<<"\n";
    consultatie1.Reducere_asigurare();
    cout<<consultatie1.getPret()<<"\n";
    Cabinet c10(c9);
    c10.setDenumire("cabinet_10");
    cout<<c10;

    return 0;


}
