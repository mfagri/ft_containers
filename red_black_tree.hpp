/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:56:15 by mfagri            #+#    #+#             */
/*   Updated: 2023/01/19 22:59:12 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE
#define RED_BLACK_TREE

#include <iostream>
#include "equal.hpp"
#include "red_black_iterator.hpp"

template <class _Tp>
    struct Node;
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
        parent = nullptr;
        left = nullptr;
        right = nullptr;
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
        typedef ft::pair<key_type,mapped_type> value_type;
        typedef ft::red_black_iterator <value_type,node>  iterator;
        // typedef ft::const_red_black_iterator <const value_type,node> const_iterator;
        
        // typedef _Rb_tree_const_iterator<value_type> const_iterator;
    // private:
        
   
    public:
        node root;
        node TNULL;
        value_compare _comp;
        // typedef value_compare (Compare c) : comp(c) {};
typedef typename Alloc::template rebind<Node<T> >::other node_allocator;        
        node_allocator alloc;
        const value_compare &value_comp() const
        {
            return (_comp);
        }
        value_compare &value_comp()
        {
            return (_comp);
        }
        RedBlackTree(){}
         
        // pair<iterator, bool> _insert_unique(const value_type &_val)
        // {
        //     node_ptr    _parent_pos = root();
        //     bool        _is_left = true;
        //     bool        _inserted;
            
        //     _inserted = _find_parent(_parent_pos, _val, _is_left);

        //     node_ptr    _new_n = _parent_pos;
        //     if (_inserted)
        //     {
        //         _new_n = _construct_node(_val);
        //         _insert_node_at(_parent_pos, _new_n, _is_left);
        //     }
        //     return (pair<iterator, bool>(iterator(_new_n), _inserted));
        // }
        void add(T d)
        {

            node newn = alloc.allocate(1);
            newn->data = d;
            newn->parent = nullptr;
            newn->left = TNULL;
            newn->right = TNULL;
            newn->color = 1;
            
            node y = nullptr;
            node x = this->root;

            while (x != TNULL)
            {
                y = x;
                if (newn->data.first < x->data.first)////
                {
                    x = x->left;
                }
                else
                {
                    x = x->right;
                }
            }
            newn->parent = y;
            if (y == nullptr)
            {
                root = newn;
                root->left = TNULL;
                root->right = TNULL;
            }
            else if (newn->data.first < y->data.first)////
            {
                y->left = newn;
            }
            else
            {
                y->right = newn;
            }

            if (newn->parent == nullptr)
            {
                newn->color = 0;
                return;
            }

            if (newn->parent->parent == nullptr)
            {
                
                return;
            }
            
            // tree_balance_after_insert(newn);
            fixViolation(newn);
        }
        void tree_balance_after_insert(node Node)
        {
            node u;
            while (Node->parent->color == 1) {
            if (Node->parent == Node->parent->parent->right) {
                u = Node->parent->parent->left;
                if (u->color == 1) {
                u->color = 0;
                Node->parent->color = 0;
                Node->parent->parent->color = 1;
                Node = Node->parent->parent;
                } else {
                if (Node == Node->parent->left) {
                    Node = Node->parent;
                    rightRotate(Node);
                }
                Node->parent->color = 0;
                Node->parent->parent->color = 1;
                leftRotate(Node->parent->parent);
                }
            } else {
                u = Node->parent->parent->right;

                if (u->color == 1) {
                u->color = 0;
                Node->parent->color = 0;
                Node->parent->parent->color = 1;
                Node = Node->parent->parent;
                } else {
                if (Node == Node->parent->right) {
                    Node = Node->parent;
                    leftRotate(Node);
                }
                Node->parent->color = 0;
                Node->parent->parent->color = 1;
                rightRotate(Node->parent->parent);
                }
            }
            if (Node == root) {
                break;
            }
            }
            root->color = 0;
        }
        void fixViolation(node z) 
        {
            node y = nullptr;
            while ((z->parent != nullptr) && (z->parent->color == 1)) 
            {
            if ( (z->parent->parent->left != nullptr) && (z->parent->data == z->parent->parent->left->data))
                {          
                    if(z->parent->parent->right!= nullptr)
                        y = z->parent->parent->right;
                    if ((y != nullptr) && (y->color == 1))
                    {
                        z->parent->color = 0;
                        y->color = 0;
                        z->parent->parent->color = 1;
                        if(z->parent->parent != nullptr)
                            z = z->parent->parent;
                    }
                    else 
                    {
                        if ((z->parent->right != nullptr) && (z->data == z->parent->right->data)) 
                        {          
                            z = z->parent;
                            leftRotate(z);
                        }
                        z->parent->color = 0;
                        z->parent->parent->color = 1;
                        rightRotate(z->parent->parent);
                    }
                }
                else 
                {
                    if(z->parent->parent->left!=nullptr)
                        y = z->parent->parent->left;
                    if ((y!=nullptr) && (y->color == 1)) 
                    {
                            z->parent->color = 0;
                        y->color = 0;
                        z->parent->parent->color = 1;
                        if(z->parent->parent!=nullptr)
                        z = z->parent->parent;
                    }
                    else 
                    {
                        if ((z->parent->left != nullptr) && (z->data == z->parent->left->data)) 
                        {          
                            z = z->parent;
                            rightRotate(z);
                        }
                        z->parent->color = 0;
                        z->parent->parent->color = 1;	
                        leftRotate(z->parent->parent);
                    }
                }
                
            }    
            root->color = 0;
        }
        void leftRotate(node x)
        {
            node y = x->right;
            x->right = y->left;
            if (y->left != TNULL) {
            y->left->parent = x;
            }
            y->parent = x->parent;
            if (x->parent == nullptr) {
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
            if (x->parent == nullptr) {
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
        
        node   min(node nd) throw()
        {
            while (nd->left != TNULL)
                nd = nd->left;
            return nd;
        }

        node max(node nd) throw()
        {
            while (nd->right != TNULL)
                nd = nd->right;
            return nd;
        }
        
        node next(node nd)
        {
            if (nd->right != nullptr)
                return (min(nd->right));
            while (!tree_is_left_child(nd))
                nd = nd->parent;
            return (nd->parent);
        }
       
        node prev(node nd)
        {
            if (nd->left != nullptr)
                return (max(nd->left));
            node ndt = nd;
            while (tree_is_left_child(ndt))
                ndt = ndt->parent;
            return (ndt->parent);
        }

        iterator begin()
        {
            return(iterator(min(root)));
        }
        // const_iterator begin() const
        // {
        //     return(const_iterator(min(root)));
        // }
        iterator end()
        {
            return(iterator(root->parent));
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
template<class node>
 inline bool tree_is_left_child(node nd)
{
    return(nd == nd->parent->left);
}
template <class node>
  inline node   min(node nd) throw()
        {
            while (nd->left != nullptr)
                nd = nd->left;
            return nd;
        }
template <class T> 
    inline T _tree_next(T _n)
    {
        if (_n->right != nullptr)
            return (min(_n->right));
        while (!tree_is_left_child(_n))
            _n = _n->parent;
        return (_n->parent);
    }

}
#endif