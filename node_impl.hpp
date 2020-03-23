#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED

#include <utility>

template <class T>
Node<T>::Node(const T& source): content(source)
{}

template <class T>
template <class T1>
Node<T>::Node(T1&& source): content(std::forward<T1>(source))
{}

#endif // NODE_HPP_INCLUDED
