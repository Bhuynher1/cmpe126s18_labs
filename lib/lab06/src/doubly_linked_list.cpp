#include "../inc/doubly_linked_list.h"

namespace lab6{
    doubly_linked_list::doubly_linked_list() {
        head = nullptr;
        tail = nullptr;
    }

    doubly_linked_list::doubly_linked_list(int input) {
        append(input);
    }

    doubly_linked_list::doubly_linked_list(std::vector<int> vector_input) {
        for (int input : vector_input)
            append(input);
    }

    doubly_linked_list::doubly_linked_list(const doubly_linked_list &original) {
        *this = original;
    }

    doubly_linked_list::~doubly_linked_list() {
        while (!is_empty())
            remove(0);
    }

    int doubly_linked_list::get_data(unsigned position) {
        node *temp = head;

        for (unsigned i = 0; i < position; i++) {
            if (temp -> next == nullptr)
                throw std::runtime_error("Error accessing index");
            temp = temp -> next;
        }
        return temp -> get_data();
    }

    std::vector<int> doubly_linked_list::get_set(unsigned position_from, unsigned position_to) {
        std::vector<int> returnedSet;

        node *first = head;
        for (unsigned i = 0; i < position_from; i++) {
            if (first -> next == nullptr)
                throw std::runtime_error("Error starting index");

            first = first -> next;
        }

        node *curr = first;
        for (unsigned i = 0; i <= position_to - position_from; i++) {
            if (curr -> next == nullptr)
                throw std::runtime_error("Error ending index");

            returnedSet.push_back(curr -> get_data());
            curr = curr -> next;
        }
        return returnedSet;
    }

    unsigned doubly_linked_list::size() {
        unsigned i = 0;

        for (node *curr = head; curr != nullptr; curr = curr -> next)
            i++;

        return i;
    }

    bool doubly_linked_list::is_empty() {
        return head == nullptr;
    }

    void doubly_linked_list::append(int input) {
        node *innode = new node(input);

        if (is_empty()) {
            head = innode;
            tail = head;
        }
        else {
            tail -> next = innode;
            tail -> next -> prev = tail;
            tail = tail -> next;
        }
    }

    void doubly_linked_list::insert(int input, unsigned int location) {
        if (is_empty()) {
            if (location!= 0)
                throw std::runtime_error("Error inserting at location");

            append(input);
        }
        else if (location == 0) {
            node *preInsert = new node(input);
            preInsert -> next = head;
            head -> prev = preInsert;
            head = preInsert;
        }
        else {
            node *preLocation = head;
            for (unsigned i = 0; i < location - 1; i++) {
                preLocation = preLocation -> next;

                if (preLocation == nullptr)
                    throw std::runtime_error("Error inserting at location");
            }

            node *preInsert = new node(input);
            preInsert -> next = preLocation -> next;

            if (preLocation -> next != nullptr)
                preLocation -> next -> prev = preInsert;
            preInsert -> prev = preLocation;
            preLocation -> next = preInsert;

            if (preLocation -> next == nullptr) {
                tail = preLocation;
            }
        }
    }

    void doubly_linked_list::remove(unsigned location) {
        if (is_empty()) {
            throw std::runtime_error("Cannot remove element from an empty list");
        }
        else if (location == 0) {
            node *preRemove = head;
            head = preRemove -> next;

            if (head != nullptr)
                head -> prev = nullptr;
            delete preRemove;

            if (head == nullptr)
                tail = nullptr;
        }
        else {
            node *pre = head;

            for (unsigned i = 0; i < location - 1; i++) {
                pre = pre -> next;
                if (pre -> next == nullptr) {
                    throw std::runtime_error("Cannot remove element from location");
                }
            }
            node *preRemove = pre -> next;
            pre -> next = preRemove -> next;

            if (pre -> next != nullptr)
                pre -> next -> prev = pre;
            delete preRemove;

            if (pre -> next == nullptr)
                tail = pre;
        }
    }

