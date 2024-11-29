#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
protected:
	std::string type;

public:
	Animal();
	Animal(std::string type);
	Animal(const Animal &src);

	Animal &operator=(const Animal &src);

	virtual ~Animal();
	virtual void makeSound() const;

	std::string getType() const;
};