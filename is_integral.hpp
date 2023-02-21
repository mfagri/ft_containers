/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 01:51:33 by mfagri            #+#    #+#             */
/*   Updated: 2023/02/21 16:58:46 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP
#include<cwchar>

    
namespace ft
{
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