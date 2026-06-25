#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <cstdlib>
#include <stdexcept>
#include <new>

template <typename T>
class DynamicArray
{
private:
    T* data_;
    int size_;
    int capacity_;

    void resize();

public:
    DynamicArray();
    ~DynamicArray();

    DynamicArray(const DynamicArray &other);
    DynamicArray &operator=(const DynamicArray &other);

    void append(T value);
    void insert(int index, T value);
    void remove(int index);

    T get(int index) const;
    void set(int index, T value);

    int size() const;
    int capacity() const;
    bool empty() const;
    void clear();
};

#include "../src/DynamicArray.cpp" 

#endif