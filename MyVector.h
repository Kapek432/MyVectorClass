#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <ostream>

template<typename T>
class MyVector
{
    T* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;
public:
    MyVector(): data(nullptr), size(0), capacity(0) {}

    MyVector(size_t capacity_): size(0), capacity(capacity_), data(new T[capacity_]) {}

    //Konstruktor kopiujący
    MyVector(const MyVector& other);

    // Konstruktor przenoszący
    MyVector(MyVector&& other) noexcept;

    ~MyVector() {delete[] data;}

    size_t getSize() const;

    size_t getCapacity() const;

    void resize(size_t newSize);

    void reserve(size_t newCapacity);

    void pushBack(const T& value);

    void pushFront(const T& value);

    void insert(size_t index, const T& value);

    void pop_back();

    void pop_front();

    void erase(size_t index);

    void clear();

    void reverse();

    void swap(size_t index1, size_t index2);

    void sort();
    // Operator przypisania (kopiujący)
    MyVector& operator=(const MyVector& other);

    // Operator przypisania (przenoszący)
    MyVector& operator=(MyVector&& other) noexcept;

    //Indexing
    T& operator[](size_t index) const;

    bool operator==(const MyVector& other) const;

    MyVector operator+(const MyVector& other);

    MyVector& operator+=(const MyVector& other);

    MyVector operator-(const MyVector& other);

    MyVector& operator-=(const MyVector& other);

    MyVector operator*(const MyVector& other);

    MyVector& operator*=(const MyVector& other);

    MyVector operator/(const MyVector& other);

    MyVector& operator/=(const MyVector& other);

    MyVector& operator+(const T& other);

    MyVector& operator+=(const T& other);

    MyVector& operator-(const T& other);

    MyVector& operator-=(const T& other);

    MyVector& operator*(const T& other);

    MyVector& operator*=(const T& other);

    MyVector& operator/(const T& other);

    MyVector& operator/=(const T& other);

    friend std::ostream& operator<<(std::ostream& os, const MyVector<T>& vec) {
        for (std::size_t i = 0; i < vec.size; ++i) {
            os << vec.data[i] << " ";
        }
        return os;
    }

    // Operator >> (for inputting)
    friend std::istream& operator>>(std::istream& is, MyVector<T>& vec) {
        for (std::size_t i = 0; i < vec.size; ++i) {
            is >> vec.data[i];
        }
        return is;
    }



};






#include "MyVector.tpp"

#endif //MYVECTOR_H
