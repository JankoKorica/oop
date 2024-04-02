
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Cvijet {
public:
    string vrsta;
    string boja;
    string kolicina;

    Cvijet() {
        cout << "Cvijet constructor called" << endl;
    }

    ~Cvijet() {
        cout << "Cvijet destructor called" << endl;
    }

};

class Vrt {

private:
    string adresa;
    string vlasnik;
    int sirina = 0;
    int duljina = 0;
    vector<Cvijet> cvijetovi;


public:

    Vrt(string _adresa, string _vlasnik, int _sirina, int _duljina) {
        setAdresa(_adresa);
        setVlasnik(_vlasnik);
        setSirina(_sirina);
        setDuljina(_duljina);
    }
    
    void setAdresa(string _adresa) {
        adresa = _adresa;
    }

    void setVlasnik(string _vlasnik) {
        if (isupper(_vlasnik[0]))
            vlasnik = _vlasnik;
        else
            cout << "Ime vlasnika morapoceti sa velikim slovom";
    }

    void setSirina(int _sirina) {
        if (_sirina * duljina >= 10 || _sirina * duljina == 0)
            sirina = _sirina;
        else
            cout << "Povrsina mora biti barem 10cm2";
    }

    void setDuljina(int _duljina) {
        duljina = _duljina;
        if (sirina * _duljina >= 10 || sirina * _duljina == 0)
            duljina = _duljina;
        else
            cout << "Povrsina mora biti barem 10cm2";
    }

    void dodajCvijet1(Cvijet z) {
        cvijetovi.push_back(z);
    }

    void dodajCvijet2(Cvijet &z) {
        cvijetovi.push_back(z);
    }

    void dodajCvijet3(Cvijet *z) {
        cvijetovi.push_back(*z);
    }

    void ispisSvihCvijetova() {
        for (Cvijet cvijet : cvijetovi)
            cout << cvijet.boja << " " << cvijet.kolicina << " " << cvijet.vrsta << endl;
    }

    Cvijet nadjiCvijet1(string vrsta) {
        for (Cvijet cvijet : cvijetovi) {
            if (cvijet.vrsta == vrsta) {
                cvijet.vrsta = "cvijetić";
                cvijet.kolicina = 300;
                cvijet.boja = "ljubičasta";
                return cvijet;
            }
        }
    }      

    Cvijet& nadjiCvijet2(string vrsta) {
        for (Cvijet cvijet : cvijetovi) {
            if (cvijet.vrsta == vrsta) {
                cvijet.vrsta = "cvijetić";
                cvijet.kolicina = 300;
                cvijet.boja = "ljubičasta";
                return cvijet;
            }
        }
    }

    Cvijet* nadjiCvijet3(string vrsta) {
        for (Cvijet cvijet : cvijetovi) {
            if (cvijet.vrsta == vrsta) {
                cvijet.vrsta = "cvijetic";
                cvijet.kolicina = 300;
                cvijet.boja = "ljubicasta";
                return &cvijet;
            }
        }

    }
};


int main()
{
    Vrt vrt("lascina", "Janko", 4, 3);
    Cvijet cvijet;
    Cvijet& cvijetref = cvijet;
    Cvijet* cvijetptr = new Cvijet();
    cvijetptr->vrsta = "jaglac";
    vrt.dodajCvijet1(Cvijet());
    vrt.dodajCvijet2(cvijetref);
    vrt.dodajCvijet3(cvijetptr);
    
    cout << vrt.nadjiCvijet1("jaglac").vrsta << "aaaa" << endl;
    cout << vrt.nadjiCvijet2("jaglac").vrsta << "aaaa" << endl;
    cout << vrt.nadjiCvijet3("jaglac")->vrsta << "aaaa" << endl;
}