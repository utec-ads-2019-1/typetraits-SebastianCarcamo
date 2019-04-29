#ifndef LIST_H
#define LIST_H

#include "node.h"

template <typename Tr>
class List {     
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
      
    private:
        Node<T>* head;
        Operation cmp;
        int tamano = 0;
              
    public:
        // No mezclaste con master
        List() : head(nullptr) {};

        bool find(T search, Node<T> **&pointer) {
            pointer = &head;
            // No va a funcionar, por uqé estás llamando a !cmp?
            while(*pointer != nullptr && !cmp(search, (*pointer)->data)){
                pointer = &((*pointer)->next);
            }
            return (*pointer)->data == search && *pointer != nullptr; 
        }
             
        bool insert(T data) {
            Node<T>* added = new Node<T>(data);
            Node<T>** aux;
            if(find(data,aux)){
                return false;
            }
            tamano++;
            added->next = *aux;
            *aux = added;
            return true;

        }
             
        bool remove(T item) {
            Node<T> **aux;
            Node<T>* removed = *aux;
            if(!find(item,aux)){
                return false;
            }
            tamano--;
            *aux = (*aux)->next;
            delete removed;
            return true;
        }  
             
        int size() {
            return tamano;
        }

        T operator[](int index) {
            Node<T>* aux = head;
            for(int i = 0;i<index;i++){
                aux = aux->next;
                if(aux == nullptr){
                    throw out_of_range("Segmentation fault");
                }
            }
            return aux->data;
        }

        /*~List() {
            // Falta validar si head es null o no
            head->killSelf();
        } */        
};

#endif