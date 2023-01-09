/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:51:30 by mfagri            #+#    #+#             */
/*   Updated: 2023/01/09 21:37:12 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <iostream>
// #include <chrono>
#include <vector>
#include <exception>
#include <string>

using namespace std;

#include <vector>
#include <cassert>
#include <iostream>


int main ()
{
  std::vector<int> first;
  std::vector<int> second;
  std::vector<int> third;

  first.assign (7,100);             // 7 ints with a value of 100

  std::vector<int>::iterator it;
  it=first.begin()+1;

  second.assign (it,first.end()-1); // the 5 central values of first

  int myints[] = {1776,7,4};
  third.assign (myints,myints+3);   // assigning from array.

  std::cout << "Size of first: " << int (first.capacity()) << '\n';
  std::cout << "Size of second: " << int (second.capacity()) << '\n';
  std::cout << "Size of third: " << int (third.capacity()) << '\n';
  return 0;
}