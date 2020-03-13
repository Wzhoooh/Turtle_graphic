#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED

template <class T>
Node<T>::Node(T&& source)
{
    std::swap(*(this->content), source);
}

#endif // NODE_HPP_INCLUDED
