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
        index = right.index;
        lifo_storage = right.lifo_storage;
        return *this;
    }

    bool lifo::is_empty(){
        return !size();
    }

    int lifo::size(){
        return index;
    }

    std::string lifo::top(){
        return lifo_storage[index - 1];
    }

    void lifo::push(std::string input) {
        if (lifo_storage.size() == index) {
            lifo_storage.append(input);
        }
        else
            lifo_storage[index] = input;
        index++;
    }

    void lifo::pop() {
        if (index > 0) {
            lifo_storage[index - 1] = "";
            index--;
        }
    }
}