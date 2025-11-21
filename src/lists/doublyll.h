#include<iostream>
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
        int elem = n->elem;
        node* pred = n->prev;
        node* succ = n->next;
        pred->next = succ;
        succ->prev = pred;
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
            node* curr;
            if(pos <= size() / 2) {
                curr = header->next;
                for(int i=1; i<pos; i++) {
                    curr = curr->next;
                }
            } else {
                curr = trailer->prev;
                for(int i=size(); i>pos; i--) {
                    curr = curr->prev;
                }
            }
            return curr->elem;
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
            node* curr = header->next;
            while(curr != trailer) {
                cout << curr->elem;
                if(curr != trailer->prev) cout << " <--> ";
                curr = curr->next;
            }

            cout << "\nFROM TAIL: ";
            curr = trailer->prev;
            while(curr != header) {
                cout << curr->elem;
                if(curr != header->next) cout << " <--> ";
                curr = curr->prev;
            }
            cout << endl;
        } 

};