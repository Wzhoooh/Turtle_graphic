#ifndef LIST_IMPL_HPP_INCLUDED
#define LIST_IMPL_HPP_INCLUDED

#include <memory>

template<class T, class Allocator>
dataStructures::list<T, Allocator>::list(){}

template<class T, class Allocator>
dataStructures::list<T, Allocator>::list(const list& source)
{
    for (typename dataStructures::list<T>::iterator i = source.begin(); i != source.end(); i++)
    {
        this->push_back(*i);
        this->size++;
    }
}

template<class T, class Allocator>
dataStructures::list<T, Allocator>::list(list&& source)
{
    for (typename dataStructures::list<T>::iterator i = source.begin(); i != source.end(); i++)
    {
        this->push_back(std::move(*i));
        this->size++;
    }
}

template<class T, class Allocator>
list<T, Allocator>& dataStructures::list<T, Allocator>::operator =(const list& source)
{
    for (typename dataStructures::list<T, Allocator>::iterator i = this->begin(); i != this->end();)
    {
        std::allocator_traits<NodeAllocator>::destroy(this->_allocNode, &(*i++));
        std::allocator_traits<NodeAllocator>::deallocate(this->_allocNode, &(*i++));
    }

    this->size = 0;

    for (typename dataStructures::list<T, Allocator>::iterator i = source.begin(); i != source.end(); i++)
    {
        this->push_back(*i);
        this->size++;
    }
}

template<class T, class Allocator>
list<T, Allocator>& dataStructures::list<T, Allocator>::operator =(list&& source)
{
    for (typename dataStructures::list<T, Allocator>::iterator i = this->begin(); i != this->end();)
    {
        std::allocator_traits<NodeAllocator>::destroy(this->_allocNode, &(*i++));
        std::allocator_traits<NodeAllocator>::deallocate(this->_allocNode, &(*i++));
    }

    this->size = 0;

    for (dataStructures::list<T, Allocator>::iterator i = source.begin(); i != source.end(); i++)
    {
        this->push_back(std::move(*i));
        this->size++;
    }
}

template<class T, class Allocator>
dataStructures::list<T, Allocator>::~list()
{
    for (typename dataStructures::list<T, Allocator>::iterator i = this->begin(); i != this->end();)
    {
        std::allocator_traits<NodeAllocator>::destroy(this->_allocNode, &(*i++));
        std::allocator_traits<NodeAllocator>::deallocate(this->_allocNode, &(*i++), 1);
    }
}

template<class T, class Allocator>
void dataStructures::list<T, Allocator>::push_back(T&& newElem)
{
    Node<T>* newNodePointer = std::allocator_traits<NodeAllocator>::allocate(this->_allocNode, sizeof(newElem));
    std::allocator_traits<NodeAllocator>::construct(this->_allocNode, newNodePointer, std::forward(newElem));

    if (this->_size == 0)
    {
        this->_first = newNodePointer;
        this->_last = newNodePointer;
        _size++;
    }
    else
    {
        this->_last->_next = newNodePointer;
        newNodePointer->_prev = this->_last;
        this->_last = newNodePointer;
        _size++;
    }
}

template<class T, class Allocator>
void dataStructures::list<T, Allocator>::push_front(T&& newElem)
{

}

template<class T, class Allocator>
void dataStructures::list<T, Allocator>::pop_back()
{

}

template<class T, class Allocator>
void dataStructures::list<T, Allocator>::pop_front()
{

}

template<class T, class Allocator>
size_t dataStructures::list<T, Allocator>::size() const noexcept(true)
{
    return _size;
}

template<class T, class Allocator>
typename dataStructures::list<T, Allocator>::iterator dataStructures::list<T, Allocator>::begin() const noexcept(true)
{
    return iterator(_first);
}

template<class T, class Allocator>
typename dataStructures::list<T, Allocator>::iterator dataStructures::list<T, Allocator>::end() const noexcept(true)
{
    return iterator(nullptr);
}



#endif // LIST_IMPL_HPP_INCLUDED
