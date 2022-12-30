/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:52:30 by mfagri            #+#    #+#             */
/*   Updated: 2022/12/30 20:57:18 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
namespace ft
{

template < class T, class Alloc = std::allocator<T> >
class vector
{
    private:
    
        T *arr;
        size_t m_size;
        size_t m_capacity;
        allocator_type alloc;
    
    public:
        /// Member types
        typedef T                                        value_type;
        typedef Allocator                                allocator_type;
        typedef typename allocator_type::reference       reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef implementation-defined                   iterator;
        typedef implementation-defined                   const_iterator;
        typedef typename allocator_type::size_type       size_type;
        typedef typename allocator_type::difference_type difference_type;
        typedef typename allocator_type::pointer         pointer;
        typedef typename allocator_type::const_pointer   const_pointer;
        typedef std::reverse_iterator<iterator>          reverse_iterator;
        typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;
        
        //default constructor
        vector (const allocator_type& alloc = allocator_type());
        {
            this->m_size = 0;
            this->m_capacity = 0;
            this->arr = NULL;
        }
        //parametres constructor
        vector (size_type n, const value_type& val = value_type(),                 const allocator_type& alloc = allocator_type())
        {
            this->m_size = n;
            this->m_capacity = n;
            this->arr = alloc.allocate(n);
            std::fill(this->arr,this->arr + this->m_size,val);
        }
        vector (InputIterator first, InputIterator last,                 const allocator_type& alloc = allocator_type());
        
        //copy constructor
        vector (const vector& x)
        {
            this->m_capacity = x.m_capacity;
            this->m_size = x.m_size;
            this->arr = alloc.allocate(x.m_size);
            /////
            for(size_t i 0;i < x.m_size;i++)
            {
                this->arr[i] = x.arr[i];
            }
        }
        
        T operator[](size_t n)
        {
            return (arr[n]);
        }

};
}
#endif