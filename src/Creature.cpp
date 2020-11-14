#include "Creature.h"
#include <iostream>
#include <typeinfo>

using namespace std;

// Creature Impl
Creature::Creature() : health(10), strength(10) {}

Creature::Creature(int _health, int _strength) : health(_health), strength(_strength) {}

int Creature::getHealth() const {
    return health;
}

int Creature::getStrength() const {
    return strength;
}

int Creature::getBaseDamage() const {
    return rand(1, getStrength());
}

string Creature::getCreature() {
    string cName = (string) typeid(*this).name();
    return cName.substr(cName.find(' ') + 1);
}

// Human Impl
Human::Human() : Creature() {}

int Human::getDamage() const {
    int damage = getBaseDamage();
    return damage;
}

// Elf Impl
Elf::Elf() : Creature(8, 13) {}

int Elf::getDamage() const {
    int damage = getBaseDamage();
    if (rand(1, 100) <= 10) {
        cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
        damage += damage;
    }
    return damage;
}


// Demon Impl
Demon::Demon() : Creature(15, 15) {}

Demon::Demon(int _health, int _strength) : Creature(_health, _strength) {}

int Demon::getDamage() const {
    int damage = getBaseDamage();
    if (rand(1, 100) <= 5) {
        damage += 50;
        cout << "Demonic attack inflicts " << 50 << " additional damage points!" << endl;
    }
    return damage;
}

// CyberDemon Impl
CyberDemon::CyberDemon() : Demon(13, 17) {}

int CyberDemon::getDamage() const {
    return Demon::getDamage();
}

// Balrog impl
Balrog::Balrog() : Demon(11, 14) {}

int Balrog::getDamage() const {
    int damage = Demon::getDamage();
    cout << "Balrog speed attack inflicts " << damage << " additional damage points!" << endl;
    return Demon::getDamage() + damage;
}