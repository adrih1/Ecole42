#include "Span.hpp"

void SubjectTest()
{
    std::cout << "Subject Test" << std::endl;
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl; // Expected 2
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;	// Expected 14

	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void AddingNumbersWithIterator()
{
    std::cout << "\nAdding Numbers With Iterator" << std::endl;
	try
	{
		Span sp = Span(5);
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(3);
        vec.push_back(5);
        vec.push_back(7);
        vec.push_back(11);
        sp.addNumbers(vec.begin(), vec.end());
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl; // Expected 2
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;	// Expected 10
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

}

void LargeSpan ()
{
    std::cout << "\nTest - Large Span" << std::endl;
	try
	{
        unsigned int largeSize = 10000;
		Span sp = Span(largeSize);
        for (unsigned int i = 0; i < largeSize; i++)
        {
            sp.addNumber(i);
        }
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl; // Expected 1
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;	// Expected 9999

		// Here we try to add one more number than the maximum size
		sp.addNumber(20);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void NotEnoughNumbers()
{
    std::cout << "\nTest - Not Enough Numbers" << std::endl;
    try
	{
		Span sp = Span(1);
		sp.addNumber(42);
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl; // Here we expect an exception
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void ErrorSpanIsFull ()
{
	std::cout << "\nTest - Span is Full" << std::endl;
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl; // Expected 2
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;	// Expected 14

		// Here we try to add one more number than the maximum size
		sp.addNumber(20);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}



int main()
{
    SubjectTest();
    AddingNumbersWithIterator();
    LargeSpan();
    NotEnoughNumbers();
    ErrorSpanIsFull();

    return (0);
}