/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_iterator.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:40:56 by mfagri            #+#    #+#             */
/*   Updated: 2023/01/17 18:31:35 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_ITERATOR
#define RED_BLACK_TREE_ITERATOR

#include <iostream>


namespace ft
{
    template < class T,class Itr>
    class red_black_iterator : public std::iterator<std::bidirectional_iterator_tag , T>
    {
            public:
                typedef Itr                                iterator_type;
                typedef T                                  value_type;
                typedef ptrdiff_t                           difference_type;
                typedef T*                                 pointer;
                typedef T&                                 reference;
                typedef std::bidirectional_iterator_tag     iterator_category;
             private:
                explicit red_black_iterator(iterator_type _rhs) : ptr(_rhs) {}
            private:
                template <class, class, class,class>
                friend class RedBlackTree;
                template <class, class, class, class>
                friend class map;
                iterator_type ptr;
            public:
                red_black_iterator()
                {
                }
                
                // red_black_iterator(const iterator &x):ptr(x.ptr)
                // {}
                // red_black_iterator &operator = (const iterator &x) 
                // {
                //     ptr = x.ptr;
                    
                //     return *this;
                // }
                // bool operator==(const red_black_iterator& rhs) const 
                // {
                //     return ptr==rhs.ptr;
                // }
                
                // bool operator!=(const red_black_iterator& rhs) const 
                // {
                //     return ptr!=rhs.ptr;
                // }

                reference operator*() const
                {
                    return *ptr->data;
                }

                pointer operator->() const 
                {
                    return &(operator*());
                }

                red_black_iterator& operator++() 
                {
                    ptr = next(ptr);
                    return *this;
                }
                red_black_iterator operator++(int) ///next
                {
                    red_black_iterator tmp(*this); 
                    ++(*this); 
                    return tmp;
                }
                red_black_iterator operator--() //preve
                {
                    ptr = prev(ptr);
                    return (*this);
                }
                red_black_iterator operator--(int)
                {
                    red_black_iterator temp(*this);
                    --(*this);
                    return temp;
                }

    };    
}

#endif