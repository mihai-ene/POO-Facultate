#include "masina.h"

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
void masina::sunet() const {std::cout << this->model << " face Vruuuum\n";}

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
int masina::calculare_delay() const {
    if (this->cutie_viteza == "manuala") {
        return 3; // Schimbarea vitezei unei masini manuale dureaza 2.5s
    }
    return 1; // Schimbarea vitezei unei masini automate dureaza 1.2s
}

void masina::accelereaza(int &treapta_curenta, float &pozitie_curenta, float viteza, int delay) const {
    pozitie_curenta+=viteza;
    if (treapta_curenta < this->nr_viteze) {
        std::this_thread::sleep_for(std::chrono::seconds(delay));
        treapta_curenta++;
    }
    this->sunet();


}

void masina::franeaza(int &treapta_curenta, float &pozitie_curenta, float viteza) {
    if (treapta_curenta >= 0 ){
        pozitie_curenta -= viteza;
        treapta_curenta--;
    }
}

void masina::afisare_info(float pozitie,int treapta) const {
    if (treapta < this->nr_viteze)
        std::cout <<this->marca<<" "<<this->model<< " a schimbat in treapta " << treapta << " si a parcurs o distanta de  " << pozitie <<" metri \n";
    else
        std::cout <<this->marca<<" "<<this->model<<" se afla in ultima treapta de viteza "<< " si a parcurs o distanta de  " << pozitie <<" metri \n";

}

void masina::intrecere(const masina &x) {
    // MASINA 1 = THIS
    // MASINA 2 = X (Masina cu care se intrece)

    int delay_masina1, delay_masina2;
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

    float pozitie_curenta_masina1 = 0, pozitie_curenta_masina2 = 0;
    int treapta_curenta_masina1 = 0, treapta_curenta_masina2 = 0;
    while (pozitie_curenta_masina1 < distanta && pozitie_curenta_masina2 < distanta){
        this->accelereaza(treapta_curenta_masina1,pozitie_curenta_masina1,viteza_pe_secunda_masina1,delay_masina1);
        this->afisare_info(pozitie_curenta_masina1,treapta_curenta_masina1);

        x.accelereaza(treapta_curenta_masina2,pozitie_curenta_masina2,viteza_pe_secunda_masina2,delay_masina2);
        x.afisare_info(pozitie_curenta_masina2,treapta_curenta_masina2);
    }
    if (pozitie_curenta_masina1 >= distanta)
        std::cout<<"A castigat "<<this->marca<<" "<<this->model<<"! \n";
    else
        std::cout<<"A castigat "<<x.marca<<" "<<x.model<<"! \n";

}

