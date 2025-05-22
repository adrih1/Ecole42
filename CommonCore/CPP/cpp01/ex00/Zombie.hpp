#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
private:
    std::string name;

public:
    Zombie(std::string name);
    ~Zombie();
    void announce() const;
};

// Fonction pour créer un zombie sur le tas
Zombie* newZombie(std::string name);

// Fonction pour créer un zombie sur la pile et le faire se présenter immédiatement
void randomChump(std::string name);

#endif
