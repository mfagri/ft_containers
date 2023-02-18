/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_iterator.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:40:56 by mfagri            #+#    #+#             */
/*   Updated: 2023/02/18 18:12:45 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_ITERATOR
#define RED_BLACK_TREE_ITERATOR

#include <iostream>
#include <cstddef>
#include "red_black_tree.hpp"
#include "map.hpp"
namespace ft
{
    template <class T,class Itr>
    class red_black_iterator : public std::iterator<std::bidirectional_iterator_tag , T>
    {
            public:
                typedef Itr                                iterator_type;
                typedef T                                  value_type;
                // typedef RedBlackTree REDB;
                typedef ptrdiff_t                           difference_type;
                typedef T*                                 pointer;
                typedef T&                                 reference;
                typedef std::bidirectional_iterator_tag     iterator_category;
             private:
                //explicit red_black_iterator( iterator_type _rhs) : ptr(_rhs) {}
            public:
                // template <class, class, class,class>
                // friend class RedBlackTree;
                // template <class, class, class, class>
                // friend class map;
                iterator_type  ptr;
                //REDB m_tree;
            public:
                explicit red_black_iterator()
                {
                }
                // ~red_black_iterator()
                // {
                //     //m_tree.clear();
                //    // std::cout << m_tree.size() << std::endl;
                // }
                red_black_iterator(iterator_type x):ptr(x)
                {
                    //puts("0");
                    //m_tree.clear();
                   // m_tree = ntree;
                    //std::cout << m_tree.size() << std::endl;

                }
                red_black_iterator &operator= (const red_black_iterator &x) 
                {
                    this->ptr = x.ptr;
                    // m_tree.dea();
                //    this->m_tree = x.get_mytree();
                //   puts("hr");
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
                    // m_tree->printTree();
                    // puts("dd");
                    ptr = suc(ptr);
                    return *this;
                }
                red_black_iterator operator++(int) ///next
                {
                    red_black_iterator tmp(*this); 
                    ++(*this);
                    // ptr = m_tree->suc(ptr);
                    return tmp;
                }
                red_black_iterator operator--() //preve
                {
                    //puts("3");
                   /// std::cout<<"work of aaaaaaaaart hahahahahahahhaa fuck it\n";
                    this->ptr = prevs(ptr);
                   // puts("dd");
                  //  puts("kamira wawaw");
                    return (*this);
                }
                red_black_iterator operator--(int)
                {
                    red_black_iterator temp(*this);
                    --(*this);
                    return temp;
                }
                // red_black_iterator operator -(red_black_iterator &a)
                // {
                //     red_black_iterator temp(*this);
                //     temp.ptr -= a.ptr;
                //     return temp;
                // }
                difference_type operator-(const red_black_iterator& x){

                    return (this->ptr - x.ptr);
                }
                // REDB get_mytree() const
                // {
                //     return m_tree;
                // }
                private:
                    template <class, class, class,class>
                    friend class RedBlackTree;
                    template <class, class, class, class>
                    friend class map;

    };
   
    template <class T,class Itr>
    class const_red_black_iterator : public std::iterator<std::bidirectional_iterator_tag , T>
    {
            public:
                typedef Itr                                iterator_type;
                typedef T                                  value_type;
                // typedef RedBlackTree REDB;
                typedef ptrdiff_t                           difference_type;
                typedef const T*                                 pointer;
                typedef const T&                                 reference;;
                typedef std::bidirectional_iterator_tag     iterator_category;
             private:
                //explicit const_red_black_iterator( iterator_type _rhs) : ptr(_rhs) {}
            public:
                iterator_type  ptr;
                template <class, class, class,class>
                friend class RedBlackTree;
                template <class, class, class, class>
                friend class map;
                //REDB m_tree;
            public:
                explicit const_red_black_iterator()
                {
                }
                template <typename Iterator>
                const_red_black_iterator(const red_black_iterator<Iterator,Itr>& it) :
                    ptr(it.ptr){}
                const_red_black_iterator(iterator_type x):ptr(x)
                {
                    // std::cout << ptr->data.first << std::endl;
                }
                const_red_black_iterator &operator = (const const_red_black_iterator &x) 
                {
                    this->ptr = x.ptr;
                //     m_tree.dea();
                //    this->m_tree = x.get_mytree();
                  // puts("hr");
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
                    //std::cout<<"work of aaaaaaaaart hahahahahahahhaa fuck it\n";
                    // m_tree->printTree();
                    ptr = suc(ptr);
                    return *this;
                }
                const_red_black_iterator operator++(int) ///next
                {
                    const_red_black_iterator tmp(*this); 
                    ++(*this);
                    // ptr = m_tree->suc(ptr);
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
                // const_red_black_iterator operator -(const_red_black_iterator &a)
                // {
                //     const_red_black_iterator temp(*this);
                //     temp.ptr -= a.ptr;
                //     return temp;
                // }
                difference_type operator-(const const_red_black_iterator& x){

                    return (this->ptr - x.ptr);
                }
                private:
                    template <class, class, class,class>
                    friend class RedBlackTree;
                    template <class, class, class, class>
                    friend class map;

    };
}

#endif