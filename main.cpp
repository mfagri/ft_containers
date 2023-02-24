#include <iostream>
#include <string>
#include <deque>
#include "map.hpp"
#include "stack.hpp"
#include "vector.hpp"
#include "red_black_tree.hpp"
#include "set.hpp"
#include "unistd.h"
#include <map>
#include <set>
#include <stack>

void ft_vector()
{
    std::vector<int>test1;
    std::vector<int>test2;


    {
        {
            std::cout<<"\033[33mft vector\033[0m"<<std::endl;
            std::cout<<"\033[32m(constructor)\033[0m"<<std::endl;

            ft::vector<int> first;
            ft::vector<int> second (4,100);
            ft::vector<int> third (second.begin(),second.end());
            ft::vector<int> fourth (third);

            int myints[] = {16,2,77,29};
            ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

            // std::cout << "The contents of fifth are:";
            for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
            {
                test1.push_back(*it);
                // std::cout << ' ' << *it;
            }
            // std::cout << '\n';
        }
        
        {
            std::vector<int> first;
            std::vector<int> second (4,100);
            std::vector<int> third (second.begin(),second.end());
            std::vector<int> fourth (third);

            int myints[] = {16,2,77,29};
            std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

            // std::cout << "The contents of fifth are:";
            for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
            {
                test2.push_back(*it);
                // std::cout << ' ' << *it;
            }
            // std::cout << '\n';
        }

        if(test1 == test2)
            std::cout<<"\033[32mok\033[0m"<<std::endl;
        else
            std::cout<<"\033[31mko\033[0m"<<std::endl;
        test1.clear();
        test2.clear();


        ////////////////////////////////
        sleep(2);
        std::cout << "\x1B[2J\x1B[H";
        {
        std::cout<<"\033[32moperator=\033[0m"<<std::endl;
            ft::vector<int> foo (3,0);
            ft::vector<int> bar (5,0);

            bar = foo;
            foo = ft::vector<int>();

            // std::cout << "Size of foo: " << int(foo.size()) << '\n';
            // std::cout << "Size of bar: " << int(bar.size()) << '\n';
            test1.push_back(foo.size());
            test1.push_back(bar.size());


        }
        {
            std::vector<int> foo (3,0);
            std::vector<int> bar (5,0);

            bar = foo;
            foo = std::vector<int>();

            // std::cout << "Size of foo: " << int(foo.size()) << '\n';
            // std::cout << "Size of bar: " << int(bar.size()) << '\n';
            test2.push_back(foo.size());
            test2.push_back(bar.size());
        }
        if(test1 == test2)
            std::cout<<"\033[32mok\033[0m"<<std::endl;
        else
            std::cout<<"\033[31mko\033[0m"<<std::endl;
        test1.clear();
        test2.clear();



         //////////////////////////////
        sleep(2);
        
        std::cout << "\x1B[2J\x1B[H";
        {
            std::cout<<"\033[32miterator\033[0m"<<std::endl;
            ft::vector<int> myvector;
            for (int i=1; i<=5; i++) myvector.push_back(i);
            // std::cout << "myvector contains:";
            for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
                 test1.push_back(*it);
            // std::cout << '\n';
        }
        {
            // std::cout<<"\033[32miterator\033[0m"<<std::endl;
            std::vector<int> myvector;
            for (int i=1; i<=5; i++) myvector.push_back(i);
            // std::cout << "myvector contains:";
            for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
                 test2.push_back(*it);
            // std::cout << '\n';
        }

        if(test1 == test2)
            std::cout<<"\033[32mok\033[0m"<<std::endl;
        else
            std::cout<<"\033[31mko\033[0m"<<std::endl;
        test1.clear();
        test2.clear();


        /////////////////////////
        sleep(2);
        std::cout << "\x1B[2J\x1B[H";
        {
            std::cout<<"\033[32mreverse iterator\033[0m"<<std::endl;
            ft::vector<int> myvector1 (5);  // 5 default-constructed ints
            int j=0;
            ft::vector<int>::reverse_iterator rit = myvector1.rbegin();
            for (; rit!= myvector1.rend(); ++rit)
                *rit = ++j;

           // std::cout << "myvector1 contains:";
            for (ft::vector<int>::iterator it = myvector1.begin(); it != myvector1.end(); ++it)
                test2.push_back(*it);
            // std::cout << '\n';
        }
        {
            //std::cout<<"\033[32mreverse iterator\033[0m"<<std::endl;
            std::vector<int> myvector1 (5);  // 5 default-constructed ints
            int i=0;
            std::vector<int>::reverse_iterator rit = myvector1.rbegin();
            for (; rit!= myvector1.rend(); ++rit)
                *rit = ++i;

           // std::cout << "myvector1 contains:";
            for (std::vector<int>::iterator it = myvector1.begin(); it != myvector1.end(); ++it)
                test1.push_back(*it);
            // std::cout << '\n';
        }

        if(test1 == test2)
            std::cout<<"\033[32mok\033[0m"<<std::endl;
        else
            std::cout<<"\033[31mko\033[0m"<<std::endl;
        test1.clear();
        test2.clear();
        //////////////////////////
        sleep(2);
        std::cout << "\x1B[2J\x1B[H";
        {
            std::cout<<"\033[32msize\033[0m"<<std::endl;
            ft::vector<int> sizev;
            test2.push_back(sizev.size());


            for (int i=0; i<10; i++) sizev.push_back(i);
            test2.push_back(sizev.size());



            sizev.insert (sizev.end(),10,100);
            test2.push_back(sizev.size());


            sizev.pop_back();
            test2.push_back(sizev.size());

        }
        {
           // std::cout<<"\033[32msize\033[0m"<<std::endl;
            std::vector<int> sizev;
            test1.push_back(sizev.size());

            for (int i=0; i<10; i++) sizev.push_back(i);
            test1.push_back(sizev.size());


            sizev.insert (sizev.end(),10,100);
           test1.push_back(sizev.size());

            sizev.pop_back();
            test1.push_back(sizev.size());
        }
        if(test1 == test2)
            std::cout<<"\033[32mok\033[0m"<<std::endl;
        else
            std::cout<<"\033[31mko\033[0m"<<std::endl;
        test1.clear();
        test2.clear();
        ////////////////////////////////////////////////////////////
         sleep(2);
        std::cout << "\x1B[2J\x1B[H";
        {
            std::cout<<"\033[32mmax_size\033[0m"<<std::endl;

            ft::vector<int> mymaxsize;

            // set some content in the vector:
            for (int i=0; i<100; i++) mymaxsize.push_back(i);

            test1.push_back( mymaxsize.size());
            test1.push_back( mymaxsize.capacity());
            test1.push_back(mymaxsize.max_size());
        }
        {
            //std::cout<<"\033[32mmax_size\033[0m"<<std::endl;

            std::vector<int> mymaxsize;

            // set some content in the vector:
            for (int i=0; i<100; i++) mymaxsize.push_back(i);

            test2.push_back( mymaxsize.size());
            test2.push_back( mymaxsize.capacity());
            test2.push_back(mymaxsize.max_size());
        }
        if(test1 == test2)
            std::cout<<"\033[32mok\033[0m"<<std::endl;
        else
            std::cout<<"\033[31mko\033[0m"<<std::endl;
        test1.clear();
        test2.clear();
        ///////////////////////////////////////////////////////
        sleep(2);
        std::cout << "\x1B[2J\x1B[H";
        {
            std::cout<<"\033[32mresize\033[0m"<<std::endl;
            ft::vector<int> myvresize;

            // set some initial content:
            for (int i=1;i<10;i++) myvresize.push_back(i);

            myvresize.resize(5);
            myvresize.resize(8,100);
            myvresize.resize(12);

            //std::cout << "myvresize contains:";
            for (int i=0;i< (int)myvresize.size();i++)
                test1.push_back(myvresize[i]);
            // std::cout << '\n';
        }
        {
            //std::cout<<"\033[32mresize\033[0m"<<std::endl;
            std::vector<int> myvresize;

            // set some initial content:
            for (int i=1;i<10;i++) myvresize.push_back(i);

            myvresize.resize(5);
            myvresize.resize(8,100);
            myvresize.resize(12);

            //std::cout << "myvresize contains:";
            for (int i=0;i< (int)myvresize.size();i++)
                test2.push_back(myvresize[i]);
            // std::cout << '\n';
        }
        if(test1 == test2)
            std::cout<<"\033[32mok\033[0m"<<std::endl;
        else
            std::cout<<"\033[31mko\033[0m"<<std::endl;
        test1.clear();
        test2.clear();
        ////////////////////
        sleep(2);
        std::cout << "\x1B[2J\x1B[H";
        {
            std::cout<<"\033[32mcapacity\033[0m"<<std::endl;
            ft::vector<int> mycapacity;

            // set some content in the vector:
            for (int i=0; i<100; i++) mycapacity.push_back(i);

            // std::cout << "size: " << (int) mycapacity.size() << '\n';
            // std::cout << "capacity: " << (int) mycapacity.capacity() << '\n';
            // std::cout << "max_size: " << (int) mycapacity.max_size() << '\n';
            test1.push_back(mycapacity.size() );
            test1.push_back(mycapacity.capacity());
            test1.push_back(mycapacity.max_size() );

        }
        {
            std::vector<int> mycapacity;

            // set some content in the vector:
            for (int i=0; i<100; i++) mycapacity.push_back(i);

            // std::cout << "size: " << (int) mycapacity.size() << '\n';
            // std::cout << "capacity: " << (int) mycapacity.capacity() << '\n';
            // std::cout << "max_size: " << (int) mycapacity.max_size() << '\n';
            test2.push_back(mycapacity.size() );
            test2.push_back(mycapacity.capacity());
            test2.push_back(mycapacity.max_size() );
        }
        if(test1 == test2)
            std::cout<<"\033[32mok\033[0m"<<std::endl;
        else
            std::cout<<"\033[31mko\033[0m"<<std::endl;
        test1.clear();
        test2.clear();
        /////////////////////////////////
        sleep(2);
        std::cout << "\x1B[2J\x1B[H";
        {
            std::cout<<"\033[32mempty\033[0m"<<std::endl;

            ft::vector<int> myempty;
            int sum (0);

            for (int i=1;i<=10;i++) myempty.push_back(i);

            while (!myempty.empty())
            {
                sum += myempty.back();
                myempty.pop_back();
            }

            // std::cout << "total: " << sum << '\n';
            test1.push_back(sum);
        }
        {
            // std::cout<<"\033[32mempty\033[0m"<<std::endl;

            std::vector<int> myempty;
            int sum (0);

            for (int i=1;i<=10;i++) myempty.push_back(i);

            while (!myempty.empty())
            {
                sum += myempty.back();
                myempty.pop_back();
            }

            // std::cout << "total: " << sum << '\n';
            test2.push_back(sum);

        }
        if(test1 == test2)
            std::cout<<"\033[32mok\033[0m"<<std::endl;
        else
            std::cout<<"\033[31mko\033[0m"<<std::endl;
        test1.clear();
        test2.clear();
        /////////////////////////////////////////////////////////////
         sleep(2);
        std::cout << "\x1B[2J\x1B[H";
        {
            std::cout<<"\033[32merase\033[0m"<<std::endl;

            ft::vector<int> myerase;

            // set some values (from 1 to 10)
            for (int i=1; i<=10; i++) myerase.push_back(i);

            // erase the 6th element
            myerase.erase (myerase.begin()+5);

            // erase the first 3 elements:
            myerase.erase (myerase.begin(),myerase.begin()+3);

            // std::cout << "myvector contains:";
            for (unsigned i=0; i<myerase.size(); ++i)
                test1.push_back(myerase[i]);
            // std::cout << '\n';
        }
        {
            // std::cout<<"\033[32merase\033[0m"<<std::endl;

            std::vector<int> myerase;

            // set some values (from 1 to 10)
            for (int i=1; i<=10; i++) myerase.push_back(i);

            // erase the 6th element
            myerase.erase (myerase.begin()+5);

            // erase the first 3 elements:
            myerase.erase (myerase.begin(),myerase.begin()+3);

            // std::cout << "myvector contains:";
            for (unsigned i=0; i<myerase.size(); ++i)
                test2.push_back(myerase[i]);
            // std::cout << '\n';
        }
        if(test1 == test2)
            std::cout<<"\033[32mok\033[0m"<<std::endl;
        else
            std::cout<<"\033[31mko\033[0m"<<std::endl;
        test1.clear();
        test2.clear();
         sleep(2);
        std::cout << "\x1B[2J\x1B[H";
        std::cout<<"\033[32mreserve\033[0m"<<std::endl;
        {
            ft::vector<int>::size_type sz;

            ft::vector<int> foo;
            sz = foo.capacity();
            //std::cout << "making foo grow:\n";
            for (int i=0; i<100; ++i) {
                foo.push_back(i);
                if (sz!=foo.capacity()) {
                sz = foo.capacity();
                test1.push_back(sz);
                }
            }

            ft::vector<int> bar;
            sz = bar.capacity();
            bar.reserve(100);   // this is the only difference with foo above
            //std::cout << "making bar grow:\n";
            for (int i=0; i<100; ++i)
            {
                bar.push_back(i);
                if (sz!=bar.capacity()) {
                sz = bar.capacity();
                test1.push_back(sz);;
                }
            }
        }
        //std::cout<<"\033[32mreserve\033[0m"<<std::endl;
        {
            std::vector<int>::size_type sz;

            std::vector<int> foo;
            sz = foo.capacity();
           // std::cout << "making foo grow:\n";
            for (int i=0; i<100; ++i) {
                foo.push_back(i);
                if (sz!=foo.capacity()) {
                sz = foo.capacity();
                test2.push_back(sz);;
                }
            }

            std::vector<int> bar;
            sz = bar.capacity();
            bar.reserve(100);   // this is the only difference with foo above
            //std::cout << "making bar grow:\n";
            for (int i=0; i<100; ++i)
            {
                bar.push_back(i);
                if (sz!=bar.capacity()) {
                sz = bar.capacity();
                test2.push_back(sz);;
                }
            }
        }
        if(test1 == test2)
            std::cout<<"\033[32mok\033[0m"<<std::endl;
        else
            std::cout<<"\033[31mko\033[0m"<<std::endl;
        test1.clear();
        test2.clear();
        ////////////////////////////////////////////////////
        sleep(2);
        std::cout << "\x1B[2J\x1B[H";
        std::cout<<"\033[32moperator[]\033[0m"<<std::endl;
        {
            ft::vector<int> myvector (10);   // 10 zero-initialized elements

            ft::vector<int>::size_type sz = myvector.size();

            // assign some values:
            for (unsigned i=0; i<sz; i++) myvector[i]=i;

            // reverse vector using operator[]:
            for (unsigned i=0; i<sz/2; i++)
            {
                int temp;
                temp = myvector[sz-1-i];
                myvector[sz-1-i]=myvector[i];
                myvector[i]=temp;
            }

           // std::cout << "myvector contains:";
            for (unsigned i=0; i<sz; i++)
                test1.push_back(myvector[i]);
            // std::cout << '\n';

        }
        {
            std::vector<int> myvector (10);   // 10 zero-initialized elements

            std::vector<int>::size_type sz = myvector.size();

            // assign some values:
            for (unsigned i=0; i<sz; i++) myvector[i]=i;

            // reverse vector using operator[]:
            for (unsigned i=0; i<sz/2; i++)
            {
                int temp;
                temp = myvector[sz-1-i];
                myvector[sz-1-i]=myvector[i];
                myvector[i]=temp;
            }

         //   std::cout << "myvector contains:";
            for (unsigned i=0; i<sz; i++)
                test2.push_back(myvector[i]);
            // std::cout << '\n';

        }
        if(test1 == test2)
            std::cout<<"\033[32mok\033[0m"<<std::endl;
        else
            std::cout<<"\033[31mko\033[0m"<<std::endl;
        test1.clear();
        test2.clear();
         sleep(2);
        std::cout << "\x1B[2J\x1B[H";
        std::cout<<"\033[32mat\033[0m"<<std::endl;
        {
            ft::vector<int> myvector (10);   // 10 zero-initialized ints

            // assign some values:
            for (unsigned i=0; i<myvector.size(); i++)
                myvector.at(i)=i;

            //std::cout << "myvector contains:";
            for (unsigned i=0; i<myvector.size(); i++)
                test1.push_back( myvector.at(i));
            // std::cout << '\n';

        }
        {
            std::vector<int> myvector (10);   // 10 zero-initialized ints

            // assign some values:
            for (unsigned i=0; i<myvector.size(); i++)
                myvector.at(i)=i;

            //std::cout << "myvector contains:";
            for (unsigned i=0; i<myvector.size(); i++)
                 test2.push_back( myvector.at(i));
            // std::cout << '\n';
        }
        if(test1 == test2)
            std::cout<<"\033[32mok\033[0m"<<std::endl;
        else
            std::cout<<"\033[31mko\033[0m"<<std::endl;
        test1.clear();
        test2.clear();
        //////////////////////////////////////////
         sleep(2);
        std::cout << "\x1B[2J\x1B[H";
        std::cout<<"\033[32m front && back\033[0m"<<std::endl;
        {
            ft::vector<int> myvector;

            myvector.push_back(78);
            myvector.push_back(16);

            // now front equals 78, and back 16

            myvector.front() -= myvector.back();

            test1.push_back(myvector.front());

        }
        {
            std::vector<int> myvector;

            myvector.push_back(78);
            myvector.push_back(16);

            // now front equals 78, and back 16

            myvector.front() -= myvector.back();

            test2.push_back(myvector.front());


        }
         if(test1 == test2)
            std::cout<<"\033[32mok\033[0m"<<std::endl;
        else
            std::cout<<"\033[31mko\033[0m"<<std::endl;
        test1.clear();
        test2.clear();
         //////////////////////////////
          sleep(2);
        std::cout << "\x1B[2J\x1B[H";
        {
            std::cout<<"\033[32m assing \033[0m"<<std::endl;

            ft::vector<int> first;
            ft::vector<int> second;
            ft::vector<int> third;

            first.assign (7,100);             // 7 ints with a value of 100

            ft::vector<int>::iterator it;
            it=first.begin()+1;

            second.assign (it,first.end()-1); // the 5 central values of first

            int myints[] = {1776,7,4};
            third.assign (myints,myints+3);   // assigning from array.

            // std::cout << "Size of first: " << int (first.size()) << '\n';
            // std::cout << "Size of second: " << int (second.size()) << '\n';
            // std::cout << "Size of third: " << int (third.size()) << '\n';
            test1.push_back(first.size());
            test1.push_back(second.size());
            test1.push_back(third.size());

        }
          {
            //std::cout<<"\033[32m assing \033[0m"<<std::endl;

            std::vector<int> first;
            std::vector<int> second;
            std::vector<int> third;

            first.assign (7,100);             // 7 ints with a value of 100

            std::vector<int>::iterator it;
            it=first.begin()+1;

            second.assign (it,first.end()-1); // the 5 central values of first

            int myints[] = {1776,7,4};
            third.assign (myints,myints+3);   // assigning from array.

            // std::cout << "Size of first: " << int (first.size()) << '\n';
            // std::cout << "Size of second: " << int (second.size()) << '\n';
            // std::cout << "Size of third: " << int (third.size()) << '\n';
            test2.push_back(first.size());
            test2.push_back(second.size());
            test2.push_back(third.size());
        }
        if(test1 == test2)
            std::cout<<"\033[32mok\033[0m"<<std::endl;
        else
            std::cout<<"\033[31mko\033[0m"<<std::endl;
        test1.clear();
        test2.clear();
        sleep(2);
        std::cout << "\x1B[2J\x1B[H";
        {
            std::cout<<"\033[32m push && pop \033[0m"<<std::endl;
            ft::vector<int> myvector;
            int sum (0);
            for (size_t i = 0; i < 1000; i++)
            {
                myvector.push_back (i+10);
            }
            

            while (!myvector.empty())
            {
                sum+=myvector.back();
                myvector.pop_back();
            }
            // std::cout << "my capacity is  " << myvector.capacity() << '\n';
            // std::cout << "The elements of myvector add up to " << sum << '\n';
            test1.push_back(myvector.capacity());
            test1.push_back(sum);


        }
        {
            // std::cout<<"\033[32m push && pop \033[0m"<<std::endl;
            std::vector<int> myvector;
            int sum (0);
            for (size_t i = 0; i < 1000; i++)
            {
                myvector.push_back (i+10);
            }
            

            while (!myvector.empty())
            {
                sum+=myvector.back();
                myvector.pop_back();
            }
            // std::cout << "my capacity is  " << myvector.capacity() << '\n';
            // std::cout << "The elements of myvector add up to " << sum << '\n';
            test2.push_back(myvector.capacity());
            test2.push_back(sum);

        }
        if(test1 == test2)
            std::cout<<"\033[32mok\033[0m"<<std::endl;
        else
            std::cout<<"\033[31mko\033[0m"<<std::endl;
        test1.clear();
        test2.clear();
        sleep(2);

        std::cout << "\x1B[2J\x1B[H";
        {
            std::cout<<"\033[32m insert \033[0m"<<std::endl;
            ft::vector<int> myvector (3,100);
            ft::vector<int>::iterator it;

            it = myvector.begin();
            it = myvector.insert ( it , 200 );

            myvector.insert (it,2,300);

            // "it" no longer valid, get a new one:
            it = myvector.begin();

            std::vector<int> anothervector (2,400);
            myvector.insert (it+2,anothervector.begin(),anothervector.end());

            int myarray [] = { 501,502,503 };
            myvector.insert (myvector.begin(), myarray, myarray+3);

            // std::cout << "myvector contains:";
            for (it=myvector.begin(); it<myvector.end(); it++)
                test1.push_back(*it);
            // std::cout << '\n';
        }
        {
            // std::cout<<"\033[32m insert \033[0m"<<std::endl;
            std::vector<int> myvector (3,100);
            std::vector<int>::iterator it;

            it = myvector.begin();
            it = myvector.insert ( it , 200 );

            myvector.insert (it,2,300);

            // "it" no longer valid, get a new one:
            it = myvector.begin();

            std::vector<int> anothervector (2,400);
            myvector.insert (it+2,anothervector.begin(),anothervector.end());

            int myarray [] = { 501,502,503 };
            myvector.insert (myvector.begin(), myarray, myarray+3);

            // std::cout << "myvector contains:";
            for (it=myvector.begin(); it<myvector.end(); it++)
                test2.push_back(*it);
            // std::cout << '\n';
        }
        if(test1 == test2)
            std::cout<<"\033[32mok\033[0m"<<std::endl;
        else
            std::cout<<"\033[31mko\033[0m"<<std::endl;
        test1.clear();
        test2.clear();
        sleep(2);
        std::cout << "\x1B[2J\x1B[H";
         {
            std::cout<<"\033[32m swap \033[0m"<<std::endl;
            ft::vector<int> foo (3,100);   // three ints with a value of 100
            ft::vector<int> bar (5,200);   // five ints with a value of 200

            foo.swap(bar);

           // std::cout << "foo contains:";
            for (unsigned i=0; i<foo.size(); i++)
                test1.push_back(foo[i]);
           // std::cout << '\n';

           // std::cout << "bar contains:";
            for (unsigned i=0; i<bar.size(); i++)
                test1.push_back( bar[i]);
            //std::cout << '\n';
        }
        {
            //std::cout<<"\033[32m swap \033[0m"<<std::endl;
            std::vector<int> foo (3,100);   // three ints with a value of 100
            std::vector<int> bar (5,200);   // five ints with a value of 200

            foo.swap(bar);

            //std::cout << "foo contains:";
            for (unsigned i=0; i<foo.size(); i++)
                test2.push_back( foo[i]);
           // std::cout << '\n';

            //std::cout << "bar contains:";
            for (unsigned i=0; i<bar.size(); i++)
                test2.push_back(bar[i]);
            //std::cout << '\n';
        }
        if(test1 == test2)
            std::cout<<"\033[32mok\033[0m"<<std::endl;
        else
            std::cout<<"\033[31mko\033[0m"<<std::endl;
        test1.clear();
        test2.clear();
         /////////////////////////////////
        sleep(2);
        std::cout << "\x1B[2J\x1B[H";
        {
            std::cout<<"\033[32m clear \033[0m"<<std::endl;
            ft::vector<int> myvector;    
            myvector.push_back (100);
            myvector.push_back (200);
            myvector.push_back (300);

            // std::cout << "myvector contains:";
            // for (unsigned i=0; i<myvector.size(); i++)
            //     std::cout << ' ' << myvector[i];
            // std::cout << '\n';

            myvector.clear();
            myvector.push_back (1101);
            myvector.push_back (2202);

            //std::cout << "myvector contains:";
            for (unsigned i=0; i<myvector.size(); i++)
                test1.push_back( myvector[i]);
           // std::cout << '\n';

        }
        {
            // std::cout<<"\033[32m clear \033[0m"<<std::endl;
            std::vector<int> myvector;    
            myvector.push_back (100);
            myvector.push_back (200);
            myvector.push_back (300);

            // std::cout << "myvector contains:";
            // for (unsigned i=0; i<myvector.size(); i++)
            //     std::cout << ' ' << myvector[i];
            // std::cout << '\n';

            myvector.clear();
            myvector.push_back (1101);
            myvector.push_back (2202);

           // std::cout << "myvector contains:";
            for (unsigned i=0; i<myvector.size(); i++)
                test2.push_back( myvector[i]);
           // std::cout << '\n';
        }
        if(test1 == test2)
            std::cout<<"\033[32mok\033[0m"<<std::endl;
        else
            std::cout<<"\033[31mko\033[0m"<<std::endl;
        test1.clear();
        test2.clear();
        std::cout << "\nthe end\n";
    }
    sleep(2);
}
int main ()
{
   ft_vector();
}