#include <iostream>
#include "list.h"
#include "node.h"
using namespace std;

class DoublyLinkedList : public List {
    using node = lists::dll::node;
    node* header;
    node* trailer;
    int _size;

    void addBetween(int num, node* pred, node* succ) {
        node* new_node = (node*) calloc(1, sizeof(node));
        if(!new_node) return;
        new_node->elem = num;
        new_node->prev = pred;
        new_node->next = succ;
        pred->next = new_node;
        succ->prev = new_node;
        _size++;
    }

    int removeNode(node* n) {
        node* pred = n->prev;
        node* succ = n->next;
        pred->next = succ;
        succ->prev = pred;
        int elem = n->elem;
        free(n);
        _size--;
        return elem;
    }

    public:
        DoublyLinkedList() {
            header = (node*) calloc(1, sizeof(node));
            trailer = (node*) calloc(1, sizeof(node));
            header->next = trailer;
            trailer->prev = header;
            _size = 0;
        }

        ~DoublyLinkedList() {
            node* current = header;
            while(current) {
                node* next = current->next;
                free(current);
                current = next;
            }
        }

        void addFirst(int num) {
            addBetween(num, header, header->next);
        }

        void addLast(int num) {
            addBetween(num, trailer->prev, trailer);
        }

        int removeFirst() {
            if(isEmpty()) return -1;
            return removeNode(header->next);
        }

        int removeLast() {
            if(isEmpty()) return -1;
            return removeNode(trailer->prev);
        }

        int get(int pos) {
            if(pos < 1 || pos > size()) return -1;
            node* current;
            if(pos <= size() / 2) {
                current = header->next;
                for(int i = 1; i < pos; i++) {
                    current = current->next;
                }
            } else {
                current = trailer->prev;
                for(int i = _size; i > pos; i--) {
                    current = current->prev;
                }
            }
            return current->elem;
        }

        int size() {
            return _size;
        }

        bool isEmpty() {
            return size() == 0;
        }

        void print() {
            if(isEmpty()) {
                cout << "Empty" << endl;
                return;
            }
            cout << "FROM HEAD: ";
            node* current = header->next;
            while(current != trailer) {
                cout << current->elem;
                if(current != trailer->prev) cout << " -> ";
                current = current->next;
            }
            cout << "\nFROM TAIL: ";
            current = trailer->prev;
            while(current != header) {
                cout << current->elem;
                if(current != header->next) cout << " -> ";
                current = current->prev;
            }
            cout << endl;
        }
};