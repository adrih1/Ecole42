#include "includes/Dog.hpp"
#include "includes/Cat.hpp"
#include "includes/WrongCat.hpp"


#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"
#define BOLD_CYAN "\033[1;36m"

// Explication de  l'interet de virtual - L'appel de fonction devient dynamique
void testVirtual()
{
    std::cout << BOLD_CYAN << "Test Virtual" << RESET << std::endl;
    std::cout << GREEN << "Création d'un animal et d'un dog" << RESET << std::endl;
    const Animal* animal = new Animal();
    const Animal* dog = new Dog();

    std::cout << CYAN << "Test de la méthode make sound" << RESET << std::endl;
    animal->makeSound();
    dog->makeSound();


    delete animal;
    delete dog;
    std::cout << BOLD_CYAN << "Fin du test" << RESET << std::endl;
}

void testAnimals()
{
    std::cout << BOLD_CYAN << "TEST ANIMALS" << RESET << std::endl;
    std::cout << GREEN << "Creating an animal, two dogs and two cats" << RESET << std::endl;
    const Animal* animal = new Animal();
    const Animal* anonymousdog = new Dog();
    const Animal* rufus = new Dog("Rufus");
    const Animal* anonymouscat = new Cat();
    const Animal* norminet = new Cat("Norminet");

    std::cout << CYAN << "Checking types" << RESET << std::endl;
    std::cout << anonymousdog->getType() << " " << std::endl; 
    std::cout << rufus->getType() << " " << std::endl; 
    std::cout << anonymouscat->getType() << " " << std::endl; 
    std::cout << norminet->getType() << " " << std::endl; 

    std::cout << CYAN << "Testing 'makeSound' method" << RESET << std::endl;
    animal->makeSound();
    anonymousdog->makeSound();
    rufus->makeSound();
    anonymouscat->makeSound();
    norminet->makeSound();


    std::cout << CYAN << "Destroying class instances" << RESET << std::endl;
    delete animal;
    delete anonymousdog;
    delete rufus;
    delete anonymouscat;
    delete norminet;
    std::cout << BOLD_CYAN << "End of test" << RESET << std::endl;
}


void testWrongAnimals()
{
    std::cout << BOLD_CYAN << "\nTEST WRONG ANIMALS" << RESET << std::endl;
    std::cout << GREEN << "Creating a wrong animal and a wrong catm" << RESET << std::endl;
    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* anonymousCat = new WrongCat();
    const WrongAnimal* Norminet = new WrongCat("Norminet");

    std::cout << CYAN << "Vérification du type" << RESET << std::endl;
    std::cout << anonymousCat->getType() << " " << std::endl;
    std::cout << Norminet->getType() << " " << std::endl;

    std::cout << CYAN << "Testing 'makeSound' method" << RESET << std::endl;
    
    wrongAnimal->makeSound();
    anonymousCat->makeSound();
    Norminet->makeSound();

    std::cout << CYAN << "Destroying class instances" << RESET << std::endl;
    delete wrongAnimal;
    delete anonymousCat;
    delete Norminet;
    std::cout << BOLD_CYAN << "End of test" << RESET << std::endl;
}

int main()
{

    testAnimals();
    testWrongAnimals();
    return (0);
}