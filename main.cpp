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
void ft_test()
{
    ft::map<int,int>mp;
  std::vector<int> v;
    for (int i = 0, j = 0; i < 30 * 100; ++i, ++j)
        mp.insert(ft::make_pair(i, j));
    typename ft::map<int, int>::iterator it = mp.begin();
    v.push_back(it->first);
    mp.erase(it);
    v.push_back(mp.size());
    it = mp.begin();
    mp.erase(++it);
    v.push_back(mp.size());
    it = mp.begin();
    v.push_back(it->first);
    typename ft::map<int, int>::iterator it4 = mp.begin();
    // g_start2 = timer();
    for (; it4 != mp.end(); it4 = mp.begin())
        mp.erase(it4);
    // g_end2 = timer();
    v.push_back(mp.size());
    ft::map<int, int> mp2;
    for (int i = 0, j = 0; i < 10 ; ++i, ++j)
        mp2.insert(ft::make_pair(i, j));
    typename ft::map<int, int>::iterator ittest = mp2.begin();
    for (int i = 0; i < 2; ++i) ittest++;
    mp2.erase(ittest);
    ittest = mp2.begin();
    for (int i = 0; i < 5; ++i) ittest++;
    mp2.erase(ittest);
    typename ft::map<int, int>::iterator it3 = mp2.begin();
    for (; it3 != mp2.end(); ++it3) {
        v.push_back(it3->first);
        v.push_back(it3->second);
    }
    puts("ff");
    return ;
}
// int main()
// {
//    system("leaks containers");
//     return 0;
// }

int main ()
{ 
  


  // std::vector<int> v;

  // v.push_back(10);

  // std::vector<int>::iterator it = v.begin();
  // cout << *it << endl;

  // it.base() 


    // ft_test();

   
    // g_end2 = timer();
  // ft::map<char,int> mymap;

  // mymap['x'] = 100;
  // mymap['y'] = 200;
  // mymap['z'] = 300;

  // // show content:
  // ft::map<char,int>::reverse_iterator rit;
  // for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
  //   std::cout << rit->first << " => " << rit->second << '\n';
  // system("leaks containers");
  return 0;
}