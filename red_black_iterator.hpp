/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_iterator.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:40:56 by mfagri            #+#    #+#             */
/*   Updated: 2023/01/16 18:52:56 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE
#define RED_BLACK_TREE


namespace ft
{
     template < class T >
    class red_balck_iterator : public std::iterator<std::bidirectional_iterator_tag , T>
    {
        private:
                T *ptr;
            public:
                typedef T value_type;
                typedef T* pointer;
                typedef T& reference;
                typedef std::ptrdiff_t difference_type;
                typedef std::bidirectional_iterator_tag iterator_category;

                red_balck_iterator(T *s = NULL)
                {
                    ptr = s;
                }
                
                red_balck_iterator(const iterator &x):ptr(x.ptr)
                {}
                red_balck_iterator &operator = (const iterator &x) 
                {
                    ptr = x.ptr;
                    return *this;
                }
                bool operator==(const red_balck_iterator& rhs) const 
                {
                    return ptr==rhs.ptr;
                }
                
                bool operator!=(const red_balck_iterator& rhs) const 
                {
                    return ptr!=rhs.ptr;
                }

                reference operator*() const
                {
                    return *ptr;
                }

                pointer operator->() const 
                {
                    return &(operator*());
                }

                red_balck_iterator& operator++() 
                {
                    ptr = getNext(ptr);
                    return *this;
                }

                red_balck_iterator operator++(int) ///next
                {
                    red_balck_iterator tmp(*this); 
                    operator++(); 
                    return tmp;
                }
                red_balck_iterator operator--() //preve
                {
                    --ptr;
                    return (*this);
                }
                red_balck_iterator operator--(int)
                {
                    red_balck_iterator temp(*this);
                    --ptr;
                    return temp;
                }

    };    
}

#endif