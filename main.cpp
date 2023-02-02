/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:51:30 by mfagri            #+#    #+#             */
/*   Updated: 2023/02/02 17:41:47 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <utility>
#include "map.hpp"
#include <iostream>

#include <iostream>
#include <map>
// map::value_comp
#include <iostream>
#include <map>
#include "vector.hpp"

#include <iostream>
#include <map>

int main ()
{
  ft::map<char,int> mymap;

  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;

  while (!mymap.empty())
  {
    std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
    mymap.erase(mymap.begin());
  }

  return 0;
}