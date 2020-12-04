#include "masina.h"

class masina_electrica : public masina{
private:
    float capacitate_baterie;
public:
    masina_electrica(motor&, std::string,std::string,std::string,int, float);
    void sunet();
    void print();
    float getCapacitateBaterie(){return this->capacitate_baterie;}
};

masina_electrica::masina_electrica(motor &m, std::string marca, std::string model, std::string culoare, int nr_locuri, float capacitate_baterie) : masina(m, marca,model,culoare,nr_locuri) {
    this->capacitate_baterie = capacitate_baterie;
}
void masina_electrica::sunet() {std::cout<<this->getModel()<<" este o masina electrica, deci nu face zgomot\n";}
void masina_electrica::print() {std::cout<<"\n##################\n"<<"Marca: "<<this->getMarca()
                                         <<"\n"<<"Model: "<<this->getModel()
                                         <<"\n"<<"Culoare: "<<this->getCuloare()
                                         <<"\n"<<"Nr locuri: "<<this->getNrLocuri()
                                         <<"\n"<<"Capacitate baterie: "<<this->capacitate_baterie<<"A"
                                         <<"\n"<<"Denumire motor: "<<getMotor().getDenumire()
                                         <<"\n"<<"Putere motor: "<<getMotor().getPutere()<<" Cai putere"
                                         <<"\n"<<"Consum motor: "<<getMotor().getConsum()<<" W"
                                         <<"\n##################\n\n";}