#include "./includes/Brain.hpp"
#include "./includes/Dog.hpp"
#include "./includes/Cat.hpp"


#define RESET "\033[0m"
#define GREEN "\033[32m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"
#define BOLD_CYAN "\033[1;36m"

int main ()
{
	const int NUM_ANIMALS = 100;
    Animal *animals[NUM_ANIMALS];

	std::cout << BOLD_CYAN << "Creating Animals" << RESET << std::endl;
	for (int i = 0; i < NUM_ANIMALS; i++)
	{
		if(i % 2 == 0)
			animals[i] = new Dog();
		else 
			animals[i] = new Cat();
	}

	std::cout << GREEN << "\nAnimals making sound" << RESET << std::endl;
	for (int i = 0; i < NUM_ANIMALS; i++)
		animals[i]->makeSound();
	
	std::cout << GREEN << "\nDeleting Animals" << RESET << std::endl;
	for (int i = 0; i < NUM_ANIMALS; i++)
		delete animals[i];
	std::cout << BOLD_CYAN << "End of test" << RESET << std::endl;
	return (0);
}
