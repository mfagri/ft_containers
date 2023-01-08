/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 01:51:33 by mfagri            #+#    #+#             */
/*   Updated: 2023/01/08 01:23:14 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP
#include<cwchar>

    
namespace ft
{
// std::is_integral is a type trait that is implemented using template metaprogramming techniques in the C++ standard library. It determines whether a type is an integral type, which includes types like char, int, and long long.
// Here is a simplified version of the implementation:
    
   template <typename T>
struct is_integral {
  static const bool value = false;
};

template <>
struct is_integral<bool> {
  static const bool value = true;
};

template <>
struct is_integral<char> {
  static const bool value = true;
};

template <>
struct is_integral<signed char> {
  static const bool value = true;
};

template <>
struct is_integral<unsigned char> {
  static const bool value = true;
};

template <>
struct is_integral<short> {
  static const bool value = true;
};

// ... more specializations for other integral types ...
// template <>
// struct is_integral<short> {
//   static const bool value = true;
// };

template <>
struct is_integral<unsigned short> {
  static const bool value = true;
};

template <>
struct is_integral<int> {
  static const bool value = true;
};

template <>
struct is_integral<unsigned int> {
  static const bool value = true;
};

template <>
struct is_integral<long> {
  static const bool value = true;
};

template <>
struct is_integral<unsigned long> {
  static const bool value = true;
};

template <>
struct is_integral<long long> {
  static const bool value = true;
};

template <>
struct is_integral<unsigned long long> {
  static const bool value = true;
};

}
#endif