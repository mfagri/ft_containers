/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:31:26 by mfagri            #+#    #+#             */
/*   Updated: 2023/01/15 18:52:26 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "equal.hpp"

namespace ft
{
    template < class Key, class T, class Compare = std::less<Key>,class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
    {
        public:
            typedef Key key_type;
            typedef T mapped_type;
            typedef ft::pair<const key_type,mapped_type> value_type;
            typedef Compare key_compare;
            typedef Alloc                               allocator_type;
            // typedef value_compare (Compare c) : comp(c) {}
            typedef typename allocator_type::size_type       size_type;//A type that counts the number of elements in a vector.
            typedef typename allocator_type::difference_type difference_type;//A type that provides the difference between the addresses of two elements in a vector.
            typedef typename allocator_type::pointer         pointer;//A type that provides a pointer to a component of a vector.
            typedef typename allocator_type::const_pointer   const_pointer;//A t
            typedef typename allocator_type::reference       reference;//A type that provides a reference to an element stored in a vector.
            typedef typename allocator_type::const_reference const_reference;
            ////////////////////////////////////////////////////////////////////////////////////////
            
             class value_compare
               : public binary_function<value_type, value_type, bool>
               {
             friend class map<_Key,_Tp,_Compare,_Alloc>;
               protected:
                Compare comp;
 
                value_compare(_Compare __c)
                : comp(__c) { }
            
                public:
                bool operator()(const value_type& __x, const value_type& __y) const
                { return comp(__x.first, __y.first); }
                };
            
            //////////////////////////////////////////////////////////////////////////
            explicit map (const key_compare& comp = key_compare(),              const allocator_type& alloc = allocator_type())
            {
            }
            //*  Create a %map consisting of copies of the elements from [first,last).
            // *  This is linear in N if the range is already sorted, and NlogN
            // *  otherwise (where N is distance(first,last)).
            template <class InputIterator>  map (InputIterator first, InputIterator last,       const key_compare& comp = key_compare(),       const allocator_type& alloc = allocator_type())
            {
                
            }
            map (const map& x)
            {
                ////////
            }
            ~map();
            map& operator= (const map& x);
            /////////////////////////////////////////////////////////////////////////////////////////
            iterator begin();
            const_iterator begin() const;
            ///////////////////////////////////////////////////////////////////////////////////////////
            iterator end();
            const_iterator end() const;
            ///////////////////////////////////////////////////////////////////////////////////////
            reverse_iterator rbegin();
            const_reverse_iterator rbegin() const;
            ///////////////////////////////////////////////////////////////////////////////////
            reverse_iterator rend();
            const_reverse_iterator rend() const;
            ///////////////////////////////////////////////////////////////////////////////////////
            bool empty() const;
            size_type size() const;
            size_type max_size() const;
            ///////////////////////////////////////////////////////////////////////////////
            mapped_type& operator[] (const key_type& k);
            mapped_type& at (const key_type& k);
            const mapped_type& at (const key_type& k) const;
            ///////////////////////////////////////////////////////////////////////////////////////////
    };
}

#endif