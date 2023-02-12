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
    ft::map<int, int> mpp;
     ft::map<int, int> mp;
    fillMap(mpp);
    for (typename ft::map<int, int>::iterator it = mpp.begin(); it != mpp.end(); it++) 
    { v.push_back(it->first); }
    for (typename ft::map<int, int>::iterator it = --mpp.end(); it != mpp.begin(); it--) 
    { v.push_back(it->first); }
    ft::map<int, int> mp0;
    ft::map<int, int>::iterator ii = mp0.insert(ft::make_pair(3, 3)).first;
    ii++;
    std::cout<<(--ii)->first<<std::endl;
    v.push_back((--ii)->first);
    for (int i = 0, j = 10; i < 5; ++i, ++j)
        mp.insert(ft::make_pair(i, j));
    typename ft::map<int, int>::iterator it = mp.begin();
    typename ft::map<int, int>::iterator it2 = mp.end();
    // g_start2 = timer();
    v.push_back(it->first);
    it++;
    std::cout<<it->first<<std::endl;
    it++;
    it++;
    it++;
    v.push_back(it->first);
    it++;
    it--;
    v.push_back(it->first);
    it2--;
    v.push_back(it2->first);
    v.push_back(it2 == it);
    v.push_back((--it2)->first);
    v.push_back((it2--)->first);
    v.push_back((it2++)->first);
    v.push_back((++it2)->first);
    // for (size_t i = 0; i < v.size(); i++)
    // {
    //     std::cout<<v[i]<<std::endl;
    // }
    
    // g_end2 = timer();
    return ;
}
// int main()
// {
//     ft_test();
//    system("leaks containers");
//     return 0;
// }

int main ()
{
  ft::map<char,int> mymap;

  mymap['x'] = 100;
  mymap['y'] = 200;
  mymap['z'] = 300;

  // show content:
  ft::map<char,int>::reverse_iterator rit;
  for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
    std::cout << rit->first << " => " << rit->second << '\n';

  return 0;
}