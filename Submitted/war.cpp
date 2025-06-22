#include <iostream>
using namespace std;

class Postac //klasa postać stałą sie klasą abstrakcyjną ponieważ ma co niajmniej jedną metode wirtualną
{
    protected:
        string nazwa;
        int zycie;
        int atak;

    public:
        Postac(string nazwa, int zycie, int atak)
        :nazwa(nazwa), zycie(zycie), atak(atak)
        {}

        virtual void wyswietl()
        {
            cout<<endl<<nazwa<< " HP: "<<zycie<<" atak: "<<atak;
        }

        ~Postac()
        {
            cout<<endl<<"postać "<<nazwa<<" nie żyje";
        }

        int get_zycie()
        {
            return zycie;
        }

        int get_atak()
        {
            return atak;
        }

        string get_nazwa()
        {
            return nazwa;
        }

        void set_zycie(int z)
        {
            zycie=z;
        }

        virtual int get_obrona()
        {
            return 0;
        }

        virtual int get_mana()
        {
            return 0;
        }

        virtual void set_mana(int m)
        {
            //mana=m;
        }

        virtual int get_strzaly() {
            return 0;
        }

        virtual void set_strzaly(int s) {

        }
};

class Wojownik : public Postac
{
    protected:
        int obrona;

    public:
        Wojownik(string nazwa, int zycie, int atak,int obrona)
        :Postac(nazwa,zycie,atak), obrona(obrona)
        {}

        void wyswietl()
        {
            Postac::wyswietl();
            cout<<" obrona: "<<obrona<<endl;
        }

        int get_obrona()
        {
            return obrona;
        }
};

class Mag : public Postac
{
    protected:
        int mana;

    public:
        Mag(string nazwa, int zycie, int atak, int mana)
        :Postac(nazwa,zycie,atak), mana(mana)
        {}

        void wyswietl()
        {
            Postac::wyswietl();
            cout<<" mana: "<<mana<<endl;
        }

        int get_mana()
        {
            return mana;
        }

        void set_mana(int m)
        {
            mana=m;
        }
};

class Lucznik : public Postac {
    protected:
        int strzaly;
    public:
        Lucznik(string nazwa, int zycie, int atak, int strzaly)
            : Postac(nazwa, zycie, atak), strzaly(strzaly){}

        void wyswietl() {
            Postac::wyswietl();
            cout<<" strzały: "<<strzaly<<endl;
        }

        int get_strzaly() {
            return strzaly;
        }

        void set_strzaly(int s) {
            strzaly = s;
        }
};

void walcz(Postac *p1, Postac *p2)
{
    while(p1->get_zycie()>0 && p2->get_zycie()>0)
    {
        p2->set_zycie(p2->get_zycie() - (p1->get_atak() - p2->get_obrona()));
        p1->set_zycie(p1->get_zycie() - (p2->get_atak() - p1->get_obrona()));

        if(p1->get_mana() > 0)
        {
            cout<<endl<<p1->get_nazwa()<<" uzywa zaklęcia";
            p1->set_mana(p1->get_mana()-25);
        }

        if(p2->get_mana() > 0)
        {
            cout<<endl<<p2->get_nazwa()<<" uzywa zaklęcia";
            p2->set_mana(p2->get_mana()-25);
        }

        if(p1->get_strzaly() > 0) {
            cout<<endl<<p1->get_nazwa()<<" strzela z łuku";
            p1->set_strzaly(p1->get_strzaly()-1);
        }

        if(p2->get_strzaly() > 0) {
            cout<<endl<<p2->get_nazwa()<<" strzela z łuku";
            p2->set_strzaly(p2->get_strzaly()-1);
        }
    }

    if(p1->get_zycie() <= 0) delete p1;
    else p1->wyswietl();

    if(p2->get_zycie() <= 0) delete p2;
    else p2->wyswietl();


}

int main()
{
    Mag *m1 = new Mag("Merlin",120,15,100);
    Wojownik *w1 = new Wojownik("Artur",80,10,3);
    Lucznik *l1 = new Lucznik("Marvan",120,15,10);
    //m1->wyswietl();
    //w1->wyswietl();

    walcz(w1,l1);
}