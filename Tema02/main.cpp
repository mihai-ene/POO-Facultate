#include <memory>
#include "masina_electrica.h"

template <typename T>
T getMaxHoursePower (T a, T b){
    if (a.getPutere() > b.getPutere())
        return a;
    else
        return b;
}

int main() {
    std::unique_ptr<motor> motor1 = std::make_unique<motor>("V12",300,2.2);
    std::unique_ptr<motor> motor2 = std::make_unique<motor>("V10",180,1.8);
    //PENTRU TESTAREA EXCEPTIEI DIN CONSTRUCTOR:
    /* try {
         std::unique_ptr<motor> motor_invalid = std::make_unique<motor>("", 0, 0.5);
     }
         catch(std::exception&e){
             std::cout<<e.what();
         }
     try {
         std::unique_ptr<masina> masina_invalida = std::make_unique<masina>(*motor1,"","","",0,"",0,0);
     }
         catch(std::exception &ex){
             std::cout<<ex.what();
         } */
    std::unique_ptr<masina> Dacie = std::make_unique<masina>(*motor1,"Dacie","Duster","Rosie",5,"manuala",5,180);
    //std::unique_ptr<masina> BMW = std::make_unique<masina>(*motor1,"BMW","M4","Neagra",4,"automata",7,250);

    std::unique_ptr<motor> motor_electric = std::make_unique<motor>("Tesla Motor V2",600,200);
    //std::unique_ptr<masina_electrica> tesla = std::make_unique<masina_electrica>(*motor_electric, "Tesla","Model S", "Neagra",4,"automata",6,270,2000);


    //Construiesc cele doua obiecte folosing Builder-ul de la masina deoarece, pentru a organiza o cursa intre cele doua masini, nu am nevoie de toate detaliile lor (ex:culoare,nr_locuri)
    masina_builder bmw_builder;
    masina BMW = bmw_builder.marcamasina("BMW").model("M4").cutie_viteza("automata").nr_viteze(7).viteza_maxima(250).Motor(*motor1).build();

    masina_builder tesla_builder;
    masina tesla = tesla_builder.marcamasina("Tesla").model("Model S").cutie_viteza("automata").nr_viteze(6).viteza_maxima(270).Motor(*motor_electric).build();

    // Inainte de cursa, stabilesc care masina are motorul cu cei mai multi cari putere.
    motor a;
    a = getMaxHoursePower<motor>(*motor1, *motor_electric);
    std::cout<<"Cel mai puternic motor: "<<a;

    tesla.intrecere(BMW);

    //std::cout<<*Dacie;
    //std::cout<<*tesla;

    // TESTARE FUNCTIE VIRTUALA
    //tesla->sunet();
    //Dacie->sunet();


    return 0;
}
