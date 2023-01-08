/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:51:30 by mfagri            #+#    #+#             */
/*   Updated: 2023/01/08 01:36:53 by mfagri           ###   ########.fr       */
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
  ft::vector<int> myvector (3,100);
  ft::vector<int>::iterator it;

  it = myvector.begin();
  it = myvector.insert ( it , 200 );

  myvector.insert (it,2,300);

  // "it" no longer valid, get a new one:
  it = myvector.begin();

  ft::vector<int> anothervector (2,400);
  myvector.insert (it+2,anothervector.begin(),anothervector.end());

  int myarray [] = { 501,502,503 };
  std::cout<<myarray<<std::endl;
  myvector.insert (myvector.begin()+1, myarray, myarray+3);

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';
//   {
//   std::vector<int> v(0,0);

// 	v.push_back(1);
// 	v.push_back(2);
// 	v.push_back(3);
	
//   v.insert (v.begin() + 1, 5,10);
// 	 std::vector<int>::iterator it;

//   for (it=v.begin(); it<v.end(); it++)
//     	std::cout << ' ' << *it;
// 	cout << "\n";
// 	cout << v.size() << endl;
// 	cout << v.capacity() << endl;
// // 	int myarray [] = { 501,502,503 };
// 	/////////////////////////////////////
// 	// ft::vector<int> test;
// 	// test.reserve(2);
// 	// std::cout << test.capacity() << std::endl;
// 	// test.push_back(3);
// 	// test.push_back(2);
// 	// test.insert(test.begin(), 1);
// 	// test.insert(test.begin(), 1);
// 	// test.insert(test.begin(), 1);
// 	// std::cout << "myvector contains:";
// 	//  ft::vector<int>::iterator it;
//   	// for (it=test.begin(); it<test.end(); it++)
//     // 	std::cout << ' ' << *it;
	std::cout <<"\n"<< myvector.capacity() << std::endl;
	std::cout << myvector.size() << std::endl;
	std::cout<<"";

	
//   }
  return 0;
}