#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
  public:
	WrongCat();
	WrongCat(std::string type);
	WrongCat(const WrongCat &src);

	WrongCat &operator=(const WrongCat &src);

	~WrongCat();

	void makeSound() const;
};

#endif