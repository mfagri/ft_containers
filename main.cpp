/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:51:30 by mfagri            #+#    #+#             */
/*   Updated: 2023/01/04 21:49:56 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <iostream>
#include <chrono>
#include <vector>
#include <exception>

using namespace std;

#include <vector>
#include <cassert>
#include <iostream>

// int main() {
//   // Create a vector with three elements
// vector<int> v;
//  v.push_back(1);
//  v.push_back(2);
//   v.push_back(3);
//   // Check that the vector has the expected size and elements
//   assert(v.size() == 3);
//   assert(v[0] == 1);
//   assert(v[1] == 2);
//   assert(v[2] == 3);

//   // Remove the last element of the vector
//   v.pop_back();

//   // Check that the vector has the expected size and elements
//   assert(v.size() == 2);
//   assert(v[0] == 1);
//   assert(v[1] == 2);

//   // Remove the last element of the vector again
//   v.pop_back();

//   // Check that the vector has the expected size and elements
//   assert(v.size() == 1);
//   assert(v[0] == 1);

//   // Remove the last element of the vector again
//   v.pop_back();

//   // Check that the vector is empty
//   assert(v.empty());

//   std::cout << "All tests passed" << std::endl;

//  return 0;

// }


// int main() {
//   // Create an empty vector
//   ft::vector<int> v;

//   // Check that the vector is empty
//   assert(v.empty());

//   // Add an element to the vector
//   v.push_back(1);

//   // Check that the vector has the expected size and elements
//   assert(v.size() == 1);
//   assert(v[0] == 1);

//   // Add another element to the vector
//   v.push_back(2);

//   // Check that the vector has the expected size and elements
//   assert(v.size() == 2);
//   assert(v[0] == 1);
//   assert(v[1] == 2);

//   // Add another element to the vector
//   v.push_back(3);

//   // Check that the vector has the expected size and elements
//   assert(v.size() == 3);
//   assert(v[0] == 1);
//   assert(v[1] == 2);
//   assert(v[2] == 3);

//   std::cout << "All tests passed" << std::endl;

//   return 0;
// }

void fun()
{
  system("leaks containers");
}
int main ()
{
  ft::vector<int> first(7,100);
  ft::vector<int> second;
  ft::vector<int> third;

  // first.assign (7,100);             // 7 ints with a value of 100

  ft::vector<int>::iterator it;
  it=first.begin()+1;

  second.assign (it,first.end()-1); // the 5 central values of first

  int myints[] = {1776,7,4};
  third.assign (myints,myints+3);   // assigning from array.

  std::cout << "Size of first: " << int (first.capacity()) << '\n';
  std::cout << "Size of second: " << int (second.capacity()) << '\n';
  std::cout << "Size of third: " << int (third.capacity()) << '\n';
  return 0;
}