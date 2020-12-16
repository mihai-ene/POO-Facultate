#include "motor.h"
#include <Windows.h>
#include <unistd.h>

class masina{
protected:
    std::string marca;
    std::string model;
    std::string culoare;
    int nr_locuri;
    std::string cutie_viteza;
    int nr_viteze;
    int viteza_maxima;
    motor Motor;
public:
    masina(motor&,std::string,std::string,std::string,int,std::string,int,int);
    ~masina();
    motor& getMotor(){return this->Motor;}
    std::string getModel(){return this->model;}
    std::string getMarca(){return this->marca;}
    std::string getCuloare(){return this->culoare;}
    std::string getCutieViteza(){return this->cutie_viteza;}
    int getNrLocuri(){return this->nr_locuri;}
    int getNrViteze(){return this->nr_viteze;}
    int getVitezaMaxima() const {return this->viteza_maxima;}
    virtual void sunet();
    void intrecere(const masina &x);
    friend std::ostream& operator<<(std::ostream& os, const masina& m);
    masina& operator=(const masina &other){
        this->marca = other.marca;
        this->model = other.model;
        this->culoare = other.culoare;
        this->nr_locuri = other.nr_locuri;
        this->cutie_viteza = other.cutie_viteza;
        this->nr_viteze = other.nr_viteze;
        this->viteza_maxima = other.viteza_maxima;
        this->Motor = other.Motor;

        return *this;
    }
    float calculare_delay() const;
};


masina::masina(motor &m,std::string marca, std::string model, std::string culoare, int nr_locuri,std::string cutie_viteza,int nr_viteze,int viteza_maxima) : Motor(m) {
    if (marca != "" && model != "" && culoare != "" && nr_locuri > 1 && nr_viteze > 0 && viteza_maxima > 10 && (cutie_viteza == "manuala" || cutie_viteza == "automata") ) {
        this->marca = marca;
        this->model = model;
        this->culoare = culoare;
        this->nr_locuri = nr_locuri;
        this->cutie_viteza = cutie_viteza;
        this->nr_viteze = nr_viteze;
        this->viteza_maxima = viteza_maxima;
    } else
        throw std::invalid_argument("Argumentele pentru masina nu sunt valide\n");
}



masina::~masina(){std::cout<<"Am distrus masina "<<this->model<<"\n";}
void masina::sunet() {std::cout<<this->model<<" face Vruuuum\n";}

std::ostream& operator<<(std::ostream& os, const masina& m ){
    os <<"\n##################\n"<<"Marca: "<<m.marca
       <<"\n"<<"Model: "<<m.model
       <<"\n"<<"Culoare: "<<m.culoare
       <<"\n"<<"Nr locuri: "<<m.nr_locuri
       <<"\n"<<"Cutie de viteze: "<<m.cutie_viteza
       <<"\n"<<"Viteza maxima: "<<m.viteza_maxima << "Km/h"
       <<"\n"<<"Numar viteze: "<<m.nr_viteze
       <<"\n"<<"Denumire motor: "<<m.Motor.getDenumire()
       <<"\n"<<"Putere motor: "<<m.Motor.getPutere()<<" Cai putere"
       <<"\n"<<"Consum motor: "<<m.Motor.getConsum()<<" %"
       <<"\n##################\n\n";
    return os;
}
float masina::calculare_delay() const {
    if (this->cutie_viteza == "manuala") {
        return 2.5; // Schimbarea vitezei unei masini manuale dureaza 2.5s
    }
    return 1.2; // Schimbarea vitezei unei masini automate dureaza 1.2s
}

void masina::intrecere(const masina &x) {
    // MASINA 1 = THIS
    // MASINA 2 = X (Masina cu care se intrece)

    float delay_masina1, delay_masina2;
    delay_masina1 = this->calculare_delay();
    delay_masina2 = x.calculare_delay();

    float viteza_pe_secunda_masina1, viteza_pe_secunda_masina2;
    //Viteza pe secunda este calculata in metrii
    viteza_pe_secunda_masina1 = float(this->getVitezaMaxima()) / 3.6;
    viteza_pe_secunda_masina2 = float(x.getVitezaMaxima()) / 3.6;

    std::cout<<this->marca<<" "<<this->model<<" este pregatita de intrecere\n";
    std::cout<<x.marca<<" "<<x.model<<" este pregatita de intrecere\n";

    float distanta;
    std::cout << "Introduceti distanta pe care se vor intrece cele doua masini (m): ";
    std::cin>>distanta;

    float pozitie_curenta_masina1 = 0, pozitie_curenta_masina2 = 0, treapta_curenta_masina1 = 0, treapta_curenta_masina2 = 0;
    while (pozitie_curenta_masina1 < distanta && pozitie_curenta_masina2 < distanta){
        if(treapta_curenta_masina1 != this->nr_viteze){
            pozitie_curenta_masina1 += viteza_pe_secunda_masina1;
            sleep(delay_masina1);
            treapta_curenta_masina1++;
            std::cout <<this->marca<<" "<<this->model<< " a schimbat in treapta " << treapta_curenta_masina1 << " si a parcurs o distanta de  " << pozitie_curenta_masina1 <<" metrii \n";
        }
        else{
            std::cout <<this->marca<<" "<<this->model<<" se afla in ultima treapta de viteza "<< " si a parcurs o distanta de  " << pozitie_curenta_masina1 <<" metrii \n";
            pozitie_curenta_masina1 += viteza_pe_secunda_masina1;
        }
        if(treapta_curenta_masina2 != x.nr_viteze){
            pozitie_curenta_masina2 += viteza_pe_secunda_masina2;
            sleep(delay_masina2);
            treapta_curenta_masina2++;
            std::cout <<x.marca<<" "<<x.model<< " a schimbat in treapta " << treapta_curenta_masina2 << " si a parcurs o distanta de  " << pozitie_curenta_masina2 <<" metrii \n";
        }
        else{
            std::cout <<x.marca<<" "<<x.model<<" se afla in ultima treapta de viteza "<< " si a parcurs o distanta de  " << pozitie_curenta_masina2 <<" metrii \n";
            pozitie_curenta_masina2 += viteza_pe_secunda_masina2;
        }
    }
    if (pozitie_curenta_masina1 >= distanta)
        std::cout<<"A castigat "<<this->marca<<" "<<this->model<<"! \n";
    else
        std::cout<<"A castigat "<<x.marca<<" "<<x.model<<"! \n";

}

