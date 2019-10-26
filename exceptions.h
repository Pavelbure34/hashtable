#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <iostream>
#include <string>
#include <exception>
using namespace std;

struct IndexOutOfBoundException:public exception{
    const char* what() const throw(){
        return "IndexOutOfBoundException";
    }
};

struct InvalidInputException:public exception{
    const char* what() const throw(){
        return "InvalidInputException";
    }
};

#endif