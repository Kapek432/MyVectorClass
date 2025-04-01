#ifndef MYVECTOR_TPP
#define MYVECTOR_TPP

#include <algorithm>

#include "MyVector.h"

template <typename T>
MyVector<T>::MyVector(const MyVector& other):size(other.size), capacity(other.capacity), data(new T[other.capacity])
{
    std::copy(other.data, other.data + other.size, data);
}

template <typename T>
MyVector<T>::MyVector(MyVector&& other) noexcept: size(other.size), capacity(other.capacity), data(other.data)
{
    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}
template <typename T>
size_t MyVector<T>::getSize() const
{
    return size;
}

template <typename T>
size_t MyVector<T>::getCapacity() const
{
    return capacity;
}

template <typename T>
void MyVector<T>::resize(size_t newSize)
{
    if (newSize > capacity)
        resize(newSize);
    size = newSize;
}

template <typename T>
void MyVector<T>::reserve(size_t newCapacity)
{
    if (newCapacity > capacity)
    {
        T* newData = new T[newCapacity];
        std::copy(data, data + size, newData);
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
}

template <typename T>
void MyVector<T>::pushBack(const T& value)
{
    if (size==capacity) reserve(2 * capacity + 1);
    data[size++] = value;
}

template <typename T>
void MyVector<T>::pushFront(const T& value)
{
    insert(0, value);
}

template <typename T>
void MyVector<T>::insert(size_t index, const T& value)
{
    if (index > size) throw std::out_of_range("Index out of range");
    if (size==capacity) reserve(2 * capacity + 1);
    for (size_t i = size; i > index; i--)
    {
        data[i] = data[i - 1];
    }
    data[index] = value;
    size++;
}

template <typename T>
void MyVector<T>::pop_back()
{
    if (size>0) size--;
}

template <typename T>
void MyVector<T>::pop_front()
{
    if (size>0) erase(0);
}

template <typename T>
void MyVector<T>::erase(size_t index)
{
    if (index >= size) throw std::out_of_range("Index out of range");
    if (size==capacity) reserve(2 * capacity + 1);
    for (size_t i = index; i < size - 1; i++)
    {
        data[i] = data[i + 1];
    }
    size--;
}

template <typename T>
void MyVector<T>::clear()
{
    delete[] data;
    data = nullptr;
    size = 0;
    capacity = 0;
}

template <typename T>
void MyVector<T>::reverse()
{
    std::reverse(data, data + size);
}

template <typename T>
void MyVector<T>::swap(size_t index1, size_t index2)
{
    if (index1 >= size || index2 >= size) throw std::out_of_range("Index out of range");
    std::swap(data[index1], data[index2]);
}

template <typename T>
void MyVector<T>::sort()
{
    std::sort(data, data + size);
}

// Operator przypisania (kopiujący)
template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& other)
{
    if (this != &other)
    {
        delete[] data;
        size = other.size;
        capacity = other.capacity;
        data = new T[other.capacity];
        std::copy(other.data, other.data + size, data);
    }
    return *this;
}

