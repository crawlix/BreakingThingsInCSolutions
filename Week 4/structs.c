#include <stdio.h>

// pew muss noch korrekt eingebunden werden
// ab drink health potion

typedef struct Gun{
    unsigned int ammo;
    unsigned int clipSize;
    unsigned int clipAmmo;
    unsigned int damage;
} Gun;

typedef struct Player{
    int health;
    int shield;
    Gun weapon;
    unsigned int money;
} Player;

typedef struct ShootingParty{
    Player attacker;
    Player defender;
} ShootingParty;

typedef struct Potion {
    unsigned int amount;
}Potion;

typedef struct Person {
    int money;
} Person;

typedef struct Family {
    Person mom;
    Person dad;
    Person kid;
}Family;


int howOftenCanIReload(Gun *weapon){
    unsigned int result = (weapon->ammo - weapon->clipAmmo) / weapon->clipSize;
    return result;
}

void reload(Gun *weapon){
    weapon->ammo -= weapon->clipSize - weapon->clipAmmo;
}

void pew (Gun *weapon){
    if(weapon->clipAmmo == 0){
        printf("You need to reload! \n");
        reload(weapon);
        weapon->clipAmmo = 25;
    }else{
        weapon->clipAmmo--;
    }
}

Player drinkPotion(Player *player, Potion *potion){
    player->health += potion->amount;
    return *player;
}



void calculateDmg(ShootingParty *shootingParty){
    pew(&(shootingParty->attacker.weapon));
    if(shootingParty->defender.shield > 0){
      shootingParty->defender.shield -= shootingParty->attacker.weapon.damage;
      shootingParty->defender.health += shootingParty->defender.shield;
      shootingParty->defender.shield = 0;
    }else{
    shootingParty->defender.health -= shootingParty->attacker.weapon.damage;
    }
}


void buyUselessSkin(Person *dad){
    dad->money -= 20;
}


int main(void){
    Gun pistol;
    Gun *pistolptr = &pistol;
    pistolptr->ammo = 125;
    pistolptr->clipAmmo = 12;
    pistolptr->clipSize = 12;
    pistolptr->damage = 1;

    printf("Current Ammo in Clip: %i \n", pistolptr->clipAmmo);
    pew(pistolptr);
    printf("Current Ammo in Clip: %i \n", pistolptr->clipAmmo);
    howOftenCanIReload(pistolptr);
    printf("How often can i reload?: %i \n", howOftenCanIReload(pistolptr));

    Gun machineGun = {100, 25, 25, 22};
    Player peter = {100, 50, machineGun, 20};

    Player dominik = {100, 50, machineGun, 20};

    
    ShootingParty party = {peter, dominik};
    ShootingParty *partyptr = &party;
    printf("Peter Ammo: %i \n", party.attacker.weapon.clipAmmo);
    printf("Dominik Shield: %i \n", party.defender.shield);
    printf("Dominik Leben: %i \n", party.defender.health);
    printf("Peter schießt auf Dominik\n");
    calculateDmg(partyptr);
    printf("Peter Ammo: %i \n", party.attacker.weapon.clipAmmo);
    printf("Dominik Shield: %i \n", party.defender.shield);
    printf("Dominik Leben: %i \n", party.defender.health);
    printf("Peter schießt auf Dominik \n");
    calculateDmg(partyptr);
    printf("Peter Ammo: %i \n", party.attacker.weapon.clipAmmo);
    printf("Dominik Shield: %i \n", party.defender.shield);
    printf("Dominik Leben: %i \n", party.defender.health);
    printf("Peter schießt auf Dominik \n");
    calculateDmg(partyptr);
    printf("Peter Ammo: %i \n", party.attacker.weapon.clipAmmo);
    printf("Dominik Shield: %i \n", party.defender.shield);
    printf("Dominik Leben: %i \n", party.defender.health);
    printf("Peter schießt auf Dominik \n");
    calculateDmg(partyptr);
    printf("Peter Ammo: %i \n", party.attacker.weapon.clipAmmo);
    printf("Dominik Shield: %i \n" , party.defender.shield);
    printf("Dominik Leben: %i \n", party.defender.health);
    printf("Peter schießt auf Dominik \n");

    
    ShootingParty kill = {dominik, peter};
    ShootingParty *killPtr = &kill;

    while(killPtr->defender.health > 0){
        calculateDmg(killPtr);
        printf("Dominik Ammo: %i \n", killPtr->attacker.weapon.clipAmmo);
        printf("Peter Shield: %i \n", killPtr->defender.shield);
        printf("Peter Leben: %i \n", killPtr->defender.health);
        printf("Dominik schießt auf Peter \n");
    } 
  
}
