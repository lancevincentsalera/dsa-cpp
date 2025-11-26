#include "lists/doublyll.h"
class Deque {
    List* list;
    public:
        Deque() {
            list = new DoublyLinkedList();
        }

        void addFirst(int num) {
            list->addFirst(num);
        }

        void addLast(int num) {
            list->addLast(num);
        }

        int removeFirst() {
            return list->removeFirst();
        }
    
        int removeLast() {
            return list->removeLast();
        }

        int size() {
            return list->size();
        }

        bool isEmpty() {
            return size() == 0;
        }
};