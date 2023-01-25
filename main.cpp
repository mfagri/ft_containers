/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:51:30 by mfagri            #+#    #+#             */
/*   Updated: 2023/01/25 21:31:35 by mfagri           ###   ########.fr       */
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

  // first insert function version (single parameter):
  mymap.insert ( std::pair<char,int>('a',100) );
  mymap.insert ( std::pair<char,int>('z',200) );

  std::pair<std::map<char,int>::iterator,bool> ret;
  ret = mymap.insert ( std::pair<char,int>('z',500) );
  if (ret.second==false) {
    std::cout << "element 'z' already existed";
    std::cout << " with a value of " << ret.first->second << '\n';
  }

  // second insert function version (with hint position):
  std::map<char,int>::iterator it = mymap.begin();
  mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
  mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting

  // third insert function version (range insertion):
  std::map<char,int> anothermap;
  anothermap.insert(mymap.begin(),mymap.find('c'));

  // showing contents:
  std::cout << "mymap contains:\n";
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  std::cout << "anothermap contains:\n";
  for (it=anothermap.begin(); it!=anothermap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
    puts("////////////////////////////////////////////////////");
      ft::map<char,int> myma;

  // first insert function version (single parameter):
  myma.insert ( ft::pair<char,int>('a',100) );
  myma.insert ( ft::pair<char,int>('z',200) );

  ft::pair<ft::map<char,int>::iterator,bool> retn;
  retn = myma.insert ( ft::pair<char,int>('z',500) );
  if (retn.second==false) {
    std::cout << "element 'z' already existed";
    std::cout << " with a value of " << retn.first->second << '\n';
  }

  // second insert function version (with hint position):
  ft::map<char,int>::iterator itn = myma.begin();
  myma.insert (itn, ft::pair<char,int>('b',300));  // max efficiency inserting
  myma.insert (itn, ft::pair<char,int>('c',400));  // no max efficiency inserting


std::cout<<myma.find('d')->first<<std::endl;
  // third insert function version (range insertion):
   ft::map<char,int> anotherma;
  anotherma.insert(myma.begin(),myma.find('c'));

  // // showing contents:
  // std::cout << "mymap contains:\n";
  // for (itn=myma.begin(); itn!=myma.end(); ++itn)
  //   std::cout << itn->first << " => " << itn->second << '\n';


  // ft::map<char,int>::iterator itnr = anotherma.begin();
  // std::cout << "anothermap contains:\n";
  // for (itnr=anotherma.begin(); itnr!=anotherma.end(); ++itn)
  //   std::cout << itnr->first << " => " << itnr->second << '\n';

  return 0;
}