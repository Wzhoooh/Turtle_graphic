#ifndef LIST_IMPL_HPP_INCLUDED
#define LIST_IMPL_HPP_INCLUDED

#include <memory>
#include <utility>

template<class T, class Allocator>
dataStructures::list<T, Allocator>::list(){}

template<class T, class Allocator>
dataStructures::list<T, Allocator>::list(const list& source)
{
    for (typename dataStructures::list<T>::iterator i = source.begin(); i != source.end(); i++)
    {
        this->push_back(*i);
        this->_size++;
    }
}

template<class T, class Allocator>
dataStructures::list<T, Allocator>::list(list&& source)
{
    for (typename dataStructures::list<T>::iterator i = source.begin(); i != source.end(); i++)
    {
        push_back(std::move(*i));
        _size++;
    }
}

template<class T, class Allocator>
list<T, Allocator>& dataStructures::list<T, Allocator>::operator =(const list& source)
{
    for (typename dataStructures::list<T, Allocator>::iterator i = begin(); i != end();)
    {
        std::allocator_traits<Allocator>::destroy(_allocT, &(*i++));
//        std::allocator_traits<Allocator>::deallocate(_allocT, &(*i++));
    }

    _size = 0;

    for (typename dataStructures::list<T, Allocator>::iterator i = source.begin(); i != source.end(); i++)
    {
        push_back(*i);
        _size++;
    }
}

template<class T, class Allocator>
list<T, Allocator>& dataStructures::list<T, Allocator>::operator =(list&& source)
{
    for (typename dataStructures::list<T, Allocator>::iterator i = begin(); i != end();)
    {
        std::allocator_traits<Allocator>::destroy(_allocT, &(*i++));
//        std::allocator_traits<Allocator>::deallocate(_allocT, &(*i++));
    }

    _size = 0;

    for (dataStructures::list<T, Allocator>::iterator i = source.begin(); i != source.end(); i++)
    {
        push_back(std::move(*i));
        _size++;
    }
}

template<class T, class Allocator>
dataStructures::list<T, Allocator>::~list()
{
    for (typename dataStructures::list<T, Allocator>::iterator i = begin(); i != end();)
    {
        std::allocator_traits<Allocator>::destroy(_allocT, &(*i++));
//        std::allocator_traits<Allocator>::deallocate(_allocT, &(*i++));
    }
}

template<class T, class Allocator>
void dataStructures::list<T, Allocator>::push_back(T&& newElem)
{
    Node<T>* newNodePointer = std::allocator_traits<NodeAllocator>::allocate(_allocNode, sizeof(newElem));
    std::allocator_traits<NodeAllocator>::construct(_allocNode, newNodePointer, std::forward<T>(newElem));

    if (_size == 0)
    {
        _first = newNodePointer;
        _last = newNodePointer;
        _size++;
    }
    else
    {
        _last->_next = newNodePointer;
        newNodePointer->_prev = _last;
        _last = newNodePointer;
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
