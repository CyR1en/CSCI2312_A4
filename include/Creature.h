//
// Created by CyR1en on 11/9/2020.
//

#ifndef CSCI2312_A4_CREATURE_H
#define CSCI2312_A4_CREATURE_H

#include <string>
#include <random>

template <typename T>
T rand(T a, T b) {
    std::random_device rd; // seeding object.
    std::mt19937 engine(rd()); // engine and seed it with rd;
    std::uniform_int_distribution<> rangeDist(a, b); // [a, b] range distribution
    return rangeDist(engine);
}

class Creature {
private:
    int health;
    int strength;

protected:
    int getBaseDamage() const;

public:
    Creature();

    Creature(int _health, int _strength);

    int getHealth() const;

    int getStrength() const;

    std::string getCreature();

    virtual int getDamage() const = 0;
};

class Human : public Creature {
public:
    Human();

    int getDamage() const override;
};

class Elf : public Creature {
public:
    Elf();

    int getDamage() const override;
};

class Demon : public Creature {
public:
    Demon();

    Demon(int _health, int _strength);

    int getDamage() const override;
};

class CyberDemon : public Demon {
public:
    CyberDemon();

    int getDamage() const override;
};

class Balrog : public Demon {
public:
    Balrog();

    int getDamage() const override;
};

#endif //CSCI2312_A4_CREATURE_H
