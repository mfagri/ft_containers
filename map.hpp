/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:31:26 by mfagri            #+#    #+#             */
/*   Updated: 2023/02/08 22:24:34 by mfagri           ###   ########.fr       */
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
                allocator_type _alloc;
                
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
            key_compare _comp;
            allocator_type _alloc;
            Rep_type m_tree;
        public:
            typedef typename Rep_type::iterator iterator;
            typedef typename Rep_type::const_iterator const_iterator;
            typedef typename Rep_type::reverse_iterator reverse_iterator;
            typedef typename Rep_type::const_reverse_iterator const_reverse_iterator;
            //////////////////////////////////////////////////////////////////////////
            
            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):_comp(comp),_alloc(alloc),m_tree()
            {
                // puts("what");
                // while (1);
                
                // this->allocator_type = allocator_type;
            }
            
            //*  Create a %map consisting of copies of the elements from [first,last).
            // *  This is linear in N if the range is already sorted, and NlogN
            // *  otherwise (where N is distance(first,last)).
            template <class InputIterator>  map (InputIterator first, InputIterator last,       const key_compare& comp = key_compare(),       const allocator_type& alloc = allocator_type()):_comp(comp),_alloc(alloc),m_tree(first,last)
            {
                // std::cout<<"taniii\n";
                //this->insert(first,last);
                // for (; first != last; ++first)
                // {
                //     // std::cout<<first->first<<std::endl;
                //     this->m_tree.add(*first);
                // }
                // puts("dd");
                
            }
            map (const map& x):_alloc(x._alloc),m_tree(x.m_tree),_comp(x._comp)
            {
                ////////
            }
            ~map(){
                // // std::cout<<"here\n";
                // this->erase(this->begin(),this->end());
                // clear();
                // m_tree.dea();
                // // while (1);
                // // // {
                // // //     /* code */
                // // // }
                
                // // erase()
                // // this->m_tree.~RedBlackTree();
                // //this->clear();
                // // _alloc.deallocate()
            }
            map& operator= (const map& x)
            {
                this->clear();
                insert(x.begin(),x.end());
                return *this;
            }
            // pair<iterator,bool> insert (const value_type& val);
             pair<iterator,bool> insert ( const value_type & val)
            {
                return m_tree.add(val); 
            }
            template <class InputIterator>  void 
            insert (InputIterator first, InputIterator last)
            {
               // difference_type n = last-first;
                // (void)n;
                
                // std::cout<<first->first<<std::endl;
                while(first != last)
                {
                    // puts("f");
                    // std::cout<<(first)->first<<std::endl;
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
                return(iterator(m_tree.searchTree(k),m_tree));
            }
            const_iterator find (const key_type& k) const
            {
                return(const_iterator(m_tree.searchTree(k),m_tree));
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
                //puts("rebegin map");
                return m_tree.rbegin();
            }
            const_reverse_iterator rbegin() const
            {
                return m_tree.rbegin();
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
                return m_tree.count(k);
            }
            //////////////////////////////////////////////
            void clear()
            {
                m_tree.clear();
            }
            void delet(const key_type &k)
            {
                    m_tree.deleteNode(k);
                    
            }
            ////////////////////////////////////////
            allocator_type get_allocator() const
            {
                return _alloc;
            }
            /////////////////////////////////////////
            void swap (map& x)
            {
                m_tree.swap(x.m_tree);
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
                return m_tree.upper_bound(k);
            }
            const_iterator upper_bound(const key_type& k) const
            {
                return m_tree.upper_bound(k);
            }
            ///////////////////////////////////////////////////////////////////
            iterator lower_bound(const key_type& k)
            {
                return m_tree.lower_bound(k);
            }
            const_iterator lower_bound (const key_type& k) const
            {
                return m_tree.lower_bound(k);
            }
            ///////////////////////////////////////////////////////
            pair<iterator,iterator>             equal_range (const key_type& k)
            {
                return m_tree.equal_range(k);
            }
            pair<const_iterator,const_iterator> equal_range (const key_type& k) const
            {
                return m_tree.equal_range(k);
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
                m_tree.deleteNode(position->first);
            }
            ///////////////////////////////////////////////////////////////////
            size_type erase (const key_type& k)
            {
                m_tree.deleteNode(k);
                return (1);
            }
            ///////////////////////////////////////////////////////////////////
            void erase (iterator first, iterator last)
            {
                iterator tmp = first;
                while(first != last)
                {
                    tmp++;
                    // m_tree.deleteNode(first->first);
                    erase(first);
                    // std::cout<<tmp->first<<std::endl;
                    first = tmp;
                    
                    // if(first == end());
                    // std::cout << "hey 2\n";
                    // first = tmp;
                }
            }
            ///////////////////////////////////////////////////////////////////
            // mapped_type& at (const key_type& k);
            // const mapped_type& at (const key_type& k) const;
            ///////////////////////////////////////////////////////////////////////////////////////////
             ///////////////////////////no member functions ///////////////////////
        
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