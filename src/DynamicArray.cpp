#include "DynamicArray.h"
#include <type_traits>
#include <cstring>

// default constructor
template <typename T>
DynamicArray<T>::DynamicArray()
{
    size_ = 0;
    capacity_ = 5;
    data_ = (T *)std::malloc(sizeof(T) * capacity_);
    if (!data_)
        throw std::bad_alloc();
}

// copy construcor
template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray &other)
{
    size_ = other.size_;
    capacity_ = other.capacity_;

    data_ = (T *)std::malloc(sizeof(T) * capacity_);

    if constexpr (std::is_trivially_copyable_v<T>)
    {
        std::memcpy(data_, other.data_, sizeof(T) * size_);
    }
    else
    {
        for (int i = 0; i < size_; i++)
            new (data_ + i) T(other.data_[i]);
    }
}

// destructor
template <typename T>
DynamicArray<T>::~DynamicArray()
{
    if (data_)
    {
        if constexpr (!std::is_trivially_destructible_v<T>)
        {
            for (int i = 0; i < size_; i++)
                data_[i].~T();
        }

        std::free(data_);
    }

    data_ = nullptr;
}

// assignment operator
template <typename T>
DynamicArray<T> &DynamicArray<T>::operator=(const DynamicArray &other)
{
    if (this == &other)
        return *this;

    // destroy current elements
    if constexpr (!std::is_trivially_destructible_v<T>)
    {
        for (int i = 0; i < size_; i++)
            data_[i].~T();
    }

    // free old memory
    std::free(data_);

    // copy metadata
    size_ = other.size_;
    capacity_ = other.capacity_;

    // allocate new memory
    data_ = (T *)std::malloc(sizeof(T) * capacity_);

    // copy-construct elements
    if constexpr (std::is_trivially_copyable_v<T>)
    {
        std::memcpy(data_, other.data_, sizeof(T) * size_);
    }
    else
    {
        for (int i = 0; i < size_; i++)
            new (data_ + i) T(other.data_[i]);
    }

    return *this;
}

// resize
template <typename T>
void DynamicArray<T>::resize()
{
    capacity_ *= 2;

    T *newData = (T *)std::malloc(sizeof(T) * capacity_);

    if constexpr (std::is_trivially_copyable_v<T>)
    {
        std::memcpy(newData, data_, sizeof(T) * size_);
    }
    else
    {
        for (int i = 0; i < size_; i++)
        {
            new (newData + i) T(data_[i]);
            data_[i].~T();
        }
    }

    std::free(data_);
    data_ = newData;
}

// append
template <typename T>
void DynamicArray<T>::append(T value)
{
    if (size_ >= capacity_)
        resize();

    if constexpr (std::is_trivially_copyable_v<T>)
    {
        data_[size_] = value;
    }
    else
    {
        new (data_ + size_) T(value);
    }
    size_++;
}

// insert
template <typename T>
void DynamicArray<T>::insert(int index, T value)
{
    if (index < 0 || index > size_)
        throw std::out_of_range("Index out of range");

    if (size_ >= capacity_)
        resize();

    if constexpr (std::is_trivially_copyable_v<T>)
    {
        for (int i = size_; i > index; i--)
            data_[i] = data_[i - 1];

        data_[index] = value;
    }
    else
    {
        for (int i = size_; i > index; i--)
        {
            new (data_ + i) T(data_[i - 1]);
            data_[i - 1].~T();
        }

        new (data_ + index) T(value);
    }
    size_++;
}

// remove
template <typename T>
void DynamicArray<T>::remove(int index)
{
    if (index < 0 || index >= size_)
        throw std::out_of_range("Index out of range");

    if constexpr (std::is_trivially_copyable_v<T>)
    {
        for (int i = index; i < size_ - 1; i++)
            data_[i] = data_[i + 1];
    }
    else
    {
        data_[index].~T();

        for (int i = index; i < size_ - 1; i++)
        {
            new (data_ + i) T(data_[i + 1]);
            data_[i + 1].~T();
        }
    }

    size_--;
}

// get
template <typename T>
T DynamicArray<T>::get(int index) const
{
    if (index < 0 || index >= size_)
    {
        throw std::out_of_range("Index out of range");
    }

    return data_[index];
}

// set
template <typename T>
void DynamicArray<T>::set(int index, T value)
{
    if (index < 0 || index >= size_)
    {
        throw std::out_of_range("Index out of range");
    }

    data_[index] = value;
}

// size
template <typename T>
int DynamicArray<T>::size() const
{
    return size_;
}

// capacity
template <typename T>
int DynamicArray<T>::capacity() const
{
    return capacity_;
}

// empty
template <typename T>
bool DynamicArray<T>::empty() const
{
    return size_ == 0;
}

// clear
template <typename T>
void DynamicArray<T>::clear()
{
    size_ = 0;
}