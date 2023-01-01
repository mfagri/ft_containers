/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:51:30 by mfagri            #+#    #+#             */
/*   Updated: 2023/01/01 05:01:23 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <iostream>
#include <chrono>
#include <vector>
#include <exception>

using namespace std;

// void print_vector(ft::vector<int> vec){
//   for(size_t x: vec.capacity())
//     cout << x << " ";
// }
// int main()
// {
//     ft::vector<int> vec;
 
//     // 5 elements are inserted
//     // in the vector
//     vec.push_back(1);
//     vec.push_back(2);
//     vec.push_back(3);
//     vec.push_back(4);
//     vec.push_back(5);
 
//     cout << "Contents of vector before resizing:"
//          << endl;
     
//     // displaying the contents of the
//     // vector before resizing
//     for (size_t i = 0; i < vec.size(); i++)
//         cout << vec[i] << " ";
 
//     cout << endl;
 
//     // vector is resized
//     vec.resize(12, 9);
 
//     cout << "Contents of vector after resizing:"
//          << endl;
     
//     // displaying the contents of the
//     // vector after resizing
//     for (size_t i = 0; i < vec.size(); i++)
//         cout << vec[i] << " ";

//     std::cout<<vec.capacity()<<std::endl;
//     return 0;
// }

int main ()
{
  ft::vector<int> myvector;

  // set some initial content:
  for (ft::vector<int>::size_type i=1;i<10;i++) myvector.push_back(i);

  myvector.resize(5);
  myvector.resize(8,100);
  myvector.resize(12);

  cout << "myvector contains:";
  for (ft::vector<int>::size_type i=0;i<myvector.size();i++)
    cout << ' ' << myvector[i];
  cout << '\n';

  return 0;
}
