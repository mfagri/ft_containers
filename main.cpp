/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:51:30 by mfagri            #+#    #+#             */
/*   Updated: 2023/01/01 03:55:34 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <iostream>
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

int    main () {
    int a = 1;
    int& aref = a;
    int b = 7;
    std::cout << a << '\n';
    std::cout << aref << '\n';
    aref = b;
    std::cout << a << '\n';
    std::cout << aref << '\n';
    
}
