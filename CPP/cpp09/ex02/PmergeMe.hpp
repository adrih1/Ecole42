#ifndef PMERGEME_HPP
#define PMERGEME_HPP


#include <climits>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>

#include <vector>
#include <deque>

class PmergeMe
{
public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);

    bool parseInput (int ac, char **av);
    void printBefore() const;
    void printAfter() const;
    void sortContainers();
    void printTimes();

private: 
    std::vector<int> vec; 
    std::deque<int> deq; 

	double vecTime;
	double deqTime;


}; 

#endif 