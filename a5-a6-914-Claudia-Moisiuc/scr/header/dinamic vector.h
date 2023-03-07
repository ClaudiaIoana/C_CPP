//
// Created by dell on 04.04.2022.
//

//
// Created by dell on 19.03.2022.
//

#ifndef A5_6_914_CLAUDIA_MOISIUC1_DINAMIC_VECTOR_H
#define A5_6_914_CLAUDIA_MOISIUC1_DINAMIC_VECTOR_H

#endif //A5_6_914_CLAUDIA_MOISIUC1_DINAMIC_VECTOR_H
#include "tutorials.h"
#include <iterator>

template <typename T>

class DynamicVector
{
private:
    T* elems;
    int size;
    int capacity;

public:
    ///create a dynamic vector of capacity
    DynamicVector(int capacity = 10);
    ///create a dynamic vector
    DynamicVector(const DynamicVector& v);
    ///destroy the dynamic vector
    void DestroyVector();

    ///add an element to the dynamic vector
    //void add(const TElem& e);
    ///remove an element from the dynamic vector
    void remove(int poz);
    ///update an element from the dynamic vector
    void update(int poz, const T& e);
    ///getter for the size
    int getSize() const;
    ///getter for the elements
    T* getAllElems() const;
    ///getter for an element
    T* getElem(int i) const;
    //void addd(TElem& e);
    void operator+(const T& e);
    void setSize(int i);

private:
    ///resize the capacity of the dynamic vector
    void resize(double factor = 2);

};

///create a dynamic vector of capacity
template <typename T>
DynamicVector<T>::DynamicVector(int capacity)
{
    this->size = 0;
    this->capacity = capacity;
    this->elems = new T[capacity];
}

///create a dynamic vector
template <typename T>
DynamicVector<T>::DynamicVector(const DynamicVector& v){
    this->size = v.size;
    this->capacity = v.capacity;
    this->elems = new T[this->capacity];
    for (int i = 0; i < this->size; i++)
        this->elems[i] = v.elems[i];
}

///destroy the dynamic vector
template <typename T>
void DynamicVector<T>::DestroyVector(){
    delete[] this->elems;
}

///add an element to the dynamic vector
template <typename T>
void DynamicVector<T>::operator+(const T& e)
{
    if(this->size == this->capacity)
        this->resize();
    this->elems[this->size] = e;
    this->size++;
}

///remove an element from the dynamic vector
template <typename T>
void DynamicVector<T>::remove(int poz){

    for (int i = poz; i < this->size-1; i++)
        this->elems[i] = this->elems[i+1];
    this->size--;
}

///update an element from the dynamic vector
template <typename T>
void DynamicVector<T>::update(int poz, const T& e){
    this->elems[poz].setDuration(e.getDuration());
    this->elems[poz].setTitle(e.getTitle());
    this->elems[poz].setPresenter(e.getPresenter());
    this->elems[poz].setLikes(e.getLikes());
    this->elems[poz].setLink(e.getLink());
}

///getter for the size
template <typename T>
int DynamicVector<T>::getSize() const{
    return this->size;
}

template <typename T>
void DynamicVector<T>::setSize(int i) {
    this->size = i;
}

///getter for the elements
template <typename T>
T* DynamicVector<T>::getAllElems() const{
    return this->elems;
}

///getter for an element
template <typename T>
T* DynamicVector<T>::getElem(int i) const{
    return &this->elems[i];
}

///resize the capacity of the dynamic vector
template <typename T>
void DynamicVector<T>::resize(double factor){
    this->capacity *= static_cast<int>(factor);

    T* els = new T[this->capacity];
    for(int i = 0; i < this->size; i++)
        els[i] = this->elems[i];

    delete[] this->elems;
    this->elems = els;
}
