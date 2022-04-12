#ifndef FORWARD_H
#define FORWARD_H
#include <iostream>
#include "list.h"

using namespace std;

// TODO: Implement all methods
template <typename T>
class ForwardList : public List<T> {
    private:
        Node<T>* head;
        int nodes;
    public:
        ForwardList() : List<T>() {}

        ~ForwardList(){ 
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
            Node<T>* temp = head;
            while(temp->next != nullptr) temp = temp->next;
            return temp->data;  
        }

        void push_front(T data){
            Node<T>* nuevo = new Node<T>;
            nuevo->data = data;
            nuevo->next = head;
            head = nuevo;
            ++nodes;
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
            ++nodes;
        }

        T pop_front(){
            if(head == nullptr) throw("Lista vacía");
            Node<T>* temp = head;
            T result = temp->data;
            head = temp->next;
            delete temp;
            --nodes;
            return result;
        }

        T pop_back(){
            if(head == nullptr) throw("Lista vacía");
            else if(head->next == nullptr){
                T result = head->data;
                delete head;
                head = nullptr;
                --nodes;
                return result;
            }
            else {
                Node<T>* temp = head;
                while(temp->next->next != nullptr) temp = temp->next;
                T result= temp->next->data;
                delete temp->next;
                temp->next = nullptr;
                --nodes;
                return result;
            }
        }

        T insert(T data, int pos){
            if(pos == 0){
                push_front(data);
            }
            else if(pos == nodes){
                push_back(data);
            }
            else{
                Node<T>* nodo = new Node<T>(data);
                Node<T>* temp = head;
                int i = 0;
                while(i++ < pos - 1) temp = temp->next;
                nodo->next = temp->next;
                temp->next = nodo;
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
                while(i++ < pos-1) temp = temp->next;
                std::cout<<"ga"<<temp->data<<"ga"<<std::endl;
                Node<T>* change = temp->next;
                temp->next = temp->next->next;
                change = nullptr;
                --nodes;
            }
        }

        T& operator[](int pos){
            if(pos < 0 || pos >= nodes){
                throw("Posicion fuera de limites");
            }
            else{
                Node<T>* temp = head;
                int i = 0;
                while(i++ < pos) temp = temp->next;
                return temp->data;
            }
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
            Node<T>* actual = head;
            Node<T>* prev = nullptr;
            Node<T>* next = nullptr;

            while (actual != nullptr)
            {
                next = actual->next;
                actual->next = prev;
                prev = actual;
                actual = next;
            }
            head = prev;
            
        }

        std::string name(){
            return "ForwardList";
        }
        
};

#endif