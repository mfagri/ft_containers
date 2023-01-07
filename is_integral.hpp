/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 01:51:33 by mfagri            #+#    #+#             */
/*   Updated: 2023/01/07 04:28:35 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP
#include<cwchar>
namespace ft{
    
    // integral_constant, defined in tr1, is a wrapper for an integer
    // value. We don't really need this generality; we could get away
    // with hardcoding the integer type to bool. We use the fully
    // general integer_constant for compatibility with tr1.

    template<class T, T v>
    struct integral_constant {
    static const T value = v;
    typedef T value_type;
    typedef integral_constant<T, v> type;
    };

    template <class T, T v> const T integral_constant<T, v>::value;
    
    // Abbreviations: true_type and false_type are structs that represent boolean
    // true and false values. Also define the boost::mpl versions of those names,
    // true_ and false_.
    typedef integral_constant<bool, true>  true_type;
    typedef integral_constant<bool, false> false_type;
    typedef true_type  true_;
    typedef false_type false_;
    template<class T>
    struct is_integral
    {
        typedef T type;
    };
    template <class T> struct is_integral;
    // template <class T> struct is_integral : false_type { };
    template<> struct is_integral<bool> : true_type { };
    template<> struct is_integral<char> : true_type { };
    template<> struct is_integral<unsigned char> : true_type { };
    template<> struct is_integral<signed char> : true_type { };

    // template<> struct is_integral<wchar_t> : true_type { };
    template<> struct is_integral<wchar_t> : true_type { };
    template<> struct is_integral<short> : true_type { };
    template<> struct is_integral<unsigned short> : true_type { };
    template<> struct is_integral<int> : true_type { };
    template<> struct is_integral<unsigned int> : true_type { };
    template<> struct is_integral<long> : true_type { };
    template<> struct is_integral<unsigned long> : true_type { };
    template<> struct is_integral<long long> : true_type { };
    template<> struct is_integral<unsigned long long> : true_type { };
}
#endif