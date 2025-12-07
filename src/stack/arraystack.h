// Define the ArrayStack class
// and extend from the Stack class
#include "stack.h"
#include "../lists/arraylist.h"

class ArrayStack : public Stack {
    List* list;
    public:
        ArrayStack() {
            list = new ArrayList();
        }

        ~ArrayStack() {
            delete list;
        }

        void push(int num) {
            list->addLast(num);
        }

        int pop() {
            return list->removeLast();
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