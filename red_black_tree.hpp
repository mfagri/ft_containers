/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:56:15 by mfagri            #+#    #+#             */
/*   Updated: 2023/01/17 22:02:46 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE
#define RED_BLACK_TREE

#include <iostream>
#include "equal.hpp"
#include "red_black_iterator.hpp"

namespace ft
{
template<class T>
struct Node
{
    T data;
    Node *parent;
    Node *left;
    Node *right;
    int color;
    Node() {
        // data = data;
        parent = nullptr;
        left = nullptr;
        right = nullptr;
        color = 0;
  }
        
};

template <class Key, class T, class Compare, class Alloc>
class RedBlackTree {
    public:
        typedef Node<T>* node;
        typedef Compare value_compare;
        typedef Key key_type;
        typedef T mapped_type;
        typedef ft::pair<const key_type,mapped_type> value_type;
        typedef ft::red_black_iterator <value_type,node>  iterator;
        
        // typedef _Rb_tree_const_iterator<value_type> const_iterator;
    private:
        
        node root;
        node TNULL;
        value_compare _comp;
   
    public:
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
                if (value_comp()(newn->data,x->data))////
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
            }
            else if (value_comp()(newn->data,x->data))///
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
            tree_balance_after_insert(newn);
            std::cout<<"sdsdsdsd\n";
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
            return(min(root));
        }

        iterator end()
        {
            return(root->parent);
        }
};

}
#endif