// Operator przypisania (przenoszący)
template <typename T>
MyVector<T>& MyVector<T>::operator=(MyVector&& other) noexcept
{
    if (this !=&other)
    {
        delete[] data;
        size = other.size;
        capacity = other.capacity;
        data = other.data;
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
    return *this;
}

//Indexing
template <typename T>
T& MyVector<T>::operator[](size_t index) const
{
    if (index >= size) throw std::out_of_range("Index out of range");
    return data[index];
}

template <typename T>
bool MyVector<T>::operator==(const MyVector& other) const
{
    if (size != other.size) return false;
    for (size_t i = 0; i < size; i++)
    {
        if (data[i] != other.data[i]) return false;
    }
    return true;
}

template <typename T>
MyVector<T> MyVector<T>::operator+(const MyVector& other)
{
    if (size != other.size) throw std::invalid_argument("Vectors must be of the same size");
    MyVector<T> newVector(size);
    for (size_t i = 0; i < size; i++)
    {
        newVector.data[i] = data[i] + other.data[i];
    }
    return newVector;
}

template <typename T>
MyVector<T>& MyVector<T>::operator+=(const MyVector& other)
{
    if (size != other.size) throw std::invalid_argument("Vectors must be of the same size");
    for (size_t i = 0; i < size; ++i) {
        data[i] += other.data[i];
    }
    return *this;
}

template <typename T>
MyVector<T> MyVector<T>::operator-(const MyVector<T>& other)
{
    if (size != other.size) throw std::invalid_argument("Vectors must be of the same size");
    MyVector<T> newVector(size);
    for (size_t i = 0; i < size; i++)
    {
        newVector.data[i] = data[i] - other.data[i];
    }
    return newVector;
}

template <typename T>
MyVector<T>& MyVector<T>::operator-=(const MyVector<T>& other)
{
    if (size != other.size) throw std::invalid_argument("Vectors must be of the same size");
    for (size_t i = 0; i < size; ++i) {
        data[i] -= other.data[i];
    }
    return *this;
}

template <typename T>
MyVector<T> MyVector<T>::operator*(const MyVector<T>& other)
{
    if (size != other.size) throw std::invalid_argument("Vectors must be of the same size");
    MyVector<T> newVector(size);
    for (size_t i = 0; i < size; i++)
    {
        newVector.data[i] = data[i] * other.data[i];
    }
    return newVector;
}

template <typename T>
MyVector<T>& MyVector<T>::operator*=(const  MyVector<T>& other)
{
    if (size != other.size) throw std::invalid_argument("Vectors must be of the same size");
    for (size_t i = 0; i < size; ++i) {
        data[i] *= other.data[i];
    }
    return *this;
}

template <typename T>
MyVector<T> MyVector<T>::operator/(const MyVector<T>& other)
{
    if (size != other.size) throw std::invalid_argument("Vectors must be of the same size");
    MyVector<T> newVector(size);
    for (size_t i = 0; i < size; i++)
    {
        newVector.data[i] = data[i] / other.data[i];
    }
    return newVector;
}

template <typename T>
MyVector<T>& MyVector<T>::operator/=(const MyVector<T>& other)
{
    if (size != other.size) throw std::invalid_argument("Vectors must be of the same size");
    for (size_t i = 0; i < size; ++i) {
        data[i] /= other.data[i];
    }
    return *this;
}

template <typename T>
MyVector<T>& MyVector<T>::operator+(const T& other)
{
    for (size_t i = 0; i < size; ++i) {
        data[i] += other;
    }
    return *this;
}

template <typename T>
MyVector<T>& MyVector<T>::operator+=(const T& other)
{
    for (size_t i = 0; i < size; ++i) {
        data[i] += other;
    }
    return *this;
}

template <typename T>
MyVector<T>& MyVector<T>::operator-(const T& other)
{
    for (size_t i = 0; i < size; ++i) {
        data[i] -= other;
    }
    return *this;
}

template <typename T>
MyVector<T>& MyVector<T>::operator-=(const T& other)
{
    for (size_t i = 0; i < size; ++i) {
        data[i] -= other;
    }
    return *this;
}

template <typename T>
MyVector<T>& MyVector<T>::operator*(const T& other)
{
    for (size_t i = 0; i < size; ++i) {
        data[i] *= other;
    }
    return *this;
}

template <typename T>
MyVector<T>& MyVector<T>::operator*=(const T& other)
{
    for (size_t i = 0; i < size; ++i) {
        data[i] *= other;
    }
    return *this;
}

template <typename T>
MyVector<T>& MyVector<T>::operator/(const T& other)
{
    for (size_t i = 0; i < size; ++i) {
        data[i] /= other;
    }
    return *this;
}

template <typename T>
MyVector<T>& MyVector<T>::operator/=(const T& other)
{
    for (size_t i = 0; i < size; ++i) {
        data[i] /= other;
    }
    return *this;
}










#endif
