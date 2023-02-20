#include <iostream>
#include <string>
#include <deque>
#include "map.hpp"
#include "stack.hpp"
#include "vector.hpp"
#include "red_black_tree.hpp"
#include "set.hpp"
#include <map>
#include <set>
#include <stack>

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


#define _ratio 10000
int main ()
{
    ft::set<int>st;
    std::vector<int> v;
    for (int i = -75 * _ratio; i < 75 * _ratio; ++i) {
        st.insert(i);
    }

    typename ft::set<int>::iterator it = st.find(34 * _ratio);
    v.push_back(*it);

    it = st.find(-34 * _ratio);
    v.push_back(*it);

    it = st.find(-987654321);
    if (it == st.end())
        v.push_back(1);
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout<<v[i]<<std::endl;
    }
    
}