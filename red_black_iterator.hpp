/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_iterator.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:40:56 by mfagri            #+#    #+#             */
/*   Updated: 2023/01/17 14:21:11 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE
#define RED_BLACK_TREE

#include <iostream>


namespace ft
{
     template < class T,class Itr>
    class red_balck_iterator : public std::iterator<std::bidirectional_iterator_tag , T>
    {
            public:
                typedef Itr                                iterator_type;
                typedef T                                  value_type;
                typedef ptrdiff_t                           difference_type;
                typedef T*                                 pointer;
                typedef T&                                 reference;
                typedef std::bidirectional_iterator_tag     iterator_category;

            private:
                template <class, class, class>
                friend class RedBlackTree;
                template <class, class, class, class>
                friend class map;
                iterator_type ptr;

                red_balck_iterator(T *s = NULL)
                {
                    ptr = s;
                }
                
                red_balck_iterator(const iterator &x):ptr(x.ptr)
                {}
                red_balck_iterator &operator = (const iterator &x) 
                {
                    ptr = x.ptr;
                    
                    return *this;
                }
                bool operator==(const red_balck_iterator& rhs) const 
                {
                    return ptr==rhs.ptr;
                }
                
                bool operator!=(const red_balck_iterator& rhs) const 
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

                red_balck_iterator& operator++() 
                {
                    ptr = next(ptr);
                    return *this;
                }

                red_balck_iterator operator++(int) ///next
                {
                    red_balck_iterator tmp(*this); 
                    operator++(); 
                    return tmp;
                }
                red_balck_iterator operator--() //preve
                {
                    ptr = prev(ptr);
                    return (*this);
                }
                red_balck_iterator operator--(int)
                {
                    red_balck_iterator temp(*this);
                    operator--()
                    return temp;
                }

    };    
}

#endif