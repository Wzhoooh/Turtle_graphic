#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED

#include <utility>

template <class T>
Node<T>::Node(T&& source): content(std::move(source))
{}

template <class T>
Node<T>::Node(const T& source): content(source)
{}

#endif // NODE_HPP_INCLUDED
