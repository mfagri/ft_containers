/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:31:26 by mfagri            #+#    #+#             */
/*   Updated: 2023/02/24 23:11:50 by mfagri           ###   ########.fr       */
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
            typedef ft::pair<const Key,mapped_type> value_type;
            typedef Compare key_compare;
            typedef Alloc                               allocator_type;
            typedef typename allocator_type::size_type       size_type;//A type that counts the number of elements in a vector.
            typedef typename allocator_type::difference_type difference_type;//A type that provides the difference between the addresses of two elements in a vector.
            typedef typename allocator_type::pointer         pointer;//A type that provides a pointer to a component of a vector.
            typedef typename allocator_type::const_pointer   const_pointer;//A t
            typedef typename allocator_type::reference       reference;//A type that provides a reference to an element stored in a vector.
            typedef typename allocator_type::const_reference const_reference;
            ////////////////////////////////////////////////////////////////////////////////////////
              class value_compare : std::binary_function<value_type,value_type,bool>{
                friend class map;
                protected:
                    Compare comp;
                public:
                    value_compare() {}
                    size_t operator() (const value_type& x, const value_type& y) const {
                        return comp(x.first, y.first);
                    }
            };
            ////////////////////////////////////////////////////////////////////////////////////////
        public:
            key_compare _comp;
            typedef ft::RedBlackTree <key_type, value_type, value_compare, Alloc> Rep_type;
            allocator_type _alloc;
            Rep_type m_tree;
        public:
            typedef typename Rep_type::iterator iterator;
            typedef typename Rep_type::const_iterator const_iterator;
            typedef typename Rep_type::reverse_iterator reverse_iterator;
            typedef typename Rep_type::const_reverse_iterator const_reverse_iterator;
            //////////////////////////////////////////////////////////////////////////
            
            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):_alloc(alloc),m_tree()
            {
                _comp = comp;
            }
            
            template <class InputIterator>  map (InputIterator first, InputIterator last,       const key_compare& comp = key_compare(),       const allocator_type& alloc = allocator_type()):_comp(comp),_alloc(alloc)
            {
                for (; first != last; ++first)
                {
                    this->m_tree.add(*first);
                }               
            }
            map (const map& x):_alloc(x._alloc),_comp(x._comp)
            {
                if (x.size() > 0)
                    insert(x.begin(),x.end());
            }
            ~map(){
            }
            map& operator= (const map& x)
            {
                if (*this != x)
			    {
                    _comp = x._comp;
                    _alloc = x._alloc;
                    erase(begin(),end());
                    insert(x.begin(),x.end());
			    }
			    return *this;
            }
             pair<iterator,bool> insert ( const value_type & val)
            {
                return m_tree.add(val); 
            }
            template <class InputIterator>  void 
            insert (InputIterator first, InputIterator last)
            {
                while(first != last)
                {
                    m_tree.add(*first++);
                }
            }
            iterator insert (iterator position, const value_type& val)
            {
                (void)position;
                insert(val);
                return (find(val.first));
            }

            iterator find (const key_type& k)
            {
                return(iterator(m_tree.find(value_type(k, mapped_type()))));
            }
            const_iterator find (const key_type& k) const
            {
                return(const_iterator(m_tree.find(value_type(k, mapped_type()))),m_tree);
            }
            // /////////////////////////////////////////////////////////////////////////////////////////
            iterator begin()
            {
                return m_tree.begin();
            }
            const_iterator begin() const
            {
                return m_tree.begin();
            }
            // ///////////////////////////////////////////////////////////////////////////////////////////
            iterator end()
            {
                return m_tree.end();
            }
            const_iterator end() const
            {
                return m_tree.end();
            }
            // ///////////////////////////////////////////////////////////////////////////////////////
            reverse_iterator rbegin()
            {
                return reverse_iterator(end());
            }
            const_reverse_iterator rbegin() const
            {
                return const_reverse_iterator(end());

            }
            // ///////////////////////////////////////////////////////////////////////////////////
            reverse_iterator rend()
            {
                return reverse_iterator(begin());
            }
            const_reverse_iterator rend() const
            {
                return const_reverse_iterator(begin());
            }
            // ///////////////////////////////////////////////////////////////////////////////////////
            bool empty() const
            {
                return m_tree.empty();
            }
            /////////////////////////////////////////////////////////////////////
            size_type size() const
            {
                return m_tree.size();
            }
            //////////////////////////////////////////////////
            size_type count (const key_type& k) const
            {
                return m_tree.count(value_type(k,mapped_type()));
            }
            //////////////////////////////////////////////
            void clear()
            {
                erase(begin(),end());
            }
            void delet(const key_type &k)
            {
                    m_tree.ft_delete(value_type(k ,mapped_type()));
                    
            }
            ////////////////////////////////////////
            allocator_type get_allocator() const
            {
                return _alloc;
            }
            /////////////////////////////////////////
            void swap (map& x)
            {
                map tmp(x);
                x = *this;
                *this = tmp;
            }
            /////////////////////////////////////////
            size_type max_size() const
            {
                return m_tree.max_size();
            }
            ////////////////////////////////////////
            
            ////////////////////////////////////////////////////////////////////////////////
            iterator upper_bound(const key_type& k)
            {
                iterator it = begin();
                while(it != end() && _comp(it->first,k))it++;
                return  it;
            }
            const_iterator upper_bound(const key_type& k) const
            {
                const_iterator it = begin();
                while(it != end() && _comp(it->first,k))it++;
                return  it;
            }
            ///////////////////////////////////////////////////////////////////
            iterator lower_bound(const key_type& k)
            {
                iterator it = begin();
                while(it != end() && _comp(it->first,k))it++;
                return  it;
            }
            const_iterator lower_bound (const key_type& k) const
            {
                const_iterator it = begin();
                while(it != end() && _comp(it->first,k))it++;
                return  it;
            }
            ///////////////////////////////////////////////////////
            ft::pair<iterator,iterator>  equal_range (const key_type& k)
            { 
                iterator i = lower_bound(k);
                iterator j = i;
                if (i != end() && !(_comp(k, (*i).first)))
                    ++j;
                return ft::make_pair(i, j);
            }
            ft::pair<const_iterator,const_iterator>  equal_range (const key_type& k) const
            { 
                const_iterator i = lower_bound(k);
                const_iterator j = i;
                if (i != end() && !(_comp(k, (*i).first)))
                    ++j;
                return ft::make_pair(i, j);
            }
            //////////////////////////////////////////////////
            value_compare value_comp() const
            {
                return _comp;
            }
            /////////////////////////////////////////////////////
            key_compare key_comp() const
            {
                return _comp;
            }
            // ///////////////////////////////////////////////////////////////////////////////
            mapped_type& operator[] (const key_type& k)
            {
                return (this->insert(value_type(k, mapped_type())).first->second);
            }
            ///////////////////////////////////////////////////////////////////
            void erase (iterator position)
            {
                m_tree.ft_delete(value_type(position->first, mapped_type()));
            }
            ///////////////////////////////////////////////////////////////////
            size_type erase (const key_type& k)
            {
                size_type i;
                if(m_tree.find(value_type(k ,mapped_type())) == m_tree.endn)
                    i = 0;
                else
                {
                    i = 1;
                    m_tree.ft_delete(value_type(k ,mapped_type()));
                }
                return (i);
            }
            ///////////////////////////////////////////////////////////////////
            void erase (iterator first, iterator last)
            {
                iterator tmp = first;
                while(first != last)
                {
                    // std::cout<<first->first<<std::endl;
                    tmp++;
                     m_tree.ft_delete(value_type(first->first, mapped_type()));
                    first = tmp;
                }
            }
    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////no member functions ////////////////////////////////////////////
        
    };
    template <class Key, class T, class Compare, class Alloc>  void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
    {
        x.swap(y);
    }
    template <class Key, class T, class Compare, class Alloc>  bool operator== ( const map<Key,T,Compare,Alloc>& lhs,                    const map<Key,T,Compare,Alloc>& rhs )
    {
        return lhs.size() == rhs.size() && ft::equal(lhs.begin(),lhs.end(),rhs.begin());
    }
    template <class Key, class T, class Compare, class Alloc>  bool operator!= ( const map<Key,T,Compare,Alloc>& lhs,                    const map<Key,T,Compare,Alloc>& rhs )
    {
       return !(lhs == rhs);
    }
    template <class Key, class T, class Compare, class Alloc>  bool operator<  ( const map<Key,T,Compare,Alloc>& lhs,                    const map<Key,T,Compare,Alloc>& rhs )
    {
         return ft::lexicographical_compare(lhs.begin(),lhs.end(),rhs.begin(),rhs.end());
    }
    template <class Key, class T, class Compare, class Alloc>  bool operator<= ( const map<Key,T,Compare,Alloc>& lhs,                    const map<Key,T,Compare,Alloc>& rhs )
    {
        return !(lhs > rhs);
    }
    template <class Key, class T, class Compare, class Alloc>  bool operator>  ( const map<Key,T,Compare,Alloc>& lhs,                    const map<Key,T,Compare,Alloc>& rhs )
    {
        return (rhs < lhs);
    }
    template <class Key, class T, class Compare, class Alloc>  bool operator>= ( const map<Key,T,Compare,Alloc>& lhs,                    const map<Key,T,Compare,Alloc>& rhs )
    {
        return !(rhs > lhs);
    }
}

#endif