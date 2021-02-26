#include "fifo.h"

namespace lab3{
    fifo::fifo() {
    fifo_storage.reserve(100);
    front_index = 0;
    back_index = 0;
    }

    fifo::fifo(std::string input_string) {
        fifo_storage.append(input_string);
    }

    fifo::fifo(const fifo &original) {
        back_index = original.back_index;
        front_index = original.front_index;
    }

    fifo::~fifo() {

    }

    fifo &fifo::operator=(const fifo &right) {
        if (this == &right) {
            return *this;
        }

        front_index = right.front_index;
        back_index = right.back_index;
        fifo_storage = right.fifo_storage;

        return *this;
        //return <#initializer#>;
    }

    bool fifo::is_empty(){
        return !size();
    }

    int fifo::size(){
        return (fifo_storage.size());
    }

    std::string fifo::top(){
        return fifo_storage[front_index];
        //return std::__cxx11::string();
    }

    void fifo::enqueue(std::string input) {
        if (fifo_storage.size() == back_index) {
            return;
        }
        else {
                fifo_storage[back_index] = input;
                back_index++;
        }
        return;
    }

    void fifo::dequeue() {
        if (front_index == back_index) {
            return;
        }
        else {
            for (int i = 0; i < back_index - 1; i++) {
                fifo_storage[i] = fifo_storage[i + 1];
            }
            back_index--;
        }
        return;
    }
}