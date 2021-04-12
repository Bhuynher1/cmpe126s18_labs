#include "../inc/doubly_linked_list.h"

namespace lab6{
    doubly_linked_list::doubly_linked_list() {
        head = nullptr;
        tail = nullptr;
    }

    doubly_linked_list::doubly_linked_list(int input) {
        head = new node (input);
        tail = head;
    }

    doubly_linked_list::doubly_linked_list(std::vector<int> vector_input) {
        head = nullptr;
        tail = nullptr;
        for (int i = 0; i < size(); i++) {
            append(vector_input[i]);
        }
    }

    doubly_linked_list::doubly_linked_list(const doubly_linked_list &original) {
        node *temphead = original.head;

        if (original.size() != 0) {
            head = new node (temphead -> get_data());
            tail = head;

            while (temphead -> next != nullptr) {
                temphead = temphead -> next;
                node *temp = new node (temphead -> get_data());

                temp = tail -> next;
                tail = temp -> prev;
                tail = tail -> next;
            }
            while (tail -> next != nullptr) {
                tail = tail -> next;
            }
        }
        else {
            head = nullptr;
            tail = nullptr;
        }
    }

    doubly_linked_list::~doubly_linked_list() {
        node *temp = head;

        if (head != nullptr) {
            while (temp != nullptr) {
                head = head -> next;
                delete temp;
                temp = head;
            }

            head = nullptr;
        }
    }

    int doubly_linked_list::get_data(unsigned position) {
        unsigned i = 0;
        node *temp = head;

        while (temp && (i < position)) {
            temp = temp -> next;
            i++;
        }
        return temp -> get_data();
    }

    std::vector<int> doubly_linked_list::get_set(unsigned position_from, unsigned position_to) {
        std::vector<int> returnedSet;

        for (unsigned i = position_from; i <= position_to; i++) {
            returnedSet.push_back(get_data(i));
        }
        return returnedSet;
    }

    unsigned doubly_linked_list::size() const {
        unsigned i = 0;

        if (head == nullptr)
            return i;

        node *temp = head;

        while (temp != nullptr) {
            temp = temp -> next;
            ++i;
        }
        return i;
    }

    bool doubly_linked_list::is_empty() {
        return !head;
    }

    void doubly_linked_list::append(int input) {
        node *innode = new node(input);

        if (is_empty()) {
            head = innode;
            tail = innode;
        }
        else {
            tail -> next = innode;
            innode -> prev = tail;
            tail = tail -> next;
        }
    }

    void doubly_linked_list::insert(int input, unsigned int location) {
        node *inNode = new node (input);
        int pos = 0;

        if (is_empty()) {
            append(input);
        }
        else if (!location) {
            head -> next = inNode;
            inNode -> next = head;
            head = inNode;
        }
        else if (location >= size()) {
            tail -> next = inNode;
            inNode -> prev = tail;
            tail = tail -> next;
        }
        else {
            node *outNode = head;
            node *temp = head;

            while (pos < location) {
                if (pos != 0)
                    outNode = outNode -> next;
                temp = temp -> next;
                pos++;
            }
            inNode -> next = outNode -> prev;
            inNode -> prev = outNode;
            outNode -> next = inNode;
            temp -> prev = inNode;
        }
    }

    void doubly_linked_list::remove(unsigned location) {
        unsigned counter = 0;

        if (head) {
            if (!location && head -> next) {
                node *temp = head;
                head = head -> next;
                delete temp;
                head -> prev = nullptr;
            }
            else if (location >= 0 && head -> next == nullptr) {
                delete head;
                head = nullptr;
                tail = nullptr;
            }
            else if (location >= 0 && location <= size()) {
                node *temp = head;
                node *after = head;

                while (counter < location) {
                    temp = temp -> next;
                    if (counter) {
                        after = after -> next;
                    }
                    counter++;
                }
                after -> next = temp -> next;

                if (temp -> next) {
                    after = temp -> next;
                    after -> prev = temp -> prev;
                    delete temp;
                }
                else {
                    delete temp;
                    tail = after;
                    tail -> next = nullptr;
                }
            }
        }
        if (!head) {
            head = nullptr;
            tail = nullptr;
        }
    }

    doubly_linked_list doubly_linked_list::split(unsigned position) {
        doubly_linked_list split;
        node *curr = head;
        node * temp = head;

        if (position != 0) {
            int counter = 0;

            while (counter < position - 1) {
                curr = curr -> next;
                counter++;
            }
            temp = curr -> next;
        }

        while (temp) {
            split.append(temp -> get_data());
            temp = temp -> next;
        }

        if (position == 0) {
            while (head != nullptr)
                remove(0);
        }
        else {
            while (curr -> next != nullptr)
                remove(position);
        }
        return split;
    }

    doubly_linked_list doubly_linked_list::split_set(unsigned position_1, unsigned position_2) {
        doubly_linked_list splitSet;
        node *node1 = head;
        node *node2 = head;
        unsigned counter = 0, pos1 = 0, pos2 = 0;

        if (position_1 > position_2) {
            counter = position_1;
            position_1 = position_2;
            position_2 = counter;
        }

        while (pos1 < position_1) {
            node1 = node1 -> next;
            pos1++;
        }

        while (pos2 < position_2) {
            node2 = node2 -> next;
            pos2++;
        }

        while (node1 != node2) {
            splitSet.append(node1 -> get_data());
            node1 = node1 -> next;
        }
        splitSet.append(node1 -> get_data());

        for (int i = position_1; i < position_2 + 1; i++)
            remove(position_1);

        return splitSet;
    }

