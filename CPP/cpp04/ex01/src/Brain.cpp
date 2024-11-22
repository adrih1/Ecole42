#include "../includes/Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructed." << std::endl;
}

Brain::Brain(const Brain& autre)
{
	for (int i = 0; i < 100; i++)
		this->idead[i] = autre.ideas[i];
	std::cout << "Brain copied" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructed" << std::endl;
}

Brain::Brain& operator=(const Brain& autre)
{
	std::cout << "Assignement operator called" << std::endl
	if (this != &autre)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = autre.ideas[i];
	}
}


