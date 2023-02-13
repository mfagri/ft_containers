/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:56:15 by mfagri            #+#    #+#             */
/*   Updated: 2023/02/13 22:34:06 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE
#define RED_BLACK_TREE

#include <iostream>
#include "equal.hpp"
#include "red_black_iterator.hpp"
#include "map.hpp"
#include "reverse_iterator.hpp"

class red_black_iterator;
template<class node>
 inline bool tree_is_left_child(node nd)
{
        return(nd == nd->parent->left);
}



template<class T>
struct Node
{
    T data;
    Node *parent;
    Node *left;
    Node *right;
    int color;
    Node(const T &d):data(d) {
        // data = data;
        // puts("ddd");
        parent = NULL;
        left = NULL;
        right = NULL;
        color = 0;
  }    
//   ~Node(){}
};
namespace ft
{

template <class Key, class T, class Compare, class Alloc>
class RedBlackTree {
    public:
        typedef T mapped_type;
        typedef Node<mapped_type>* node;
        typedef Compare value_compare;
        typedef Key key_type;
        typedef RedBlackTree self;
        // typedef ft::pair<key_type,mapped_type> value_type;
        typedef mapped_type value_type;
        typedef ft::red_black_iterator <self,value_type,node>  iterator;
        typedef ft::const_red_black_iterator <self,const value_type,node> const_iterator;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
        typedef typename Alloc::size_type       size_type;
        typedef typename Alloc::difference_type difference_type;
        
        // typedef _Rb_tree_const_iterator<value_type> const_iterator;
    // private:
        
   
    public:
        Compare comp;
        node root;
        node TNULL;
        node endn;
        size_type m_size;
        // value_compare _comp;
        // typedef value_compare (Compare c) : comp(c) {};
        typedef typename Alloc::template rebind<Node<T> >::other node_allocator;   ////rebin node   
        node_allocator alloc;
        // const value_compare &value_comp() const
        // {
        //     return (_comp);
        // }
        // value_compare &value_comp()
        // {
        //     return (_comp);
        // }
        void dea()
        {
            if(TNULL && endn)
            {
                //alloc.destroy(TNULL);
                alloc.deallocate(TNULL, 1);
               // alloc.destroy(endn);
                alloc.deallocate(endn, 1);
            }
        }
         RedBlackTree(){
            // puts("ddd");
             m_size = 0;
            TNULL = alloc.allocate(1);
            //  alloc.construct(TNULL,T(0,0));
            // TNULL->data = (T(0,0));
            TNULL->right = NULL;
            TNULL->left = NULL;
            TNULL->parent = NULL;
            TNULL->color = 0;
            root = TNULL;
            endn = alloc.allocate(1);
        //    endn->data = (T(1,1));
            endn->right = NULL;
             endn->left = root;   
            endn->parent = NULL;
            endn->color = 0;
            comp = Compare();
            // while(1);
        }
        RedBlackTree(iterator first,iterator last){
             m_size = 0;
            TNULL = alloc.allocate(1);
            //  alloc.construct(TNULL,T(0,0));
            // TNULL->data = (T(0,0));
            TNULL->right = nullptr;
            TNULL->left = nullptr;
            TNULL->parent = nullptr;
            TNULL->color = 0;
            root = TNULL;
            endn = alloc.allocate(1);
        //    endn->data = (T(1,1));
            endn->right = nullptr;
             endn->left = root;   
            endn->parent = nullptr;
            endn->color = 0;
            comp = Compare();
            // std::cout<<first.data.first<<std::endl;
            while (first != last)
            {
                add(*first++);
            }
            
        }
        // ~RedBlackTree()
        // {
        //     // iterator it = begin();
        //     // iterator tmp = it;
        //     // while(it != end())
        //     // {
        //     //     puts("hello");
        //     //     tmp++;
        //     //     deleteNode(it->first);
        //     //     it = tmp;
        //     // }
        //     clear();
        //     //puts("ok");
        // }
        ////////////////////////////////
        void clear_alltree(node n)
        {
           // puts("f");
            if (n  != TNULL && n != endn)
            {
                if (n->left != NULL || n->right != NULL)
                {
                    clear_alltree(n->left);
                    clear_alltree(n->right);
                    alloc.destroy(n);
                    alloc.deallocate(n, 1);
                }
                n->left = NULL;
                n->right = NULL;
            }
            else
                return;
        }
        // clear
        void clear()
        {
            clear_alltree(root);
            // if(!root)
            //     puts("root is null");
            // if(root == TNULL)
            //     puts("tnull root");
            // if(root == endn)
            //     puts("endn");
            // if(root)
            //     puts("wtf");
            // if(root->left == NULL)
            //     puts("yes");
            // if(root->right == NULL)
            //     puts("yes");
            //     std::cout<<root->data.first<<std::endl;
            root = NULL;
            // puts("sala");
            m_size = 0;
        }
        ///////////////////
        pair<iterator, bool> add(const T& data)
        {
            node n = alloc.allocate(1);
            alloc.construct(n, data);
            n->left = TNULL;
            n->right = TNULL;
            n->parent = endn;
            n->color = 1;

            if (root == TNULL)
            {
                n->color = 0;
                root = n;
                root->right = TNULL;
                root->left = TNULL;
                m_size = 1;
                return ft::make_pair(iterator(n, *this), true);
            }
            else
            {
                node y = NULL;
                node x = root;

                while (x != TNULL)
                {
                    y = x;
                    // !value_comp()(y->data,x->data)
                    if (!comp(n->data.first, x->data.first) && !comp(x->data.first,n->data.first))
                        return ft::make_pair(iterator(x, *this), false);
                        
                    if (comp(n->data.first, x->data.first))
                    {
                        x = x->left;
                    }
                    else
                    {
                        x = x->right;
                    }
                }
                //std::cout<<"data is "<<y->data.second<<std::endl;
                n->parent = y;
                if (n->data.first < y->data.first)
                {
                    y->left = n;
                }
                else
                {
                    y->right = n;
                }
            }

            m_size++;
            tree_balance_after_insert(n);
            endn->left = root;
            return ft::make_pair(iterator(n, *this), true);
        }
        //  pair<iterator,bool> add(const T& data)
        // {
        //     node n = alloc.allocate(1);
        //     // puts("ff");
        //     alloc.construct(n,data);
        //     // n->data = data;
        //     n->left = TNULL;
        //     n->right = TNULL;
        //     // std::cout<<n->data.first<<std::endl;
        //     // if(n->left == TNULL)
        //     // {
        //     //     puts("is good for now");
        //     // }
        //     n->parent = endn;
        //     n->color = 1;
        //     if(root == TNULL)//if tree is empty
        //     {
        //         n->color = 0;
        //         root = n;
        //         root->right = TNULL;
        //         root->left = TNULL;
        //         m_size = 1;
        //         return (ft::make_pair(iterator(n,*this), true));
        //     }
        //     else//tree not empty
        //     {
        //         node y = NULL;
        //         node x = this->root;

        //         while (x != TNULL)
        //         {
                    
        //             y = x;
        //             if (n->data.first < x->data.first)
        //             {
        //                 x = x->left;
        //             }
        //             else if (n->data.first > x->data.first)
        //             {
        //                 x = x->right;
        //             }
        //             else
        //                 return (ft::make_pair(iterator(x,*this), false));
        //         }
        //         n->parent = y;
        //         if (n->data.first < y->data.first)
        //         {
        //             y->left = n;
        //             n->left = TNULL;
        //             n->right = TNULL;
        //         }
        //         else if ((n->data.first > y->data.first))
        //         {
        //             y->right = n;
        //             n->left = TNULL;
        //             n->right = TNULL;
        //         }
        //         // else
        //         //     return (ft::make_pair(iterator(y,*this), true));
        //     }
        //     m_size++;
        //     tree_balance_after_insert(n);
        //     endn->left = root;   
        //     // fixViolation(n);
        //     // puts("awal mara");
        //     // min(root,TNULL);
        //     // puts("awal mara2");
        //     return (ft::make_pair(iterator(n,*this), true));
        // }
void tree_balance_after_insert(node& N)
        {
            node u;
            while (N->parent->color == 1) {
                if (N->parent == N->parent->parent->right) {
                    u = N->parent->parent->left;
                    if (u->color == 1) {
                    u->color = 0;
                    N->parent->color = 0;
                    N->parent->parent->color = 1;
                    N = N->parent->parent;
                    } else {
                    if (N == N->parent->left) {
                        N = N->parent;
                        rightRotate(N);
                    }
                    N->parent->color = 0;
                    N->parent->parent->color = 1;
                    leftRotate(N->parent->parent);
                    }
                } else {
                    u = N->parent->parent->right;

                    if (u->color == 1) {
                    u->color = 0;
                    N->parent->color = 0;
                    N->parent->parent->color = 1;
                    N = N->parent->parent;
                    } else {
                    if (N == N->parent->right) {
                        N = N->parent;
                        leftRotate(N);
                    }
                    N->parent->color = 0;
                    N->parent->parent->color = 1;
                    rightRotate(N->parent->parent);
                    }
                }
                if (N == root) {
                    break;
                }
            }
            root->color = 0;
        }
       node searchTreeHelper(node n, key_type key) const {
        
            if (n == TNULL || key == n->data.first)
            {
                return n;
            }
            if (key < n->data.first)
            {
                return searchTreeHelper(n->left, key);
            }
            return searchTreeHelper(n->right, key);
        }
        node searchTree(key_type k) const
        {
            return searchTreeHelper(this->root, k);
        }
        void leftRotate(node x)
        {
            node y = x->right;
            x->right = y->left;
            if (y->left != TNULL) {
            y->left->parent = x;
            }
            y->parent = x->parent;
            if (x->parent == endn) {
            this->root = y;
            } else if (x == x->parent->left) {
            x->parent->left = y;
            } else {
            x->parent->right = y;
            }
            y->left = x;
            x->parent = y;
        }

        void rightRotate(node x)
        {
            node y = x->left;
            x->left = y->right;
            if (y->right != TNULL) {
                y->right->parent = x;
            }
            y->parent = x->parent;
            if (x->parent == endn) {
                this->root = y;
            } else if (x == x->parent->right) {
                x->parent->right = y;
            } else {
                x->parent->left = y;
            }
            y->right = x;
            x->parent = y;
        }
        
        bool tree_is_left_child(node nd)
        {
            return(nd == nd->parent->left);
        }
        
        bool tree_is_right_child(node nd)
        {
            return(nd == nd->parent->right);
        }
        
        node    min(node x) const
        {
            // puts("ff");
            while (x && x->left != NULL && x->left->left!= NULL)
            {
                //  puts("ll");
                x = x->left;
            }
            if(x->left == NULL && x->right == NULL)
                return endn;
            return (x);
        }
        node suc(node nd)
        {
            //puts("gg");
            // if (x->right != TNULL) {
            // return min(x->right);
            // }

            // node y = x->parent;
            // while (y != TNULL && x == y->right) {
            // x = y;
            // y = y->parent;
            // }
            // return y;
            // // return(next(nd));
            // // puts("ff");
            if (nd->right->left!= NULL && nd->right != TNULL)
            {
                // puts("lol2");
                return (min(nd->right));
            }
                //   puts("sssssss");  
            while (nd && nd != endn && nd != TNULL && !tree_is_left_child(nd))
            {
                //  puts("here");
                //  if(nd != endn && nd != TNULL && nd->right != NULL)
                //     puts("hhhhhhhhh");
                nd = nd->parent;
                if(nd->right == NULL)
                    return (nd);
                // std::cout<<"wast : "<<nd->parent->data.first<<std::endl;
                // if(nd->parent == endn)
                // {
                //      puts("hhh");
                //     break;
                // }
            }
            // // puts("lol");
            //  if (nd == NULL)
            // {
            //     // puts("szzz");
            //     // endn->left = nullptr;
            //     // endn->right = nullptr;
            //     return endn;
            // }
            // // puts("kh");
            return (nd->parent);
        }
        bool empty()const
        {
            return m_size == 0;
        }
        // bool empty()const noexcept
        // {
        //     return root == TNULL;
        // }
      
        node max(node nd)
        {
            while (nd->right->right != NULL)
                nd = nd->right;
            return nd;
        }
        node prev(node n)
        {
             //puts("g");
            if (n->left->right != NULL && n->left != TNULL)
            {
                return max(n->left);
            }
            node tmp = n->parent;
            
            if(!tmp && root->right)
            {
                   // puts("hna");
                    return max(root);
            }
            else if(!tmp)
            {
                //puts("what");
                return endn;
            }
            while (tmp && tmp != endn &&tmp->left && n == tmp->left )//&& tmp->data.second != 0)
            {
                n = tmp;
                tmp = tmp->parent;
            }
            if (tmp == endn)
            {
            //    puts("ok");
                return endn;
            }
            return (tmp);
           
        }
        pair<iterator,iterator>             equal_range (const key_type& k)
        {
            return ft::make_pair(lower_bound(k),upper_bound(k));
        }
        pair<const_iterator,const_iterator> equal_range (const key_type& k) const
        {
            return ft::make_pair(lower_bound(k),upper_bound(k));
        }
        node next(node nd)
        {
            if (nd->right != NULL)
                return (min(nd->right));
            
            while (!tree_is_left_child(nd))
                nd = nd->parent;
            return (nd->parent);
        }
       
        // node prev(node nd)
        // {
        //     if (nd->left != NULL)
        //         return (max(nd->left));
        //     node ndt = nd;
        //     while (tree_is_left_child(ndt))
        //         ndt = ndt->parent;
        //     return (ndt->parent);
        // }

        iterator begin()
        {
            node x = min(root);
            // puts("ff");
            return(iterator(x,*this));
        }

        const_iterator begin() const
        {
            node x = min(root);
            // puts("ff");
            return(const_iterator(x,*this));
        }
        // const_iterator begin()
        // {
        //     node x = min(root);
        //     // puts("ff");
        //     return( const_iterator(x,*this));
        // }
        // const_iterator begin() const
        // {
        //     return(const_iterator(min(root)));
        // }
        iterator end()
        {
            if (root)
                root->parent = endn;
            endn->left = root;
            // puts("end map");      
            return(iterator(endn,*this));///////////
        }
        const_iterator end() const
        {
            if (root)
                root->parent = endn;
            endn->left = root;
            // puts("end map");
            return(const_iterator(endn,*this));///////////
        }
        // reverse_iterator rbegin()
        // {
        //     // puts("rbegin tree");
        //     return reverse_iterator((this->end()));
        // }
        // const_reverse_iterator rbegin() const
        // {
        //     return const_reverse_iterator(this->end());
        // }
        //////////////////////////////////////////////
        size_type count(const key_type &k) const
        {
            // node n = ;
            if(searchTree(k) == TNULL)
                return 0;
            return 1;   
        }
        /////////////////////////////////////////////
         iterator lower_bound(const key_type &k)
        {
            iterator from = this->begin();
            iterator to = this->end();

            while (from != to)
            {
                if (!comp((*from).first, k))
                    return from;
                from++;
            }
            return from;
        }
        const_iterator lower_bound(const key_type &k) const
        {
            const_iterator from = this->begin();
            const_iterator to = this->end();

            while (from != to)
            {
                if (!comp((*from).first, k))
                    return from;
                from++;
            }
            return from;
        }
        ////////////////////////////////////////////
        iterator upper_bound(const key_type &k)
        {
            iterator from = this->begin();
            iterator to = this->end();

            while (from != to)
            {
                if (comp(k,(*from).first))
                    return from;
                from++;
            }
            return from;
        }
        size_type size() const
        {
            return m_size;
        }
        ////////////////////////////
        size_type max_size() const
        {
            return (std::min<size_type>(alloc.max_size(),
                            std::numeric_limits<difference_type>::max()));
        }
        ////////////////////////////////////////
        void swap (RedBlackTree& x)
        {
            std::swap(*this,x);
        }
    ///////////////////////////////////////////////////////////////////
    //////////////////////////////
    void delete_fix(node x) {
    node s;
    while (x != root && x->color == 0) {
      if (x == x->parent->left) {
        s = x->parent->right;
        if (s->color == 1) {
          s->color = 0;
          x->parent->color = 1;
          leftRotate(x->parent);
          s = x->parent->right;
        }

        if (s->left->color == 0 && s->right->color == 0) {
          s->color = 1;
          x = x->parent;
        } else {
          if (s->right->color == 0) {
            s->left->color = 0;
            s->color = 1;
            rightRotate(s);
            s = x->parent->right;
          }

          s->color = x->parent->color;
          x->parent->color = 0;
          s->right->color = 0;
          leftRotate(x->parent);
          x = root;
        }
      } else {
        s = x->parent->left;
        if (s->color == 1) {
          s->color = 0;
          x->parent->color = 1;
          rightRotate(x->parent);
          s = x->parent->left;
        }

        if (s->right->color == 0 && s->right->color == 0) {
          s->color = 1;
          x = x->parent;
        } else {
          if (s->left->color == 0) {
            s->right->color = 0;
            s->color = 1;
            leftRotate(s);
            s = x->parent->left;
          }

          s->color = x->parent->color;
          x->parent->color = 0;
          s->left->color = 0;
          rightRotate(x->parent);
          x = root;
        }
      }
    }
    x->color = 0;
  }
void rbTransplant(node u, node v)
{
    if (u->parent == endn) {
    root = v;
    } else if (u == u->parent->left) {
    u->parent->left = v;
    } else {
    u->parent->right = v;
    }
    v->parent = u->parent;
}
    void deleteNodeHelper(const key_type &k)
    {
        node z = TNULL;
        node x, y;
        z = searchTree(k);
        if (z == TNULL) {
        //   std::cout << "Key not found in the tree" << std::endl;
          return;
        }
        m_size--;
        y = z;
        int y_original_color = y->color;
        if (z->left == TNULL) {
          x = z->right;
          rbTransplant(z, z->right);
        } else if (z->right == TNULL) {
          x = z->left;
          rbTransplant(z, z->left);
        } else {
          y = max(z->left);
          y_original_color = y->color;
          x = y->left;
          if (y->parent == z) {
            x->parent = y;
          } else {
            rbTransplant(y, y->left);
            y->left = z->left;
            y->left->parent = y;
          }
    
          rbTransplant(z, y);
          y->right = z->right;
          y->right->parent = y;
          y->color = z->color;
    }
    alloc.deallocate(z,1);
    if (y_original_color == 0) {
      delete_fix(x);
    }
  }
   void deleteNode(const key_type &data) {
    deleteNodeHelper(data);
    root->parent = endn;
    endn->left = root;
  }
        ///////////////////////////////////////////////////////////////////
        const_iterator upper_bound(const key_type &k) const
        {
            const_iterator from = this->begin();
            const_iterator to = this->end();

            while (from != to)
            {
                if (comp(k,(*from).first))
                    return from;
                from++;
            }
            return from;
        }
         void printHelper(node root, std::string indent, bool last) {
            if (root != TNULL) {
            std::cout << indent;
            if (last) {
                std::cout << "R----";
                indent += "   ";
            } else {
                std::cout << "L----";
                indent += "|  ";
            }

            std::string sColor = root->color ? "RED" : "BLACK";
            std::cout << root->data.second<< "(" << sColor << ")" << std::endl;
            printHelper(root->left, indent, false);
            printHelper(root->right, indent, true);
            }
        }
         void printTree() {
            if (root) {
                printHelper(this->root, "", true);
        }
    }
    ///////////////////////////no member functions ///////////////////////
    // template <class Key, class T, class Compare, class Alloc>  void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
    // {
    //     std::swap(x,y);
    // }
    // template <class Key, class T, class Compare, class Alloc>  bool operator== ( const map<Key,T,Compare,Alloc>& lhs,                    const map<Key,T,Compare,Alloc>& rhs );	
    // template <class Key, class T, class Compare, class Alloc>  bool operator!= ( const map<Key,T,Compare,Alloc>& lhs,                    const map<Key,T,Compare,Alloc>& rhs );
    // template <class Key, class T, class Compare, class Alloc>  bool operator<  ( const map<Key,T,Compare,Alloc>& lhs,                    const map<Key,T,Compare,Alloc>& rhs );
    // template <class Key, class T, class Compare, class Alloc>  bool operator<= ( const map<Key,T,Compare,Alloc>& lhs,                    const map<Key,T,Compare,Alloc>& rhs );
    // template <class Key, class T, class Compare, class Alloc>  bool operator>  ( const map<Key,T,Compare,Alloc>& lhs,                    const map<Key,T,Compare,Alloc>& rhs );
    // template <class Key, class T, class Compare, class Alloc>  bool operator>= ( const map<Key,T,Compare,Alloc>& lhs,                    const map<Key,T,Compare,Alloc>& rhs );

};
}
#endif