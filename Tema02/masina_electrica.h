#include "masina.h"

class masina_electrica : public masina{
private:
    float capacitate_baterie;
public:
    masina_electrica(motor&, std::string,std::string,std::string,int,std::string,int,int, float);
    void sunet();
    friend std::ostream& operator<<(std::ostream& os, const masina_electrica& m);
    float getCapacitateBaterie(){return this->capacitate_baterie;}
};

masina_electrica::masina_electrica(motor &m, std::string marca, std::string model, std::string culoare, int nr_locuri,std::string cutie_viteza,int nr_viteze,int viteza_maxima, float capacitate_baterie) : masina(m, marca,model,culoare,nr_locuri,cutie_viteza, nr_viteze,viteza_maxima) {
    this->capacitate_baterie = capacitate_baterie;
}
void masina_electrica::sunet() {std::cout<<this->getModel()<<" este o masina electrica, deci nu face zgomot\n";}
std::ostream& operator<<(std::ostream& os, const masina_electrica& m ) {
    os <<"\n##################\n"<<"Marca: "<<m.marca
    <<"\n"<<"Model: "<<m.model
    <<"\n"<<"Culoare: "<<m.culoare
    <<"\n"<<"Nr locuri: "<<m.nr_locuri
    <<"\n"<<"Cutie de viteze: "<<m.cutie_viteza
    <<"\n"<<"Viteza maxima: "<<m.viteza_maxima << "Km/h"
    <<"\n"<<"Numar viteze: "<<m.nr_viteze
    <<"\n"<<"Capacitate baterie: "<<m.capacitate_baterie<<"A"
    <<"\n"<<"Denumire motor: "<<m.Motor.getDenumire()
    <<"\n"<<"Putere motor: "<<m.Motor.getPutere()<<" Cai putere"
    <<"\n"<<"Consum motor: "<<m.Motor.getConsum()<<" W"
    <<"\n##################\n\n";
    return os;
}
