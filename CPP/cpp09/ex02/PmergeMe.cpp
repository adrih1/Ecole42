#include "PmergeMe.hpp"

PmergeMe::PmergeMe(): vecTime(0.0), deqTime(0.0) {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other) : vec(other.vec), deq(other.deq), vecTime(other.vecTime), deqTime(other.deqTime) {}


bool PmergeMe::parseInput(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error: Wrong number of inputs." << std::endl;
        return false;
    }
    for (int i = 1; i < ac; i++)
    {
        std::string arg = av[i];

        if (arg.empty())
        {
            std::cerr << "Error: Empty argument." << std::endl;
            return false;
        }
        for (size_t j = 0; j < arg.length(); j++)
        {
            if (!isdigit(arg[j]))
            {
                std::cerr << "Error: invalid character " << arg[j] << std::endl;
                return false;
            }
        }
        int number;
        std::istringstream iss(arg);
        iss >> number;
        if (number < 0)
        {
            std::cerr << "Error negative number " << number << "is forbidden." << std::endl;
            return false;
        } 
        vec.push_back(number);
        deq.push_back(number);
    }
    return (true);
}

void PmergeMe::printBefore() const
{
    std::cout << "Before: "; 
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::endl;
}


void PmergeMe::printAfter() const
{
    std::cout << "After: "; 
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::endl;
}

double PmergeMe::getTime() const
{
	return static_cast<double>(clock()) / CLOCKS_PER_SEC * 1000000.0;
}
