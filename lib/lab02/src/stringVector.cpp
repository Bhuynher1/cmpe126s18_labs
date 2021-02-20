#include "../inc/stringVector.h"
#include <iostream>
#include <utility>

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
        std::string *temp = new std::string[new_size];

        if (new_size > capacity()) {
            for (int i = 0; i < allocated_length; i++) {
                    temp[i] = data[i];
            }
            delete []data;
            data = temp;

            allocated_length = new_size;
            length = new_size;
        }
        if (new_size < capacity()) {
            for (int i = 0; i < new_size; i++) {
                    temp[i] = data[i];
            }
            delete []data;
            data = temp;
        }
    }

    bool stringVector::empty() const{
       return (length == 0);
    }

    void stringVector::append(std::string new_data)
    {
        if (length == allocated_length) {
            reserve(length + 1);
            allocated_length = length + 1;
        }

            data[length] = new_data;
            length++;
    }

    void stringVector::swap(unsigned pos1, unsigned pos2) {
        std::string string1;
        if((pos1 > length) || (pos2 > length)){
            std::cout << "Index is out of bounds" << std::endl;
            return;
        }

        string1 = data[pos1];
        data[pos1] = data[pos2];
        data[pos2] = string1;
    }
//maybe error
    stringVector &stringVector::operator=(stringVector const &rhs) {
        if (this == &rhs) {
            return *this;
        }

        length = rhs.length;
        data = new std::string[length];
        allocated_length = rhs.allocated_length;

        for (int i = 0; i < length; i++) {
            data[i] = rhs.data[i];
        }

        return *this;
    }

    std::string &stringVector::operator[](unsigned position) {
        if (position > length) {
            throw std::out_of_range("Position out of range");
        }
        return data[position - 1];
    }

    void stringVector::sort() {
        for (int i = 0; i < length; i++) {
            for (int j = i + 1;j < length; j++) {
                if (data[j] > data[j + 1]) {
                    swap (j, j + 1);
                }
            }
        }
    }
}