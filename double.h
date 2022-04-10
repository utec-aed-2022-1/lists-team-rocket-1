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
        int nodes=0;
    public:
        DoubleList() : List<T>() {}
        ~DoubleList(){ 
         	// TODO            
        }
        T front(){
            if (nodes==0){throw ("the list is empty");}
            return head->data;
        };

        T back(){
            if (nodes==0){throw ("the list is empty");}
            return tail->data;
        };

        void push_front(T data){
            Node<T>* new_node = new Node<T>(data);
            if (nodes==0){
                head = new_node;
                tail = new_node;
                nodes=1;
            }
            else{
                new_node->next = head;
                head->prev = new_node;
                head = new_node;
                nodes+=1;
            }
        };

        void push_back(T data){
            Node<T>* new_node = new Node<T>(data);
            if (nodes==0){
                head = new_node;
                tail = new_node;
                nodes+=1;
            }
            else{
                new_node->prev = tail;
                tail->next = new_node;
                tail = new_node;
                nodes+=1;
            }
        };

        T pop_front(){
            if (nodes==0){throw ("the list is alredy empty");};
            if (nodes==1){
                T valueToReturn = head->data;
                delete head;
                delete tail;
                head = nullptr;
                tail = nullptr;
                nodes-=1;
                return valueToReturn;
            }
            else{
                T valueToReturn = head->data;
                Node<T>* head_copy = head;
                head = head->next;
                head->prev = nullptr;
                delete head_copy;
                nodes-=1;
                return valueToReturn;
            }
        };

        T pop_back(){
            if (nodes==0){throw ("the list is alredy empty");};
            if (nodes==1){
                T valueToReturn = head->data;
                delete head;
                delete tail;
                head = nullptr;
                tail = nullptr;
                nodes-=1;
                return valueToReturn;
            }
            else{
                T valueToReturn = tail->data;
                Node<T>* tail_copy = tail;
                tail = tail->prev;
                tail->next = nullptr;
                delete tail_copy;
                nodes-=1;
                return valueToReturn;
            }
        };

        T insert(T data, int pos){
            if (pos==0){
                push_front(data);
            }
            else{
                Node<T>* head_copy = head;
                for(int i=0; i<pos-1; ++i){
                    head_copy = head_copy->next;
                }
                Node<T>* head_auxiliary = head_copy->next;
                Node<T>* new_node = new Node<T>(data);
                head_copy->next = new_node;
                new_node->next = head_auxiliary;
                new_node->prev = head_copy;
                head_auxiliary->prev = new_node;
            }
            nodes+=1;
            return data;
        };

        bool remove(int pos){
            if (nodes==0){throw ("the list is alredy empty");}
            if (pos==0){
                pop_front();
            }
            else if (pos==nodes-1){
                pop_back();
            }
            else{
                Node<T>* head_copy = head;
                for(int i=0; i<pos-1; ++i){
                    head_copy = head_copy->next;
                }
                Node<T>* head_auxiliary = (head_copy->next)->next;
                delete head_copy->next;
                head_copy->next=head_auxiliary;
                head_auxiliary->prev = head_copy;
            }
            nodes-=1;
        };

        T& operator[](int pos){
            if (pos<0 || pos>=nodes){throw ("the position is out of range");}
            else{
                Node<T>* head_copy = head;
                for(int i=0; i<pos; ++i){
                    head_copy = head_copy->next;
                }
                return head_copy->data;
            }
        };

        bool is_empty(){
            if(nodes==0){return true;}
            return false;
        };

        int size(){
            return nodes;
        };

        void clear(){
            if (nodes==0){throw ("the list is alredy empty");}
            Node<T>* head_copy = head;
            while(head->next!=nullptr){
                head = head->next;
                delete head_copy;
                head_copy = head;
            }
            delete head_copy;
            head_copy = nullptr;
            head = nullptr;
            tail = nullptr;
            nodes = 0;
        };

        void sort(){
            if(nodes==0 || nodes==1);
            else if(nodes==2){
                Node<T>* index0 = head;
                Node<T>* index1 = head->next;
                index1->next = index0;
                index0->next = nullptr;
                head = index1;
                tail = index0;
            }
            else{
                bool swap = true;
                while(swap){
                    swap = false;
                    for(int i=0; i<nodes-2; ++i){
                        Node<T>* index0 = head;
                        Node<T>* index1 = head->next;
                        Node<T>* index2 = head->next->next;
                        for(int j=0; j<i; ++j){
                            index0 = index0->next;
                            index1 = index1->next;
                            index2 = index2->next;
                        }
                        if(i==0 && i==nodes-3){
                            if(index0->data > index1->data){
                                index1->next = index0;
                                index0->next = index2;
                                index1->prev = nullptr;
                                index0->prev = index1;
                                head = index1;
                                if(index0->data > index2->data){
                                    index1->next = index2;
                                    index2->next = index0;
                                    index0->next = nullptr;
                                    index0->prev = index2;
                                    index2->prev = index1;
                                    tail = index0;
                                }
                            }
                            else{
                                if(index1->data > index2->data){
                                    index0->next = index2;
                                    index2->next = index1;
                                    index1->next = nullptr;
                                    index1->prev = index2;
                                    index2->prev = index0;
                                    tail = index1;
                                }
                            }
                        }
                        else if(i==0){
                            Node<T>* index3 = index0->next->next->next;
                            if(index0->data > index1->data){
                                index1->next = index0;
                                index0->next = index2;
                                index2->prev = index0;
                                index0->prev = index1;
                                index1->prev = nullptr;
                                head = index1;
                                if(index0->data > index2->data){
                                    index1->next = index2;
                                    index2->next = index0;
                                    index0->next = index3;
                                    index3->prev = index0;
                                    index0->prev = index2;
                                    index2->prev = index1;
                                }
                                swap = true;
                            }
                            else{
                                if(index1->data > index2->data){
                                    index0->next = index2;
                                    index2->next = index1;
                                    index1->next = index3;
                                    index3->prev = index1;
                                    index1->prev = index2;
                                    index2->prev = index0;
                                    swap = true;
                                }
                            }
                        }
                        else if(i==nodes-3){
                            if(index1->data > index2->data){
                                index0->next = index2;
                                index2->next = index1;
                                index1->next = nullptr;
                                index1->prev = index2;
                                index2->prev = index0;
                                tail = index1;
                                swap = true;
                            }
                        }
                        else{
                            if(index1->data > index2->data){
                                Node<T>* index3 = index0->next->next->next;
                                index0->next = index2;
                                index2->next = index1;
                                index1->next = index3;
                                index3->prev = index1;
                                index1->prev = index2;
                                index2->prev = index0;
                                swap = true;
                            }
                        }
                    }
                    if (swap == false){break;}
                }
            }
        }

        bool is_sorted(){
            if(nodes==0 || nodes==1){return true;}
            Node<T>* index0 = head;
            Node<T>* index1 = head->next;
            while(index1->next != nullptr){
                if(index0->data > index1->data)
                    return false;
                index0 = index0->next;
                index1 = index1->next;
            }
            return true;
        }

        void reverse(){
            if(nodes==0 || nodes==1);
            else{
                for(int i=0; i<nodes-1; ++i){
                    Node<T>* index0 = head;
                    Node<T>* index1 = head->next;
                    while(index1->next != nullptr){
                        index0 = index0->next;
                        index1 = index1->next;
                    }
                    index1->next = head;
                    index0->next = nullptr;
                    index1->prev = nullptr;
                    head = index1;
                    tail = index0;
                }
            }
        };
        std::string name(){
            return "DubleLinkedList";
        } 

        void display(){
            if(head!=nullptr){
              Node<T>* head_copy=head;
              while(head_copy->next != nullptr){
                std::cout<<head_copy->data<<" ";
                head_copy = head_copy->next;
              }
              std::cout<<head_copy->data<<std::endl;
              std::cout<<"head-data: "<<head->data<<std::endl;
            }
            std::cout<<"nodes: "<<this->nodes<<std::endl;
        }
};
#endif