/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:55:52 by mfagri            #+#    #+#             */
/*   Updated: 2023/02/20 19:14:34 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP
#include "equal.hpp"
#include "red_black_tree.hpp"
// #include<set>

namespace ft
{
    template <class Key,  class Compare = std::less<Key> ,class Alloc = std::allocator<Key> > 
    class set
    {
        public:
            typedef Key                                      key_type;
            typedef key_type                                 value_type;
            typedef Compare                                  key_compare;
            typedef key_compare                              value_compare;
            typedef Alloc                                    allocator_type;
            typedef typename allocator_type::reference       reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::size_type       size_type;
            typedef typename allocator_type::difference_type difference_type;
            typedef typename allocator_type::pointer         pointer;
            typedef typename allocator_type::const_pointer   const_pointer;
            ///////////////////////////////////////////////////////////////
            class value_compar : std::binary_function<value_type,value_type,bool>{
                friend class set;
                protected:
                    Compare comp;
                public:
                    value_compar() {}
                    size_t operator() (const value_type& x, const value_type& y) const {
                        return comp(x, y);
                    }
            };
            //////////////////////////////////////////////////////////////////
        public:
            key_compare _comp;
            typedef ft::RedBlackTree <key_type, value_type, value_compar, Alloc> Rep_type;
            allocator_type _alloc;
            Rep_type m_tree;
        public:
            typedef typename Rep_type::iterator iterator;
            typedef typename Rep_type::const_iterator const_iterator;
            typedef typename Rep_type::reverse_iterator reverse_iterator;
            typedef typename Rep_type::const_reverse_iterator const_reverse_iterator;
        public:
            explicit set (const key_compare& comp = key_compare(),              const allocator_type& alloc = allocator_type()):_alloc(alloc),m_tree()
            {
                _comp = comp;    
            }	
            template <class InputIterator>  set (InputIterator first, InputIterator last,       const key_compare& comp = key_compare(),       const allocator_type& alloc = allocator_type()):_comp(comp),_alloc(alloc)
            {
                for (; first != last; ++first)
                {
                    this->m_tree.add(*first);
                }
            }
            set (const set& x)
            {
                // if (*this != x)
			    // {
                    _comp = x._comp;
                    _alloc = x._alloc;
                   // erase(begin(),end());
                    insert(x.begin(),x.end());
			    // }
			    // return *this;
            }
            set& operator= (const set& x)
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
            ~set()
            {
                
            }
            /////////////////////////////////////////////////////////////
            pair<iterator,bool> insert (const value_type& val)
            {
                return (m_tree.add(val));
            }
            iterator insert (iterator position, const value_type& val)
            {
                (void)position;
                insert(val);
                return (find(val));
            }
            template <class InputIterator>
            void insert (InputIterator first, InputIterator last)
            {
                while(first != last)
                {
                    m_tree.add(*first++);
                }
            }
            //////////////////////////////////////////////////////////////
            //////////////////////////////////////////////////////////////
            void erase (iterator position)
            {
                 m_tree.deleteNode(*position);
            }
            size_type erase (const value_type& val)
            {
                size_type i;
                if(m_tree.searchTree(val) == m_tree.endn)
                    i = 0;
                else
                {
                    i = 1;
                    m_tree.deleteNode(val);
                }
                return (i);
            }
            void erase (iterator first, iterator last)
            {
                iterator tmp = first;
                while(first != last)
                {
                    tmp++;
                    erase(first);
                    first = tmp;
                }
            }
            /////////////////////////////////////////////////////////////
            iterator find (const value_type& val) const
            {
                return(iterator(m_tree.searchTree(val)));
            }
            //////////////////////////////////////////////////////////////
            //////////////////
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
            /////////////////////////////////////////////////////////////
            size_type size() const
            {
                return m_tree.size();
            }
            ///////////////////////////////////////////////////////////
            bool empty() const
            {
                return m_tree.empty();
            }
            ///////////////////////////////////////////////////////////
            size_type max_size() const
            {
                return m_tree.max_size();
            }
            ////////////////////////////////////////////////////////////
            void clear()
            {
                erase(begin(),end());
            }
            ////////////////////////////////////////////////////////////
            size_type count (const value_type& val) const
            {
                return m_tree.count(val);
            }
            ////////////////////////////////////////////////////////////
            value_compare value_comp() const
            {
                return _comp;
            }
            /////////////////////////////////////////////////////
            key_compare key_comp() const
            {
                return _comp;
            }
            ////////////////////////////////////////////////////
            void swap (set& x)
            {
                set tmp = x;
                x = *this;
                *this = tmp;
            }
            /////////////////////////////////////////////////////
            iterator upper_bound (const value_type& val) const
            {
                return m_tree.upper_bound(val);
            }
            iterator lower_bound (const value_type& val) const
            {
                return m_tree.lower_bound(val);
            }
            pair<iterator,iterator> equal_range (const value_type& val) const
            {
                return(ft::make_pair(lower_bound(val),upper_bound(val)));
            }




            
    };
    template <class T, class Compare, class Alloc>  void swap (const set<T,Compare,Alloc>& x, const set<T,Compare,Alloc>& y)
    {
        x.swap(y);
    }
    template <class T, class Compare, class Alloc>  bool operator== (const set<T,Compare,Alloc>& lhs,                   const set<T,Compare,Alloc>& rhs )
    {
        return lhs.size() == rhs.size() && ft::equal(lhs.begin(),lhs.end(),rhs.begin());
    }
    template <class T, class Compare, class Alloc>  bool operator!= (const set<T,Compare,Alloc>& lhs,                   const set<T,Compare,Alloc>& rhs )
    {
       return !(lhs == rhs);
    }
    template <class T, class Compare, class Alloc>  bool operator<  (const set<T,Compare,Alloc>& lhs,                   const set<T,Compare,Alloc>& rhs )
    {
         return ft::lexicographical_compare(lhs.begin(),lhs.end(),rhs.begin(),rhs.end());
    }
    template <class T, class Compare, class Alloc>  bool operator<= (const set<T,Compare,Alloc>& lhs,                   const set<T,Compare,Alloc>& rhs )
    {
        return !(lhs > rhs);
    }
    template <class T, class Compare, class Alloc> bool operator>  (const set<T,Compare,Alloc>& lhs,                   const set<T,Compare,Alloc>& rhs )
    {
        return (rhs < lhs);
    }
    template <class T, class Compare, class Alloc>  bool operator>= (const set<T,Compare,Alloc>& lhs,                   const set<T,Compare,Alloc>& rhs )
    {
        return !(rhs > lhs);
    }
}

#endif