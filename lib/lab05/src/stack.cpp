#include "stack.h"
namespace lab5{
    stack::stack() {

    }

    stack::stack(std::string &data) {
        storage_structure.append(data);
    }

    stack::stack(const stack &original) {
        storage_structure.operator= (original.storage_structure);
    }

    stack::~stack() {
        storage_structure.~linked_list();
    }

    stack &stack::operator=(const stack &RHS) {
        const stack* temp = &RHS;
        if (this == temp)
            return *this;

        storage_structure =  temp -> storage_structure;
        return *this;
    }

    bool stack::isEmpty() const {
        return storage_structure.isEmpty();
    }

    unsigned stack::stackSize() const {
        return storage_structure.listSize();
    }

    std::string stack::top() const {
        return storage_structure.get_value_at(storage_structure.listSize() - 1);
    }

    void stack::push(const std::string &data) {
        storage_structure.append(data);
    }

    void stack::pop() {
        storage_structure.remove(storage_structure.listSize() - 1);
    }

    std::ostream& operator<<(std::ostream &stream, stack &RHS) {
        return stream;
    }

    std::istream& operator>>(std::istream &stream, stack &RHS) {
        return stream;
    }
}