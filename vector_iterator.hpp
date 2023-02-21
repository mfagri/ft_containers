/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:41:06 by mfagri            #+#    #+#             */
/*   Updated: 2023/02/21 16:46:28 by mfagri           ###   ########.fr       */
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
                template<typename B>
                iterator(const iterator<B> &x):ptr(x.ptr)
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
                     iterator temp(*this);
                    temp.ptr += m;
                    return temp;;
                }
                iterator operator-(const difference_type& m) const
                {
                    iterator temp(*this);
                    temp.ptr -= m;
                    return temp;
                }
                difference_type operator-(const iterator& x) const {

                    return (ptr - x.ptr);
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
               bool operator < (const iterator& x) const{ return (ptr < x.ptr); }

			    bool operator > (const iterator &x) const { return (ptr > x.ptr); }

			    bool operator <= (const iterator &x) const { return (ptr <= x.ptr); }

			    bool operator >= (const iterator &x) const { return (ptr >= x.ptr); }
        };
         ////////////////////////////////// 
        template <class T>
        class iterator_traits {
        public:
            typedef typename T::iterator_category iterator_category;
            typedef typename T::value_type         value_type;
            typedef typename T::pointer            pointer;
            typedef typename T::reference          reference;
            typedef typename std::ptrdiff_t       difference_type;
        };
        template<class T>
        class iterator_traits<T*> {
        public:
            typedef std::random_access_iterator_tag iterator_category;
            typedef T                               value_type;
            typedef T*                              pointer;
            typedef T&                              reference;
            typedef std::ptrdiff_t                  difference_type;
        };

        template<class T>
        
        class iterator_traits<const T*> {
        public:
            typedef std::random_access_iterator_tag iterator_category;
            typedef const T                               value_type;
            typedef const T*                              pointer;
            typedef const T&                              reference;
            typedef std::ptrdiff_t                  difference_type;
        };
}
#endif