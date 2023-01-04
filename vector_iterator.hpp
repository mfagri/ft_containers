/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:41:06 by mfagri            #+#    #+#             */
/*   Updated: 2023/01/04 02:50:40 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include <iterator>
namespace ft
{
    template < class T >
    class iterator : public std::iterator<std::random_access_iterator_tag , T>
          {
            private:
                T *ptr;
            public:
                typedef T value_type;
                typedef T* pointer;
                typedef T& reference;
                typedef std::ptrdiff_t difference_type;
                
                iterator(T *s = NULL)
                {
                    ptr =s;
                }
                
                iterator(const iterator &x):ptr(x.ptr)
                {}
                iterator &operator = (const iterator &x) 
                {
                    ptr = x.ptr;
                    return *this;
                }
                iterator& operator++() 
                {
                    ++ptr;return *this;
                }

                iterator operator++(int) 
                {
                    iterator tmp(*this); 
                    operator++(); 
                    return tmp;
                }
                iterator operator--()
                {
                    --ptr;
                    return (*this);
                }
                iterator operator--(int)
                {
                    iterator temp(*this);
                    --ptr;
                    return temp;
                }

                iterator operator+(const difference_type& m)
                {
                    T oldPtr = ptr;
                    ptr+=m;
                    iterator temp(*this);
                    ptr = oldPtr;
                    return temp;
                }
                iterator operator-(const difference_type& m)
                {
                    T oldPtr = ptr;
                    ptr-=m;
                    iterator temp(*this);
                    ptr = oldPtr;
                    return temp;
                }
                bool operator==(const iterator& rhs) const 
                {
                    return ptr==rhs.ptr;
                }
                
                bool operator!=(const iterator& rhs) const 
                {
                    return ptr!=rhs.ptr;
                }
                
                reference operator*() const
                {
                    return *ptr;
                }

                pointer operator->() const 
                {
                    return &(operator*());
                }
                iterator& operator+=(const difference_type& x)
                {
                    ptr += x;
                    return (*this);
                }
                iterator& operator-=(const difference_type& x)
                {
                    ptr -= x;
                    return (*this);
                }
                reference operator[] (difference_type n) const
                {
                    return ptr[n];
                }
                bool					operator > (iterator& iter) {return (this->ptr > iter.ptr) ?  1 : 0;}
                bool					operator >= (iterator& iter) {return (this->ptr >= iter.ptr) ?  1 : 0;}
                bool					operator < (iterator& iter) {return (this->ptr < iter.ptr) ?  1 : 0;}
                bool					operator <= (iterator& iter) {return (this->ptr <= iter.ptr) ?  1 : 0;}
          };
}

#endif