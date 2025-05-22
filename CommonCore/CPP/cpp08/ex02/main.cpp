#include <iostream>
#include <vector>
#include "MutantStack.hpp"


int main() {
    // Utilisation avec le conteneur par défaut (std::deque)
    MutantStack<int> mstack;

    mstack.push(10);
    mstack.push(20);
    mstack.push(30);

    std::cout << "Iterating through MutantStack (default deque):" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Utilisation avec un std::vector comme conteneur
    MutantStack<int, std::vector<int> > mstackVec;

    mstackVec.push(100);
    mstackVec.push(200);
    mstackVec.push(300);

    std::cout << "Iterating through MutantStack (vector):" << std::endl;
    for (MutantStack<int, std::vector<int> >::iterator it = mstackVec.begin(); it != mstackVec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
