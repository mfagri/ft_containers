/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:51:30 by mfagri            #+#    #+#             */
/*   Updated: 2023/01/17 22:03:06 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include "map.hpp"


int main()
{
	ft::map<char,int> mymap;

  // first insert function version (single parameter):
  	mymap.insert ( ft::pair<char,int>('a',100) );
	puts("ddddddd");
  	mymap.insert ( ft::pair<char,int>('z',200) );
	return 0;
}