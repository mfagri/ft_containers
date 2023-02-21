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
ft::vector<int> v1;
ft::vector<int> v2;

for (size_t i = 0; i < 999*10; i++)
{
    v1.push_back(i);
}

v2.insert(v2.begin(),v1.begin(),v1.end());

std::cout<<v2.size()<<std::endl;
std::cout<<v2.capacity()<<std::endl;
puts("////////////////////////////////");
ft::vector<int> v3;
ft::vector<int> v5;

for (size_t i = 0; i < 999*10; i++)
{
    v3.push_back(i);
}

v5.insert(v5.begin(),v3.begin(),v3.end());


std::cout<<v5.size()<<std::endl;
std::cout<<v5.capacity()<<std::endl;
// puts("here");

}