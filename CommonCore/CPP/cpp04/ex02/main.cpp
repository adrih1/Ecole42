#include "./includes/Brain.hpp"
#include "./includes/Dog.hpp"
#include "./includes/Cat.hpp"
#include "includes/WrongCat.hpp"

#define RESET "\033[0m"
#define GREEN "\033[32m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"
#define BOLD_CYAN "\033[1;36m"


// Test de l'abstraction
void testAbstrcatClass()
{
	// AAnimal *animal = new AAnimal();
	// AAnimal *animal = new Dog();

}


void testAnimals()
{
    std::cout << BOLD_CYAN << "TEST ANIMALS" << RESET << std::endl;
    std::cout << GREEN << "Creating an animal, two dogs and two cats" << RESET << std::endl;
    const AAnimal* anonymousdog = new Dog();
    const AAnimal* rufus = new Dog("Rufus");
    const AAnimal* anonymouscat = new Cat();
    const AAnimal* norminet = new Cat("Norminet");

    std::cout << CYAN << "Checking types" << RESET << std::endl;
    std::cout << anonymousdog->getType() << " " << std::endl; 
    std::cout << rufus->getType() << " " << std::endl; 
    std::cout << anonymouscat->getType() << " " << std::endl; 
    std::cout << norminet->getType() << " " << std::endl; 

    std::cout << CYAN << "Testing 'makeSound' method" << RESET << std::endl;
    anonymousdog->makeSound();
    rufus->makeSound();
    anonymouscat->makeSound();
    norminet->makeSound();


    std::cout << CYAN << "Destroying class instances" << RESET << std::endl;
    delete anonymousdog;
    delete rufus;
    delete anonymouscat;
    delete norminet;
    std::cout << BOLD_CYAN << "End of test" << RESET << std::endl;
}


int main()
{
	// testAbstrcatClass();
    testAnimals();
    return (0);
}