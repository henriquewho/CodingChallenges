#ifndef LLIST_H
#define LLIST_H

// Define the class Linked List, with a nested class Node
// The LL has two sentinel nodes, tail and head to make the
// coding simpler. The LList can hold any primitive type. 


template <typename Object> 
class List {
private: 
    struct Node {
        Object data; 
        Node *prev; 
        Node *next; 
        Node (const Object &x = Object {}): data {x} {}
    };

private: 
    int theSize=0;
    Node *head; 
    Node *tail; 

public: 
    List () : theSize {0} {
        std::cout << "Main constructor called\n";
        head = new Node;
        tail = new Node; 
        head->next = tail; 
        tail->prev = head; 
    }

    void push_front(const Object &x){
        theSize++; 
        auto a = new Node(x); 

        a->next = head->next; 
        a->prev = head; 
        head->next->prev = a; 
        head->next = a; 
    }

    void push_back(const Object &x ){
        theSize++; 
        auto a = new Node(x); 

        a->next = tail; 
        a->prev = tail->prev; 
        tail->prev->next = a; 
        tail->prev = a;
    }

    Object pop_front(){
        theSize--; 
        head->next->next->prev = head; 
        head->next = head->next->next; 
    }

    Object pop_back(){
        theSize--; 
        tail->prev->prev->next = tail; 
        tail->prev = tail->prev->prev;
    }

    Object back(){
        return tail->prev->data; 
    }

    Object front(){
        return head->next->data; 
    }

    int size() const {return theSize;}

    void print(){
        auto temp = new Node;
        temp = head->next; 

        for (int i{}; i<theSize; i++){
            std::cout << temp->data << std::endl;
            temp = temp->next; 
        }        
    }
};

#endif