#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main()
{
    try
    {
        // Test avec std::vector
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);

        std::cout << "Testing with std::vector" << std::endl;
        std::cout << "Found: " << *easyfind(vec, 3) << std::endl;
        std::cout << "Searching for 10 in vector..." << std::endl;
        std::cout << "Found: " << *easyfind(vec, 10) << std::endl; // Devrait lancer une exception
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        // Test avec std::list
        std::list<int> lst;
        lst.push_back(10);
        lst.push_back(20);
        lst.push_back(30);
        lst.push_back(40);
        lst.push_back(50);

        std::cout << "\nTesting with std::list" << std::endl;
        std::cout << "Found: " << *easyfind(lst, 30) << std::endl;
        std::cout << "Searching for 100 in list..." << std::endl;
        std::cout << "Found: " << *easyfind(lst, 100) << std::endl; // Devrait lancer une exception
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        // Test avec std::deque
        std::deque<int> deq;
        deq.push_back(100);
        deq.push_back(200);
        deq.push_back(300);
        deq.push_back(400);
        deq.push_back(500);

        std::cout << "\nTesting with std::deque" << std::endl;
        std::cout << "Found: " << *easyfind(deq, 500) << std::endl;
        std::cout << "Searching for 999 in deque..." << std::endl;
        std::cout << "Found: " << *easyfind(deq, 999) << std::endl; // Devrait lancer une exception
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
