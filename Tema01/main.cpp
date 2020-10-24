#include <iostream>

/*
    In League of Legends:
        * Campion = Caracter.
        * Fiecare campion are:
            - un nume
            - standard dmg
            - standard HP
            - standard attack speed
            - standard movement speed
            - un skin
            - 4 abilitati (Q,W,E,R) si o pasiva
*/


class Abilities{

private:
    std::string passive_name;
    std::string q_ability_name;
    std::string w_ability_name;
    std::string e_ability_name;
    std::string r_ability_name;
    double q_dmg;
    double w_dmg;
    double e_dmg;
    double r_dmg;

public:

    // Getters & Setters //
    void setPassiveName(std::string passive_name){this->passive_name = passive_name;}
    std::string getPassiveName(){return passive_name;}

    void setQAbbilityName(std::string q_ability_name){this->q_ability_name = q_ability_name;}
    std::string getQAbbilityName(){return q_ability_name;}

    void setWAbbilityName(std::string w_ability_name){this->w_ability_name = w_ability_name;}
    std::string getWAbbilityName(){return w_ability_name;}

    void setEAbbilityName(std::string e_ability_name){this->e_ability_name = e_ability_name;}
    std::string getEAbbilityName(){return e_ability_name;}

    void setRAbbilityName(std::string r_ability_name){this->r_ability_name = r_ability_name;}
    std::string getRAbbilityName(){return r_ability_name;}

    void setQDmg(double q_dmg){this->q_dmg = q_dmg;}
    double getQDmg(){return q_dmg;}

    void setWDmg(double w_dmg){this->w_dmg = w_dmg;}
    double getWDmg(){return w_dmg;}

    void setEDmg(double e_dmg){this->e_dmg = e_dmg;}
    double getEDmg(){return e_dmg;}

    void setRDmg(double r_dmg){this->r_dmg = r_dmg;}
    double getRDmg(){return r_dmg;}

    void setAll(std::string passive_name,std::string q_ability_name,std::string w_ability_name,
    std::string e_ability_name,std::string r_ability_name,double q_dmg,double w_dmg,double e_dmg,double r_dmg){

        this->q_ability_name = q_ability_name;
        this->w_ability_name = w_ability_name;
        this->e_ability_name = e_ability_name;
        this->r_ability_name = r_ability_name;
        this->q_dmg = q_dmg;
        this->w_dmg = w_dmg;
        this->e_dmg = e_dmg;
        this->r_dmg = r_dmg;

    }

    // CONSTRUCTOR //
    Abilities(std::string passive_name,std::string q_ability_name,std::string w_ability_name,
                std::string e_ability_name,std::string r_ability_name,double q_dmg,double w_dmg,double e_dmg,double r_dmg){
        this->q_ability_name = q_ability_name;
        this->w_ability_name = w_ability_name;
        this->e_ability_name = e_ability_name;
        this->r_ability_name = r_ability_name;
        this->q_dmg = q_dmg;
        this->w_dmg = w_dmg;
        this->e_dmg = e_dmg;
        this->r_dmg = r_dmg;
    }

    // DEFAULT CONSTRUCTOR //
    Abilities(){
        this->q_ability_name = "NoName";
        this->w_ability_name = "NoName";
        this->e_ability_name = "NoName";
        this->r_ability_name = "NoName";
        this->q_dmg = 0;
        this->w_dmg = 0;
        this->e_dmg = 0;
        this->r_dmg = 0;
    }

    // DESTRUCTOR //
    ~Abilities(){
        std::cout<<"Destoying Abilites...\n";
    }
};

class Skin{

private:
    std::string name_of_skin;
    double price_in_RP;

public:

    // Getters & Setters //
    void setNameOfSkin(std::string name_of_skin){this->name_of_skin = name_of_skin;}
    std::string getNameOfSkin(){return name_of_skin;}

    void setPriceInRp(double price_in_RP){ this->price_in_RP = price_in_RP;}
    double getPriceInRp(){return price_in_RP;}

    void setAll(std::string name_of_skin, double price_in_RP){
        this->name_of_skin = name_of_skin;
        this->price_in_RP = price_in_RP;
    }

