#include "masina.h"

class masina_electrica : public masina{
private:
    float capacitate_baterie;
public:
    masina_electrica(motor&, std::string,std::string,std::string,int,std::string,int,int, float);
    void sunet() const;
    friend std::ostream& operator<<(std::ostream& os, const masina_electrica& m);
    float getCapacitateBaterie(){return this->capacitate_baterie;}
    void accelereaza(int &treapta_curenta,float &pozitie_curenta, float viteza,int delay) const ;
    ~masina_electrica();
};

