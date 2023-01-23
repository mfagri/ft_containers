/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:31:26 by mfagri            #+#    #+#             */
/*   Updated: 2023/01/23 19:16:21 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <string>
#include "equal.hpp"
#include "red_black_tree.hpp"

namespace ft
{
    template < class Key, class T, class Compare = std::less<Key>,class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
    {
        public:
            typedef Key key_type;
            typedef T mapped_type;
            typedef ft::pair<Key,T> value_type;
            // typedef Compare key_compare;
            typedef Alloc                               allocator_type;
            // typedef value_compare (Compare c) : comp(c) {}
            typedef typename allocator_type::size_type       size_type;//A type that counts the number of elements in a vector.
            typedef typename allocator_type::difference_type difference_type;//A type that provides the difference between the addresses of two elements in a vector.
            typedef typename allocator_type::pointer         pointer;//A type that provides a pointer to a component of a vector.
            typedef typename allocator_type::const_pointer   const_pointer;//A t
            typedef typename allocator_type::reference       reference;//A type that provides a reference to an element stored in a vector.
            typedef typename allocator_type::const_reference const_reference;
            ////////////////////////////////////////////////////////////////////////////////////////
            typedef Compare key_compare;
            class value_compare
            {
                friend class map;

            protected:
                Compare _comp;
                value_compare(Compare _c) : _comp(_c) {}

            public:
                typedef bool result_type;
                typedef value_type first_type;
                typedef value_type second_type;
                result_type operator()(const value_type &_x, const value_type &_y) const
                {
                    return (_comp(_x.first, _y.first));
                }
            };
        public:
            typedef ft::RedBlackTree <key_type, value_type, key_compare, Alloc> Rep_type;
            Rep_type m_tree;
        public:
            typedef typename Rep_type::iterator iterator;
            // typedef typename Rep_type::const_iterator const_iterator;
            //////////////////////////////////////////////////////////////////////////
            
            // explicit map (const key_compare& comp = key_compare(),              const allocator_type& alloc = allocator_type()) 
            // {
               
            //     // this->allocator_type = allocator_type;
            // }
            
            //*  Create a %map consisting of copies of the elements from [first,last).
            // *  This is linear in N if the range is already sorted, and NlogN
            // *  otherwise (where N is distance(first,last)).
            // template <class InputIterator>  map (InputIterator first, InputIterator last,       const key_compare& comp = key_compare(),       const allocator_type& alloc = allocator_type())
            // {
                
            // }
            // map (const map& x)
            // {
            //     ////////
            // }
            ~map(){}
            void insert ( const value_type & val)
            {
                m_tree.add(val);
            }
            // map& operator= (const map& x);
            // /////////////////////////////////////////////////////////////////////////////////////////
            iterator begin()
            {
                return m_tree.begin();
            }
            // const_iterator begin() const;
            // ///////////////////////////////////////////////////////////////////////////////////////////
            iterator end()
            {
                return m_tree.end();
            }
            // const_iterator end() const
            // {
            //     return m_tree.end();
            // }
            // ///////////////////////////////////////////////////////////////////////////////////////
            // reverse_iterator rbegin();
            // const_reverse_iterator rbegin() const;
            // ///////////////////////////////////////////////////////////////////////////////////
            // reverse_iterator rend();
            // const_reverse_iterator rend() const;
            // ///////////////////////////////////////////////////////////////////////////////////////
            // bool empty() const;
            // size_type size() const;
            // size_type max_size() const;
            // ///////////////////////////////////////////////////////////////////////////////
            mapped_type& operator[] (const key_type& k)
            {
                (*((this->insert(make_pair(k,mapped_type()))).first));
            }
            // mapped_type& at (const key_type& k);
            // const mapped_type& at (const key_type& k) const;
            ///////////////////////////////////////////////////////////////////////////////////////////
    };
}

#endif