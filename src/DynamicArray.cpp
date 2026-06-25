#include "DynamicArray.h"

// default constructor
template<typename T>
DynamicArray<T>::DynamicArray()
{
    size_ = 0;
    capacity_ = 5;
    data_ = (T*)std::malloc(sizeof(T) * capacity_);
    if (!data_)
    throw std::bad_alloc();
}

// copy construcor
template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& other)
{
    size_ = other.size_;
    capacity_ = other.capacity_;    

    data_ = (T*)std::malloc(sizeof(T) * capacity_);

    for (int i = 0; i < size_; i++)
        new (data_ + i) T(other.data_[i]);
}

// destructor
template<typename T>
DynamicArray<T>::~DynamicArray()
{
    if (data_)
    {
        for (int i = 0; i < size_; i++)
            data_[i].~T();

        std::free(data_);
    }

    data_ = nullptr;
}

// assignment operator
template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& other)
{
    if (this == &other)
        return *this;

    // destroy current elements
    for (int i = 0; i < size_; i++)
        data_[i].~T();

    // free old memory
    std::free(data_);

    // copy metadata
    size_ = other.size_;
    capacity_ = other.capacity_;

    // allocate new memory
    data_ = (T*)std::malloc(sizeof(T) * capacity_);

    // copy-construct elements
    for (int i = 0; i < size_; i++)
        new (data_ + i) T(other.data_[i]);

    return *this;
}
