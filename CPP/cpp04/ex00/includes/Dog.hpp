#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
  public:
	Dog();
	Dog(const std::string name);
	Dog(const Dog &src);

	Dog &operator=(const Dog &src);

	~Dog();

	void makeSound() const;
};