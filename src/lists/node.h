#pragma once
namespace lists {
    namespace sll {
        struct node {
            int elem;
            node* next;
        };
    }

    namespace dll {
        struct node {
            int elem;
            node* next;
            node* prev;
        };
    }
}