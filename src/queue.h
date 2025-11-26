#include "lists/singlyll.h"
class Queue {
    List* list;
    public:
        Queue() {
            list = new SinglyLinkedList();
        }

        void enqueue(int num) {
            list->addLast(num);
        }

        int dequeue() {
            return list->removeFirst();
        }

        int first() {
            return list->get(size());
        }

        int size() {
            return list->size();
        }

        bool isEmpty() {
            return size() == 0;
        }
};