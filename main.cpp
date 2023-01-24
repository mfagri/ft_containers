/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:51:30 by mfagri            #+#    #+#             */
/*   Updated: 2023/01/24 21:00:56 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <utility>
#include "map.hpp"
#include <iostream>

int main ()
{
  ft::map<char,int> mymap;

  // first insert function version (single parameter):
  mymap.insert ( ft::pair<char,int>('a',100) );
  mymap.insert ( ft::pair<char,int>('z',200) );
  
  mymap.insert ( ft::pair<char,int>('t',500) );
  



// mymap.insert ( ft::pair<char,int>('a',100) );
  // mymap.insert ( ft::pair<char,int>('z',200) );

  ft::pair<ft::map<char,int>::iterator,bool> ret;
  ret = mymap.insert (ft::pair<char,int>('z',500) );
  if (ret.second==false) {
    std::cout << "element 'z' already existed";
    std::cout << " with a value of " << ret.first->second << '\n';
  }




  
  //   mymap.insert ( ft::pair<char,int>('a',100) );
  // mymap.insert ( ft::pair<char,int>('z',200) );
  
  // mymap.insert ( ft::pair<char,int>('t',500) );
   ft::map<char,int>::iterator it = mymap.begin();
  // std::cout << it->second  << std::endl;
  // it++;
  // std::cout << it->second  << std::endl;
  // mymap['b'] = 100;
 mymap.m_tree.printTree();
  std::cout << "mymap contains:\n";
  for (it=mymap.begin(); it!=mymap.end();++it)
    std::cout << it->first << " => " << it->second << '\n';
   std::cout<<"preevvv\n";
   ft::map<char,int> second (mymap.begin(),mymap.end());
   ft::map<char,int>::iterator itn= second.begin();
   for (itn=second.begin(); itn!=second.end();itn++)
    std::cout << itn->first << " => " << itn->second << '\n';
    // std::cout << itn->first << " => " << itn->second << '\n';

//     std::cout << it->second  << std::endl;
// --it;
//  std::cout << it->second  << std::endl;
//  --it;
//   std::cout << it->second  << std::endl;
//  --it;
//   std::cout << it->second  << std::endl;
//     --it;
//   std::cout << it->second  << std::endl;
//     --it;
//       std::cout << it->second  << std::endl;
//    //    --it;
//   std::cout<<"///////////////////////////////////////////////////\n";
//   std::map<char,int> mh;

//   // first insert function version (single parameter):
//   mh.insert ( std::pair<char,int>('a',100) );
//   mh.insert ( std::pair<char,int>('z',200) );
  
//   mh.insert ( std::pair<char,int>('t',500) );
//    mh.insert ( std::pair<char,int>('a',100) );
//   mh.insert ( std::pair<char,int>('z',200) );
  
//   mh.insert ( std::pair<char,int>('t',500) );
  
//    std::map<char,int>::iterator itr = mh.begin();

// // // mh.m_tree.printTree();
//   std::cout << "mh contains:\n";
//   for (itr=mh.begin(); itr!=mh.end(); ++itr)
//     std::cout << itr->first << " => " << itr->second << '\n';
//     // ++itr;
// std::cout<<"preevvv\n";
//    std::cout << itr->second  << std::endl;
//  --itr;
//    std::cout << itr->second  << std::endl;
//  --itr;
//   std::cout << itr->second  << std::endl;
//  --itr;
//   std::cout << itr->second  << std::endl;
//  --itr;
//  std::cout << itr->second  << std::endl;
//   --itr;
//   // --itr;
  return 0;
}