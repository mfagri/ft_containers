/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:03:13 by mfagri            #+#    #+#             */
/*   Updated: 2023/02/02 22:17:53 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef REVERSE_HPP
# define REVERSE_HPP

#include "vector_iterator.hpp"

namespace ft{
    
template< class Iterator >
    class reverse_iterator : public std::iterator<
        typename iterator_traits<Iterator>::iterator_category,
        typename iterator_traits<Iterator>::value_type
        >
    {
        private:
            Iterator m_it;
        public:
            typedef Iterator iterator_type;
            typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
            typedef typename iterator_traits<Iterator>::value_type value_type;
            typedef typename iterator_traits<Iterator>::difference_type difference_type;
            typedef typename iterator_traits<Iterator>::pointer pointer;
            typedef typename iterator_traits<Iterator>::reference reference;

            reverse_iterator(){};
            explicit reverse_iterator (iterator_type it)
            {
                m_it = it;
            }
            template <class iter>
            reverse_iterator (const reverse_iterator<iter>& rev_it)
            {
                this->m_it = rev_it.m_it;
            }
            iterator_type base() const
            {
                return m_it;
            }
            reference operator*() const
            {
                //puts("revers iterator");
                Iterator tmp = m_it;
                return *(--tmp);
            }
            reverse_iterator operator+ (difference_type n) const
            {
                this->m_it - n;
                return (*this);
            }
            reverse_iterator operator- (difference_type n) const
            {
                this->m_it - n;
                return (*this);
            }
            reverse_iterator operator++(int)
            {
                reverse_iterator temp = *this;
                ++(*this);
                return temp;
            }

            reverse_iterator& operator++()
            {
                m_it--;
                return (*this);
            }
            reverse_iterator operator--(int)
            {
                reverse_iterator temp = *this;
                --(*this);
                return temp;
            }
            reverse_iterator& operator--()
            {
                m_it++;
                return (*this);
            }
            reverse_iterator& operator+= (difference_type n)
            {
                this->m_it -=n;
                return (*this);
            }
            reverse_iterator& operator-= (difference_type n)
            {
                this->m_it +=n;
                return (*this);
            }
            
            reference operator[] (difference_type n) const
            {
                return base()[-n-1];
            }
            pointer operator->() const
            {
                return &(operator*());
            }
            

    };
    template <class Iterator>  bool operator== (const reverse_iterator<Iterator>& lhs,const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() == rhs.base());
    }
    template <class Iterator>  bool operator!= (const reverse_iterator<Iterator>& lhs,const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() != rhs.base());
    }
    template <class Iterator>  bool operator<  (const reverse_iterator<Iterator>& lhs,const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() > rhs.base());
    }
    template <class Iterator>  bool operator<= (const reverse_iterator<Iterator>& lhs,const reverse_iterator<Iterator>& rhs)
    {
         return (lhs.base() >= rhs.base());
    }
    template <class Iterator>  bool operator>  (const reverse_iterator<Iterator>& lhs,const reverse_iterator<Iterator>& rhs)
    {
         return (lhs.base() < rhs.base());
    }
    template <class Iterator>  bool operator>= (const reverse_iterator<Iterator>& lhs,const reverse_iterator<Iterator>& rhs)
    {
         return (lhs.base() <= rhs.base());
    }
    template <class Iterator>  reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n,const reverse_iterator<Iterator>& rev_it)
    {
         return (n - rev_it);
    }
    template <class Iterator>  typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs,const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() + rhs.base());
    }
}
# endif