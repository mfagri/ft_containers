/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 03:51:17 by mfagri            #+#    #+#             */
/*   Updated: 2023/02/28 18:36:12 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
#define EQUAL_HPP
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "vector_iterator.hpp"

namespace ft
{
    template<class InputIt1, class InputIt2>
    bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
    {
        for (; first1 != last1; ++first1, ++first2) {
            if (!(*first1 == *first2)) {
                return false;
            }
        }
        return true;
    }
    

    template<class InputIt1, class InputIt2>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
                                InputIt2 first2, InputIt2 last2)
    {
        for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
        {
            if (*first1 < *first2)
                return true;
            if (*first2 < *first1)
                return false;
        }
    
        return (first1 == last1) && (first2 != last2);
    }
    
    ///////////////////////////////////////////

    template <typename T1, typename T2>
        class pair
    {
        typedef T1 first_type;
        typedef T2 second_type;

        public:
            first_type   first;
            second_type  second;

            pair() : first(), second() { }

            template<class U, class V>
            pair (const ft::pair<U,V> & pr):first(pr.first),second(pr.second)
            {
            }
            pair(first_type const &a, second_type const &b)
            :first(a),second(b)
            {
            }
            
            pair& operator = (const pair& __p)
            { 
                first = __p.first;
                second = __p.second;
                return *this;
            }
    };
    template <class T1, class T2>
    bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return lhs.first==rhs.first && lhs.second==rhs.second; }
    template <class T1, class T2>
    bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return !(lhs==rhs); }
    template <class T1, class T2>
    bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }
    template <class T1, class T2>
    bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return !(rhs<lhs); }
    template <class T1, class T2>
    bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return rhs<lhs; }
    template <class T1, class T2>
    bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return !(lhs<rhs); }
    
    template<class _T1, class _T2>
    void swap(pair<_T1, _T2>& __x, pair<_T1, _T2>& __y)
     { __x.swap(__y); }
    
    template <typename T1, typename T2>
    pair<T1, T2> make_pair(T1  a,T2  b)
    {
        return pair<T1, T2>(a, b);
    }
}

#endif