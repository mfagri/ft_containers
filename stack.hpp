/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 03:09:48 by mfagri            #+#    #+#             */
/*   Updated: 2023/02/03 20:35:34 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP
#include "vector.hpp"
namespace ft
{
    template <class T, class Container = ft::vector<T> > class stack
    {
        public:
            typedef size_t size_type;
            typedef T value_type;
            typedef Container container_type;
            typedef T* pointer;
            typedef T const * const_pointer;
            typedef T& reference;
            typedef T const & const_reference;
        protected:
            container_type c;
        public:
            explicit stack (const container_type& ctnr = container_type()):c(ctnr)
            {
            }
            bool empty() const
            {
                return (this->c.empty());
            }
            size_type size() const
            {
                return (this->c.size());
            }
            value_type& top()
            {
                return (this->c.back());
            }
            const value_type& top() const
            {
                 return (this->c.back());
            }
            void push (const value_type& val)
            {
                this->c.push_back(val);
            }
            void pop()
            {
                this->c.pop_back();
            }
    };

template <class T, class Container>  bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
    return (lhs.c == rhs.c);
}	
template <class T, class Container>  bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
    return (lhs.container != rhs.container);
}
template <class T, class Container>  bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
    return (lhs.c < rhs.c);
}
template <class T, class Container>  bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
    return (lhs.container <= rhs.container);
}
template <class T, class Container>  bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
    return (lhs.c > rhs.c);
}
template <class T, class Container>  bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
    return (lhs.c >= rhs.c);
}
}

#endif