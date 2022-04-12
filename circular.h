#ifndef CIRCULAR_H
#define CIRCULAR_H
#include <iostream>
#include "list.h"

// TODO: Implement all methods
template <typename T>
class CircularList : public List<T> {  
    private:
        Node<T>* head;//sentinel
        int nodes; 
    public:
        CircularList() : List<T>() {
            head = new Node<T>; 
            head->next = head;
            head->prev = head;
            nodes = 0;
        }

        ~CircularList(){
           // TODO
        }

        T front(){
            return head->next->data;
        }

        T back(){
            return head->prev->data;
        }

        void push_front(T data){
            Node<T>* nuevo = new Node<T>;
            nuevo->data = data;

            if(nodes == 0){
                nuevo->next = head;
                nuevo->prev = head;
                head->next = nuevo;
                head->prev = nuevo;
            }
            else{
                nuevo->next = head->next;
                nuevo->prev = head;
                head->next = nuevo;
                head->next->prev = nuevo;
            }

            ++nodes;
        }

        void push_back(T data){
            Node<T>* nuevo = new Node<T>;
            nuevo->data = data;
            if(nodes == 0){
                nuevo->next = head;
                nuevo->prev = head;
                head->next = nuevo;
                head->prev = nuevo;
            }
            else{
                nuevo->next = head;
                nuevo->prev = head->prev;
                head->prev->next = nuevo;
                head->prev = nuevo;
            }

            ++nodes;
        }

        T pop_front(){
            if(nodes == 0) throw("Lista vacia");
            Node<T>* change = head->next;
            T result = change->data;
            head->next = head->next->next;
            head->next->prev = head;
            delete change;
            --nodes;
            return result;
        }

        T pop_back(){
            if(nodes == 0) throw("Lista vacia");
            Node<T>* change = head->prev;
            T result = change->data;
            head->prev->next = head;
            head->prev = head->prev->prev;
            
            
            delete change;
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
                while(i++ < pos) temp = temp->next;
                nuevo->next = temp->next;
                nuevo->prev = temp;
                temp->next->prev = nuevo;
                temp->next = nuevo;
            }
            ++nodes;
            return data;
        }

        void remove(int pos){
            
            if(pos < 0 || pos >= nodes){
                throw("Posicion fuera de limites");
            }
            else if(pos == 0){
                pop_front();
                --nodes;
            }
            else if(pos == nodes-1){
                pop_back();
                --nodes;
            }
            else{
                Node<T>* temp = head;
                int i = 0;
                while(i++ < pos) temp = temp->next;
                Node<T>* aux = temp->next;
                temp->next = temp->next->next;
                temp->next->prev = temp;
                delete aux;            
                --nodes;
            }
        }

        T& operator[](int pos){
            Node<T>* temp = head;
            int i = 0;
            while(i++ < pos+1) temp = temp->next;
            return temp->data;
        }

        bool is_empty(){
            return nodes == 0;
        }

        int size(){
            return nodes;
        }

        void clear(){
            int i = 0;
            while(i++ < nodes){
                Node<T>* temp = head->next;
                head->next = head->next->next;
                delete temp;
            }
            nodes=0;
        }
        
        void sort(){
            bool swap_r;
            Node<T>* rptr;
            Node<T>* lptr = head;

            if(nodes == 0) throw("Lista vacia");

            do{
                rptr = head->next;
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
            Node<T>* temp = head->next;
            while(temp->next != head){
                if(temp->data > temp->next->data){
                    result = false;
                    break;
                }
                temp = temp->next;   
            }
            return result;
        }

        void reverse(){
            Node<T>* actual = head;
            Node<T>* prev = nullptr;
            Node<T>* next = nullptr;

            do
            {
                next = actual->next;
                actual->next = prev;
                prev = actual;
                actual = next;
            } while (actual != head);

            head->next = prev;
            head->prev = prev;
        }

        std::string name(){
            return "CircularList";
        }


};

#endif