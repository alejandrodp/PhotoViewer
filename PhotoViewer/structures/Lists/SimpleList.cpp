#include <iostream>
#include "SimpleList.h"

/**
 * @brief Construct a new Simple List:: Simple List object
 * Este es el constructor de la lista Simple.
 * 
 */
SimpleList::SimpleList() {
    this->root = nullptr;
    this->size = 0;
}

/**
 * @brief Destroy the Simple List:: Simple List object
 * El destructor borra cada nodo que fue creado liberando la memoria.
 * 
 */
SimpleList::~SimpleList(){
    if(this->size == 1){
        delete root;
        root = nullptr;
    }else if(root != nullptr){
    struct Node* toDel = root;
    struct Node* next = root->next;
    while (next->next != nullptr) {
        delete toDel;
        toDel = next;
        next = next->next;
    }
    delete toDel;
    delete next;
    }
}

/**
 * @brief Construct a new Simple List:: Simple List object
 * Este método copia todos los nodos de la lista y coloca el puntero en la variable que se haya designado
 * @param other 
 */
SimpleList::SimpleList(const SimpleList &other){
    this->root = new struct Node(*other.root);
    this->size = other.size;
    struct Node* pivot = this->root;
    while (pivot->next != nullptr){
        pivot->next = new struct Node(*(pivot->next));
        pivot = pivot->next;
    }
}

/**
 * @brief Add new elements
 * Añade nuevos elementos a la lista en el final.
 * @param value El vlor quese desea añadir
 */
void SimpleList::AddEnd(int value){
    struct Node* adding = new struct Node;
    adding->value = value;
    adding->next = nullptr;
    if (root == nullptr){
         root = adding;
    }else{
        struct Node* pivot = root;
        while (pivot->next != nullptr){
            pivot = pivot->next;
        }
        pivot->next = adding;
    }
    this->size++;
}

/**
 * @brief Add new elements
 * Añade nuevos elementos al principio de la lista
 * @param value El elemento que se desea añadir.
 */
void SimpleList::AddStart(int value){
    struct Node* adding = new struct Node;
    adding->value = value;
    adding->next = nullptr;
    if (root == nullptr){
        root = adding;
    }else{
        adding->next = root;
        root = adding;
    }
    this->size++;
}

/**
 * @brief Delete elements
 * Eliminar el primer elemento de la lista
 * @return true Si se logró eliminar el elemento
 * @return false Si no se logró eliminar el elemento
 */
bool SimpleList::DelStart(){
    if(root == nullptr){
        return false;
    }else{
        struct Node* toDelete = root;
        root = toDelete->next;
        delete toDelete;
        this->size--;
        return true;
    }
}

/**
 * @brief Delete elements
 * Eliminar el último elemento de la lista
 * @return true Si se logró eliminar el elemento
 * @return false Si no se logró eliminar el elemento
 */
bool SimpleList::DelEnd(){
    if(root == nullptr){
        return false;
    }else if (root->next == nullptr) {
        delete root;
        root = nullptr;
    }else{
        struct Node* prevToLast = root;
        while(prevToLast->next->next != nullptr){
            prevToLast = prevToLast->next;
        }
        delete prevToLast->next;
        prevToLast->next = nullptr;
    }
    this->size--;
    return true;
}

/**
 * @brief Add elements in custom position
 * Añade nuevos elementos en una cierta posición
 * 
 * @param value El elemento a insertar
 * @param pos La posición en la lista
 * @return true Si se logra insertar el elemento
 * @return false Si no se logra insertar el elemento
 */
bool SimpleList::AddPosition(int value, unsigned int pos){
    if(pos > this->size){
        return false;
    }else if(pos == 0){
        AddStart(value);
    }else{
        struct Node* adding = new struct Node;
        adding->next = nullptr;
        adding->value = value;
        struct Node* index = root;
        for(unsigned int i=0; i<(pos-1); i++){
            index = index->next;
        }
        adding->next = index->next;
        index->next = adding;
        this->size++;
    }
    return true;
}

/**
 * @brief Deletes elements in custom position
 * Elimina elementos en unna posición determinada
 * @param pos Posición en la lista
 * @return true Si se logró eliminar el elemento
 * @return false Si no se logró eliminar el elemento
 */
bool SimpleList::DelPosition(unsigned int pos){
    if(pos > this->size or this->size == 0){
        return false;
    }else if(pos == 0){
        this->DelStart();
    }else{
        struct Node* nextToDeleting = root;
        for(unsigned int i=0; i<(pos-1); i++){
            nextToDeleting = nextToDeleting->next;
        }
        struct Node* toDelete = nextToDeleting->next;
        nextToDeleting->next = toDelete->next;
        delete toDelete;
        this->size--;
    }
    return true;
}

/**
 * @brief Get values of certain position
 * Obtiene elementos en una posición determinada
 * @param pos Posición en la lista
 * @return int El elemento solicitado
 */
int SimpleList::getValue(unsigned int pos){
    if(pos > this->size or this->size == 0){
        return -1000;
    }else if(pos == 0){
        return root->value;
    }else{
        struct Node* searching = root;
        for(unsigned int i=0; i<(pos-1); i++){
            searching = searching->next;
        }
        if(searching->next == nullptr) return searching->value; else return searching->next->value;
    }
}

/**
 * @brief Change value of certain element
 * Cambia el valor de un elemento en una posición determinada
 * @param value El nuevo valor a insertar
 * @param pos La posición en la lista
 * @return true Si se logró hacer el cambio
 * @return false Si no se logró hacer el cambio
 */
bool SimpleList::EditPosition(int value, unsigned int pos){
    if(pos > this->size or this->root == nullptr){
        return false;
    }else if(pos == 0){
        this->root->value = value;
    }else{
        struct Node* searching = root;
        for(unsigned int i=0; i<(pos-1); i++){
            searching = searching->next;
        }
        searching->next->value = value;
    }
    return true;
}

/**
 * @brief Get size of list
 * Obtiene el tamaño de la lista
 * @return int 
 */
int SimpleList::getSize(){

    return this->size;

}

