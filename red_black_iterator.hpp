/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_iterator.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:40:56 by mfagri            #+#    #+#             */
/*   Updated: 2023/01/26 18:43:24 by mfagri           ###   ########.fr       */
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
    template <class tree, class T,class Itr>
    class red_black_iterator : public std::iterator<std::bidirectional_iterator_tag , T>
    {
            public:
                typedef Itr                                iterator_type;
                typedef T                                  value_type;
                typedef tree REDB;
                typedef ptrdiff_t                           difference_type;
                typedef T*                                 pointer;
                typedef T&                                 reference;
                typedef std::bidirectional_iterator_tag     iterator_category;
             private:
                //explicit red_black_iterator( iterator_type _rhs) : ptr(_rhs) {}
            private:
                // template <class, class, class,class>
                // friend class RedBlackTree;
                // template <class, class, class, class>
                // friend class map;
                iterator_type  ptr;
                REDB m_tree;
            public:
                explicit red_black_iterator()
                {
                }
             
                red_black_iterator(iterator_type x,REDB ntree):ptr(x),m_tree(ntree)
                {
                    // std::cout << ptr->data.first << std::endl;
                }
                red_black_iterator &operator = (const red_black_iterator &x) 
                {
                    ptr = x.ptr;
                    
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
                    ptr = m_tree.suc(ptr);
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
                   /// std::cout<<"work of aaaaaaaaart hahahahahahahhaa fuck it\n";
                    this->ptr = m_tree.prev(ptr);
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
                private:
                    template <class, class, class,class>
                    friend class RedBlackTree;
                    // template <class, class, class, class>
                    // friend class map;

    };
    ////////////////////////////////////////////////////////////////////////////////////////////////
    //const_red_black_iterator
    // template <class tree, class T,class Itr>
    // class const_red_black_iterator : public std::iterator<std::bidirectional_iterator_tag , T>
    // {
    //         public:
    //             typedef Itr                                iterator_type;
    //             typedef T                                  value_type;
    //             typedef ptrdiff_t                           difference_type;
    //             typedef const T*                                 pointer;
    //             typedef const T&                                 reference;
    //             typedef std::bidirectional_iterator_tag     iterator_category;
    //          private:
    //             explicit const_red_black_iterator(iterator_type _rhs) : ptr(_rhs) {}
    //         private:
    //             // template <class, class, class,class>
    //             // friend class RedBlackTree;
    //             // template <class, class, class, class>
    //             // friend class map;
    //             iterator_type ptr;
    //         public:
    //             const_red_black_iterator()
    //             {
    //             }
    //             const_red_black_iterator base() const 
    //             {
    //                 return (ptr);
    //             }
    //             const_red_black_iterator(const iterator_type &x):ptr(x.ptr)
    //             {}
    //             const_red_black_iterator &operator = (const iterator_type &x) 
    //             {
    //                 ptr = x.ptr;
                    
    //                 return *this;
    //             }
    //             bool operator==(const const_red_black_iterator& rhs) const 
    //             {
    //                 return ptr==rhs.ptr;
    //             }
                
    //             bool operator!=(const const_red_black_iterator& rhs) const 
    //             {
    //                 return ptr!=rhs.ptr;
    //             }

    //             reference operator*() const
    //             {
    //                 return (ptr->data);
    //             }

    //             pointer operator->() const 
    //             {
    //                 return (&ptr->data);
    //             }

    //             const_red_black_iterator& operator++() 
    //             {
    //                 ptr = next(ptr);
    //                 return *this;
    //             }
    //             const_red_black_iterator operator++(int) ///next
    //             {
    //                 const_red_black_iterator tmp(*this); 
    //                 ++(*this); 
    //                 return tmp;
    //             }
    //             const_red_black_iterator operator--() //preve
    //             {
    //                 ptr = prev(ptr);
    //                 return (*this);
    //             }
    //             const_red_black_iterator operator--(int)
    //             {
    //                 const_red_black_iterator temp(*this);
    //                 --(*this);
    //                 return temp;
    //             }
    //             private:
    //                 template <class, class, class,class>
    //                 friend class RedBlackTree;
    //                 template <class, class, class, class>
    //                 friend class map;

    // };  
    template <class tree, class T,class Itr>
    class const_red_black_iterator : public std::iterator<std::bidirectional_iterator_tag , T>
    {
            public:
                typedef Itr                                iterator_type;
                typedef T                                  value_type;
                typedef tree REDB;
                typedef ptrdiff_t                           difference_type;
                typedef const T*                                 pointer;
                typedef const T&                                 reference;;
                typedef std::bidirectional_iterator_tag     iterator_category;
             private:
                //explicit const_red_black_iterator( iterator_type _rhs) : ptr(_rhs) {}
            private:
                // template <class, class, class,class>
                // friend class RedBlackTree;
                // template <class, class, class, class>
                // friend class map;
                iterator_type  ptr;
                REDB m_tree;
            public:
                explicit const_red_black_iterator()
                {
                }
             
                const_red_black_iterator(iterator_type x,REDB ntree):ptr(x),m_tree(ntree)
                {
                    // std::cout << ptr->data.first << std::endl;
                }
                const_red_black_iterator &operator = (const const_red_black_iterator &x) 
                {
                    ptr = x.ptr;
                    
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
                    ptr = m_tree.suc(ptr);
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
                    ptr = m_tree.prev(ptr);
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
                    // template <class, class, class, class>
                    // friend class map;

    };
}

#endif