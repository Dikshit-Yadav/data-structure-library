#include "Linked_List.h"

// constructor
template<typename T>
LinkedList<T>::LinkedList()
{
    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
}

// destructor
template<typename T>
LinkedList<T>::~LinkedList()
{
    Node* current = head_;

    while (current != nullptr)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }

    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
}

// copy constructor
template<typename T>
LinkedList<T>::LinkedList(const LinkedList& other)
{
    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;

    Node* current = other.head_;

    while (current != nullptr)
    {
        insertBack(current->data);
        current = current->next;
    }
}

// assignment operator
template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& other)
{
    if (this == &other)
        return *this;

    clear();

    Node* current = other.head_;

    while (current != nullptr)
    {
        insertBack(current->data);
        current = current->next;
    }

    return *this;
}

// insert back
template<typename T>
void LinkedList<T>::insertBack(T value)
{
    Node* newNode = new Node(value);

    if (head_ == nullptr)
    {
        head_ = tail_ = newNode;
    }
    else
    {
        tail_->next = newNode;
        newNode->prev = tail_;
        tail_ = newNode;
    }

    ++size_;
}

//clear
template<typename T>
void LinkedList<T>::clear()
{
    Node* current = head_;

    while (current != nullptr)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }

    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
}

//size
template<typename T>
int LinkedList<T>::size() const
{
    return size_;
}

//empty
template<typename T>
bool LinkedList<T>::empty() const
{
    return size_ == 0;
}