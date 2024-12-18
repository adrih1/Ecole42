#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

Base  *generate()
{
    switch (rand() % 3)
    {
        case 0:
            std::cout << "Generated a new A" << std::endl;
			return (new A());
        case 1:
            std::cout << "Generated a new B" << std::endl;
            return (new B());
        default: 
            std::cout << "Generated a new C" << std::endl;
            return (new C());

    }
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
		std::cout << "  (identify Base*) Confirmed as an A." << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "  (identify Base*) Confirmed as a  B." << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "  (identify Base*) Confirmed as a  C." << std::endl;
	else
		std::cout << "  (identify Base*) Can't identify this Base*..." << std::endl;

}

void identify(Base &p)
{
    try
	{
		(void) dynamic_cast<A&>(p);
		std::cout << "  (identify Base&) Confirmed as an A." << std::endl;
		return;
	}
	catch (std::exception &e) { (void)e; }

	try
	{
		(void) dynamic_cast<B&>(p);
		std::cout << "  (identify Base&) Confirmed as a  B." << std::endl;
		return;
	}
	catch (std::exception &e) { (void)e; }

	try
	{
		(void) dynamic_cast<C&>(p);
		std::cout << "  (identify Base&) Confirmed as a  C." << std::endl;
		return;
	}
	catch (std::exception &e) { (void)e; }

	std::cout << "  (identify Base&) Can't identify this Base&..." << std::endl;
}

int	main(void)
{
	for (int cur = 0; cur < 5; cur++)
	{
		Base *randBase = generate();
		identify(randBase);
		identify(*randBase);
		delete randBase;
	}
	return 0;
}

