#include "lists/arraylist.h"
class Stack {
    List* list;
    public:
        Stack() {
            list = new ArrayList();
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