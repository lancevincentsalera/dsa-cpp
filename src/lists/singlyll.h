#include <iostream>
#include "list.h"
#include "node.h"
using namespace std;

class SinglyLinkedList : public List {
    using node = lists::sll::node;
    node* head;
    node* tail;
    int _size;

    public:
        SinglyLinkedList() {
            head = nullptr;
            tail = nullptr;
            _size = 0;
        }

        ~SinglyLinkedList() {
            node* current = head;
            while(current) {
                node* next = current->next;
                free(current);
                current = next;
            }
        }

        // STEPS
        // 1. Create a new node, and check if it was created successfully
        // 2. Assign the value to the new node
        // 3. If the list is empty
        //   a. Set head to the new_node
        // 4. If the list is not empty
        //   a. Set tail's next to the new_node
        // 5. Update tail to the new node
        // 6. Increment size
        void addLast(int num) {
            node* new_node = (node*) calloc(1, sizeof(node));

            if(!new_node) return; // new_node == null, memory allocation failed
            new_node->elem = num;

            if(!head) { // head == null
                head = new_node;
            } else {
                tail->next = new_node;
            }
            tail = new_node;
            _size++;
        }

        void addFirst(int num) {
            node* new_node = (node*) calloc(1, sizeof(node));

            if(!new_node) return; // new_node == null, memory allocation failed
            new_node->elem = num;
            new_node->next = head;
            head = new_node;
            if(!tail) {
                tail = new_node;
            }
            _size++;
        }

        int removeFirst() {
            if(!head) return -1;
            node* temp = head;
            int elem = head->elem;
            head = head->next;
            free(temp);
            _size--;
            return elem;
        }

        int removeLast() {
            if(!tail) return -1;
            node *curr = head, *prev = nullptr;
            while(curr != tail) {
                prev = curr;
                curr = curr->next;
            }

            if(prev) {
                tail = prev;
                prev->next = nullptr;
            } else {
                head = tail = nullptr;
            }
            int elem = curr->elem;
            free(curr);
            _size--;
            return elem;
        }

        int get(int pos) {
            if(pos < 1 || pos > size()) return -1;
            node* curr = head;
            for(int i=1; i<pos; i++) {
                curr = curr->next;
            }
            return curr->elem;
        }

        int size() {
            return _size;
        }

        bool isEmpty() {
            return _size == 0;
        }

        // STEPS
        // 1. Start from the head node
        // 2. While the current node is not null
        //    a. Print the current node's element
        //    b. Move to the next node
        // 3. Print a newline at the end
        void print() {
            if(!head) {
                cout << "Linked List is empty." << endl;
                return;
            }
            
            node* current = head;
            while(current) { 
                cout << current->elem;
                if (current->next) cout << " -> ";
                current = current->next;
            }
            cout << endl;
        }
};