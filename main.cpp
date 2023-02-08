/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:51:30 by mfagri            #+#    #+#             */
/*   Updated: 2023/02/08 22:11:48 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <deque>
#include "map.hpp"
#include "stack.hpp"
#include "vector.hpp"
#include "red_black_tree.hpp"
#include <map>

void ft_insert()
{
     ft::map<char,int> mymap;

  // first insert function version (single parameter):
//   mymap.insert ( ft::pair<char,int>('a',100) );
//   mymap.insert ( ft::pair<char,int>('z',200) );
 
//   ft::pair<ft::map<char,int>::iterator,bool> ret;
//   ret = mymap.insert ( ft::pair<char,int>('z',500) );
//   if (ret.second==false) {
//     std::cout << "element 'z' already existed";
//     std::cout << " with a value of " << ret.first->second << '\n';
//   }

//   // second insert function version (with hint position):
//   ft::map<char,int>::iterator it = mymap.begin();
//   mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
//   mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting

//   // third insert function version (range insertion):
//   ft::map<char,int> anothermap;
//   anothermap.insert(mymap.begin(),mymap.find('c'));

//   // showing contents:
//   std::cout << "mymap contains:\n";
//   for (it=mymap.begin(); it!=mymap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';

//   std::cout << "anothermap contains:\n";
//   for (it=anothermap.begin(); it!=anothermap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';
}
int main()
{
    ft_insert();
    system("leaks containers");
}