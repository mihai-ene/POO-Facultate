#include <iostream>

class motor{
private:
    std::string denumire;
    int putere;
    float consum;
public:
    motor(std::string, int, float);
    ~motor();
    std::string getDenumire() const;
    int getPutere() const;
    float getConsum() const;
    motor(const motor&);
};

motor::motor(std::string denumire, int putere, float consum){
    try{
        if (denumire !="" && putere>=50 && consum >= 1){
            this->denumire = denumire;
            this->putere = putere;
            this->consum = consum;
        }else{
            throw 1;
        }
    }
    catch (int Error){
        std::cout<<"Error code: "<<Error<<"\n"
                 <<"- Denumirea motorului nu poate fi nula"<<"\n"
                 <<"- Puterea motorului nu poate fi mai mica ca 50 de cai putere"<<"\n"
                 <<"- Consumul motorului nu poate fi mai mic ca 1%"<<"\n";
    }

};
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
