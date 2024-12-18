#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>
#include <cctype>


template< typename T >

void iter(T *array, size_t array_size, void (*foo) (T &))
{
    if (array == NULL || foo == NULL)
        return ;
    for (size_t i = 0; i < array_size; i++)
        foo(array[i]);
}; 

#endif
