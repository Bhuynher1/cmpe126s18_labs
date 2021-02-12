#include "../inc/stringVector.h"

namespace lab2 {
    stringVector::stringVector() {
        this->data = nullptr;
        length = 0;
        allocated_length = 0;
    }

    stringVector::~stringVector() {
        delete[] data;
        data = nullptr;


    }

    unsigned stringVector::size() const{
        return length;
    }

    unsigned stringVector::capacity() const{
        return allocated_length;
    }

    void stringVector::reserve(unsigned new_size) {

        unsigned array1[new_size];
    //create new array that fills up to given size and doesnt take more than the given allocated size
    }

    bool stringVector::empty() const{
        if (array1 == )
    }

    void stringVector::append(std::string new_data) {
//case 1: array is empty;
//size: 5 capacity: 6;
//size: 6 capacity: 10;

//make new array with doubled capacity;
//copy data over to new array;
//change the pointer to point to the new array;
    }

    void stringVector::swap(unsigned pos1, unsigned pos2) {

    }

    stringVector &stringVector::operator=(stringVector const &rhs) {
        //return ;
    }

    std::string &stringVector::operator[](unsigned position) {
        //return ;
    }

    void stringVector::sort() {

    }
}