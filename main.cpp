/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:51:30 by mfagri            #+#    #+#             */
/*   Updated: 2023/01/26 20:01:18 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <utility>
#include "map.hpp"
#include <iostream>

#include <iostream>
#include <map>


  int main ()
{
  std::map<char,int> mymap;

  mymap['x'] = 100;
  // mymap['y'] = 200;
  // mymap['z'] = 300;

  // show content:
  std::map<char,int>::reverse_iterator rit;
  // std::cout<<mymap.rend()->first<<std::endl;
  for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
    std::cout << rit->first << " => " << rit->second << '\n';
  puts("######################################################");
   ft::map<char,int> mymapn;

  mymapn['x'] = 100;
  // mymapn['y'] = 200;
  // mymapn['z'] = 300;
  mymapn.m_tree.printTree();
  // show content:
  ft::map<char,int>::reverse_iterator ritn= mymapn.rbegin();
  puts("//////////////");
  for (;ritn!=(ft::map<char,int>::reverse_iterator)mymapn.begin(); ++ritn)
  {
    // puts("fff");
    std::cout << ritn->first << " => " << ritn->second << '\n';
  }
  puts("///////////////");
  // std::map<char,int> mymap;

  // mymap['b'] = 100;
  // mymap['a'] = 200;
  // mymap['c'] = 300;

  // show content:
  for (ft::map<char,int>::iterator itrr=mymapn.begin(); itrr !=mymapn.end(); ++itrr)
    std::cout << itrr->first << " => " << itrr->second << '\n';
  //   char c;
  //  for (c='a'; c<'h'; c++)
  // {
  //   std::cout << c;
  //   if (mymapn.count(c)>0)
  //     std::cout << " is an element of mymap.\n";
  //   else 
  //     std::cout << " is not an element of mymap.\n";
  // }
  return 0;
;
}
