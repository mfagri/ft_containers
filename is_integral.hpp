/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 01:51:33 by mfagri            #+#    #+#             */
/*   Updated: 2023/02/28 18:18:31 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

    
namespace ft
{
   template <class T> struct is_integral: public std::false_type{};
    
    template <> struct is_integral<bool>: public std::true_type{};
    template <> struct is_integral<char>: public std::true_type{};
    template <> struct is_integral<char16_t>: public std::true_type{};
    template <> struct is_integral<char32_t>: public std::true_type{};
    template <> struct is_integral<wchar_t>: public std::true_type{};
    template <> struct is_integral<signed char>: public std::true_type{};
    template <> struct is_integral<short int>: public std::true_type{};
    template <> struct is_integral<int>: public std::true_type{};
    template <> struct is_integral<long int>: public std::true_type{};
    template <> struct is_integral<long long int>: public std::true_type{};
    template <> struct is_integral<unsigned char>: public std::true_type{};
    template <> struct is_integral<unsigned short int>: public std::true_type{};
    template <> struct is_integral<unsigned int>: public std::true_type{};
    template <> struct is_integral<unsigned long int>: public std::true_type{};
    template <> struct is_integral<unsigned long long int>: public std::true_type{};

// template <>
// struct is_integral<signed char> {
//   static const bool value = true;
// };

// template <>
// struct is_integral<unsigned char> {
//   static const bool value = true;
// };

// template <>
// struct is_integral<short> {
//   static const bool value = true;
// };

// template <>
// struct is_integral<unsigned short> {
//   static const bool value = true;
// };

// template <>
// struct is_integral<int> {
//   static const bool value = true;
// };

// template <>
// struct is_integral<unsigned int> {
//   static const bool value = true;
// };

// template <>
// struct is_integral<long> {
//   static const bool value = true;
// };

// template <>
// struct is_integral<unsigned long> {
//   static const bool value = true;
// };

// template <>
// struct is_integral<long long> {
//   static const bool value = true;
// };

// template <>
// struct is_integral<unsigned long long> {
//   static const bool value = true;
// };

}
#endif