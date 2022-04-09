#ifndef FORWARD_H
#define FORWARD_H
#include <iostream>
#include "list.h"

// TODO: Implement all methods
template <typename T>
class ForwardList : public List<T> {
    private:
        Node<T>* head;
        int nodes;

    public:
        ForwardList() : List<T>() {}

        ~ForwardList(){ 
         	// TODO            
        }

        T front(){
            throw ("sin definir");
        }

        T back(){
            throw ("sin definir");
        }

        void push_front(T data){
            Node<T>* nuevo = new Node<T>;
            nuevo->data = data;
            nuevo->next = head;
            head = nuevo;
        }

        void push_back(T data){
            Node<T>* nuevo = new Node<T>;
            nuevo->data = data;
            nuevo->next = nullptr;
            if(head == nullptr)
            head = nuevo;
            else {
                Node<T>* temp = head;
                while(temp->next != nullptr)        
                temp = temp->next;
                temp->next = nuevo;    
            }
        }

        T pop_front(){
            if(head == nullptr) return;
            Node<T>* temp = head;
            head=temp->next;
            delete temp;
        }

        T pop_back(){
            if(head->next == NULL){
                delete head;
                head = NULL;
            }
            else {
                Node<T>* temp = head;
                while(temp->next->next != NULL)
                temp = temp->next;
                delete temp->next;
                temp->next = NULL;
            }
        }

        T insert(T data, int pos){
            /*
            Node<T>* nodo = new Nodo(data);
            Node<T>* temp = head;
            int i = 0;
            while(i++ < pos - 1) temp = temp->next;
            nodo->next = temp->next;
            temp->next = nodo;
            return data;
            */
           throw ("sin definir");
        }

        bool remove(int pos){
            throw ("sin definir");
        }

        T& operator[](int pos){
            throw ("sin definir");
        }

        bool is_empty(){
            throw ("sin definir");
        }

        int size(){
            throw ("sin definir");
        }

        void clear(){
            throw ("sin definir");
        }
        
        void sort(){
            throw ("sin definir");
        }

        bool is_sorted(){
            throw ("sin definir");
        }

        void reverse(){
            throw ("sin definir");
        }

        std::string name(){
            return "ForwardList";
        }
        
};

#endif