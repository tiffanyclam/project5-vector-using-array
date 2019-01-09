#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <stdexcept>
#include <new>

using namespace std;

template <typename T>
class Vector {
    
public:
    Vector();
    Vector( const unsigned ) throw ( bad_alloc );
    Vector( const unsigned, const T& ) throw ( bad_alloc );
    Vector( const Vector<T> & ) throw ( bad_alloc );
    ~Vector();
    void assign( const unsigned, const T& ) throw ( out_of_range );
    T& at( const unsigned ) const throw ( out_of_range );
    unsigned capacity() const;
    void clear();
    bool empty() const;
    void insert( const unsigned, const T& ) throw ( bad_alloc, out_of_range );
    T& operator[]( const unsigned ) const throw ( out_of_range );
    const Vector<T> &operator=( const Vector<T>& ) throw ( bad_alloc );
    void push_back( const T& ) throw ( bad_alloc );
    void resize( const unsigned, const T& = T() ) throw ( bad_alloc );
    unsigned size() const;
    void sort();
    void remove( const unsigned ) throw ( out_of_range );
    void printInternal(ostream & =cout);
    
private:
    T* contents;
    unsigned sz;
    unsigned cap;
    
    void increaseCapacity() throw ( bad_alloc );
    
}; // Vector<T> class

template <typename T>
Vector<T>::Vector(){
    cap = 10;
    contents = new T[cap];
    sz = 0;
}

template <typename T>
Vector<T>::Vector(const unsigned cap) throw (bad_alloc){
    sz = 0;
    this->cap = cap;
    contents = new T[cap];
}

template <typename T>
Vector<T>::Vector(const unsigned sz, const T &object) throw (bad_alloc){
    contents = new T[sz];
    for (unsigned i = 0; i < sz; i++){
        contents[i] = object;
    }
    this->sz = sz;
    this->cap = sz;
}

template <typename T> //The copy constructor should call operator=.
Vector<T>::Vector(const Vector<T> &vector) throw (bad_alloc){
//    cap = vector.cap;
//    contents = new T[cap];
//    sz = 0;
//    for (unsigned i = 0; i < vector.sz; i++)
//        contents[i] = vector.contents[i];
//    sz = vector.sz;
    sz = 0;
    cap = 0;
    currents = 0;
    *this = vector;
}

template <typename T>
Vector<T>::~Vector(){
    delete [] contents;
}

template <typename T> // You don't need to check if i < 0.  It can't be.  Why?
void Vector<T>::assign(const unsigned i, const T &object) throw (out_of_range){
    if (i >= sz)
        throw out_of_range
        ("Vector<T>::assign: out of range");
    contents[i] = object;
}

template <typename T>
T & Vector<T>::at(const unsigned i) const throw (out_of_range){
    if (i >= sz)
        throw out_of_range
        ("Vector<T>::at: out of range");
    return contents[i];
}

template <typename T>
unsigned Vector<T>::capacity() const{
    return cap;
}

template <typename T>
void Vector<T>::clear(){
    sz = 0;
}

template <typename T>
bool Vector<T>::empty() const{
    return (sz == 0);
}

template <typename T>
void Vector<T>::increaseCapacity() throw (bad_alloc){
    unsigned oldSize = sz;
    resize(cap*2);
    sz = oldSize;
}

// In insert, if sz == 0, it is possible for !empty to be true? If sz != 0, is it possible for !empty to be false?
template <typename T>
void Vector<T>::insert(const unsigned i, const T& object)throw (bad_alloc, out_of_range){
    if (i >= sz)
        throw out_of_range
        ("Vector<T>::insert: out of range");
    if (!empty()){
        if (sz == cap)
            increaseCapacity();
        for (unsigned j = sz; j > i; j--)
            contents[j] = contents[j-1];
        contents[i] = object;
        sz++;
    }
}

template <typename T> //In operator=, clear isn't doing anything for you.  delete [] contents is the important operation.
const Vector<T> &Vector<T>::operator=(const Vector<T> &vector) throw (bad_alloc){
    if (this != &vector){
        if (!empty())
            clear();
        if (this->cap != vector.cap){
            delete [] contents;
            contents = new T[vector.cap];
            cap = vector.cap;
        }
        sz = vector.sz;
        for (unsigned i = 0; i < vector.sz; i++)
            contents[i] = vector[i];
    }
    return *this;
}

template <typename T>
T & Vector<T>::operator[](const unsigned i) const throw (out_of_range){
    if (i > (sz-1))
        throw out_of_range
        ("Vector<T>::operator[]: out of range");
    return contents[i];
}

template <typename T>
void Vector<T>::push_back(const T &object) throw (bad_alloc){
    if (sz == cap)
        increaseCapacity();
    contents[sz] = object;
    sz++;
}

// It looks like remove is having trouble removing at position 0.  Test 50. Then at position 4, Test 54.  It's blowing up on line 183.  I'm not seeing the problem.
template <typename T>
void Vector<T>::remove(const unsigned i) throw (out_of_range){
    if (i > (sz-1))
        throw out_of_range
        ("Vector<T>::remove: out of range");
    for (unsigned j = i; j < (sz-1); j++)
        contents[j] = contents[j+1];
    sz--;
}

template <typename T>
void Vector<T>::resize(const unsigned newSize, const T &object) throw (bad_alloc){
    if (newSize <= sz)
        sz = newSize;
    else if (newSize > sz && newSize <= cap){
        for (unsigned i = sz; i < newSize; i++)
            contents[i] = object;
        sz = newSize;
    }
    else if (newSize > cap){
        T *newContents = new T[newSize];
        for (unsigned i = 0; i < sz; i++)
            newContents[i] = contents[i];
        for (unsigned i = sz; i < newSize; i++)
            newContents[i] = object;
        sz = newSize;
        cap = newSize;
        delete [] contents;
        contents = newContents;
    }
}

template <typename T>
unsigned Vector<T>::size() const{
    return sz;
}

template <typename T>
void Vector<T>::sort(){
    for (unsigned i = 1; i < sz; i++){
        for (unsigned j = 0; j < (sz-i); j++){
            if (contents[j] > contents[j+1]){
                T f = contents[j];
                contents[j] = contents[j+1];
                contents[j+1] = f;
            }
        }
    }
}
        
template <typename T>
void Vector<T>::printInternal(ostream &out){
    out << "size: " << this->size() << endl;
    out << "capacity: " << this->capacity() << endl;
    for (unsigned i = 0; i < size(); i++)
        out << at(i) << " ";
    out << endl;
}

#endif // VECTOR_H
