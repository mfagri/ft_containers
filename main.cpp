/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:51:30 by mfagri            #+#    #+#             */
/*   Updated: 2022/12/30 20:52:10 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "vector.hpp"
#include <iostream>
#include <vector>
#include <exception>

int main()
{
    std::cout<<std::string()<<std::endl;
    std::vector<int> k;
    k.push_back(4);
    try{
        
    std::cout<<k[10]<<std::endl;
    }
    catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }
}