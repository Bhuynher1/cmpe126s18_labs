#include "../inc/hash_table.h"
#include <cmath>

namespace lab8{
    unsigned hash_table::hash_1(std::string to_hash) {
        // DJB2 Hashing Algorithm
        unsigned int hash = 5381;
        for(char c: to_hash){
            hash = ((hash << 5) + hash) + c;
        }
        return hash;
    }

    unsigned hash_table::hash_2(std::string to_hash) {
        // BKDR Hashing Algorithm
        unsigned int seed = 131;
        unsigned int hash = 0;
        for(char c: to_hash){
            hash = (hash * seed) + c;
        }
        return hash;
    }

    void hash_table::expand() {
        int prime = 0;

        int prevSize = current_size;
        auto *prevTable = hash_table_array;

        if(max_size == PRIMES[15])
            throw std::runtime_error("Max array size");

        for(int i = 0; i <= 15; i++)
        {
            prime = PRIMES[i];
            if(max_size < prime)
            {
                max_size = prime;
                break;
            }
        }
        hash_table_array = new key_value[max_size];
        current_size = 0;

        for(int i = 0; current_size < prevSize; i++)
        {
            if(!prevTable[i].key.empty())
                insert(prevTable[i].key, prevTable[i].value);
        }
        delete[] prevTable;
    }

    hash_table::hash_table(char type) {
        /*
         * Define the probing technique
         * 'l': Linear probing
         *          hash_1() + attempt
         * 'q': Quadratic probing
         *          hash_1() + attempt^2
         * 'd': Double Probing
         *          hash_1() + attempt * hash_2()
         *
         * Create a hash table with an initial size of 100
         */

        if( type == 'l' || type == 'q' || type == 'd')
            this -> probing = type;

        max_size = PRIMES[0];
        hash_table_array = new key_value[max_size];
        current_size = 0;
    }

    hash_table::~hash_table() {
        delete [] hash_table_array;
    }

    bool hash_table::insert(std::string key, int value) {
        // Insert a key according to the defined probing technique
        // If you run into an issue where you get an infinite collision loop,
        //   figure out a way to get out of the loop.
        unsigned hash = hash_1(key);
        for(int attempt = 0; attempt < max_size; attempt++)
        {
            unsigned index;
            if (probing == '1')
                index = (hash + attempt) % max_size;
            else if (probing == 'q')
                index = (hash + (attempt * attempt)) % max_size;
            else if (probing == 'd')
                index = (hash + attempt * hash_2(key)) % max_size;

            if(hash_table_array[index].key.empty())
            {
                hash_table_array[index].key = key;
                hash_table_array[index].value = value;
                current_size++;

                if(current_size >= max_size * 0.7)
                    expand();

                return true;
            }
            else if(hash_table_array[index].key == key)
                return false;
        }
        return false;
    }

    bool hash_table::in_table(std::string key){
        // Checks to see if that key is in the table.
        // Use the specified probing technique
        // Keep collisions in mind

        if(key.empty())
            throw std::runtime_error("key can't be empty");

        unsigned hash = hash_1(key);
        for(int attempt = 0; attempt < max_size; attempt++)
        {
            unsigned index;
            if (probing == 'l')
                index = (hash + attempt) % max_size;
            else if (probing == 'q')
                index = (hash + (attempt * attempt)) % max_size;
            else if (probing == 'd')
                index = (hash + attempt * hash_2(key)) % max_size;

            if(hash_table_array[index].key == key)
                return true;
        }
        return false;
    }

    int hash_table::get(std::string key) {
        // Get the int value from the node that has key
        // Use the specified probing technique
        if (key.empty())
            throw std::runtime_error("key cannot be empty");

        unsigned hash = hash_1(key);
        for (unsigned attempt = 0; attempt < max_size; attempt++) {
            unsigned index;
            if (probing == 'l')
                index = (hash + attempt) % max_size;
            else if (probing == 'q')
                index = (hash + unsigned(pow(attempt, 2))) % max_size;
            else if (probing == 'd')
                index = (hash + attempt * hash_2(key)) % max_size;

            if (hash_table_array[index].key == key)
                return hash_table_array[index].value;
        }
        return 0;
    }

    void hash_table::update(std::string key, int value){
        // Update a key in the hash table.
        // Keep collisions in mind
        // Use the specified probing technique

        unsigned hash = hash_1(key);
        for (unsigned attempt = 0; attempt < max_size; attempt++) {
            unsigned index;
            if (probing == 'l')
                index = (hash + attempt) % max_size;
            else if (probing == 'q')
                index = (hash + unsigned(pow(attempt, 2))) % max_size;
            else if (probing == 'd')
                index = (hash + attempt * hash_2(key)) % max_size;

            if (hash_table_array[index].key == key) {
                hash_table_array[index].value = value;
                return;
            }
        }
        insert(key, value);
    }

    void hash_table::remove(std::string key){
        // Remove an item from the hash table. Keep collisions in mind
        // Use the specified probing technique
        // If the item isn't in the table, do nothing.

        if (key.empty()) throw std::runtime_error("key cannot be empty");

        unsigned hash = hash_1(key);
        for (unsigned attempt = 0; attempt < max_size; attempt++) {
            unsigned index;
            if (probing == 'l')
                index = (hash + attempt) % max_size;
            else if (probing == 'q')
                index = (hash + unsigned(pow(attempt, 2))) % max_size;
            else if (probing == 'd')
                index = (hash + attempt * hash_2(key)) % max_size;

            if (hash_table_array[index].key == key) {
                hash_table_array[index].key.clear();
                hash_table_array[index].value = 0;
                current_size--;

                return;
            }
        }
    }

    std::string hash_table::to_string(){
        // Run through the entire array and create a string following this format. The {} brackets aren't part of the return
        // [{array location}]{key_value.key}:{key_value.int}

        std::string string;
        for (unsigned i = 0; i < max_size; i++)
            if (!hash_table_array[i].key.empty())
                string += "[" + std::to_string(i) + "]" + hash_table_array[i].key + ":" + std::to_string(hash_table_array[i].value) + "\n";
        return string;
    }
}
