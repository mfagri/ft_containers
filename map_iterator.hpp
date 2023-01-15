/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:53:03 by mfagri            #+#    #+#             */
/*   Updated: 2023/01/15 19:17:03 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include <iterator>

namespace ft
{
    template < class T >
    class map_iterator : public std::iterator<std::bidirectional_iterator_tag , T>
    {
        private:
                T *ptr;
            public:
                typedef T value_type;
                typedef T* pointer;
                typedef T& reference;
                typedef std::ptrdiff_t difference_type;
                typedef std::bidirectional_iterator_tag iterator_category;

                map_iterator(T *s = NULL)
                {
                    ptr =s;
                }
                
                map_iterator(const iterator &x):ptr(x.ptr)
                {}
                map_iterator &operator = (const iterator &x) 
                {
                    ptr = x.ptr;
                    return *this;
                }
                bool operator==(const map_iterator& rhs) const 
                {
                    return ptr==rhs.ptr;
                }
                
                bool operator!=(const map_iterator& rhs) const 
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

                map_iterator& operator++() 
                {
                    ++ptr;return *this;
                }

                map_iterator operator++(int) 
                {
                    map_iterator tmp(*this); 
                    operator++(); 
                    return tmp;
                }
                map_iterator operator--()
                {
                    --ptr;
                    return (*this);
                }
                map_iterator operator--(int)
                {
                    map_iterator temp(*this);
                    --ptr;
                    return temp;
                }

                value_type operator*++
    }
}
#endif