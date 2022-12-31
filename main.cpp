/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:51:30 by mfagri            #+#    #+#             */
/*   Updated: 2022/12/31 21:43:01 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <iostream>
#include <vector>
#include <exception>

int main()
{
     ft::vector<int> myvector;

//   set some content in the vector:
  for (int i=0; i<10; i++) myvector.push_back(i);
size_t j = 0;
  // while(j < myvector.size())
  // {
  //   std::cout<<myvector[j]<<std::endl;
  //   j++;
  // }
  myvector.resize(12, 9);
  j = 0;
  while(j < myvector.size())
  {
    std::cout<<myvector[j]<<std::endl;
    j++;
  }
  std::cout << "size: " << myvector.size() << "\n";
  std::cout << "capacity: " << myvector.capacity() << "\n";
  std::cout << "max_size: " << myvector.max_size() << "\n";
    
}