    doubly_linked_list doubly_linked_list::split(unsigned position) {
        doubly_linked_list split;

        if (is_empty()) {
            return split;
        } else if (position == 0) {
            split.head = head;
            split.tail = tail;

            head = nullptr;
            tail = nullptr;
        } else {
            node *first = head;
            for (unsigned i = 0; i < position; i++) {
                first = first->next;
                if (first == nullptr) {
                    throw std::runtime_error("invalid split location");
                }
            }

            split.head = first;
            split.tail = tail;
            tail = first->prev;

            tail->next = nullptr;
            first->prev = nullptr;
        }

        return split;
    }

    doubly_linked_list doubly_linked_list::split_set(unsigned position_1, unsigned position_2) {
        doubly_linked_list split;

        node *node1 = head;
        for (unsigned i = 0; i < position_1; i++) {
            node1 = node1->next;
            if (node1 == nullptr) {
                throw std::runtime_error("Cannot start at location");
            }
        }

        node *node2 = head;
        for (unsigned i = 0; i < position_2; i++) {
            node2 = node2->next;
            if (node2 == nullptr) {
                throw std::runtime_error("Cannot end at location");
            }
        }

        split.head = node1;
        split.tail = node2;

        node1->prev->next = node2->next;
        node2->next->prev = node1->prev;

        node1->prev = nullptr;
        node2->next = nullptr;

        return split;
    }

    void doubly_linked_list::swap(unsigned position_1, unsigned position_2) {
        if (position_1 == position_2)
            return;

        int pos1 = get_data(position_1);
        int pos2 = get_data(position_2);

        remove(position_1);
        remove(position_2 - 1);

        insert(pos1, position_2 - 1);
        insert(pos2, position_1);
    }

    void doubly_linked_list::swap_set(unsigned location_1_start, unsigned location_1_end, unsigned location_2_start,
                                      unsigned location_2_end) {
        unsigned loc2 = location_2_start;
        for (unsigned loc1 = location_1_start; loc1 <= location_1_end; loc1++) {
            swap (loc1, loc2);
            loc2++;
        }
    }

    void doubly_linked_list::sort() {
        unsigned listSize = size();

        for (unsigned i = 0; i < listSize - 1; i++) {
            unsigned min = i;
            for (unsigned j = i + 1; j < listSize; j++) {
                if (get_data(j) < get_data(min))
                    min = j;
            }
            swap(i, min);
        }
    }

    doubly_linked_list doubly_linked_list::operator+(const doubly_linked_list &rhs) const {
        doubly_linked_list add(*this);
        add += rhs;
        return add;
    }

    doubly_linked_list& doubly_linked_list::operator=(const doubly_linked_list &rhs) {
        if (this == &rhs)
            return *this;

        while (head != nullptr)
            remove(0);

        *this += rhs;
        return *this;
    }

    doubly_linked_list& doubly_linked_list::operator+=(const doubly_linked_list &rhs) {
        for (node *curr = rhs.head; curr != nullptr; curr = curr -> next)
            append(curr -> get_data());

        return *this;
    }

    bool doubly_linked_list::operator==(const doubly_linked_list &rhs) {
        bool equal = false;
        node *node1 = head;
        node *node2 = rhs.head;

        while (!equal) {
            if ((node1 == nullptr) != (node2 == nullptr))
                return false;
            if ((node1 -> get_data()) != (node2 -> get_data()))
                return false;

            node1 = node1 -> next;
            node2 = node2 -> next;

            if (node1 == nullptr && node2 == nullptr)
                equal = true;
        }
        return true;
    }

    std::ostream &operator<<(std::ostream &stream, doubly_linked_list &RHS) {
        stream << "NULL <- ";
        for (node *element = RHS.head; element != nullptr; element = element -> next) {
            stream << std::to_string(element -> get_data());
            if (element -> next != nullptr)
                stream << " <-> ";
        }
        stream << " -> NULL";
        return stream;
    }

    std::istream &operator>>(std::istream &stream, doubly_linked_list &RHS) {
        int in;
        stream >> in;
        RHS.append(in);
        return stream;
    }
}


