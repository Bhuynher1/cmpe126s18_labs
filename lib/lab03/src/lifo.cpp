#include "lifo.h"

namespace lab3{
    lifo::lifo() {
        lifo_storage.reserve(100);
        index = 0;
    }

    lifo::lifo(std::string input_string) {
        lifo_storage.append(input_string);
    }

    lifo::lifo(const lifo &original) {
        index = original.index;
    }

    lifo::~lifo() {

    }

    lifo &lifo::operator=(const lifo &right) {
        index = right.index;
        lifo_storage = right.lifo_storage;

        return *this;
        //return <#initializer#>;
    }

    bool lifo::is_empty(){
        return !size();
    }

    int lifo::size(){
        return (lifo_storage.size());
        //return 0;
    }

    std::string lifo::top(){
        return lifo_storage[index];
        //return std::__cxx11::string();
    }

    void lifo::push(std::string input) {
        if (lifo_storage.size() == index) {
            return;
        }
        else {
            lifo_storage[index] = input;
        }
        return;
    }

    void lifo::pop() {

    }
}