#include <memory>
#include "masina_electrica.h"

int main() {
    std::unique_ptr<motor> TestMotorException(new motor("",0,0.5));
    std::unique_ptr<motor> motor1(new motor("V12",300,2.2));

    std::unique_ptr<masina> TestMasinaException(new masina(*motor1,"","","",0));

    std::unique_ptr<masina> Dacie(new masina(*motor1,"Dacie","Duster","Rosie",5));

    std::unique_ptr<motor> motor_electric(new motor("Tesla Motor V2",600,200));
    std::unique_ptr<masina_electrica> tesla(new masina_electrica(*motor_electric, "Tesla","Model S", "Neagra",4,2000));

    std::cout<<*Dacie;
    std::cout<<*tesla;

    tesla->sunet();
    Dacie->sunet();


    return 0;
}
