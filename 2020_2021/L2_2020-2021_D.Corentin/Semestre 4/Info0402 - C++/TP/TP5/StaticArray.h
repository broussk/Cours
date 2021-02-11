#ifndef TP_STATICARRAY_H
#define TP_STATICARRAY_H

#include <cstddef>
#include <iostream>
#include <stdexcept>

template <typename T>
class StaticArray{
    T* array;
    size_t size{};
public:
    explicit StaticArray(size_t size);
    StaticArray(const StaticArray &sa);
    ~StaticArray();

    size_t getSize() const;
    T& operator[](size_t index) const;
};

template <typename T>
std::ostream & operator<<(std::ostream &os, const StaticArray<T> & array){
    os << "[";
    for(int i = 0; i < array.getSize(); i++){
        os << array[i];
        if(i < array.getSize() - 1)  os << ", ";
    }
    os << "]";
    return os;
};

template <typename T>
bool operator==(const StaticArray<T> &sa1,  const StaticArray<T> &sa2){
    if(sa1.getSize() != sa2.getSize()) return false;
    for (size_t i = 0; i < sa1.getSize(); i ++){
        if(sa1[i] != sa2[i]) return false;
    }
    return true;
}

template <typename T>
StaticArray<T>::StaticArray(size_t size) : array (new T[size]), size(size){};

template <typename T>
StaticArray<T>::~StaticArray<T>() {delete[] array;}

template <typename T>
size_t StaticArray<T>::getSize() const {return this->size;}

template <typename T>
T & StaticArray<T>::operator[](size_t index) const{
    if(index >= this->size) throw std::out_of_range("Dépassement du tableau");
    return this->array[index];
}

template <typename T>
StaticArray<T>::StaticArray(const StaticArray &sa) : array (sa.array), size(sa.size){};

#endif //TP_STATICARRAY_H
