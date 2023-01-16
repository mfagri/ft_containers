/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:56:15 by mfagri            #+#    #+#             */
/*   Updated: 2023/01/16 18:55:16 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE
#define RED_BLACK_TREE

#include <iostream>

template<class T>
struct Node
{
    T data;
    Node *parent;
    Node *left;
    Node *right;
    int color;
    Node() {
        data = data;
        parent = nullptr;
        left = nullptr;
        right = nullptr;
        color = 0;
  }
        
};

template <class T, class Compare, class Alloc>
class RedBlackTree {
    public:
        typedef Node<T>* node;
        typedef Compare value_compare;
    private:
        Alloc _alloc;
        node root;
        node TNULL;
        value_compare _comp;

    public:
        typedef value_compare (Compare c) : comp(c) {};
        RedBlackTree()
        {
            _alloc = Alloc;
            root = nullptr;
            TNULL = nullptr;
        }
        void add(T d)
        {
            node newn = _alloc.allocate(1);
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
                if (!value_comp()(y->data,x->data))////
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
            else if (!value_comp()(newn->data,x->data))///
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
        }
        tree_balance_after_insert(node Node)
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
        void next(node t)
        {
            t
        }
};

#endif