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
    motor& operator=(const motor &other){
        this->denumire = other.denumire;
        this->putere = other.putere;
        this->consum = other.consum;
        return *this;
    }
};

