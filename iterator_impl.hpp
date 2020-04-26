#ifndef ITERATOR_IMPL_HPP_INCLUDED
#define ITERATOR_IMPL_HPP_INCLUDED

template <class T>
BidirectionalIterator<T>::BidirectionalIterator(Node<T>* source)
{
    this->node = source;
}

template <class T>
BidirectionalIterator<T>::~BidirectionalIterator(){}

template <class T>
BidirectionalIterator<T> BidirectionalIterator<T>::operator ++()
{
    node = node->_next;
    return *this;
}

template <class T>
BidirectionalIterator<T> BidirectionalIterator<T>::operator --()
{
    node = node->_prev;
    return *this;
}

template <class T>
BidirectionalIterator<T> BidirectionalIterator<T>::operator ++(int)
{
    BidirectionalIterator<T> iteratorCopy = *this;
    node = node->_next;
    return iteratorCopy;
}

template <class T>
BidirectionalIterator<T> BidirectionalIterator<T>::operator --(int)
{
    BidirectionalIterator<T> iteratorCopy = *this;
    node = node->_prev;
    return iteratorCopy;
}

template <class T>
bool BidirectionalIterator<T>::operator ==(const BidirectionalIterator<T>& other) const
{
    return this->node == other.node;
}

template <class T>
bool BidirectionalIterator<T>::operator !=(const BidirectionalIterator<T>& other) const
{
    return this->node != other.node;
}

template <class T>
T* BidirectionalIterator<T>::operator ->()
{
    return &(node->content);
}

template <class T>
T& BidirectionalIterator<T>::operator *()
{
    return node->content;
}

template <class T>
T& BidirectionalIterator<T>::get()
{
    return node->content;
}

template <class T>
bool BidirectionalIterator<T>::isEnd()
{
    return node == nullptr;
}

#endif // ITERATOR_IMPL_HPP_INCLUDED
