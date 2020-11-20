#include "Creature.h"
#include <iostream>
#include <typeinfo>
#include <algorithm>

using namespace std;

// =====================
//  Creature Impl
// =====================

/**
 * Creature Default constructor.
 *
 * Just set values to 10.
 */
Creature::Creature() : health(10), strength(10) {}

/**
 * Two argument constructor for Creature.
 *
 * @param _health new value for health.
 * @param _strength new value for strength.
 */
Creature::Creature(int _health, int _strength) : health(_health), strength(_strength) {}

/**
 * Health accessor.
 *
 * @return health.
 */
int Creature::getHealth() const {
    return health;
}

/**
 * Strength accessor.
 *
 * @return strength.
 */
int Creature::getStrength() const {
    return strength;
}

/**
 * Base damage accessor.
 *
 * This returns the default damage for each Creature without its special attack damage.
 * (just a random number from 1 to the strength of the Creature)
 *
 * @return base damage of the implementing Creature.
 */
int Creature::getBaseDamage() const {
    return rand(1, getStrength());
}

/**
 * Creature name accessor
 *
 * Instead of passing down the responsibility of this accessor to the implementing class. The parent class
 * will instead handle the accessing of the creature name. This is makes it easier to update creature names
 * in the future.
 *
 * The creature names are not hardcoded but taken from the class name itself.
 *
 * @return The name of the Creature
 */
string Creature::getCreature() {
    string cName = (string) typeid(*this).name();
    cName = cName.substr(cName.find(' ') + 1); // Remove extra stuff that can be found on win typeid().name().

    cName.erase(remove_if(begin(cName), end(cName), [](char ch) {
        return std::isdigit(ch);
    }), cName.end()); // Remove the digit in front of the typeid().name() in linux.
    return cName;
}

// =====================
//  Human Impl
// =====================

/**
 * Human default constructor
 *
 * Calls Creature default constructor.
 */
Human::Human() : Creature() {}

/**
 * Damage accessor for Humans
 *
 * This just returns the base damage of a creature.
 *
 * @return Human damage.
 */
int Human::getDamage() const {
    return getBaseDamage();
}

// =====================
//  Elf Impl
// =====================

/**
 * Elf default constructor
 *
 * Calls two-arg Creature constructor with 8 for health and 13 for strength.
 */
Elf::Elf() : Creature(8, 13) {}

/**
 * Damage accessor for Elf
 *
 * The minimum damage is the base damage for the creature.
 * The damage could be doubled with a 10% chance.
 *
 * @return Elf damage
 */
int Elf::getDamage() const {
    int damage = getBaseDamage();
    if (is_lucky(0.1)) {
        cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
        damage += damage;
    }
    return damage;
}

// =====================
//  Demon Impl
// =====================

/**
 * Demon default constructor.
 *
 * A regular demon has 15 health and 15 strength.
 */
Demon::Demon() : Creature(15, 15) {}

/**
 * Two-arg constructor for Demon for sub classes.
 *
 * @param _health new health
 * @param _strength new strength
 */
Demon::Demon(int _health, int _strength) : Creature(_health, _strength) {}


int Demon::getDamage() const {
    int damage = getBaseDamage();
    if (is_lucky(0.05)) {
        damage += 50;
        cout << "Demonic attack inflicts " << 50 << " additional damage points!" << endl;
    }
    return damage;
}

// =====================
//  CyberDemon Impl
// =====================

CyberDemon::CyberDemon() : Demon(13, 17) {}

int CyberDemon::getDamage() const {
    return Demon::getDamage();
}

// =====================
//  Balrog Impl
// =====================

Balrog::Balrog() : Demon(11, 14) {}

int Balrog::getDamage() const {
    int damage = Demon::getDamage();
    int damage2 = Demon::getDamage();
    cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
    return damage + damage2;
}