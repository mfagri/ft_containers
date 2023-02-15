#include <iostream>
#include <string>
#include <deque>
#include "map.hpp"
#include "stack.hpp"
#include "vector.hpp"
#include "red_black_tree.hpp"
#include <map>

template <class T, class V, class C>
void fillMap(ft::map<T, V, C> &mp) {
	mp.insert(ft::make_pair(16, 3));
	mp.insert(ft::make_pair(8, 3));
	mp.insert(ft::make_pair(23, 3));
	mp.insert(ft::make_pair(7, 3));
	mp.insert(ft::make_pair(19, 3));
	mp.insert(ft::make_pair(29, 3));
	mp.insert(ft::make_pair(41, 3));
	mp.insert(ft::make_pair(4, 3));
	mp.insert(ft::make_pair(11, 3));
}
void std_test()
{
     std::map<int, int> mp;
    std::vector<int> v;
    std::map<int, int> mp2;
    mp.insert(std::make_pair(10, 10));
    mp2.insert(std::make_pair(10, 10));
    if (mp.upper_bound(11) == mp.end())
        v.push_back(1);
    if (mp2.upper_bound(1) == mp2.end())
        v.push_back(1);
    mp.insert(std::make_pair(20, 20));
    mp.insert(std::make_pair(30, 30));
    mp.insert(std::make_pair(40, 40));
    mp.insert(std::make_pair(50, 50));
    mp.insert(std::make_pair(60, 60));
    mp2.insert(std::make_pair(20, 20));
    mp2.insert(std::make_pair(30, 30));
    mp2.insert(std::make_pair(40, 40));
    mp2.insert(std::make_pair(50, 50));
    mp2.insert(std::make_pair(60, 60));
    std::map<int, int>::iterator it;
    for (int i = 1; i < 60; i += 10) {
        it = mp.upper_bound(i);
        v.push_back(it->first);
    }
    for (int i = 11; i < 70; i += 10) {
        it = mp2.upper_bound(i);
        v.push_back(it->first);
    }
    std::map<int, int> mp3;
    for (int i = 0, j = 0; i < 50 * 100; ++i, ++j) {
        mp3.insert(std::make_pair(i, j));
    }
    std::map<int, int> mp4;
    mp.insert(std::make_pair(-10, 10));
    mp.insert(std::make_pair(-20, 20));
    v.push_back((--mp.upper_bound(0))->first);
    // g_start2 = timer();
    mp3.upper_bound(49 * 100);
    // g_end2 = timer();
    for (size_t i = 0; i < v.size(); i++)
    {
      std::cout<<v[i]<<std::endl;
    }
    
    //return v;
    return ;
}
void ft_test()
{
    std::vector<int> v;
    ft::map<int,int>mp;
    mp.insert(ft::make_pair(10, 10));
    mp.insert(ft::make_pair(20, 20));
    mp.insert(ft::make_pair(30, 30));
    mp.insert(ft::make_pair(40, 40));
    mp.insert(ft::make_pair(50, 50));
    mp.insert(ft::make_pair(60, 60));
    // g_start2 = timer();
    const ft::pair<ft::map<int, int>::const_iterator , ft::map<int, int>::const_iterator>& pair = mp.equal_range(10);
    const ft::pair<ft::map<int, int>::const_iterator , ft::map<int, int>::const_iterator>& pair2 = mp.equal_range(11);
    const ft::pair<ft::map<int, int>::const_iterator , ft::map<int, int>::const_iterator>& pair3 = mp.equal_range(1);
    // g_end2 = timer();
    v.push_back(pair.first->first);
    v.push_back(pair.first->second);
    v.push_back(pair.second->first);
    v.push_back(pair.second->second);
    v.push_back(pair2.first->first);
    v.push_back(pair2.first->second);
    v.push_back(pair2.second->first);
    v.push_back(pair2.second->second);
    v.push_back(pair3.first->first);
    v.push_back(pair3.first->second);
    v.push_back(pair3.second->first);
    v.push_back(pair3.second->second);
    for (size_t i = 0; i < v.size(); i++)
    {
      std::cout<<v[i]<<std::endl;
    }
    
    //return v;
    return ;
}
// int main()
// {
//    system("leaks containers");
//     return 0;
// }

int main ()
{ 
  


ft_test();
puts("///////////////////////////////////");
std_test();
  // ft::map<char,int> mymap;
  // ft::map<char,int>::iterator itlow,itup;

  // mymap['a']=20;
  // mymap['b']=40;
  // mymap['c']=60;
  // mymap['d']=80;
  // mymap['e']=100;

  // itlow=mymap.lower_bound ('b');  // itlow points to b
  // itup=mymap.upper_bound ('d');   // itup points to e (not d!)

  // mymap.erase(itlow,itup);        // erases [itlow,itup)

  // // print content:
  // for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
  //   std::cout << it->first << " => " << it->second << '\n';


    //system("leaks containers");
  return 0;
}