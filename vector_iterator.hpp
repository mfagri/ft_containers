/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:41:06 by mfagri            #+#    #+#             */
/*   Updated: 2023/01/04 06:56:35 by mfagri           ###   ########.fr       */
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
                typedef std::random_access_iterator_tag iterator_category;
                
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
         ////////////////////////////////// 
        template <class T>
        class iterator_traits {
        public:
            typedef std::random_access_iterator_tag iterator_category;
            typedef T                               value_type;
            typedef T*                              pointer;
            typedef T&                              reference;
            typedef std::ptrdiff_t                  difference_type;
        };
        // ///////////////////////////////////////////////////////////
        // template< class T>
        // class reverse_iterator : public std::iterator<
        // typename std::iterator_traits<Iterator>::iterator_category,
        // typename std::iterator_traits<Iterator>::value_type,
        // typename std::iterator_traits<Iterator>::difference_type,
        // typename std::iterator_traits<Iterator>::pointer,
        // typename std::iterator_traits<Iterator>::reference >
        // {
        //     public:
        //         typedef typename	T  iterator_type;
        //         typedef typename	ft::iterator_traits<T>::difference_type  difference_type;
        //         typedef typename	ft::iterator_traits<T>::pointer  pointer;
        //         typedef typename	ft::iterator_traits<T>::reference  reference;
        //         reverse_iterator(){};
        //         explicit reverse_iterator( T x ){
        //             *this = x;
        //         }
        //         template< class U >
        //         reverse_iterator( const reverse_iterator<U>& other );
        // };
        ///////////////////////////////////////////////////////////
    // template< class T >
    // class reverse_iterator : public iterator<T>
    // {
    //     private:
    //         T* ptr;
    //     public:
        
    //         typedef T value_type;
    //         typedef T* pointer;
    //         typedef T& reference;
    //         typedef std::ptrdiff_t difference_type;
            
            
    //         reverse_iterator(T* ptr = NULL):iterator<T>(ptr){}
    //         reverse_iterator( iterator<T> x )
    //         {
    //             this->ptr = x.ptr;
    //         }
    //         // reverse_iterator( const reverse_iterator<T>& other ) = default;
    //         ~reverse_iterator(){}
    //         reverse_iterator& operator=( const reverse_iterator<T>& other )
    //         {
    //             this->ptr = other.ptr;
    //             return(*this);
    //         }
    //         // reverse_iterator<T>&           operator=(const reverse_iterator<T>& rawReverseIterator) = default;
            
    //         reverse_iterator<T>&           operator=(const iterator<T>& rawIterator){this->ptr = rawIterator.ptr;return (*this);}
    //         reverse_iterator<T>&           operator=(T* ptr){this->ptr = ptr;return (*this);}

    //         reverse_iterator<T>&           operator+=(const difference_type& m){this->ptr -= m;return (*this);}
    //         reverse_iterator<T>&           operator-=(const difference_type& m){this->ptr += m;return (*this);}
    //         reverse_iterator<T>&           operator++(){--this->ptr;return (*this);}
    //         reverse_iterator<T>&           operator--(){++this->ptr;return (*this);}
    //         reverse_iterator<T>            operator++(int){reverse_iterator temp(*this);--this->ptr;return temp;}
    //         reverse_iterator<T>            operator--(int){reverse_iterator temp(*this);++this->ptr;return temp;}
    //         reverse_iterator<T>            operator+(const int& m){T oldPtr = this->ptr;this->ptr-=m;reverse_iterator temp(*this);this->ptr = oldPtr;return temp;}
    //         reverse_iterator<T>            operator-(const int& m){T oldPtr = this->ptr;this->ptr+=m;reverse_iterator temp(*this);this->ptr = oldPtr;return temp;}

    //         difference_type                             operator-(const reverse_iterator<T>& rawReverseIterator){return std::distance(this->ptr,rawReverseIterator.ptr);}

    //         iterator<T>                   base(){iterator<T> forwardIterator(this->ptr); ++forwardIterator; return forwardIterator;}

    //         bool operator!=( const reverse_iterator<T>& lhs)
    //         {
    //             return (this->ptr != lhs.ptr);
    //         }

    // };
}

#endif