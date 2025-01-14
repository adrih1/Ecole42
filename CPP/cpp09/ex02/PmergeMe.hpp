#ifndef PMERGEME_HPP
#define PMERGEME_HPP


#include <climits>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>

#include <vector>
#include <deque>

class PmergeMe
{
public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);

    void setData(const std::vector<int> &data); 
    void setData(const std::deque<int> &data); 
    std::vector<int> & getData(); 
    std::deque<int> & getDeq(); 

private: 
    std::vector<int> m_data; 
    std::deque<int> m_deq; 
}; 

#endif 