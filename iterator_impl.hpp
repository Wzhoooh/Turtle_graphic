#ifndef ITERATOR_IMPL_HPP_INCLUDED
#define ITERATOR_IMPL_HPP_INCLUDED

template <class T>
BidirectionalIterator<T>::BidirectionalIterator(const BidirectionalIterator& source): content(source.content){}

template <class T>
BidirectionalIterator<T>::BidirectionalIterator(Node<T>* source)
{
    this->content = source;
}

template <class T>
BidirectionalIterator<T>::~BidirectionalIterator()
{
    delete this->content;
}

template <class T>
BidirectionalIterator<T> BidirectionalIterator<T>::operator ++()
{
    return content = content.next;
}

template <class T>
BidirectionalIterator<T> BidirectionalIterator<T>::operator --()
{
    return content = content.prev;
}

template <class T>
BidirectionalIterator<T> BidirectionalIterator<T>::operator ++(int)
{
    Node<T>* pointerCopy = content;
    content = content.next;
    return pointerCopy;
}

template <class T>
BidirectionalIterator<T> BidirectionalIterator<T>::operator --(int)
{
    Node<T>* pointerCopy = content;
    content = content.prev;
    return pointerCopy;
}

template <class T>
bool BidirectionalIterator<T>::operator ==(BidirectionalIterator<T>&& other) const
{
    return this->content == other->content;
}

template <class T>
bool BidirectionalIterator<T>::operator !=(BidirectionalIterator<T>&& other) const
{
    return this->content != other.content;
}

template <class T>
T* BidirectionalIterator<T>::operator ->()
{
    return content;
}

template <class T>
T& BidirectionalIterator<T>::operator *()
{
    return *content;
}

template <class T>
T& BidirectionalIterator<T>::get()
{
    return *content;
}


#endif // ITERATOR_IMPL_HPP_INCLUDED
