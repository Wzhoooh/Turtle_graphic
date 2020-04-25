#ifndef LIST_IMPL_HPP_INCLUDED
#define LIST_IMPL_HPP_INCLUDED

#include <stdio.h>
#include <memory>
#include <utility>

template<class T, class Allocator>
DS::list<T, Allocator>::list(){}

template<class T, class Allocator>
DS::list<T, Allocator>::list(const list& source)
{
    for (typename DS::list<T>::iterator i = source.begin(); i != source.end(); i++)
    {
        this->push_back(*i);
        this->_size++;
    }
}

template<class T, class Allocator>
DS::list<T, Allocator>::list(list&& source)
{
    std::swap(_first, source._first);
    std::swap(_last, source._last);
    std::swap(_size, source._size);
}

template<class T, class Allocator>
list<T, Allocator>& DS::list<T, Allocator>::operator =(const list& source)
{
    auto itThis = this->begin();
    auto itSource = source.begin();
    for (; itThis != this->end() && itSource != source.end(); ++itThis, ++itSource)
        *itThis = *itSource;

    if (itThis == this->end() && itSource == source.end())
        ;
    else if(itThis == this->end() && itSource != source.end())
        for (; itSource != source.end(); ++itSource)
            push_back(*itSource);
    else if(itThis != this->end() && itSource == source.end())
    {
        itThis.node->_prev->_next = nullptr;
        _size = source.size();
        for (Node<T>* n = itThis.node; n != nullptr;)
        {
            Node<T>* nextNode = n->_next;
            std::allocator_traits<NodeAllocator>::destroy(_allocNode, n);
            std::allocator_traits<NodeAllocator>::deallocate(_allocNode, n, sizeof(Node<T>));
            n = nextNode;
        }
    }
    return *this;
}

template<class T, class Allocator>
list<T, Allocator>& DS::list<T, Allocator>::operator =(list&& source)
{
    std::swap(_first, source._first);
    std::swap(_last, source._last);
    std::swap(_size, source._size);
    source._first = nullptr;
    source._last = nullptr;
    source._size = 0;

    return *this;
}

template<class T, class Allocator>
DS::list<T, Allocator>::~list()
{
    for (Node<T>* n = _first; n != nullptr;)
    {
        Node<T>* nextNode = n->_next;
        std::allocator_traits<NodeAllocator>::destroy(_allocNode, n);
        std::allocator_traits<NodeAllocator>::deallocate(_allocNode, n, sizeof(Node<T>));
        n = nextNode;
    }
}

