/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:51:30 by mfagri            #+#    #+#             */
/*   Updated: 2023/01/17 22:54:05 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include "map.hpp"
#include <iostream>

int main()
{
	ft::map<char,int> mymap;

  // first insert function version (single parameter):
  	mymap.insert ( ft::pair<char,int>('A',100) );
	// mymap.insert ( ft::pair<char,int>('B',100) );
	mymap.m_tree.printTree();
	return 0;
}