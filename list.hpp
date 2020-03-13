#ifndef DATASTRUCTERS_H_INCLUDED
#define DATASTRUCTERS_H_INCLUDED

#include <memory>
#include <iterator>
#include <algorithm>

namespace dataStructures
{

template <class T>
struct Node
{
    T content;
    Node<T>* prev;
    Node<T>* next;
};

template <class T>
class BidirectionalIterator//: class std::iterator<std::bidirectional_iterator_tag> /// i just have to learn iterators!!
{
public:
    BidirectionalIterator(const BidirectionalIterator&);
    BidirectionalIterator<T>& operator ++(); // prefix
    BidirectionalIterator<T>& operator --();
    BidirectionalIterator<T>& operator ++(int); // postfix
    BidirectionalIterator<T>& operator --(int);
    bool operator ==(BidirectionalIterator<T>& other) const;
    bool operator !=(BidirectionalIterator<T>& other) const;
    T* operator ->();
    T& operator *();
    T& get();

private:
    Node<T>* content = nullptr;
};

template<class T, class Allocator = std::allocator<T>>
class list
{
public:
    typedef T type;
    typedef BidirectionalIterator<T> iterator;

    list();
    list(const list&);
    list(list&&);
    list& operator =(const list&);
    list& operator =(list&&);
    virtual ~list();

    void push_back(T&&);
    void push_front(T&&);
    void pop_back();
    void pop_front();
    iterator insert(iterator pos, const T& value);
    iterator erase(iterator pos);
    size_t size() const noexcept(true);

    iterator begin() const noexcept(true);
    iterator end() const noexcept(true);

private:
    typedef typename Allocator::template rebind<Node<T>>::other NodeAllocator;
    typedef Node<T>* pNode;

    size_t _size = 0;
    pNode _first = nullptr;
    pNode _last = nullptr;
    NodeAllocator _allocNode;
};

#include "list_impl.hpp"
#include "iterator_impl.hpp"
}

#endif // DATASTRUCTERS_H_INCLUDED