    // CONSTRUCTOR //
    Skin(std::string name_of_skin, double price_in_RP){
        this->name_of_skin = name_of_skin;
        this->price_in_RP = price_in_RP;
    }

    // DEFAULT CONSTRUCTOR //
    Skin()
    {
        this->name_of_skin = "";
        this->price_in_RP = 0;
    }

    // DESTURCTOR //
    ~Skin()
    {
        std::cout<<"Destroying "<<name_of_skin<<"\n";
    }
};

class Champion{

private:
    std::string name;
    double standard_dmg;
    double hp;
    double attack_speed;
    double movement_speed;
    Skin skin;
    Abilities abilities;

public:

    // Getters & Setters //
    void setName(std::string name){this->name = name;}
    std::string getName(){return name;}

    void setStandardDmg(double standard_dmg){this->standard_dmg = standard_dmg;}
    double getStandardDmg(){return standard_dmg;}

    void setHp(double hp){ this->hp = hp;}
    double getHp(){return hp;}

    void setAttackSpeed(double attack_speed){this->attack_speed = attack_speed;}
    double getAttackSpeed(){return attack_speed;}

    void setMovementSpeed(double movement_speed){ this->movement_speed = movement_speed;}
    double getMovementSpeed(){return movement_speed;}

    void setSkin(std::string name_of_skin, double price_in_rp){
        this->skin.setNameOfSkin(name_of_skin);
        this->skin.setPriceInRp(price_in_rp);
    }
    Skin getSkin(){return skin;}

    void setAbilites(std::string passive_name,std::string q_ability_name,std::string w_ability_name,
                     std::string e_ability_name,std::string r_ability_name,double q_dmg,double w_dmg,double e_dmg,double r_dmg){
        this->abilities.setPassiveName(passive_name);
        this->abilities.setQAbbilityName(q_ability_name);
        this->abilities.setWAbbilityName(w_ability_name);
        this->abilities.setEAbbilityName(e_ability_name);
        this->abilities.setRAbbilityName(r_ability_name);
        this->abilities.setQDmg(q_dmg);
        this->abilities.setWDmg(w_dmg);
        this->abilities.setEDmg(e_dmg);
        this->abilities.setRDmg(r_dmg);
    }
    Abilities getAbilites(){return abilities;}

    void setAll(std::string name,double standard_dmg,double hp,
    double attack_speed,double movement_speed,std::string name_of_skin,
    double price_in_rp, std::string passive_name,std::string q_ability_name,std::string w_ability_name,
    std::string e_ability_name,std::string r_ability_name,double q_dmg,double w_dmg,double e_dmg,double r_dmg){
        this->name = name;
        this->standard_dmg = standard_dmg;
        this->hp = hp;
        this->attack_speed = attack_speed;
        this->movement_speed = movement_speed;
        
        this->skin.setNameOfSkin(name_of_skin);
        this->skin.setPriceInRp(price_in_rp);
        /* Se poate inlocui cu this->skin.setAll(name_of_skin, price_in_rp); */
        
        this->abilities.setPassiveName(passive_name);
        this->abilities.setQAbbilityName(q_ability_name);
        this->abilities.setWAbbilityName(w_ability_name);
        this->abilities.setEAbbilityName(e_ability_name);
        this->abilities.setRAbbilityName(r_ability_name);
        this->abilities.setQDmg(q_dmg);
        this->abilities.setWDmg(w_dmg);
        this->abilities.setEDmg(e_dmg);
        this->abilities.setRDmg(r_dmg);
        /* Se poate inlocui cu this->abilites.setAll(passive_name, q_ability_name, w_ability_name,e_ability_name,r_ability_name, q_dmg, w_dmg, e_dmg, r_dmg); */
    }

