/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:52:30 by mfagri            #+#    #+#             */
/*   Updated: 2023/01/01 04:57:28 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <algorithm>
#include <iostream>
#include <vector>
#include <memory>
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
        Alloc _alloc;
    
    public:
        /// Member types
        typedef T                                        value_type;
        typedef Alloc                               allocator_type;
        typedef typename allocator_type::reference       reference;
        typedef typename allocator_type::const_reference const_reference;
        // typedef implementation-defined                   iterator;
        // typedef implementation-defined                   const_iterator;
        typedef typename allocator_type::size_type       size_type;
        typedef typename allocator_type::difference_type difference_type;
        typedef typename allocator_type::pointer         pointer;
        typedef typename allocator_type::const_pointer   const_pointer;
        // typedef std::reverse_iterator<iterator>          reverse_iterator;
        // typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;
        
        //default constructor
    vector (const allocator_type& alloc = allocator_type())
    {
        _alloc = alloc;
        this->m_size = 0;
        this->m_capacity = 0;
        this->arr = NULL;
    }
    //parametres constructor
    vector (size_type n, const value_type& val = value_type(),const allocator_type& alloc = allocator_type())
    {
        this->m_size = n;
        this->m_capacity = n;
        _alloc =  alloc;
        this->arr = _alloc.allocate(n);
        for(size_t i = 0;i < m_size;i++)
        {
            this->arr[i] = val;
        }
    }
    
    //copy constructor
    vector (const vector& x)
    {
        this->m_capacity = x.m_capacity;
        this->m_size = x.m_size;
        this->arr = _alloc.allocate(x.m_size);
        /////
        for(size_t i = 0;i < x.m_size;i++)
        {
            this->arr[i] = x.arr[i];
        }
    }
    
    reference operator[](size_type n)
    {
        return (arr[n]);
    }
    const_reference operator[] (size_type n) const {
        return (arr[n]);
    }
    size_type capacity() const
    {
        return(this->m_capacity);
    }
    size_type size() const
    {
        return(this->m_size);
    }
    size_type max_size() const
    {
        return (this->_alloc.max_size());
    }
    bool empty() const
    {
        return (this->m_size == 0);
    }

    void shrink_to_fit()
    {
         value_type *tmp = _alloc.allocate(m_size);
         for (size_t i = 0; i < m_size; i++)
             tmp[i] = arr[i];
        _alloc.deallocate(arr,m_capacity);
         arr = tmp;
        this->m_capacity = this->m_size;
    }
    
    void reserve (size_type n)
    {
        if(n == m_capacity)
            return;
        value_type *new_arr = _alloc.allocate(n);

        for (size_t i = 0; i < m_size && i < n; i++) {
            new_arr[i] = arr[i];
        }
        _alloc.deallocate(arr, m_capacity);
        arr = new_arr;
        m_capacity = n;
    }
    
    void resize (size_type n, value_type val = value_type())
    {
        if(n <= m_size)
        {
        //     value_type *tmp = _alloc.allocate(n);
        //     for (size_t i = 0; i < n; i++)
        //         tmp[i] = arr[i];
        //    // _alloc.deallocate(arr,m_capacity);
        //     arr = tmp;
            m_size = n;
        }
        if(n > m_size)
        {
            if(n > m_capacity)
                m_capacity *=2;
            value_type *tmp = _alloc.allocate(m_capacity);
            for (size_t i = 0; i < n; i++)
            {
                if(i < m_size)
                    tmp[i] = arr[i];
                else
                    tmp[i] = val;
            }
            _alloc.deallocate(arr,m_capacity);
            arr = tmp;
            m_size = n;
        }
    }
    void push_back (const value_type& val)
    {
            if (m_capacity == m_size) {
                value_type *tmp = _alloc.allocate(m_capacity);
                for (size_t i = 0; i < m_capacity; i++)
                {
                    tmp[i] = arr[i];
                }
                _alloc.deallocate(arr,m_capacity);
                m_capacity *= 2;
                if(m_capacity == 0)
                    m_capacity++;
                arr = _alloc.allocate(m_capacity);
                for (size_t i = 0; i < m_size; i++)
                {
                    arr[i] = tmp[i];
                }
                arr[m_size] = val;
                
            }
            else
                arr[m_size] = val;
            m_size++;
    }
};
}
#endif