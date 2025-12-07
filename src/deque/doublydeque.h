// Define the DoublyDeque class
// and extend from the Deque class
#include "deque.h"
#include "../lists/doublyll.h"

class DoublyDeque : public Deque {
    List* list;
    public:
        DoublyDeque() {
            list = new DoublyLinkedList();
        }

        ~DoublyDeque() {
            delete list;
        }

        void addFirst(int num) {
            list->addFirst(num);
        }

        void addLast(int num) {
            list->addFirst(num);
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