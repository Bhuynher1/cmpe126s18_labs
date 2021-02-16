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
        std::string *temp = new std::string[new_size];
        for (int i = 0; i < new_size; i++) {
            if (i < length) {
                temp[i] = data[i];
            }
            else {
                break;
            }
        }

        delete []data;
        data = temp;
        allocated_length = new_size;

        if (length > new_size) {
            length = new_size;
        }
    }

    bool stringVector::empty() const{
       return (length == 0);
    }

    void stringVector::append(std::string new_data) {
    std::string *temp = NULL;

    if (length == allocated_length) {
        data = new std::string[10];
        allocated_length = 10;
    }
    else {
        temp = new std::string[2 * allocated_length];
        for (int i = 0;i < length; i++) {
            temp[i] = data[i];
        }
        allocated_length = 2 * allocated_length;

        if (data != NULL) {
            delete []data;
            data = temp;
        }
    }

    data[length] = new_data;
    length++;
    }

    void stringVector::swap(unsigned pos1, unsigned pos2) {
        std::string string1;
        if ((pos1 >= length) || (pos2 >= length))
            return;

        string1 = data[pos1];
        data[pos1] = data[pos2];
        data[pos2] = string1;
    }

    stringVector &stringVector::operator=(stringVector const &rhs) {
        delete []data;
        length = rhs.length;
        allocated_length = rhs.allocated_length;

        this->data = new std::string[allocated_length];

        for (int i = 0; i < length; i++) {
            this -> data[i] = rhs.data[i];
        }
    }

    std::string &stringVector::operator[](unsigned position) {
        return data[position - 1];
    }

    void stringVector::sort() {
        std::string string1;

        for (int i = (length - 1); i < 0; i--) {
            for (int j = 0; i > 0; i--) {
                if (data[j].compare(data[j + 1]) > 0) {
                    string1 = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = string1;
                }
            }
        }
    }
}