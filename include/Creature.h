//
// Created by CyR1en on 11/9/2020.
//

#ifndef CSCI2312_A4_CREATURE_H
#define CSCI2312_A4_CREATURE_H

#include <string>
#include <random>

// A Uniform Distribution template to aid #rand() with templating.
// Defines uniform_distribution in compile time.
template<class T>
using uniform_distribution =
typename std::conditional<
        std::is_floating_point<T>::value, // if T is a floating point
        std::uniform_real_distribution<T>, // uniform_distribution should be this.
        typename std::conditional< // else this.
                std::is_integral<T>::value, // condition if T is integral
                std::uniform_int_distribution<T>, // int distribution if true.
                void // else void
        >::type
>::type;

// Template function to generate a random generic type number from  a to b.
template<typename T>
T rand(T a, T b) {
    std::mt19937 engine(std::random_device{}()); // engine and seed it with rd;
    uniform_distribution<T> rangeDist(a, b); // [a, b] range distribution
    return rangeDist(engine);
}

// Simplify logic when implementing attack bonus.
auto is_lucky = [](float chance) { return rand(0.0, 1.0) <= chance; };

// Parent class for all of the Creatures
class Creature {
private:
    int health;
    int strength;

protected:
    // A protected function that gets the base damage
    // (generates a random random number based on the strength)
    int getBaseDamage() const;

public:
    // Default constructor
    Creature();

    // Two-argument constructor
    Creature(int _health, int _strength);

    // Health accessor
    int getHealth() const;

    // Strength accessor
    int getStrength() const;

    // Function to return the type of creature
    std::string getCreature();

    // Virtual function to return the damage of the creature
    virtual int getDamage() const = 0;
};

// Human sub class
class Human : public Creature {
public:
    // Human default constructor
    Human();

    // Implement abstract getDamage() func from parent class
    int getDamage() const override;
};

// Elf sub class
class Elf : public Creature {
public:
    // Elf default constructor
    Elf();

    // Implement abstract getDamage() func from parent class
    int getDamage() const override;
};

// Demon sub class (super class for all demons)
class Demon : public Creature {
public:
    // Demon default constructor
    Demon();

    // Two-argument constructor for demon sub class
    Demon(int _health, int _strength);

    // Implement abstract getDamage() func from parent class
    int getDamage() const override;
};

// CyberDemon sub class
class CyberDemon : public Demon {
public:
    // CyberDemon default constructor
    CyberDemon();

    // Implement abstract getDamage() func from parent class
    int getDamage() const override;
};

// Balrog sub class
class Balrog : public Demon {
public:
    // Balrog default constructor
    Balrog();

    // Implement abstract getDamage() func from parent class
    int getDamage() const override;
};

#endif //CSCI2312_A4_CREATURE_H
