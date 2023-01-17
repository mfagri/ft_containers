/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:56:15 by mfagri            #+#    #+#             */
/*   Updated: 2023/01/17 12:33:00 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE
#define RED_BLACK_TREE

#include <iostream>
#include "equal.hpp"
#include "red_black_iterator.hpp"

// template<typename _Tp>
//      struct _Rb_tree_iterator
//      {
//            typedef _Tp  value_type;
//        typedef _Tp& reference;
//        typedef _Tp* pointer;
 
//        typedef bidirectional_iterator_tag iterator_category;
//        typedef ptrdiff_t                  difference_type;
 
//        typedef _Rb_tree_iterator<_Tp>        _Self;
//        typedef _Rb_tree_node_base::_Base_ptr _Base_ptr;
//        typedef _Rb_tree_node<_Tp>*           _Link_type;
 
//        _Rb_tree_iterator() { }
 
//        _Rb_tree_iterator(_Link_type __x)
//        : _M_node(__x) { }
 
//        reference
//        operator*() const
//        { return static_cast<_Link_type>(_M_node)->_M_value_field; }
 
//        pointer
//        operator->() const
//        { return &static_cast<_Link_type>(_M_node)->_M_value_field; }
 
//        _Self&
//        operator++()
//        {
//          _M_node = _Rb_tree_increment(_M_node);
//      return *this;
//        }
 
//        _Self
//        operator++(int)
//        {
//          _Self __tmp = *this;
//      _M_node = _Rb_tree_increment(_M_node);
//      return __tmp;
//        }
 
//        _Self&
//        operator--()
//        {
//          _M_node = _Rb_tree_decrement(_M_node);
//      return *this;
//        }
 
//        _Self
//        operator--(int)
//        {
//          _Self __tmp = *this;
//      _M_node = _Rb_tree_decrement(_M_node);
//      return __tmp;
//        }
 
//        bool
//        operator==(const _Self& __x) const
//        { return _M_node == __x._M_node; }
 
//        bool
//        operator!=(const _Self& __x) const
//        { return _M_node != __x._M_node; }
 
//        _Base_ptr _M_node;
//    };
 
//    template<typename _Tp>
//      struct _Rb_tree_const_iterator
//      {
//            typedef _Tp        value_type;
//        typedef const _Tp& reference;
//        typedef const _Tp* pointer;
 
//        typedef _Rb_tree_iterator<_Tp> iterator;
 
//        typedef bidirectional_iterator_tag iterator_category;
//        typedef ptrdiff_t                  difference_type;
 
//        typedef _Rb_tree_const_iterator<_Tp>        _Self;
//        typedef _Rb_tree_node_base::_Const_Base_ptr _Base_ptr;
//        typedef const _Rb_tree_node<_Tp>*           _Link_type;
 
//        _Rb_tree_const_iterator() { }
 
//        _Rb_tree_const_iterator(_Link_type __x)
//        : _M_node(__x) { }
 
//        _Rb_tree_const_iterator(const iterator& __it)
//        : _M_node(__it._M_node) { }
 
//        reference
//        operator*() const
//        { return static_cast<_Link_type>(_M_node)->_M_value_field; }
 
//        pointer
//        operator->() const
//        { return &static_cast<_Link_type>(_M_node)->_M_value_field; }
 
//        _Self&
//        operator++()
//        {
//          _M_node = _Rb_tree_increment(_M_node);
//      return *this;
//        }
 
//        _Self
//        operator++(int)
//        {
//          _Self __tmp = *this;
//      _M_node = _Rb_tree_increment(_M_node);
//      return __tmp;
//        }
 
//        _Self&
//        operator--()
//        {
//          _M_node = _Rb_tree_decrement(_M_node);
//      return *this;
//        }
 
//        _Self
//        operator--(int)
//        {
//          _Self __tmp = *this;
//      _M_node = _Rb_tree_decrement(_M_node);
//      return __tmp;
//        }
 
//        bool
//        operator==(const _Self& __x) const
//        { return _M_node == __x._M_node; }
 
//        bool
//        operator!=(const _Self& __x) const
//        { return _M_node != __x._M_node; }
 
//        _Base_ptr _M_node;
//      };
 
//    template<typename _Val>
//      inline bool
//      operator==(const _Rb_tree_iterator<_Val>& __x,
//                 const _Rb_tree_const_iterator<_Val>& __y)
//      { return __x._M_node == __y._M_node; }
 
//    template<typename _Val>
//      inline bool
//      operator!=(const _Rb_tree_iterator<_Val>& __x,
//                 const _Rb_tree_const_iterator<_Val>& __y)
//      { return __x._M_node != __y._M_node; }
 
//    void
//    _Rb_tree_rotate_left(_Rb_tree_node_base* const __x,
//                         _Rb_tree_node_base*& __root);
 
//    void
//    _Rb_tree_rotate_right(_Rb_tree_node_base* const __x,
//                          _Rb_tree_node_base*& __root);
 
//    void
//    _Rb_tree_insert_and_rebalance(const bool __insert_left,
//                                  _Rb_tree_node_base* __x,
//                                  _Rb_tree_node_base* __p,
//                                  _Rb_tree_node_base& __header);
 
//    _Rb_tree_node_base*
//    _Rb_tree_rebalance_for_erase(_Rb_tree_node_base* const __z,
//                     _Rb_tree_node_base& __header);





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

template <class Key, class T, class Compare, class Alloc>
class RedBlackTree {
    public:
        typedef Node<T>* node;
        typedef Compare value_compare;
        typedef Key key_type;
        typedef T mapped_type;
        typedef ft::pair<const key_type,mapped_type> value_type;
        typedef red_balck_iterator <value_type,node>       iterator;
        // typedef _Rb_tree_const_iterator<value_type> const_iterator;
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
        
        bool tree_is_left_child(node nd)
        {
            return(nd == nd->parent->left)
        }
        
        bool tree_is_right_child(node nd)
        {
            return(nd == nd->parent->right)
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
};

#endif