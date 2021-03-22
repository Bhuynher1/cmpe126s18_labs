#include "queue.h"
namespace lab5{
    queue::queue() {

    }

    queue::queue(std::string &data) {
        storage_structure.append(data);
    }

    queue::queue(const queue &original) {
        *this = original;
    }

    queue::~queue() {
        storage_structure.~linked_list();
    }

    queue &queue::operator=(const queue &RHS) {
        const queue* temp = &RHS;
        if (this == temp)
            return *this;

        storage_structure =  temp -> storage_structure;
        return *this;
    }

    bool queue::isEmpty() const {
        return storage_structure.isEmpty();
    }

    unsigned queue::queueSize() const {
        return storage_structure.listSize();
    }

    std::string queue::top() const {
        linked_list queue;
        queue = storage_structure;
        return queue.get_value_at(0);
    }

    void queue::enqueue(const std::string &data) {
        storage_structure.append(data);
    }

    void queue::dequeue() {
        storage_structure.remove(0);
    }

    std::ostream& operator<<(std::ostream &stream, queue &RHS) {
        for (int x = 0; x < RHS.queueSize(); x++){
            stream << RHS.top() << " ";
            RHS.dequeue();
        }
        return stream;
    }

    std::istream& operator>>(std::istream &stream, queue &RHS) {
        std::string input;
        getline(stream, input);
        RHS.enqueue(input);
        return stream;
    }
}
