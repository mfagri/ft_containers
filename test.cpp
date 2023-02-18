

#include <iostream>
#include <string>
#include "red_black_tree.hpp"
#include "map.hpp"

int main()
{
    ft::map<int, std::string>mp;
    for (int i = 0;i < 10;i++)
        mp[i] = std::to_string(i+ 48);

    ft::map<int, std::string>mp2;
    mp2 = mp;
    
    mp.erase(3);
    mp.erase(5);
    mp.erase(7);
    mp.erase(6);

    ft::map<int, std::string>::iterator it = mp.begin();
    for (it; it != mp.end();it++)
        std::cout << it->first << "\n";
   
   
    ft::map<int, std::string>::iterator ite = mp2.begin();
    for (it; ite != mp2.end();it++)
        std::cout << ite->first << "\n";
   
    


}