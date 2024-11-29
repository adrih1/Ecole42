<<<<<<< HEAD
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
=======
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
>>>>>>> 412540f22a7ac7f3ee42edc048d78652fad56b73

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
<<<<<<< HEAD
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

return 0;
=======

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
>>>>>>> 412540f22a7ac7f3ee42edc048d78652fad56b73
}