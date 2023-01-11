/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 03:09:48 by mfagri            #+#    #+#             */
/*   Updated: 2023/01/11 03:30:17 by mfagri           ###   ########.fr       */
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
            container_type container;
        public:
            explicit stack (const container_type& ctnr = container_type()):container(ctnr)
            {
            }
            bool empty() const
            {
                return (this->container.empty());
            }
            size_type size() const
            {
                return (this->container.size());
            }
            value_type& top()
            {
                return (this->container.back());
            }
            const value_type& top() const
            {
                 return (this->container.back());
            }
            void push (const value_type& val)
            {
                this->container.push_back(val);
            }
            void pop()
            {
                this->container.pop_back();
            }
    };

template <class T, class Container>  bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
    return (lhs.container == rhs.container);
}	
template <class T, class Container>  bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
    return (lhs.container != rhs.container);
}
template <class T, class Container>  bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
    return (lhs.container < rhs.container);
}
template <class T, class Container>  bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
    return (lhs.container <= rhs.container);
}
template <class T, class Container>  bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
    return (lhs.container > rhs.container);
}
template <class T, class Container>  bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
    return (lhs.container >= rhs.container);
}
}

#endif