    // CONSTRUCTOR //
    Champion(std::string name,double standard_dmg,double hp,
                double attack_speed,double movement_speed,std::string name_of_skin,
                double price_in_rp, std::string passive_name,std::string q_ability_name,std::string w_ability_name,
                std::string e_ability_name,std::string r_ability_name,double q_dmg,double w_dmg,double e_dmg,double r_dmg){
        this->name = name;
        this->standard_dmg = standard_dmg;
        this->hp = hp;
        this->attack_speed = attack_speed;
        this->movement_speed = movement_speed;
        
        this->skin.setNameOfSkin(name_of_skin);
        this->skin.setPriceInRp(price_in_rp);
        /* Se poate inlocui cu this->skin.setAll(name_of_skin, price_in_rp); */
        
        this->abilities.setPassiveName(passive_name);
        this->abilities.setQAbbilityName(q_ability_name);
        this->abilities.setWAbbilityName(w_ability_name);
        this->abilities.setEAbbilityName(e_ability_name);
        this->abilities.setRAbbilityName(r_ability_name);
        this->abilities.setQDmg(q_dmg);
        this->abilities.setWDmg(w_dmg);
        this->abilities.setEDmg(e_dmg);
        this->abilities.setRDmg(r_dmg);
        /* Se poate inlocui cu this->abilites.setAll(passive_name, q_ability_name, w_ability_name,e_ability_name,r_ability_name, q_dmg, w_dmg, e_dmg, r_dmg); */
    }


    // DEFAULT CONSTRUCTOR //
    Champion(){
        this->name = "NoName";
        this->standard_dmg = 0;
        this->hp = 0;
        this->attack_speed = 0;
        this->movement_speed = 0;
        
        this->skin.setNameOfSkin("NoName");
        this->skin.setPriceInRp(0);
        /* Se poate inlocui cu this->skin.setAll("", 0); */
        
        this->abilities.setPassiveName("NoName");
        this->abilities.setQAbbilityName("NoName");
        this->abilities.setWAbbilityName("NoName");
        this->abilities.setEAbbilityName("NoName");
        this->abilities.setRAbbilityName("NoName");
        this->abilities.setQDmg(0);
        this->abilities.setWDmg(0);
        this->abilities.setEDmg(0);
        this->abilities.setRDmg(0);
        /* Se poate inlocui cu this->abilites.setAll("NoName", "NoName","NoName","NoName","NoName", 0, 0, 0, 0); */
        
    }

    // DESTRUCTOR //
    ~Champion(){
        std::cout<<"Destroying "<< this->name<<"\n";
    }

    //  Functii prin care un campion foloseste o abilitate asupra altui campion//
    void useQ_on(Champion x){
        std::cout<<name<<" used his Q ability called "<<abilities.getQAbbilityName()<<" and dealt "<<abilities.getQDmg()<<" DMG to "<<x.name<<"\n";
    }

    void useW_on(Champion x){
        std::cout<<name<<" used his W ability called "<<abilities.getWAbbilityName()<<" and dealt "<<abilities.getWDmg()<<" DMG to "<<x.name<<"\n";
    }

    void useE_on(Champion x){
        std::cout<<name<<" used his E ability called "<<abilities.getEAbbilityName()<<" and dealt "<<abilities.getEDmg()<<" DMG to "<<x.name<<"\n";
    }

    void useR_on(Champion x){
        std::cout<<name<<" used his R ability called "<<abilities.getRAbbilityName()<<" and dealt "<<abilities.getRDmg()<<" DMG to "<<x.name<<"\n";
    }


};

int main() {

    Champion Yasuo("Yasuo",100,2000,2.5,350,"High Noon Yasuo",
            1350,"Way of the wanderer", "Steel Tempest", "Wind Wall",
            "Sweeping Blade", "Last Brath", 50, 25, 20, 100);
    Champion Tryndamere("Tryndamere", 90,2100,2.2,
            350,"Demonblade Tryndamere",1820,
            "Battle Fury", "Bloodlust", "Mocking Shout",
            "Spinning Slash", "Undying Rage",20,40,50,150);

    Yasuo.useQ_on(Tryndamere);
    Tryndamere.useQ_on(Yasuo);

    Yasuo.useW_on(Tryndamere);
    Tryndamere.useW_on(Yasuo);

    Yasuo.useE_on(Tryndamere);
    Tryndamere.useE_on(Yasuo);

    Yasuo.useR_on(Tryndamere);
    Tryndamere.useR_on(Yasuo);
    
    return 0;
}
