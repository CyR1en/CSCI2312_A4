#include <iostream>
#include <type_traits>
#include "Creature.h"

/**
 * A template function that makes testing all of the creatures easy.
 *
 * T must a type of Creature.
 *
 * @tparam T a Generic Creature.
 */
template <typename T>
void test() {
    static_assert(std::is_base_of<Creature, T>::value, "T must be a type of Creature");

    Creature *creature = new T();
    std::cout << creature->getCreature() << " is attacking!" << std::endl;
    for(int i = 0; i < 5; i++)
        std::cout << creature->getCreature() << " dealt a total damage of: " << creature->getDamage() << std::endl;

    std::cout << std::endl;
}

int main() {
    test<Human>();
    test<Elf>();
    test<Demon>();
    test<CyberDemon>();
    test<Balrog>();
}
