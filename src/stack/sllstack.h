// Define the SLLStack class
// and extend from the Stack class
#include "stack.h"
#include "../lists/singlyll.h"

class SLLStack : public Stack {
    List* list;
    public:
        SLLStack() {
            list = new SinglyLinkedList();
        }

        ~SLLStack() {
            delete list;
        }

        void push(int num) {
            list->addFirst(num);
        }

        int pop() {
            return list->removeFirst();
        }

        int top() {
            return list->get(size());
        }

        int size() {
            return list->size();
        }

        bool isEmpty() {
            return size() == 0;
        }
};