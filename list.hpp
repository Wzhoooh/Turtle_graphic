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
    Node(T&& source);
    Node(const T& source);

    T content;
    Node<T>* _prev = nullptr;
    Node<T>* _next = nullptr;
};

template <class T>
class BidirectionalIterator//: class std::iterator<std::bidirectional_iterator_tag> /// i just have to learn iterators!!
{
    template<class U, class Allocator>
    friend class list;

public:
    BidirectionalIterator() = delete;
    BidirectionalIterator(Node<T>* source);
    BidirectionalIterator(const BidirectionalIterator&) = default;
    BidirectionalIterator<T>& operator =(const BidirectionalIterator<T>&) = default;
    BidirectionalIterator(BidirectionalIterator&&) = default;
    ~BidirectionalIterator();

    BidirectionalIterator<T> operator ++(); // prefix
    BidirectionalIterator<T> operator --();
    BidirectionalIterator<T> operator ++(int); // postfix
    BidirectionalIterator<T> operator --(int);
    bool operator ==(const BidirectionalIterator<T>& other) const;
    bool operator !=(const BidirectionalIterator<T>& other) const;
    T* operator ->();
    T& operator *();
    T& get();

private:
    Node<T>* node = nullptr;
};

template<class T, class Allocator = std::allocator<T>>
class list
{
public:
    typedef T                           type;
    typedef T*                          pointer;
    typedef const T*                    const_pointer;
    typedef T&                          reference;
    typedef const T&                    const_reference;
    typedef BidirectionalIterator<T>    iterator;

    list();
    list(const list&);
    list(list&&);
    list& operator =(const list&); // нужно исправить, удаление - не оптимальный путь
    list& operator =(list&&); // нужно исправить, удаление - не оптимальный путь
    virtual ~list();

template<class T1>
    void push_back(T1&&);
template<class T1>
    void push_front(T1&&);
    void pop_back();
    void pop_front();
template<class T1>
    iterator insert(iterator pos, T1&& value);
    iterator erase(iterator pos);
    size_t size() const noexcept(true);

    iterator begin() const noexcept(true);
    iterator end() const noexcept(true);
    iterator front() const noexcept(true);

private:
    typedef Node<T>* pNode;
    typedef typename Allocator::template rebind<Node<T>>::other NodeAllocator;

    size_t _size = 0;
    pNode _first = nullptr;
    pNode _last = nullptr;
    NodeAllocator _allocNode;
    Allocator _allocT;
};

#include "node.hpp"
#include "iterator_impl.hpp"
#include "list_impl.hpp"
}

#endif // DATASTRUCTERS_H_INCLUDED
