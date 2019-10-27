#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <iostream>
#include <string>
#include <exception>
using namespace std;

class IndexOutOfBoundException:public exception{
public:
    const char* what() const throw(){
        return "IndexOutOfBoundException";
    }
};

class InvalidInputException:public exception{
public:
    const char* what() const throw(){
        return "InvalidInputException";
    }
};

class noKeyException: public exception{
public:
    const char* what() const throw(){
        return "No Key was found";
    }
};

class fullTableException: public exception{
public:
    const char* what() const throw(){
        return "hash table has no empty slot left.";
    }
};

#endif