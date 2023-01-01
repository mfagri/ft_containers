/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:51:30 by mfagri            #+#    #+#             */
/*   Updated: 2023/01/01 01:25:43 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <iostream>
#include <vector>
#include <exception>

int main()
{
    ft::vector<int> vec;
 
    // 5 elements are inserted
    // in the vector
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
 
    // std::cout << "Contents of vector before resizing:"
    //      << std::endl;
     
    // // displaying the contents of the
    // // vector before resizing
    // for (size_t i = 0; i < vec.size(); i++)
    //     std::cout << vec[i] << " ";
 
    std::cout << std::endl;
 
    // vector is resized
    //  vec.resize(4);
     vec.resize(8);
    vec.resize(12, 9);
 
    // std::cout << "Contents of vector after resizing:"
    //      << std::endl;
 
    // displaying the contents of
    // the vector after resizing
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
  std::cout << "size: " << vec.size() << "\n";
  std::cout << "capacity: " << vec.capacity() << "\n";
  std::cout << "max_size: " << vec.max_size() << "\n";

  std::vector<int> vecs;
 
    // 5 elements are inserted
    // in the vecstor
    vecs.push_back(1);
    vecs.push_back(2);
    vecs.push_back(3);
    vecs.push_back(4);
    vecs.push_back(5);
 
    // std::cout << "Contents of vecstor before resizing:"
    //      << std::endl;
     
    // // displaying the contents of the
    // // vecstor before resizing
    // for (size_t i = 0; i < vecs.size(); i++)
    //     std::cout << vecs[i] << " ";
 
    std::cout << std::endl;
 
    // vecstor is resized
    //  vecs.resize(4);
     vecs.resize(8);
     vecs.resize(12, 9);
 
    // std::cout << "Contents of vecstor after resizing:"
    //      << std::endl;
 
    // displaying the contents of
    // the vecstor after resizing
    for (size_t i = 0; i < vecs.size(); i++)
        std::cout << vecs[i] << " ";
  std::cout << "ssize: " << vecs.size() << "\n";
  std::cout << "scapacity: " << vecs.capacity() << "\n";
  std::cout << "smax_size: " << vecs.max_size() << "\n";
    
}