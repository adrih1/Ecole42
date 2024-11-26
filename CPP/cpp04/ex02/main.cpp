#include "./includes/Brain.hpp"
#include "./includes/Dog.hpp"
#include "./includes/Cat.hpp"


//Main pour expliquer la classe abstraite 
// int main()
// {
// 	Animal *animal = new Animal();
// 	Animal *animal = new Dog();

// 	return (0);
// }


int main ()
{
	const int NUM_ANIMALS = 100;
    Animal *animals[NUM_ANIMALS];

	std::cout << "Creating Animals" << std::endl;
	for (int i = 0; i < NUM_ANIMALS; i++)
	{
		if(i % 2 == 0)
			animals[i] = new Dog();
		else 
			animals[i] = new Cat();
	}

	std::cout << "\nAnimals making sound" << std::endl;
	for (int i = 0; i < NUM_ANIMALS; i++)
		animals[i]->makeSound();
	
	std::cout << "\nDeleting Animals" << std::endl;
	for (int i = 0; i < NUM_ANIMALS; i++)
		delete animals[i];

	return (0);
}
