#ifndef DOUBLY_H
#define DOUBLY_H
#include <iostream>
#include "list.h"



// TODO: Implement all methods
template <typename T>
class DoubleList : public List<T> {
    private:
        Node<T>* head;
        Node<T>* tail;
        int nodes;
    public:
        DoubleList() : List<T>() {}

        ~DoubleList(){ 
         	while (head != nullptr)
            {
                Node<T>* temp = head;
                head = head->next;
                delete temp;
            }
            nodes=0;           
        }

        T front(){
            return head->data;
        }

        T back(){
            return tail->data; 
        }
        
        void push_front(T data){
            Node<T>* nuevo = new Node<T>;
            nuevo->data = data;
            if(head == nullptr){
                head = nuevo;
                tail = nuevo;
            }
            else{
                nuevo->prev = nullptr;
                nuevo->next = head;
                head->prev = nuevo;
                head = nuevo;
            }
            ++nodes;
        }

        void push_back(T data){
            Node<T>* nuevo = new Node<T>;
            nuevo->data = data;
            if(head == nullptr){
                head = nuevo;
                tail = nuevo;
            }
            else{
                nuevo->prev = tail;
                nuevo->next = nullptr;
                tail->next = nuevo;
                tail = nuevo;
            }
            ++nodes;
        }

        T pop_front(){
            if(head == nullptr) throw("Lista vacia");
            T result = head->data;
            head = head->next;
            delete head->prev;
            --nodes;
            return result;
        }

        T pop_back(){
            if(head == nullptr) throw("Lista vacia");
            T result = tail->data;
            tail = tail->prev;
            delete tail->next;
            --nodes;
            return result;
        }

        T insert(T data, int pos){
            if(pos == 0){
                push_front(data);
            }
            else if(pos == nodes){
                push_back(data);
            }
            else{
                Node<T>* nuevo = new Node<T>;
                nuevo->data = data;
                Node<T>* temp = head;
                int i = 0;
                while(i++ < pos -1) temp = temp->next;
                nuevo->next = temp->next;
                nuevo->prev = temp;
                temp->next->prev = nuevo;
                temp->next = nuevo;
            }
            ++nodes;
            return data;
        }

        void remove(int pos){
            if(pos < 0 || pos > nodes){
                throw("Posicion fuera de limites");
            }
            else if(pos == 0){
                pop_front();
                --nodes;
            }
            else if(pos == nodes){
                pop_back();
                --nodes;
            }
            else{
                Node<T>* temp = head;
                int i = 0;
                while(i++ < pos) temp = temp->next;
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                temp = nullptr;
                --nodes;
            }
        }

        T& operator[](int pos){
            Node<T>* temp = head;
            int i = 0;
            while(i++ < pos) temp = temp->next;
            return temp->data;
        }

        bool is_empty(){
            return head==nullptr;
        }

        int size(){
            return nodes;
        }

        void clear(){
            while (head != nullptr)
            {
                Node<T>* temp = head;
                head = head->next;
                delete temp;
            }
            nodes=0;
        }
        
        void sort(){
            bool swap_r;
            Node<T>* rptr;
            Node<T>* lptr = nullptr;

            if(head == nullptr) throw("Lista vacia");

            do{
                rptr = head;
                swap_r = false;

                while (rptr->next != lptr)
                {
                    if(rptr->data > rptr->next->data){
                        swap(rptr, rptr->next);
                        swap_r = true;
                    }
                    rptr = rptr->next;
                }
                lptr = rptr;
            }
            while(swap_r);
        }

        bool is_sorted(){
            bool result = true;
            Node<T>* temp = head;
            while(temp->next != nullptr){
                if(temp->data > temp->next->data){
                    result = false;
                    break;
                }
                temp = temp->next;   
            }
            return result;
        }

        void reverse(){
            Node<T>* temp = nullptr;
            Node<T>* current = head;
            Node<T>* change =head;
            while(current != nullptr){
                temp = current->prev;
                current->prev = current->next;
                current->next = temp;
                current = current->prev;
            }

            head = tail;
            tail = change;
        }

        std::string name(){
            return "DoublyLikedList";
        }
};
#endif