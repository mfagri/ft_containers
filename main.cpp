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
    std::vector<int> v;

    // g_start2 = g_end2 = timer();
    ft::map<int,int>mp;
    mp.insert(ft::make_pair(5, 5));
    mp.insert(ft::make_pair(3, 3));
    mp.insert(ft::make_pair(7, 7));
    typename ft::map<int, int>::reverse_iterator rit = mp.rbegin();
    typename ft::map<int, int>::reverse_iterator rit2 = mp.rend();
    v.push_back(rit->first);
     rit++;
    // rit2--;
    // v.push_back(rit->first);
    // v.push_back(rit2->first);
    // rit++;
    // v.push_back(*rit == *rit2);
    // rit2--;
    // v.push_back(rit->first);
    // v.push_back(rit2->first);
    // v.push_back(*rit2 > *rit);
    // v.push_back(*rit2 < *rit);
    // v.push_back((--rit)->first);
    // v.push_back((++rit2)->first);
    // v.push_back((rit--)->first);
    // v.push_back((rit2++)->first);
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


    ft_test();

   
    // g_end2 = timer();
  // ft::map<char,int> mymap;

  // mymap['x'] = 100;
  // mymap['y'] = 200;
  // mymap['z'] = 300;

  // // show content:
  // ft::map<char,int>::reverse_iterator rit;
  // for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
  //   std::cout << rit->first << " => " << rit->second << '\n';
    system("leaks containers");
  return 0;
}