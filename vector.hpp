/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:52:30 by mfagri            #+#    #+#             */
/*   Updated: 2023/01/04 06:31:14 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <algorithm>
#include <iostream>
#include <vector>
#include <memory>
#include <map>
#include "vector_iterator.hpp"
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
        typedef ft::iterator<T>						iterator;
		typedef ft::iterator<const T>					const_iterator;
        // typedef implementation-defined                   const_iterator;
        typedef typename allocator_type::size_type       size_type;
        typedef typename allocator_type::difference_type difference_type;
        typedef typename allocator_type::pointer         pointer;
        typedef typename allocator_type::const_pointer   const_pointer;
        // typedef ft::reverse_iterator<T>          reverse_iterator;
        // typedef ft::reverse_iterator<const T>    const_reverse_iterator;
        
    
        //default constructor
        
    vector (const allocator_type& alloc = allocator_type())
    {
        _alloc = alloc;
        this->m_size = 0;
        this->m_capacity = 0;
        this->arr = NULL;
    }
    //destructor
    ~vector()
    {
        _alloc.deallocate(arr,m_capacity);
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
    
    class throw_out_of_range : public std::exception
    {
        const char *what() const throw()
        {
            return "vector";
        }
    };
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
    vector& operator= (const vector& x)
    {
        if(this != &x)
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
        return(*this);
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

    // void shrink_to_fit()
    // {
    //     if(m_capacity > m_size)
    //     {
    //         value_type *tmp = _alloc.allocate(m_size);
    //         for (size_t i = 0; i < m_size; i++)
    //             tmp[i] = arr[i];
    //         _alloc.deallocate(arr,m_capacity);
    //         arr = tmp;
    //         this->m_capacity = this->m_size;
    //     }
    // }
    
    void reserve (size_type n)
    {
        if(n <= m_capacity)
            return;
        value_type *new_arr = _alloc.allocate(n);

        for (size_t i = 0; i < m_size && i < n; i++)
            new_arr[i] = arr[i];// construct
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
    void assign (size_type n, const value_type& val)
    {
        if(n >= this->m_capacity)
        {
            value_type *tmp = _alloc.allocate(n);
            for (size_t i = 0; i < n; i++)
            {
                tmp[i] = val;
            }
            _alloc.deallocate(arr,m_capacity);
            arr = tmp;
            m_capacity = n;
            m_size = n;
            
        }
        else{
            value_type *tmp = _alloc.allocate(n);
            for (size_t i = 0; i < n; i++)
            {
                tmp[i] = val;
            }
             _alloc.deallocate(arr,m_capacity);
            arr = tmp;
            m_size = n;
        }
    }
    reference back()
    {
       return (arr[m_size - 1]);
    }
    const_reference back() const
    {
       return (arr[m_size - 1]);
    }
    
    reference front()
    {
        return (arr[0]);
    }
    
    const_reference front() const
    {
        return (arr[0]);
    }
    
    const_reference at (size_type n) const
    {
        if (n >= size())
            throw throw_out_of_range();
        return this->arr[n];
    }
    
    reference at (size_type n)
    {
        if (n >= size())
            throw throw_out_of_range();
        return this->arr[n];
    }
    void pop_back()
    {
        --m_size;
    }
    
    void clear()
    {
        m_size = 0;
    }
    allocator_type get_allocator() const
    {
        return (_alloc);
    }
    void swap (vector& x)
    {
        std::swap(*this,x);////ssds
    }
    //   void reserve( int newCapacity )
    // {
    //     if( newCapacity < theSize )  ➀
    //         return;

    //     Object *newArray = new Object[ newCapacity ]; ➁
    //     for( int k = 0; k < theSize; ++k )            ➂
    //         newArray[ k ] = std::move( objects[ k ] );

    //     theCapacity = newCapacity;
    //     std::swap( objects, newArray );   ➃
    //     delete [ ] newArray;              ➄
    // }
    // void push_back( const Object & x )
    // {
    //     if( theSize == theCapacity ) ➀
    //         reserve( 2 * theCapacity + 1 ); ➁
    //     objects[ theSize++ ] = x;
    // }
    void push_back (const value_type& val)
    {
            if (m_capacity == m_size) {
                value_type *tmp = _alloc.allocate(m_capacity);
                for (size_t i = 0; i < m_capacity; i++)
                {
                    _alloc.construct(tmp+i,arr[i]);
                }
                _alloc.deallocate(arr,m_capacity);
                _alloc.destroy(arr);
                m_capacity *= 2;
                if(m_capacity == 0)
                    m_capacity++;
                arr = _alloc.allocate(m_capacity);
                for (size_t i = 0; i < m_size; i++)
                {
                    // arr[i] = tmp[i];
                    _alloc.construct(arr+i,tmp[i]);
                }
                _alloc.construct(arr+m_size,val);
                //arr[m_size] = val;
                _alloc.deallocate(tmp,m_capacity);
                _alloc.destroy(tmp);
            }
            else
                arr[m_size] = val;
            m_size++;
    }

    iterator begin()
    {
        return iterator(&arr[0]);
    }
    const_iterator begin() const
    {
        return iterator(&arr[0]);
    }
    iterator end()
    {
        return iterator(&arr[m_size]);
    }

    const_iterator end() const
    {
        return iterator(&arr[m_size]);
    }

    // iterator                                       begin(){return iterator(&m_data[0]);}
    // iterator                                       end(){return iterator(&m_data[m_size]);}

    // const_iterator                                 cbegin(){return const_iterator(&m_data[0]);}
    // const_iterator                                 cend(){return const_iterator(&m_data[m_size]);}

    // reverse_iterator                               rbegin(){return reverse_iterator(&arr[m_size - 1]);}
    // reverse_iterator                               rend(){return reverse_iterator(&arr[-1]);}

    // const_reverse_iterator                         crbegin(){return const_reverse_iterator(&m_data[m_size - 1]);}
    // const_reverse_iterator                         crend(){return const_reverse_iterator(&m_data[-1]);}

};
}
#endif