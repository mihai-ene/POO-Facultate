#include "motor.h"
class masina{
protected:
    std::string marca;
    std::string model;
    std::string culoare;
    int nr_locuri;
    motor Motor;
public:
    masina(motor&,std::string,std::string,std::string,int);
    ~masina();
    motor& getMotor(){return this->Motor;}
    std::string getModel(){return this->model;}
    std::string getMarca(){return this->marca;}
    std::string getCuloare(){return this->culoare;}
    int getNrLocuri(){return this->nr_locuri;}
    virtual void sunet();
    friend std::ostream& operator<<(std::ostream& os, const masina& m);
    masina& operator=(const masina &other){
        this->marca = other.marca;
        this->model = other.model;
        this->culoare = other.culoare;
        this->nr_locuri = other.nr_locuri;
        this->Motor = other.Motor;
    }
};


masina::masina(motor &m,std::string marca, std::string model, std::string culoare, int nr_locuri) : Motor(m){
    try {
        if (marca != "" && model != "" && culoare != "" && nr_locuri > 1) {
            this->marca = marca;
            this->model = model;
            this->culoare = culoare;
            this->nr_locuri = nr_locuri;
        } else
            throw 2;
    }
    catch (int Error){
        std::cout<<"Error code: "<<Error<<"\n"
                 <<"- Marca masinii nu poate fi nula"<<"\n"
                 <<"- Modelul masinii nu poate fi null"<<"\n"
                 <<"- Culoare masinii nu poate fi nula"<<"\n"
                 <<"- Numarul de locuri nu poate fi mai mic ca 1"<<"\n";
    }

}


masina::~masina(){std::cout<<"Am distrus masina "<<this->model<<"\n";}
void masina::sunet() {std::cout<<this->model<<" face Vruuuum\n";}

std::ostream& operator<<(std::ostream& os, const masina& m ){
    os <<"\n##################\n"<<"Marca: "<<m.marca
          <<"\n"<<"Model: "<<m.model
          <<"\n"<<"Culoare: "<<m.culoare
          <<"\n"<<"Nr locuri: "<<m.nr_locuri
          <<"\n"<<"Denumire motor: "<<m.Motor.getDenumire()
          <<"\n"<<"Putere motor: "<<m.Motor.getPutere()<<" Cai putere"
          <<"\n"<<"Consum motor: "<<m.Motor.getConsum()<<" %"
          <<"\n##################\n\n";
    return os;
}

