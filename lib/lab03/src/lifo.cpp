#include "lifo.h"

namespace lab3{
    lifo::lifo() {
        lifo_storage.reserve(100);
        index = 0;
    }

    lifo::lifo(std::string input_string) {
        lifo_storage.reserve(100);
        lifo_storage.append(input_string);
        index = 1;
    }

    lifo::lifo(const lifo &original) {
        lifo_storage = original.lifo_storage;
        index = original.index;
    }

    lifo::~lifo() {

    }

    lifo &lifo::operator=(const lifo &right) {
        if (this == &right)
            return *this;
        else {
            index = right.index;
            lifo_storage = right.lifo_storage;
        }
        return *this;
    }

    bool lifo::is_empty(){
        if (size() == 0)
            return true;
        else
            return false;
    }

    int lifo::size(){
        return index;
    }

    std::string lifo::top(){
        return lifo_storage.operator[](index - 1);
    }

    void lifo::push(std::string input) {
        lifo_storage.append(input);
        index++;
    }

    void lifo::pop() {
        lab3::lifo *temp = new lab3::lifo();
        for (int i = 0; i < lifo_storage.size() - 1; i++) {
            temp -> lifo_storage.append(lifo_storage.operator[](i));
        }
        lifo_storage = temp -> lifo_storage;
        index--;
    }
}