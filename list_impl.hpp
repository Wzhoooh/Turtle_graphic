#ifndef LIST_IMPL_HPP_INCLUDED
#define LIST_IMPL_HPP_INCLUDED

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
        delete (&(*i++));

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
        delete (&(*i++));

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
        delete (&(*i++));
}

template<class T, class Allocator>
void dataStructures::list<T, Allocator>::push_back(T&& newElem)
{

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


#endif // LIST_IMPL_HPP_INCLUDED
