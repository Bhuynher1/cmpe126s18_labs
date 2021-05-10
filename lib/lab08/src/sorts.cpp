#include "doubly_linked_list.h"

namespace lab6{
    // Auxiliary Functions
    unsigned partition(doubly_linked_list& to_sort, int low, int high);

    doubly_linked_list recursive_merge_sort(doubly_linked_list to_sort);
    doubly_linked_list merge(doubly_linked_list left, doubly_linked_list right);

    void quicksort(doubly_linked_list& to_sort, int low, int high){
        unsigned size = (high - low) + 1;
        if (size < 2) return;

        if (low < high) {
            unsigned partitionIndex = partition(to_sort, low, high);
            quicksort(to_sort, low, partitionIndex - 1);
            quicksort(to_sort, partitionIndex + 1, high);
        }
    }
    unsigned partition(doubly_linked_list& to_sort, int low, int high){
        int pivot = to_sort.get_data(high);

        unsigned i = low;
        for (unsigned j = low; j < high; j++) {
            if (to_sort.get_data(j) < pivot) to_sort.swap(i++, j);
        }
        to_sort.swap(i, high);
        return i;
    }

    void mergesort(doubly_linked_list& to_sort){
        to_sort = recursive_merge_sort(to_sort);
    }

    doubly_linked_list recursive_merge_sort(doubly_linked_list to_sort) {
        unsigned listSize = to_sort.size();
        if (listSize < 2)
            return to_sort;

        doubly_linked_list left = to_sort.split_set(0, (listSize - 1) / 2);
        doubly_linked_list right = to_sort;

        left = recursive_merge_sort(left);
        right = recursive_merge_sort(right);

        return merge(left, right);
    }

        //Used for the merging the two lists

    doubly_linked_list merge(doubly_linked_list left, doubly_linked_list right) {
        doubly_linked_list list;

        unsigned leftSize = left.size(), rightSize = right.size();
        unsigned leftIndex = 0, rightIndex = 0;
        while (leftIndex < leftSize && rightIndex < rightSize) {
            if (left.get_data(leftIndex) <= right.get_data(rightIndex))
                list.append(left.get_data(leftIndex++));
            else
                list.append(right.get_data(rightIndex++));
        }

        while (leftIndex < leftSize)
            list.append(left.get_data(leftIndex++));
        while (rightIndex < rightSize)
            list.append(right.get_data(rightIndex++));

        return list;
        }
}