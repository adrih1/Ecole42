#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <cctype>



class OutOfBoundsException : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return "Index out of bounds";
	}
};


template< typename T >
class Array
{
private:
    T *_array; 
    unsigned int _size;

public: 
    // Constructors
    Array(): _size(0)
    {
        std::cout << "Default Constructor called: created empty Array of size 0" << std::endl;
        this->_array = new T[this->_size];
    }


    Array(unsigned int size): _size(size)
    {
        std::cout << "Constructor for an Array of " << size  << " called" << std::endl;
        if (size == 0)
			_array = NULL;
        else 
            this->_array = new T[this->_size];
    }

    Array(const Array &src): _size(src.size())
    {
        std::cout << "Copy Constuctor called" << std::endl;
        this->_array = NULL;
        *this = src;
    }


    // Destructor
    ~Array() 
    {
        if (this->_array != NULL)
            delete [] this->_array; 
    }


    //Overload Constructors 
    Array &operator=(const Array &src)
    {
        if (this->_array != NULL)
            delete [] this->_array;
        if (src.size() != 0)
        {
            this->_size = src.size();
            this->_array = new T[this->_size];
            for (unsigned int i = 0; i < this->size(); i++)
                this->_array[i] = src._array[i];
        }
        return (*this);
    }

    T &operator[](size_t index)
	{
		if (index >= _size)
			throw OutOfBoundsException();
		return _array[index];
	}


    // Getter 
    unsigned int size() const
    {
        return (this->_size);
    }



}; 

#endif
