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
    }

    bool fifo::is_empty(){
        return !size();
    }

    int fifo::size(){
        return (back_index - front_index);
    }

    std::string fifo::top(){
        return fifo_storage[front_index];
    }

    void fifo::enqueue(std::string input) {
        fifo_storage.append(input);
        if (fifo_storage.capacity() <= back_index) {
            fifo_storage.reserve(fifo_storage.capacity() + 1);
        }
        back_index++;
    }

    void fifo::dequeue() {
        front_index++;
        if (front_index == back_index) {
            front_index = 0;
            back_index = 0;
        }
    }
}