    void doubly_linked_list::swap(unsigned position_1, unsigned position_2) {
        node *swap1 = head;
        node *swap2 = head;
        unsigned counter = 0;

        if (position_2 < position_1) {
            counter = position_1;
            position_1 = position_2;
            position_2 = counter;
        }
        counter = 0;

        while (counter < position_2) {
            if (counter < position_1)
                swap1 = swap1 -> next;

            swap2 = swap2 -> next;
            counter++;
        }

        insert(swap1 -> get_data(), position_2 + 1);
        insert(swap2 -> get_data(), position_1 + 1);
        remove(position_1);
        remove(position_2);

    }

    void doubly_linked_list::swap_set(unsigned location_1_start, unsigned location_1_end, unsigned location_2_start,
                                      unsigned location_2_end) {
        node *swapA1 = head;
        node *swapB1 = head;
        node *swapA2 = head;
        node *swapB2 = head;
        unsigned counter = 0;

        if ((location_2_start + location_2_end) < (location_1_start + location_1_end)) {
            unsigned temp1 = location_1_start;
            unsigned temp2 = location_1_end;
            location_1_start = location_2_start;
            location_1_end = location_2_end;
            location_2_start = temp1;
            location_2_end = temp2;
        }

        if ((location_1_start == location_1_end) && (location_2_start == location_2_end))
            swap (location_1_start, location_2_start);

        else {
            while (counter < location_2_end) {
                if (counter < location_1_start) {
                    swapA1 = swapA1 -> next;
                }
                if (counter < location_1_end) {
                    swapB1 = swapA2 -> next;
                }
                if (counter < location_2_start) {
                    swapA2 = swapA2 -> next;
                }
                swapB2 = swapB2 -> next;
                counter++;
            }

            counter = 1;
            node *swapN = swapA2;
            for (int i = location_1_start; i < location_1_end + 1; i++) {
                insert(swapB1 -> get_data(), location_1_end + counter);
                counter++;
                swapN = swapN -> next;
            }

            unsigned calc1, calc2, calc3;

            for (int i = location_1_start; i < location_1_end + 1; i++) {
                remove(location_1_start);
            }

            calc2 = location_1_end - location_1_start;
            calc3 = location_2_end - location_2_start;

            if (calc2 > calc3) {
                calc1 = calc2 - calc3;
                for (int i = location_2_start; i < location_2_end + 1; i++)
                    remove (location_2_start - calc1);
            }
            else if (calc2 < calc3) {
                calc1 = calc3 - calc2;
                for (int i = location_2_start; i < location_2_end + 1; i++)
                    remove (location_2_start + calc1);
            }
            else {
                for (int i = location_2_start; i < location_2_end + 1; i++)
                    remove (location_2_start);
            }
        }
    }

    void doubly_linked_list::sort() {
        node *min = head;
        int counter;
        int temp = min -> get_data();

        for (int i = 0; i < size() - 1; i++) {
            if (i != 0) {
                min = head;
                counter = 0;

                while (counter != i) {
                    min = min -> next;
                    counter++;
                }
                temp = min -> get_data();
            }
            min = min -> next;

            for (int j = i + 1; j < size(); j++) {
                if (min -> get_data() < temp) {
                    temp = min -> get_data();
                    swap(i,j);
                    min = head;
                    for (int k = 0; k < j; k++) {
                        min = min -> next;
                    }
                }
                min = min -> next;
            }
        }
    }

    doubly_linked_list doubly_linked_list::operator+(const doubly_linked_list &rhs) const {
        doubly_linked_list add = *this;
        node *temp = rhs.head;

        while (temp) {
            add.append(temp -> get_data());
            temp = temp -> next;
        }
        return add;
    }

    doubly_linked_list& doubly_linked_list::operator=(const doubly_linked_list &rhs) {
        if (!rhs.head) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            node *temp = rhs.head;
            while (temp) {
                append (temp -> get_data());
                temp = rhs.head -> next;
            }
        }
        return *this;
    }

    doubly_linked_list& doubly_linked_list::operator+=(const doubly_linked_list &rhs) {
        node *addequal = rhs.head;

        while (addequal) {
            append(addequal -> get_data());
            addequal = addequal -> next;
        }
        return *this;
    }

    bool doubly_linked_list::operator==(const doubly_linked_list &rhs) {
        node *temp1 = this -> head;
        node *temp2 = rhs.head;

        if (rhs.size() != size())
            return false;

        while (temp1) {
            if (temp1 -> get_data() != temp2 -> get_data())
                return false;

            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
    }

    std::ostream &operator<<(std::ostream &stream, doubly_linked_list &RHS) {
        node *out = RHS.head;

        if (!out) {
            stream << "NULL";
        }
        else if (out) {
            stream << "NULL" << " <- " << out -> get_data() << " <-> ";
            out = out -> next;

            while (out -> next) {
                stream << out -> get_data() << " <-> ";
                out = out -> next;
            }
            stream << out -> get_data() << " -> " << "NULL";
        }
    }

    std::istream &operator>>(std::istream &stream, doubly_linked_list &RHS) {
        int in;
        stream >> in;
        RHS.append(in);
    }
}


