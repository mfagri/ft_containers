/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:52:30 by mfagri            #+#    #+#             */
/*   Updated: 2023/02/24 19:32:04 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
// #include <type_traits>
#include <algorithm>
#include <iostream>
#include <vector>
#include <memory>
#include <map>
#include "vector_iterator.hpp"
#include "reverse_iterator.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "equal.hpp"
    using namespace std;

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
        typedef T                                        value_type;//Type representing the type of data stored in a vector.
        typedef Alloc                               allocator_type;//A type that represents the allocator class for the vector object.
        typedef typename allocator_type::reference       reference;//A type that provides a reference to an element stored in a vector.
        typedef typename allocator_type::const_reference const_reference;//A type that provides a reference to a const element stored in a vector. It is used to read and perform const operations.
        typedef ft::iterator<T>						iterator;//A type that provides a random access iterator to read or modify an element in a vector.
		typedef ft::iterator<const T>					const_iterator;//A type that provides a random access iterator that can read a const element in a vector.
        typedef typename allocator_type::size_type       size_type;//A type that counts the number of elements in a vector.
        typedef typename allocator_type::difference_type difference_type;//A type that provides the difference between the addresses of two elements in a vector.
        typedef typename allocator_type::pointer         pointer;//A type that provides a pointer to a component of a vector.
        typedef typename allocator_type::const_pointer   const_pointer;//A type that provides a pointer to a const component of a vector.
        typedef typename ft::reverse_iterator<ft::iterator<T> >          reverse_iterator;//A type that provides a random access iterator that can read or modify an element of an inverted vector.
        typedef typename ft::reverse_iterator<ft::iterator<const T> >    const_reverse_iterator;//A type that provides a random access iterator that can read any const element in the vector.
        
    
    //default constructor
        
    explicit vector (const allocator_type& alloc = allocator_type())
    {
        _alloc = alloc;
        this->m_size = 0;
        this->m_capacity = 0;
        this->arr = NULL;
        // puts("1");
        //   exit(0);
    }
    template< class InputIt >
    vector( InputIt first, InputIt last,const allocator_type& alloc = allocator_type(),typename ft::enable_if<!ft::is_integral<InputIt>::value>::type* = 0)
    {
        _alloc = alloc;
        this->m_size = last - first;
        this->m_capacity = last -first;
       difference_type n =  last -first;
       size_t i = 0;
       arr = _alloc.allocate(n);
        while (n)
        {
            _alloc.construct(arr+i,*first);
            first++;
            i++;
            n--;
            
        }
    }
    //destructor
    ~vector()
    {
        clear();
            _alloc.deallocate(arr,m_capacity);
    }
    //parametres constructor
    explicit vector (size_type n, const value_type& val = value_type(),const allocator_type& alloc = allocator_type())
    {
        this->m_size = n;
        this->m_capacity = n;
        _alloc =  alloc;
        this->arr = _alloc.allocate(n);
        for(size_t i = 0;i < m_size;i++)
        {
            // this->arr[i] = val;
            _alloc.construct(arr+i,val);
        }
        // puts("3");
        //   exit(0);
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
        for(size_t i = 0;i < x.m_size;i++)
        {
            _alloc.construct(arr+i,x.arr[i]);
        }
    }
    vector& operator= (const vector& x)
    {
        if(this != &x)
        {
            // puts("fff");
            clear();
            _alloc.deallocate(arr,m_capacity);
            this->m_capacity = x.m_capacity;
            this->m_size = x.m_size;
            this->arr = _alloc.allocate(x.m_size);
            /////
            for(size_t i = 0;i < x.m_size;i++)
            {
                //this->arr[i] = x.arr[i];
                _alloc.construct(arr+i,x.arr[i]);
            }
        }
        return(*this);
    }
    //operator[]: Returns a reference to the vector element at a specified position.
    reference operator[](size_type n)
    {
        return (arr[n]);
    }
    const_reference operator[] (size_type n) const {
        return (arr[n]);
    }
    //capacity: Returns the number of elements that the vector could contain without allocating more storage.
    size_type capacity() const
    {
        return(this->m_capacity);
    }
    //size: Returns the number of elements in the vector.
    size_type size() const
    {
        return(this->m_size);
    }
    //max_size: Returns the maximum length of the vector.
    size_type max_size() const
    {
        return (this->_alloc.max_size());
    }
    //empty: Tests if the vector is empty.
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
    
    //reserve: Reserves a minimum length of storage for a vector object, allocating space if necessary.
    void reserve (size_type n)
    {
        if(n <= m_capacity)
            return;
        value_type *new_arr = _alloc.allocate(n);

        for (size_t i = 0; i < m_size && i < n; i++)
            _alloc.construct(new_arr+i,arr[i]);
        _alloc.deallocate(arr, m_capacity);
        arr = new_arr;
        m_capacity = n;
    }
    //resize: Specifies a new size for a vector.
    void resize (size_type n, value_type val = value_type())
    {
        if(n <= m_size)
        {
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
                    _alloc.construct(tmp+i,arr[i]);
                else
                    _alloc.construct(tmp+i,val);
            }
            _alloc.deallocate(arr,m_capacity);
            
            arr = tmp;
            m_size = n;
        }
    }
    //assing :Erases a vector and copies the specified elements to the empty vector.
    void assign (size_type n, const value_type& val)
    {
        if(n >= this->m_capacity)
        {
            value_type *tmp = _alloc.allocate(n);
            for (size_t i = 0; i < n; i++)
            {
                _alloc.construct(tmp+i,val);
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
                _alloc.construct(tmp+i,val);
            }
             _alloc.deallocate(arr,m_capacity);
            arr = tmp;
            m_size = n;
        }
    }
    //back: Returns a reference to the last element of the vector.
    reference back()
    {
       return (arr[m_size - 1]);
    }
    const_reference back() const
    {
       return (arr[m_size - 1]);
    }
    //front: Returns a reference to the first element in a vector.
    reference front()
    {
        return (arr[0]);
    }
    
    const_reference front() const
    {
        return (arr[0]);
    }
    //at: Returns a reference to the element at a specified location in the vector
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
    //pop_back :Deletes the element at the end of the vector.
    void pop_back()
    {
        --m_size;
    }
    //clear :Erases the elements of the vector.
    void clear()
    {
        // for (size_t i = 0; i < m_capacity; i++)
        // {
        //     _alloc.destroy(arr+i);
        // }
        // if(m_capacity > 0)
            // _alloc.deallocate(arr,m_capacity);
        //m_capacity = 0;
        m_size = 0;
    }
    //get_allocator: Returns a copy of the allocator object used to construct the vector.
    allocator_type get_allocator() const
    {
        return (_alloc);
    }

    //swap: Exchanges the elements of two vectors.
    
    void swap (vector& x)
    {
        // vector *tmp(x);
        // x = *this;
        // *this = tmp;
        // std::swap(*this,x);////ssds
        if(x != *this)
        {
            // std::swap(arr,x.arr);
            // std::swap(m_size,x.m_size);
            // std::swap(m_capacity,x.m_capacity);
            vector tmp(x);
            x = *this;
            *this = tmp;
        }

        
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

    
    //push_back: Adds an element to the end of the vector.
    void push_back (const value_type& val)
    {
        // puts("here");
            // size_t firstc = m_capacity;
            if (m_capacity == m_size) {
                value_type *tmp = _alloc.allocate(m_capacity);
                for (size_t i = 0; i < m_capacity; i++)
                {
                    _alloc.construct(tmp+i,arr[i]);
                }
                _alloc.deallocate(arr,m_capacity);
               // _alloc.destroy(arr);
                // puts("hna");
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
                // _alloc.destroy(tmp);
            }
            else
                arr[m_size] = val;
            m_size++;
    }
    //begin : Returns a random-access iterator to the first element in the vector.
    iterator begin()
    {
        // puts("begin");
        return iterator(&arr[0]);
    }
    const_iterator begin() const
    {
        return const_iterator(&arr[0]);
    }
    //end: Returns a past-the-end iterator that points to the element following the last element of the vector.
    iterator end()
    {
        // puts("end");
        return iterator(&arr[m_size]);
    }

    const_iterator end() const
    {
        return const_iterator(&arr[m_size]);
    }
    //rbegin: Returns an iterator to the first element in a reversed vector.
    reverse_iterator                rbegin()
    {
        return reverse_iterator(end());
    }
    const_reverse_iterator rbegin() const
    {
        return reverse_iterator(end());
    }
    //rend: Returns a past-the-end reverse iterator that points to the element following the last element of the reversed vector.
    reverse_iterator                  rend()
    {
        return reverse_iterator(begin());
    }
    const_reverse_iterator rend() const
    {
        return reverse_iterator(begin());
    }

    //assing: Erases a vector and copies the specified elements to the empty vector.
    template <class InputIterator>  void assign (InputIterator first, InputIterator last,typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
    {
        difference_type n = last - first;
        _alloc.deallocate(arr,(difference_type)m_capacity);
        if((size_t)n >= m_capacity)
        {
            m_capacity = n;
        }
        value_type *tmp = _alloc.allocate(m_capacity);
        for (size_t i = 0; i < (size_t)n; i++)
        {
            //tmp[i] = *first;
            _alloc.construct(tmp+i,*first);
            first++;
        }
        arr = tmp;
        m_size = n;
    }

    //arase: Removes an element or a range of elements in a vector from specified positions.
    iterator erase (iterator first, iterator last)
    {
        size_t position = last - first;
        size_t l = first - begin();
        for(size_t i  = l; i < (m_size - position);)
        {
            arr[i] = arr[i +  position];
            i++;
        }
        m_size-= position;
        return (this->arr + (l));        
    }
    iterator erase (iterator position)
    { 
        size_t t_position = position - begin();
        for(size_t i = t_position;i < m_size-1;)
        {
            arr[i] = arr[i + 1];
            i++;
        }
        m_size--;
        return (position);
    }



    //insert: Inserts an element, or many elements, or a range of elements into the vector at a specified position.
    iterator insert (iterator position, const value_type& val)
    {

        size_t l = position - begin();
        iterator it = begin();
        size_t z = 0;
        while(it != position)///need to fix hhhhhhh
        {
            it++;
            z++;
        }
        m_size++;
        if(m_size > m_capacity)
            m_capacity *= 2;
        if(m_capacity == 0)
            m_capacity++;
        value_type *tmp = _alloc.allocate(m_capacity);
        for (size_t i = 0; i < l; i++)
        {
            _alloc.construct(tmp+i,arr[i]);
        }
        size_t i = l;
        _alloc.construct(tmp+i,val);
        i++;
        for ( ;i < m_size; i++)
        {
            _alloc.construct(tmp+i,arr[i-1]);
        }
        _alloc.deallocate(arr,m_capacity);
        arr = tmp;
        return (iterator(&arr[z]));
    }
    void insert (iterator position, size_type n, const value_type & val)
    {
    
        iterator it = this->begin();
        size_t i = 0;
        for (; it != position; it++)
        {
            i++;
        }
        value_type *tmp;
        size_type m_n;
        if(m_capacity == 0)
            m_capacity++;
        else if(m_size + n >= m_capacity)
        {
            m_n = m_size + n;
            m_capacity = m_n;
        }
        // printf("m : %d\n",m_capacity);
        tmp = _alloc.allocate(m_capacity);
        size_t j = 0;
        for(;j != i;j++)
        {
            _alloc.construct(tmp+j,arr[j]);
        }
        size_type k = n;
        while(n)
        {
            _alloc.construct(tmp+j,val);
            j++;
            n--;
        }
        // std::cout << "hey\n";
        // printf("i : %d\tk : %d\tj : %d\tm_size : %d\n", i, k, j, m_size);
        while(i + k < m_size+k)
        {
            _alloc.construct(tmp+j,arr[i]);
            j++;
            i++;
        }
        m_size += k;
        // _alloc.destroy(arr);
        _alloc.deallocate(arr, m_size);
        arr =tmp;
        
    }

  
    template <class InputIterator> 
    void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
    {
       
        vector tmpv;
        InputIterator tm;
        tm = first;
        while (tm != last)
        {
            tmpv.push_back(*tm);
            tm++;
        }
        

        difference_type n = std::distance(first, last);

        iterator it = this->begin();
        size_t i = 0;
        for (; it != position; it++)
        {
            i++;
        }
        value_type *tmp;
        if(m_size + n >= m_capacity)
        {
            m_capacity *= 2;
        }
        else if(m_capacity == 0)
        {
            m_capacity++;
        }
        if(m_capacity)
            tmp = _alloc.allocate(m_capacity);
        else
            tmp = _alloc.allocate(n);
        size_t j = 0;
        for(;j != i;j++)
        {
             _alloc.construct(tmp+j,arr[j]);
        }
        size_type k = n;
        while(n)
        {
            tmp[j]= *first;
            ++j;
            --n;
            ++first;
        }
        while(i+k < m_size+k)
        {
            _alloc.construct(tmp+j,arr[i]);
            ++j;
            ++i;
        }
        _alloc.deallocate(arr, m_capacity);
        m_size += k;
        if(m_capacity == 0)
            m_capacity = m_size;
        arr = tmp;  

    }




    
};
    template <class T, class Alloc>  bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return lhs.size() == rhs.size() && ft::equal(lhs.begin(),lhs.end(),rhs.begin());
    }

    template <class T, class Alloc>  bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return !(lhs == rhs);
    }

    template <class T, class Alloc>  bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return ft::lexicographical_compare(lhs.begin(),lhs.end(),rhs.begin(),rhs.end());
    }

    template <class T, class Alloc>  bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return !(lhs > rhs);
    }

    template <class T, class Alloc>  bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (rhs < lhs);
    }

    template <class T, class Alloc>  bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return !(rhs > lhs);
    }

    template <class T, class Alloc>  void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
    {
        x.swap(y);
    }
}
#endif