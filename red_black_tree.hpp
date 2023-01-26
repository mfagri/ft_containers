/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:56:15 by mfagri            #+#    #+#             */
/*   Updated: 2023/01/26 19:53:00 by mfagri           ###   ########.fr       */
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

// template <class node>
//   inline node   min(node nd) throw()
//         {
//             while (nd->left != NULL)
//                 nd = nd->left;
//             return nd;
//         }
// template <class node>
// node max(node nd) throw()
// {
//     while (nd->right != TNULL)
//         nd = nd->right;
//     return nd;
// }

// template <class T> 
//     inline T next(T nd)
//     {
//         if (nd->right != NULL)
//             return (min(nd->right));
//         while (!tree_is_left_child(nd))
//             nd = nd->parent;
//         return (nd->parent);
//     }
// template <class node>
// node prev(node nd)
// {
    
//     if (nd->left != NULL)
//         return (max(nd->left));
//     node ndt = nd;
//     while (tree_is_left_child(ndt))
//         ndt = ndt->parent;
//     return (ndt->parent);
// }

template<class T>
struct Node
{
    T data;
    Node *parent;
    Node *left;
    Node *right;
    int color;
    Node(T d):data(d) {
        // data = data;
        parent = NULL;
        left = NULL;
        right = NULL;
        color = 0;
  }     
};
namespace ft
{

template <class Key, class T, class Compare, class Alloc>
class RedBlackTree {
    public:
        typedef Node<T>* node;
        typedef Compare value_compare;
        typedef Key key_type;
        typedef T mapped_type;
        typedef RedBlackTree self;
        // typedef ft::pair<key_type,mapped_type> value_type;
        typedef mapped_type value_type;
        typedef ft::red_black_iterator <self,value_type,node>  iterator;
        typedef ft::const_red_black_iterator <self,const value_type,node> const_iterator;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
        
        // typedef _Rb_tree_const_iterator<value_type> const_iterator;
    // private:
        
   
    public:
        Compare comp;
        node root;
        node TNULL;
        node endn;
        // value_compare _comp;
        // typedef value_compare (Compare c) : comp(c) {};
typedef typename Alloc::template rebind<Node<T> >::other node_allocator;        
        node_allocator alloc;
        // const value_compare &value_comp() const
        // {
        //     return (_comp);
        // }
        // value_compare &value_comp()
        // {
        //     return (_comp);
        // }

         RedBlackTree(){
             
            TNULL = alloc.allocate(1);
            //  alloc.construct(TNULL,T(0,0));
            TNULL->data = (T(0,0));
            TNULL->right = nullptr;
            TNULL->left = nullptr;
            TNULL->parent = nullptr;
            TNULL->color = 0;
            root = TNULL;
            endn = alloc.allocate(1);
           endn->data = (T(1,1));
            endn->right = nullptr;
             endn->left = root;   
            endn->parent = nullptr;
            endn->color = 0;
        }
        RedBlackTree(iterator first,iterator last){
             
            TNULL = alloc.allocate(1);
             alloc.construct(TNULL,T(0,0));
            TNULL->data = (T(0,0));
            TNULL->right = nullptr;
            TNULL->left = nullptr;
            TNULL->parent = nullptr;
            TNULL->color = 0;
            root = TNULL;
            endn = alloc.allocate(1);
           endn->data = (T(1,1));
            endn->right = nullptr;
             endn->left = root;   
            endn->parent = nullptr;
            endn->color = 0;
            // std::cout<<first.data.first<<std::endl;
            while (first != last)
            {
                add(*first++);
            }
            
        }
         pair<iterator,bool> add(T data)
        {
            node n = alloc.allocate(1);
            alloc.construct(n,data);
            n->data = data;
            n->left = TNULL;
            n->right = TNULL;
            // std::cout<<n->data.first<<std::endl;
            // if(n->left == TNULL)
            // {
            //     puts("is good for now");
            // }
            n->parent = endn;
            n->color = 1;
            if(root == TNULL)//if tree is empty
            {
                n->color = 0;
                root = n;
                root->right = TNULL;
                root->left = TNULL;
                return (ft::make_pair(iterator(n,*this), true));
            }
            else//tree not empty
            {
                node y = NULL;
                node x = this->root;

                while (x != TNULL)
                {
                    
                    y = x;
                    if (n->data.first < x->data.first)
                    {
                        x = x->left;
                    }
                    else if (n->data.first > x->data.first)
                    {
                        x = x->right;
                    }
                    else
                        return (ft::make_pair(iterator(x,*this), false));
                }
                n->parent = y;
                if (n->data.first < y->data.first)
                {
                    y->left = n;
                    n->left = TNULL;
                    n->right = TNULL;
                }
                else if ((n->data.first > y->data.first))
                {
                    y->right = n;
                    n->left = TNULL;
                    n->right = TNULL;
                }
                // else
                //     return (ft::make_pair(iterator(y,*this), true));
            }
            tree_balance_after_insert(n);
            endn->left = root;   
            // fixViolation(n);
            // puts("awal mara");
            // min(root,TNULL);
            // puts("awal mara2");
            return (ft::make_pair(iterator(n,*this), true));
        }
void tree_balance_after_insert(node N)
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
       node searchTreeHelper(node n, key_type key) {
        
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
        node searchTree(key_type k)
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
        
        node    min(node x)
        {
            while (x && x->left!= TNULL)
            {
                x = x->left;
            }
            return (x);
        }
         node suc(node nd)
        {
            if (nd->right != TNULL)
                return (min(nd->right));
            
            while (!tree_is_left_child(nd))
                nd = nd->parent;
            return (nd->parent);
        }
        // node max(node nd) throw()
        // {
        //     while (nd->right != TNULL)
        //         nd = nd->right;
        //     return nd;
        // }
        node max(node nd)
        {
             while (nd->right->right != NULL)
                nd = nd->right;
            return nd;
        }
        node prev(node n)
        {
            // puts("prev tree");
            if (n->left->right != NULL && n->left != TNULL)
            {
                //if(n == endn)
                  //  puts("endn");
            //    std::cout<<n->left->right->data.first<<std::endl;
                return max(n->left);
            }
             //   puts("here2");
            node tmp = n->parent;
            while (tmp != endn && n == tmp->left )//&& tmp->data.second != 0)
            {
                n = tmp;
                tmp = tmp->parent;
            }
            if (tmp == endn)
            {
                // endn->left = nullptr;
                // endn->right = nullptr;
                return endn;
            }
                // puts("sssssss");
            return (tmp);
           
        }

        
        // node next(node nd)
        // {
        //     if (nd->right != NULL)
        //         return (min(nd->right));
            
        //     while (!tree_is_left_child(nd))
        //         nd = nd->parent;
        //     return (nd->parent);
        // }
       
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
            return(iterator(x,*this));
        }
        // const_iterator begin() const
        // {
        //     return(const_iterator(min(root)));
        // }
        iterator end()
        {
            root->parent = endn;
            endn->left = root;
            // puts("end map");      
            return(iterator(endn,*this));///////////
        }
        reverse_iterator rbegin()
        {
            // puts("rbegin tree");
            return reverse_iterator((this->end()));
        }
        const_reverse_iterator rbegin() const
        {
            return const_reverse_iterator(this->end());
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
};
}
#endif