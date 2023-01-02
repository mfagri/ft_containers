/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:51:30 by mfagri            #+#    #+#             */
/*   Updated: 2023/01/02 19:04:15 by mfagri           ###   ########.fr       */
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


int main ()
{
  std::vector<int> myvector (5);

  int* p = myvector.data();

  *p = 10;
  ++p;
  *p = 20;
  p[2] = 100;

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); ++i)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

  return 0;
}