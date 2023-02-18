#include <iostream>
#include <string>
#include <deque>
#include "map.hpp"
#include "stack.hpp"
#include "vector.hpp"
#include "red_black_tree.hpp"
#include <map>
#include <stack>

template <class T, class V, class C>
void fillMap(std::map<T, V, C> &mp) {
	mp.insert(std::make_pair(16, 3));
	mp.insert(std::make_pair(8, 3));
	mp.insert(std::make_pair(23, 3));
	mp.insert(std::make_pair(7, 3));
	mp.insert(std::make_pair(19, 3));
	mp.insert(std::make_pair(29, 3));
	mp.insert(std::make_pair(41, 3));
	mp.insert(std::make_pair(4, 3));
	mp.insert(std::make_pair(11, 3));
}

// // template <class T, class V, class C>
// // void fillMap(ft::map<T, V, C> &mp) {
// // 	mp.insert(_make_pair(16, 3));
// // 	mp.insert(_make_pair(8, 3));
// // 	mp.insert(_make_pair(23, 3));
// // 	mp.insert(_make_pair(7, 3));
// // 	mp.insert(_make_pair(19, 3));
// // 	mp.insert(_make_pair(29, 3));
// // 	mp.insert(_make_pair(41, 3));
// // 	mp.insert(_make_pair(4, 3));
// // 	mp.insert(_make_pair(11, 3));
// // }
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
// void std_test()
// {
//      std::map<int, int> mp;
//     std::vector<int> v;
//     std::map<int, int> mp2;
//     mp.insert(std::make_pair(10, 10));
//     mp2.insert(std::make_pair(10, 10));
//     if (mp.upper_bound(11) == mp.end())
//         v.push_back(1);
//     if (mp2.upper_bound(1) == mp2.end())
//         v.push_back(1);
//     mp.insert(std::make_pair(20, 20));
//     mp.insert(std::make_pair(30, 30));
//     mp.insert(std::make_pair(40, 40));
//     mp.insert(std::make_pair(50, 50));
//     mp.insert(std::make_pair(60, 60));
//     mp2.insert(std::make_pair(20, 20));
//     mp2.insert(std::make_pair(30, 30));
//     mp2.insert(std::make_pair(40, 40));
//     mp2.insert(std::make_pair(50, 50));
//     mp2.insert(std::make_pair(60, 60));
//     std::map<int, int>::iterator it;
//     for (int i = 1; i < 60; i += 10) {
//         it = mp.upper_bound(i);
//         v.push_back(it->first);
//     }
//     for (int i = 11; i < 70; i += 10) {
//         it = mp2.upper_bound(i);
//         v.push_back(it->first);
//     }
//     std::map<int, int> mp3;
//     for (int i = 0, j = 0; i < 50 * 100; ++i, ++j) {
//         mp3.insert(std::make_pair(i, j));
//     }
//     std::map<int, int> mp4;
//     mp.insert(std::make_pair(-10, 10));
//     mp.insert(std::make_pair(-20, 20));
//     v.push_back((--mp.upper_bound(0))->first);
//     // g_start2 = timer();
//     mp3.upper_bound(49 * 100);
//     // g_end2 = timer();
//     for (size_t i = 0; i < v.size(); i++)
//     {
//       std::cout<<v[i]<<std::endl;
//     }
    
//     //return v;
//     return ;
// }
void ft_test()
{

    ft::map<int,int>mp;
    std::vector<int> v;
    fillMap(mp);
    for (typename ft::map<int,int>::iterator it = mp.begin(); it != mp.end(); it++) { v.push_back(it->first); }
    for (typename ft::map<int,int>::iterator it = --mp.end(); it != mp.begin(); it--) { v.push_back(it->first); }
    ft::map<int, int, std::greater<int> > mp1;
    fillMap(mp1);
    v.push_back(mp1.begin()->first);
    mp1.erase(41);
    v.push_back(mp1.begin()->first);
    mp1.erase(29);
    v.push_back(mp1.begin()->first);
    ft::map<int, int, std::greater<int> > mp2;
    mp2.insert(ft::make_pair(3, 3));
    v.push_back(mp2.begin()->first);
    mp2.erase(3);
    if (mp2.begin() == mp2.end())
        v.push_back(1);
    ft::map<int, int, std::plus<int> > mp3;
    fillMap(mp3);
    // for (typename ft::map<int,int, std::plus<int> >::iterator it = mp3.begin(); it != mp3.end(); it++) { v.push_back(it->first); }
    // for (typename ft::map<int,int, std::plus<int> >::iterator it = --mp3.end(); it != mp3.begin(); it--) { v.push_back(it->first); }
    // ft::map<int, int, std::minus<int> > mp4;
    // fillMap(mp4);
    // for (typename ft::map<int,int, std::minus<int> >::iterator it = mp4.begin(); it != mp4.end(); it++) { v.push_back(it->first); }
    // for (typename ft::map<int,int, std::minus<int> >::iterator it = --mp4.end(); it != mp4.begin(); it--) { v.push_back(it->first); }
    // ft::map<int, int, std::greater_equal<int> > mp5;
    // fillMap(mp5);
    // for (typename ft::map<int,int, std::greater_equal<int> >::iterator it = mp5.begin(); it != mp5.end(); it++) { v.push_back(it->first); }
    // for (typename ft::map<int,int, std::greater_equal<int> >::iterator it = --mp5.end(); it != mp5.begin(); it--) { v.push_back(it->first); }
    // ft::map<int, int, std::multiplies<int> > mp6;
    // fillMap(mp6);
    // for (typename ft::map<int,int, std::multiplies<int> >::iterator it = mp6.begin(); it != mp6.end(); it++) { v.push_back(it->first); }
    // for (typename ft::map<int,int, std::multiplies<int> >::iterator it = --mp6.end(); it != mp6.begin(); it--) { v.push_back(it->first); }
    // ft::map<int, int, std::bit_xor<int> > mp7;
    // fillMap(mp7);
    // for (typename ft::map<int,int, std::bit_xor<int> >::iterator it = mp7.begin(); it != mp7.end(); it++) { v.push_back(it->first); }
    // for (typename ft::map<int,int, std::bit_xor<int> >::iterator it = --mp7.end(); it != mp7.begin(); it--) { v.push_back(it->first); }
    // std::map<int, int, std::logical_and<int> > mp8;
    // fillMap(mp8);
    // for (typename std::map<int,int, std::logical_and<int> >::iterator it = mp8.begin(); it != mp8.end(); it++) { v.push_back(it->first); }
    // for (typename std::map<int,int, std::logical_and<int> >::iterator it = --mp8.end(); it != mp8.begin(); it--) { v.push_back(it->first); }
    // // g_start1 = timer();
    // // g_end1 = timer();
    // v.push_back(mp1.size());
    // g_end2 = timer();/
    // return v;
    return ;
}

int main ()
{
  ft_test();
  system("leaks containers");
  return 0;
}