// Define the SLLQueue class
// and extend from the Queue class
#include "queue.h"
#include "../lists/singlyll.h"

class SLLQueue : public Queue {
    List* list;
    public:
        SLLQueue() {
            list = new SinglyLinkedList();
        }

        ~SLLQueue() {
            delete list;
        }

        void enqueue(int value) {
            list->addFirst(value);
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