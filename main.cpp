/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:51:30 by mfagri            #+#    #+#             */
/*   Updated: 2023/01/04 06:42:09 by mfagri           ###   ########.fr       */
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

#include <iostream>
#include <vector>

int main() {
  typedef ft::iterator_traits<int*> traits;
  if (typeid(traits::iterator_category)==typeid(std::random_access_iterator_tag))
    std::cout << "int* is a random-access iterator";
  return 0;
}