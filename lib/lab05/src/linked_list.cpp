#include <linked_list.h>
namespace lab5 {
    linked_list::linked_list() {
        tail = head = nullptr;
    }

    linked_list::linked_list(std::string &data) {
        node* temp = new node(data);
        head = tail = temp;

    }

    linked_list::linked_list(const linked_list &original) {
        node *temp;
        int counter = 0;

        temp = original.head;
        while (counter < original.listSize()) {
            append (temp -> data);
            temp = temp -> next;
            counter++;
        }
    }

    linked_list::~linked_list() {
        node *temp;
        while (head != nullptr){
            temp = head;
            head = head -> next;
            delete temp;
        }

        tail = nullptr;
    }

    linked_list &lab5::linked_list::operator=(const linked_list &RHS) {
        node *temp;
        int counter = 0;
        std::string test;

        if (RHS.head == nullptr)
            head = nullptr;

        else if (head == RHS.head)
            return *this;

        else {
            temp = RHS.head;
            while (counter < RHS.listSize()) {
                test = temp -> data;
                append (test);
                temp = temp -> next;
                counter++;
            }
        }
        return *this;
    }

    bool linked_list::isEmpty() const {
        return (head == nullptr);
    }

    unsigned linked_list::listSize() const {
        node *current = head;
        int size = 1;
        if (isEmpty())
            return 0;

        while (current -> next){
            current = current -> next;
            size++;
        }
        return size;
    }

    void linked_list::insert(const std::string input, unsigned int location) {
        node *current = head;
        node *temp = new node(input);

        if (location == 0){
            temp -> next = head;
            head = temp;
        }
        else if (0 < location){
            for (int i = 1; i < location; i++){
                current = current -> next;
            }

            temp -> next = current -> next;
            current -> next = temp;
        }
    }

    void linked_list::append(const std::string input) {
        node *temp = new node(input);
        node * curr = head;
        if (isEmpty()) {
            head = temp;
            tail = head;
        }
        else if (head -> next == nullptr){
            head -> next = temp;
            tail = temp;
        }
        else {
            while (curr -> next != nullptr){
                curr = curr -> next;
            }
            curr -> next = temp;
            tail = temp;
        }
    }

    void linked_list::remove(unsigned location) {
        if (isEmpty())
            throw;
        else if (location == 0 && head != nullptr){
            node *temp = head;
            head = head -> next;
            delete temp;
        }
        else {
            node *temp;
            node *curr;
            curr = head;
            for (int i=0;i<location-1;i++){
                curr = curr -> next;
            }
            temp=curr -> next;
            curr -> next = temp -> next;
            delete temp;
        }
    }

    std::ostream& operator<<(std::ostream &stream, linked_list &RHS) {
        node *curr = RHS.head;
        if (RHS.isEmpty())
            throw;
        while (curr != nullptr){
            stream << curr -> data << " -> ";
            curr = curr -> next;
        }
        stream << "NULL";
        return stream;
    }

    std::istream& operator>>(std::istream &stream, linked_list &RHS) {
        std::string input;
        getline(stream, input);
        RHS.append(input);
        return stream;
    }

    void linked_list::sort() {
        node* temp = head;

        while (temp!= nullptr) {
            node* min = temp;
            node* net = temp -> next;

            while (net != nullptr) {
                if (min -> data > net -> data)
                    min = net;
                net = net -> next;
            }

            std::string x = temp -> data;
            temp -> data = min -> data;
            min -> data = x;
            temp = temp -> next;
        }
    }

    std::string linked_list::get_value_at(unsigned location) const{
        node* temp = head;
        if (location > listSize() || location < 0)
            throw;
        else if (location == 0){
            return head -> data;
        }
        for (int i = 0; i < location; i++){
            if (temp -> next == nullptr)
                throw;
            temp = temp -> next;
        }
        return temp -> data;
    }
}