#include "motor.h"

motor::motor() {
    this->denumire = "";
    this->putere = 0;
    this->consum = 0;
}
motor::motor(std::string denumire, int putere, float consum){
    if (denumire !="" && putere>=50 && consum >= 1){
        this->denumire = denumire;
        this->putere = putere;
        this->consum = consum;
    }else
        throw std::invalid_argument("Argumentele pentru motor nu sunt valide\n");

}
motor::motor(const motor &other){
    this->denumire = other.denumire;
    this->putere = other.putere;
    this->consum = other.consum;
}
std::string motor::getDenumire() const{
    return this->denumire;
}
float motor::getConsum() const {
    return this->consum;
}
int motor::getPutere() const {
    return this->putere;
}

motor::~motor(){
    std::cout << "Am distrus motorul " << this->denumire <<"\n";
}
std::ostream& operator<<(std::ostream& os, const motor& m ){
    os <<"\n##################\n"<<"Denumire: "<<m.denumire
       <<"\n"<<"Putere: "<<m.putere
       <<"\n"<<"Consum: "<<m.consum
       <<"\n##################\n\n";
    return os;
}
