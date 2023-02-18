/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:31:26 by mfagri            #+#    #+#             */
/*   Updated: 2023/02/18 23:54:57 by mfagri           ###   ########.fr       */
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
            // typedef value_compare (Compare c) : comp(c) {}
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
            
            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):_alloc(alloc)
            {
                _comp = comp;
                // puts("what");
                // while (1);
                
                // this->allocator_type = allocator_type;
            }
            
            //*  Create a %map consisting of copies of the elements from [first,last).
            // *  This is linear in N if the range is already sorted, and NlogN
            // *  otherwise (where N is distance(first,last)).
            template <class InputIterator>  map (InputIterator first, InputIterator last,       const key_compare& comp = key_compare(),       const allocator_type& alloc = allocator_type()):_comp(comp),_alloc(alloc)
            {
                // std::cout<<"taniii\n";
                //this->insert(first,last);
                for (; first != last; ++first)
                {
                    // std::cout<<first->first<<std::endl;
                    this->m_tree.add(*first);
                }
                // puts("dd");
                
            }
            map (const map& x):_alloc(x._alloc),_comp(x._comp)
            {
                if (x.size() > 0)
                    insert(x.begin(),x.end());
            }
            ~map(){
                // std::cout<<"here\n";
                //m_tree()
             erase(begin(),end());
                
               // m_tree.clear();
             //  puts("hhh");
               m_tree.dea();
               //m_tree.dea();
                //m_tree.printTree();

                // puts("ggg");
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
                if (*this != x)
			    {
                    _comp = x._comp;
                    _alloc = x._alloc;
                    //clear();
                    erase(begin(),end());
                    //m_tree = x.m_tree;

                     
			    	// this->m_size = x.m_size;
                    //std::cout<<size()<<std::endl;
                    insert(x.begin(),x.end());
                   // puts("ffo");
                    //return *this;
			    	// this->_tree.clear();
			    	// this->_tree.~RBT();	
			    	// _alloc.deallocate(this->_tree.get_node_end(), 1);
			    	// // _alloc.deal
			    	// this->_tree = _m._tree;
			    }
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
                return(iterator(m_tree.searchTree(value_type(k, mapped_type()))));
            }
            const_iterator find (const key_type& k) const
            {
                return(const_iterator(m_tree.searchTree(value_type(k, mapped_type()))),m_tree);
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
                //m_tree.clear();
            }
            void delet(const key_type &k)
            {
                    m_tree.deleteNode(value_type(k ,mapped_type()));
                    
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
            // const_iterator upper_bound(const key_type& k) const
            // {
            //     return m_tree.upper_bound(k);
            // }
            ///////////////////////////////////////////////////////////////////
            iterator lower_bound(const key_type& k)
            {
                iterator it = begin();
                while(it != end() && _comp(it->first,k))it++;
                return  it;
            }
            // const_iterator lower_bound (const key_type& k) const
            // {
            //     return m_tree.lower_bound(k);
            // }
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
                //mapped_type b = this->insert(value_type(k, mapped_type()));
                return (this->insert(value_type(k, mapped_type())).first->second);
            }
            ///////////////////////////////////////////////////////////////////
            void erase (iterator position)
            {
                m_tree.deleteNode(value_type(position->first, mapped_type()));
            }
            ///////////////////////////////////////////////////////////////////
            size_type erase (const key_type& k)
            {
                size_type i;
                if(m_tree.searchTree(value_type(k ,mapped_type())) == m_tree.TNULL)
                    i = 0;
                else
                    i = 1;
                m_tree.deleteNode(value_type(k ,mapped_type()));
                return (i);
            }
            ///////////////////////////////////////////////////////////////////
            void erase (iterator first, iterator last)
            {
                iterator tmp = first;
                while(first != last)
                {
                    //std::cout<<first->first<<std::endl;
                    tmp++;
                    m_tree.deleteNode(value_type(first->first, mapped_type()));
                    //erase(first);
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