template<class T, class Allocator>
template<class T1>
void DS::list<T, Allocator>::push_back(T1&& newElem)
{
    Node<T>* newNodePointer = std::allocator_traits<NodeAllocator>::allocate(_allocNode, sizeof(newElem));
    std::allocator_traits<NodeAllocator>::construct(_allocNode, newNodePointer, std::forward<T1>(newElem));

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
template<class T1>
void DS::list<T, Allocator>::push_front(T1&& newElem)
{
    Node<T>* newNodePointer = std::allocator_traits<NodeAllocator>::allocate(_allocNode, sizeof(newElem));
    std::allocator_traits<NodeAllocator>::construct(_allocNode, newNodePointer, std::forward<T1>(newElem));

    if (_size == 0)
    {
        _first = newNodePointer;
        _last = newNodePointer;
        _size++;
    }
    else
    {
        _first->_prev = newNodePointer;
        newNodePointer->_next = _first;
        _first = newNodePointer;
        _size++;
    }
}

template<class T, class Allocator>
void DS::list<T, Allocator>::pop_back()
{
    if (_size == 0)
    {
        return;
    }
    else if (_size == 1)
    {
        std::allocator_traits<NodeAllocator>::destroy(_allocNode, _first);
        std::allocator_traits<NodeAllocator>::deallocate(_allocNode, _first, sizeof(Node<T>));
        _size = 0;
        _first = nullptr;
        _last = nullptr;
    }
    else
    {
        Node<T>* deleteNode = _last;
        _last = _last->_prev;
        _last->_next = nullptr;
        std::allocator_traits<NodeAllocator>::destroy(_allocNode, deleteNode);
        std::allocator_traits<NodeAllocator>::deallocate(_allocNode, deleteNode, sizeof(Node<T>));
        _size--;
    }
}

template<class T, class Allocator>
void DS::list<T, Allocator>::pop_front()
{
    if (_size == 0)
    {
        return;
    }
    else if (_size == 1)
    {
        std::allocator_traits<NodeAllocator>::destroy(_allocNode, _first);
        std::allocator_traits<NodeAllocator>::deallocate(_allocNode, _first, sizeof(Node<T>));
        _size--;
        _first = nullptr;
        _last = nullptr;
    }
    else
    {
        Node<T>* deleteNode = _first;
        _first->_next->_prev == nullptr;
        _first = _first->_next;
        std::allocator_traits<NodeAllocator>::destroy(_allocNode, deleteNode);
        std::allocator_traits<NodeAllocator>::deallocate(_allocNode, deleteNode, sizeof(Node<T>));
        _size--;
    }
}

template<class T, class Allocator>
template<class T1>
typename DS::list<T, Allocator>::iterator DS::list<T, Allocator>::insert
(typename DS::list<T, Allocator>::iterator pos, T1&& newElem)
{
    if(pos.node->_next == nullptr)
    {
        push_back(newElem);
    }
    else if(pos.node->_prev == nullptr)
    {
        push_front(newElem);
    }
    else
    {
        Node<T>* newNodePointer = std::allocator_traits<NodeAllocator>::allocate(_allocNode, sizeof(newElem));
        std::allocator_traits<NodeAllocator>::construct(_allocNode, newNodePointer, std::forward<T1>(newElem));

        newNodePointer->_prev = pos.node;
        newNodePointer->_next = pos.node->_next;
        pos.node->_next->_prev = newNodePointer;
        pos.node->_next = newNodePointer;
        _size++;
    }
    return ++pos;
}

template<class T, class Allocator>
typename DS::list<T, Allocator>::iterator DS::list<T, Allocator>::erase
(DS::list<T, Allocator>::iterator pos)
{
    if(pos.node->_next == nullptr)
    {
        pop_back();
        return back();
    }
    else if(pos.node->_prev == nullptr)
    {
        pop_front();
        return begin();
    }
    else
    {
        iterator rIter = --pos;
        ++pos;
        pos.node->_prev->_next = pos.node->_next;
        pos.node->_next->_prev = pos.node->_prev;
        std::allocator_traits<NodeAllocator>::destroy(_allocNode, pos.node);
        std::allocator_traits<NodeAllocator>::deallocate(_allocNode, pos.node, sizeof(Node<T>));
        _size--;
        return rIter;
    }
}

template<class T, class Allocator>
size_t DS::list<T, Allocator>::size() const noexcept(true)
{
    return _size;
}

template<class T, class Allocator>
typename DS::list<T, Allocator>::iterator DS::list<T, Allocator>::begin() const noexcept(true)
{
    return iterator(_first);
}

template<class T, class Allocator>
typename DS::list<T, Allocator>::iterator DS::list<T, Allocator>::end() const noexcept(true)
{
    return iterator(nullptr);
}

template<class T, class Allocator>
typename DS::list<T, Allocator>::iterator DS::list<T, Allocator>::back() const noexcept(true)
{
    return iterator(_last);
}


template<class T, class Allocator>
typename DS::list<T, Allocator>::iterator begin(const DS::list<T, Allocator>& l)
{
    return l.begin();
}

template<class T, class Allocator>
typename DS::list<T, Allocator>::iterator end(const DS::list<T, Allocator>& l)
{
    return l.end();
}

#endif // LIST_IMPL_HPP_INCLUDED
