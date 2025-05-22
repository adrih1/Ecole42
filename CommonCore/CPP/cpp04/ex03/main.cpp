#include "includes/AMateria.hpp"
#include "includes/ICharacter.hpp"
#include "includes/Character.hpp"
#include "includes/IMateriaSource.hpp"
#include "includes/MateriaSource.hpp"
#include "includes/Ice.hpp"
#include "includes/Cure.hpp"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define ORANGE "\033[36m"
#define YELLOW "\033[33m"

// Main du sujet 
// int main()
// {
//     IMateriaSource* src = new MateriaSource();

//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());
    
//     ICharacter* me = new Character("me");
//     AMateria* tmp;
    
//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     tmp = src->createMateria("cure");
//     me->equip(tmp);
    
//     ICharacter* bob = new Character("bob");
//     me->use(0, *bob);
//     me->use(1, *bob);
    
//     delete bob;
//     delete me;
//     delete src;
    
//     return 0;
// }

int main()
{
	std::cout << "=== Materia System Comprehensive Test ===\n\n";

	// -----------------------------
	// Test 1: Learning and Creating Materias
	// -----------------------------
	std::cout << ">>> Test 1: Learning and Creating Materias\n";
	IMateriaSource *src = new MateriaSource();

	AMateria *tempMateria;

	// Learn Ice
	tempMateria = new Ice();
	src->learnMateria(tempMateria);
	delete tempMateria; // Prevent memory leak since MateriaSource clones the Materia

	// Learn Cure
	tempMateria = new Cure();
	src->learnMateria(tempMateria);
	delete tempMateria; // Prevent memory leak

	// Attempt to learn more than 4 Materias
	tempMateria = new Ice();
	src->learnMateria(tempMateria);
	delete tempMateria; // Prevent memory leak

	tempMateria = new Cure();
	src->learnMateria(tempMateria);
	delete tempMateria; // Prevent memory leak

	// Attempt to learn a fifth Materia (should not be learned)
	tempMateria = new Ice();
	src->learnMateria(tempMateria);
	delete tempMateria; // Prevent memory leak or handle accordingly
	// Since inventoryDelete is not used here, we delete the extra Materia to prevent leak

	std::cout << "\n";

	// -----------------------------
	// Test 2: Character Creation and Equipping Materias
	// -----------------------------
	std::cout << ">>> Test 2: Character Creation and Equipping Materias\n";
	ICharacter *me = new Character("me");

	AMateria *tmp;

	// Equip Ice
	tmp = src->createMateria("ice");
	if (tmp)
		me->equip(tmp); // Equip
	else
		std::cout << "Failed to create Materia 'ice'\n";

	// Equip Cure
	tmp = src->createMateria("cure");
	if (tmp)
		me->equip(tmp); // Equip
	else
		std::cout << "Failed to create Materia 'cure'\n";

	// Equip Ice
	tmp = src->createMateria("ice");
	if (tmp)
		me->equip(tmp); // Equip
	else
		std::cout << "Failed to create Materia 'ice'\n";

	// Equip Cure
	tmp = src->createMateria("cure");
	if (tmp)
		me->equip(tmp); // Equip
	else
		std::cout << "Failed to create Materia 'cure'\n";

	// Attempt to equip a fifth Materia (should fail and be deleted to prevent leak)
	tmp = src->createMateria("ice");
	if (tmp)
		me->equip(tmp); // Equip (will be stored in inventoryDelete or deleted if inventoryDelete is full)
	else
		std::cout << "Failed to create Materia 'ice'\n";

	std::cout << "\n";

	// -----------------------------
	// Test 3: Using Materias
	// -----------------------------
	std::cout << ">>> Test 3: Using Materias\n";
	ICharacter *bob = new Character("bob");

	me->use(0, *bob); // Expected: * shoots an ice bolt at bob *
	me->use(1, *bob); // Expected: * heals bob's wounds *
	me->use(2, *bob); // Expected: * shoots an ice bolt at bob *
	me->use(3, *bob); // Expected: * heals bob's wounds *
	me->use(4, *bob); // Invalid index, should do nothing

	std::cout << "\n";

	// -----------------------------
	// Test 4: Copy Constructor
	// -----------------------------
	std::cout << ">>> Test 4: Copy Constructor\n";
	Character original("original");
	original.equip(new Ice());
	original.equip(new Cure());

	// Create a copy of 'original' using the copy constructor
	Character copy = original;
	copy.use(0, *bob); // Expected: * shoots an ice bolt at bob *
	copy.use(1, *bob); // Expected: * heals bob's wounds *

	// Modify 'original' to ensure deep copy
	original.use(0, *bob); // Expected: * shoots an ice bolt at bob *
	original.use(1, *bob); // Expected: * heals bob's wounds *

	std::cout << "\n";

	// -----------------------------
	// Test 5: Assignment Operator
	// -----------------------------
	std::cout << ">>> Test 5: Assignment Operator\n";
	Character assigned("assigned");
	assigned.equip(new Cure());
	assigned.equip(new Ice());

	// Assign 'original' to 'assigned' using the assignment operator
	assigned = original;
	assigned.use(0, *bob); // Expected: * shoots an ice bolt at bob *
	assigned.use(1, *bob); // Expected: * heals bob's wounds *

	// Modify 'original' to ensure deep copy
	original.use(0, *bob); // Expected: * shoots an ice bolt at bob *
	original.use(1, *bob); // Expected: * heals bob's wounds *

	std::cout << "\n";

	// -----------------------------
	// Test 6: Unequipping Materias
	// -----------------------------
	std::cout << ">>> Test 6: Unequipping Materias\n";

	// Unequip Materia from slot 1
	me->unequip(1);
	std::cout << "After unequipping slot 1:\n";

	// Attempt to use unequipped Materia (should do nothing)
	me->use(1, *bob);

	// Unequip Materia from an invalid slot
	me->unequip(5); // Should do nothing

	std::cout << "\n";

	// -----------------------------
	// Test 7: Equipping NULL Materia
	// -----------------------------
	std::cout << ">>> Test 7: Equipping NULL Materia\n";
	me->equip(NULL); // Should do nothing and not cause any issues

	me->use(0, *bob); // Expected: * shoots an ice bolt at bob *
	me->use(2, *bob); // Expected: * shoots an ice bolt at bob *
	me->use(3, *bob); // Expected: * heals bob's wounds *

	std::cout << "\n";

	// -----------------------------
	// Test 8: Creating and Equipping Unknown Materia
	// -----------------------------
	std::cout << ">>> Test 8: Creating and Equipping Unknown Materia\n";
	AMateria *unknown = src->createMateria("fire"); // Should return NULL
	if (!unknown)
		std::cout << "Materia 'fire' is unknown and cannot be created.\n";
	else
	{
		me->equip(unknown); // Equip if possible
		std::cout << "Equipped unknown Materia 'fire' unexpectedly.\n";
		delete unknown;
	}

	std::cout << "\n";

	// -----------------------------
	// Test 9: Cleaning Up
	// -----------------------------
	std::cout << ">>> Test 9: Cleaning Up\n";
	delete bob;
	delete me;
	delete src;
	// 'original', 'copy', and 'assigned' are stack-allocated and will be destructed automatically

	std::cout << "\n=== End of Materia System Comprehensive Test ===\n";

	return 0;
}