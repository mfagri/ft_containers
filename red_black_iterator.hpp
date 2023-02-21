/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_iterator.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:40:56 by mfagri            #+#    #+#             */
/*   Updated: 2023/02/21 16:57:36 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_ITERATOR
#define RED_BLACK_TREE_ITERATOR

#include <iostream>
#include <cstddef>
#include "red_black_tree.hpp"
namespace ft
{
    template <class T,class Itr>
    class red_black_iterator : public std::iterator<std::bidirectional_iterator_tag , T>
    {
            public:
                typedef Itr                                iterator_type;
                typedef T                                  value_type;
                typedef ptrdiff_t                           difference_type;
                typedef T*                                 pointer;
                typedef T&                                 reference;
                typedef std::bidirectional_iterator_tag     iterator_category;
            public:
                iterator_type  ptr;
            public:
                explicit red_black_iterator()
                {
                }
                red_black_iterator(iterator_type x):ptr(x)
                {

                }
                red_black_iterator &operator= (const red_black_iterator &x) 
                {
                    if(this != &x)
                        this->ptr = x.ptr;
                    return *this;
                }
                bool operator==(const red_black_iterator& rhs) const 
                {
                    return ptr==rhs.ptr;
                }
                
                bool operator!=(const red_black_iterator& rhs) const 
                {
                    return ptr!=rhs.ptr;
                }

                reference operator*() const
                {
                    return (ptr->data);
                }
                pointer operator->() const
                {
                    return (&ptr->data);
                }
                red_black_iterator& operator++() 
                {
                    ptr = suc(ptr);
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
                    this->ptr = prevs(ptr);
                    return (*this);
                }
                red_black_iterator operator--(int)
                {
                    red_black_iterator temp(*this);
                    --(*this);
                    return temp;
                }
                difference_type operator-(const red_black_iterator& x){

                    return (this->ptr - x.ptr);
                }

    };
   
    template <class T,class Itr>
    class const_red_black_iterator : public std::iterator<std::bidirectional_iterator_tag , T>
    {
            public:
                typedef Itr                                iterator_type;
                typedef T                                  value_type;
                typedef ptrdiff_t                           difference_type;
                typedef const T*                                 pointer;
                typedef const T&                                 reference;;
                typedef std::bidirectional_iterator_tag     iterator_category;
            public:
                iterator_type  ptr;
            public:
                explicit const_red_black_iterator()
                {
                }
                template <typename Iterator>
                const_red_black_iterator(const red_black_iterator<Iterator,Itr>& it) :
                    ptr(it.ptr){}
                const_red_black_iterator(iterator_type x):ptr(x)
                {
                }
                const_red_black_iterator &operator = (const const_red_black_iterator &x) 
                {
                    this->ptr = x.ptr;
                    return *this;
                }
                bool operator==(const const_red_black_iterator& rhs) const 
                {
                    return ptr==rhs.ptr;
                }
                
                bool operator!=(const const_red_black_iterator& rhs) const 
                {
                    return ptr!=rhs.ptr;
                }

                reference operator*() const
                {
                    return (ptr->data);
                }
                pointer operator->() const
                {
                    return (&ptr->data);
                }
                const_red_black_iterator& operator++() 
                {
                    ptr = suc(ptr);
                    return *this;
                }
                const_red_black_iterator operator++(int) ///next
                {
                    const_red_black_iterator tmp(*this); 
                    ++(*this);
                    return tmp;
                }
                const_red_black_iterator operator--() //preve
                {
                    ptr = prevs(ptr);
                    return (*this);
                }
                const_red_black_iterator operator--(int)
                {
                    const_red_black_iterator temp(*this);
                    --(*this);
                    return temp;
                }
                difference_type operator-(const const_red_black_iterator& x){

                    return (this->ptr - x.ptr);
                }

    };
}

#endif