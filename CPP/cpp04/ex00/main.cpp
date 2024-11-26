#include "includes/Dog.hpp"
#include "includes/Cat.hpp"
#include "includes/WrongCat.hpp"

// Explication de  l'interet de virtual - L'appel de fonction devient dynamique
// int main()
// {
//     const Animal* meta = new Animal();
//     const Animal* j = new Dog();

//     meta->makeSound();
//     j->makeSound();

//     delete meta;
//     delete j;
//     return 0;
// }

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl; 
    std::cout << i->getType() << " " << std::endl; 

    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;

    const WrongAnimal* metaWrong = new WrongAnimal();
    const WrongAnimal* k = new WrongCat();

    std::cout << k->getType() << " " << std::endl;

    k->makeSound();

    delete metaWrong;
    delete k;
    return (0);
}