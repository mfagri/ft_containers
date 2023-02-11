#include <iostream>
#include <string>
#include <deque>
#include "map.hpp"
#include "stack.hpp"
#include "vector.hpp"
#include "red_black_tree.hpp"
#include <map>


class B {
public:
    char *l;
    int i;
    B():l(nullptr), i(1) {};
    B(const int &ex) {
        this->i = ex;
        this->l = new char('a');
    };
    virtual ~B() {
        delete this->l;
        this->l = nullptr;
    };
};

class A : public B {
public:
    A():B(){};
    A(const B* ex){
        this->l = new char(*(ex->l));
        this->i = ex->i;
        if (ex->i == -1) throw "n";
    }
    ~A() {
        delete this->l;
        this->l = nullptr;
    };
};

// template <typename T>
// std::vector<int> insert_test_3(std::vector<T> vector) {
//     // std::vector<int> v;
//     // std::vector<int> tmp;
//     // tmp.assign(2600 * _ratio, 1);
//     // vector.assign(4200 * _ratio, 1);
//     // g_start1 = timer();
//     // vector.insert(vector.end() - 1000 * _ratio, tmp.begin(), tmp.end());
//     // g_end1 = timer();
//     // v.push_back(vector[3]);
//     // v.push_back(vector.size());
//     // v.push_back(vector.capacity());

//     // std::unique_ptr<B> k2(new B(3));
//     // std::unique_ptr<B> k3(new B(4));
//     // std::unique_ptr<B> k4(new B(-1));
//     // std::vector<A> vv;
//     // std::vector<B*> v1;

//     // v1.push_back(&(*k2));
//     // v1.push_back(&(*k3));
//     // v1.push_back(&(*k4));
//     // try { vv.insert(vv.begin(), v1.begin(), v1.end()); }
//     // catch (...) {
//     //     v.push_back(vv.size());
//     //     v.push_back(vv.capacity());
//     // }

//     return v;
// }
void ft_tester()
{
    std::vector<int> v;
    ft::vector<int> vector;
    ft::vector<int> tmp;
    tmp.assign(2600 * 10000, 1);
    vector.assign(4200 * 10000, 1);
    // g_start1 = timer();
    vector.insert(vector.end() - 1000 * 10000, tmp.begin(), tmp.end());
    // g_end1 = timer();
    // v.push_back(vector[3]);
    // v.push_back(vector.size());
    // v.push_back(vector.capacity());

    std::unique_ptr<B> k2(new B(3));
    std::unique_ptr<B> k3(new B(4));
    std::unique_ptr<B> k4(new B(-1));
    ft::vector<A> vv;
    ft::vector<B*> v1;

    v1.push_back(&(*k2));
    v1.push_back(&(*k3));
    v1.push_back(&(*k4));
    // return;
    puts("ff");
    try { vv.insert(vv.begin(), v1.begin(), v1.end()); }
    catch (...) {
        // v.push_back(vv.size());
        // v.push_back(vv.capacity());
        //std::cout<<"bitchs = "<<vv.capacity()<<std::endl;
        // for (size_t i = 0; i < v.size(); i++)
        // {
        //     std::cout<<v[i]<<std::endl;
        // }
        
    }
    // for (size_t i = 0; i < v.size(); i++)
    // {
    //     std::cout<<v[i]<<std::endl;
    // }
}
int main ()
{
   ft_tester();
   system("leaks containers");
}




  // first insert function version (single parameter):
//   mymap.insert ( ft::pair<char,int>('a',100) );
//   mymap.insert ( ft::pair<char,int>('z',200) );
 
//   ft::pair<ft::map<char,int>::iterator,bool> ret;
//   ret = mymap.insert ( ft::pair<char,int>('z',500) );
//   if (ret.second==false) {
//     std::cout << "element 'z' already existed";
//     std::cout << " with a value of " << ret.first->second << '\n';
//   }

//   // second insert function version (with hint position):
//   ft::map<char,int>::iterator it = mymap.begin();
//   mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
//   mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting

//   // third insert function version (range insertion):
//   ft::map<char,int> anothermap;
//   anothermap.insert(mymap.begin(),mymap.find('c'));

//   // showing contents:
//   std::cout << "mymap contains:\n";
//   for (it=mymap.begin(); it!=mymap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';

//   std::cout << "anothermap contains:\n";
//   for (it=anothermap.begin(); it!=anothermap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';
// }
// int main()
// {
//   ft_insert();
//   system("leaks containers");
//     return 0;
// }