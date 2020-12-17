#include <memory>
#include "masina_electrica.h"

int main() {
    std::unique_ptr<motor> motor1 = std::make_unique<motor>("V12",300,2.2);

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
    std::unique_ptr<masina> BMW = std::make_unique<masina>(*motor1,"BMW","M4","Neagra",4,"automata",7,250);

    std::unique_ptr<motor> motor_electric = std::make_unique<motor>("Tesla Motor V2",600,200);
    std::unique_ptr<masina_electrica> tesla = std::make_unique<masina_electrica>(*motor_electric, "Tesla","Model S", "Neagra",4,"automata",6,270,2000);


    tesla->intrecere(*BMW);

    //std::cout<<*Dacie;
    //std::cout<<*tesla;

    // TESTARE FUNCTIE VIRTUALA
    //tesla->sunet();
    //Dacie->sunet();


    return 0;
}
