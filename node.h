#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(){
        Node(0);
    }

    Node(T value){
        data = value;
    }

    void killSelf(){
        delete next;
        delete prev;
    }    
};

#endif