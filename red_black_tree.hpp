/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:56:15 by mfagri            #+#    #+#             */
/*   Updated: 2023/02/28 20:47:48 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE
#define RED_BLACK_TREE

#include <iostream>
#include "equal.hpp"
#include "red_black_iterator.hpp"
#include "reverse_iterator.hpp"



template<class node>
bool tree_is_left_child(node nd)
{
        return(nd == nd->parent->left);
}
template<class node>
  node max(node nd)
        {
            node current = nd;
	
            while (current->right->right != NULL) 
                current = current->right;
            return (current);
        }
        template<class node>
        node prevs(node n)
        {
            if(n->left->left != NULL)
                return max(n->left);
            while (tree_is_left_child(n))
                n = n->parent;
            return n->parent;
           
        }
template<class node>
node    min(node x)
{
    node current = x;
    while (current->left->left != NULL) 
        current = current->left;
    return (current);
}
template<class node>
node suc(node nd)
        {
           if(nd->right->right != NULL)
		        return min(nd->right);
            while (!tree_is_left_child(nd))
                nd = nd->parent;
            
            return nd->parent;
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
        typedef T mapped_type;
        typedef Node<mapped_type>* node;
        typedef Key key_type;
        typedef Compare comp;
        typedef mapped_type value_type;
        typedef ft::red_black_iterator <value_type,node>  iterator;
        typedef ft::const_red_black_iterator <const value_type,node> const_iterator;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
        typedef typename Alloc::size_type       size_type;
        typedef typename Alloc::difference_type difference_type;
        
   
    public:
        comp _comp;
        node root;
        node TNULL;
        node endn;
        size_type m_size;
        typedef typename Alloc::template rebind<Node<T> >::other node_allocator;   ////rebind node   
        node_allocator alloc;
        void dea()
        {
            if(TNULL && endn)
            {
                alloc.destroy(TNULL);
                alloc.deallocate(TNULL, 1);
                alloc.destroy(endn);
                alloc.deallocate(endn, 1);       
            }
          
        }
        RedBlackTree(){
             m_size = 0;
            TNULL = alloc.allocate(1);
            TNULL->right = NULL;
            TNULL->left = NULL;
            TNULL->parent = NULL;
            TNULL->color = 0;
            root = TNULL;
            endn = alloc.allocate(1);
            endn->right = NULL;
            endn->left = root;   
            endn->parent = NULL;
            endn->color = 0;
        }
        ~RedBlackTree()
        {
            clear();
            if (endn && TNULL )
            {
                dea();
            }   
        }
        ////////////////////////////////    
        void destroy_allmy_tree(node n)///////name
        {
          if (n->left != this->TNULL )
            destroy_allmy_tree(n->left);
          if (n->right != this->TNULL  )
            destroy_allmy_tree(n->right);
          if (n != this->TNULL)
          {
            if (n != this->root && n == n->parent->right)
              n->parent->right = this->TNULL;
            if (n != this->root && n == n->parent->left)
              n->parent->left = this->TNULL;
            if (n == this->root)
              this->root = this->TNULL;
            this->alloc.destroy(n);
            this->alloc.deallocate(n, 1);
          }
        }
        void    clear()
        {
          if (this->root != this->TNULL)
            destroy_allmy_tree(this->root);
        }
        ///////////////////////////////////////
        pair<iterator, bool> add(const T& data)
        {
            node n = alloc.allocate(1);
            Node<T> tmp(data);
            alloc.construct(n, tmp);

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
                root->parent = endn;
                endn->left = root;

                return ft::make_pair(iterator(n), true);
            }
            else
            {
                node y = NULL;
                node x = root;

                while (x != TNULL)
                {
                    y = x;
                    if (!_comp(n->data, x->data) && !_comp(x->data,n->data))
                    {
                        alloc.deallocate(n,1);
                        return ft::make_pair(iterator(x), false);
                    }                       
                    if (_comp(n->data, x->data))
                    {
                        x = x->left;
                    }
                    else
                    {
                        x = x->right;
                    }
                }
                n->parent = y;
                if (_comp(n->data, y->data))
                {
                    y->left = n;
                }
                else
                {
                    y->right = n;
                }
            }

            m_size++;
            // std::cout << "=> " << n->data.second << std::endl;
            tree_balance(n);
            // std::cout << "============> " << n->data.second << std::endl;

            root->parent = endn;
                endn->left = root;
            return ft::make_pair(iterator(n), true);
        }
        void swap_colors(node &a , node&b)
        {
            int ca = a->color;
            int cb = b->color;
            a->color = cb;
            b->color = ca;
        }
        void tree_balance( node newn)
        {
            node u;
            while (newn->parent->color == 1)
            {
                if (newn->parent == newn->parent->parent->left)//case if parent is left child of grand parent
                {
                    u = newn->parent->parent->right;

                    if (u->color == 1) // if uncle color is red
                    {
                        u->color = 0;
                        swap_colors(newn->parent,newn->parent->parent);
                        newn = newn->parent->parent;
                    }
                    else
                    {
                        if(newn == newn->parent->right)//if new child is right child of parent , case 2
                        {
                            newn = newn->parent;
                            left_rotate(newn);
                        }
                        swap_colors(newn->parent,newn->parent->parent);
                        right_rotate(newn->parent->parent);
                    }
                }
                else//case if parent is right child of grand parent
                {
                    u = newn->parent->parent->left;
                    if (u->color == 1)// if uncle color is red
                    {
                        u->color = 0;
                        swap_colors(newn->parent,newn->parent->parent);
                        newn = newn->parent->parent;
                    } 
                    else
                    {
                        if (newn == newn->parent->left)//if new child is left child of parent , case 4
                        {
                            newn = newn->parent;
                            right_rotate(newn);
                        }
                        swap_colors(newn->parent,newn->parent->parent);
                        left_rotate(newn->parent->parent);
                    }
                }
                if (newn == root) {
                    break;
                }
            }
            root->color = 0;
        }
        node search_in_tree(node n, value_type key) const {
            if (n == endn || n == TNULL || (!_comp(n->data, key) && !_comp(key,n->data)))
            {
                if(n == TNULL)
                {
                    return endn;
                }
                return n;
            }
            if (!_comp(n->data, key))
            {
                return search_in_tree(n->left, key);
            }
            return search_in_tree(n->right, key);
        }
        node find(value_type k) const
        {
            return search_in_tree(this->root, k);
        }
        void left_rotate(node x)
        {
            node y = x->right;
            x->right = y->left;
            if (y->left != TNULL)
            {
                y->left->parent = x;
            }
            y->parent = x->parent;
            if (x->parent == endn)
            {
                this->root = y;
            } else if (x == x->parent->left)
            {
            x->parent->left = y;
            } else {
            x->parent->right = y;
            }
            y->left = x;
            x->parent = y;
        }

        void right_rotate(node x)
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
            while (x && x->left != NULL && x->left->left!= NULL)
            {
                x = x->left;
            }
            if(x->left == NULL && x->right == NULL)
                return endn;
            return (x);
        }
        bool empty()const
        {
            return m_size == 0;
        }
        iterator begin()
        {
            return(iterator(min(root)));
        }

        const_iterator begin() const
        {
            return(const_iterator(min(root)));
        }
        iterator end()
        {     
            return(iterator(endn));
        }
        const_iterator end() const
        {
            return(const_iterator(endn));
        }
        reverse_iterator rbegin()
        {
            return reverse_iterator((this->end()));
        }
        const_reverse_iterator rbegin() const
        {
            return const_reverse_iterator(this->end());
        }
        reverse_iterator rend()
        {
            return reverse_iterator((this->begin()));
        }
        const_reverse_iterator rend() const
        {
            return const_reverse_iterator(this->begin());
        }
        //////////////////////////////////////////////
        size_type count(const value_type &k) const
        {
            if(find(k) == endn)
                return 0;
            return 1;   
        }
        ///////////////////////////////////////////
    iterator	lower_bound(const value_type & k) const
    {
        iterator it(min(root));
        node i;
    
        i = min(root);
        while(_comp(i->data, k) && i != endn)
            i = suc(i);
        return (i);
    }

    iterator upper_bound(const value_type & k) const
    {
        node i;

        i = min(root);
        while(_comp(i->data, k) && i != endn)
          i = suc(i);
        if (!_comp(k, i->data) && i != endn)
          i = suc(i);
        return (i);
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
    // void swap (RedBlackTree& x)
    // {
    //     std::swap(*this,x);
    // }
    ///////////////////////////////////////////////////////////////////
    //////////////////////////////
    void delete_fix(node x) {
    node s;
    while (x != root && x->color == 0)
    {
      if (x == x->parent->left) //for left side 
      {
        s = x->parent->right;//s is brother of x is the sibling
        if (s->color == 1)//case 1 if sibling is red
        {
          s->color = 0;
          x->parent->color = 1;
          left_rotate(x->parent);
          s = x->parent->right;
        }

        if (s->left->color == 0 && s->right->color == 0)//case 2 if sibling left is black and sibling rigt is black
        {
          s->color = 1;
          x = x->parent;
        }
        else
        {
          if (s->right->color == 0)//case 3 if sibling right is black
          {
            s->left->color = 0;
            s->color = 1;
            right_rotate(s);
            s = x->parent->right;
          }
          //case 4 sibling black && sibling right is red
          s->color = x->parent->color;
          x->parent->color = 0;
          s->right->color = 0;
          left_rotate(x->parent);
          x = root;
        }
      }
      else//right side
      {
        s = x->parent->left;
        if (s->color == 1)
        {
          s->color = 0;
          x->parent->color = 1;
          right_rotate(x->parent);
          s = x->parent->left;
        }

        if (s->right->color == 0 && s->right->color == 0) {
          s->color = 1;
          x = x->parent;
        }
        else
        {
          if (s->left->color == 0)
          {
            s->right->color = 0;
            s->color = 1;
            left_rotate(s);
            s = x->parent->left;
          }

          s->color = x->parent->color;
          x->parent->color = 0;
          s->left->color = 0;
          right_rotate(x->parent);
          x = root;
        }
      }
    }
    x->color = 0;
    }
    void ft_transplant(node u, node v)
    {
        if (u->parent == endn)//if u is the root
            root = v;
        else if (u == u->parent->left)// if u is left child of parent
            u->parent->left = v;
        else //if u is right child of parent 
            u->parent->right = v;
        v->parent = u->parent;
    }
    void delete_my_node(const value_type &k)
    {
        node z = TNULL;
        node x, y;
        z = find(k);
        if (z == endn)
        {
          return;
        }
        m_size--;
        y = z;
        int y_original_color = y->color;
        if (z->left == TNULL)//left child is nil
        {
          x = z->right;
          ft_transplant(z, z->right);
        }
        else if (z->right == TNULL)//right child is nil
        {
          x = z->left;
          ft_transplant(z, z->left);
        }
        else
        {
          y = max(z->left);//in order predecessor
          y_original_color = y->color;
          x = y->left;
          if (y->parent == z)
          {
            x->parent = y;
          }
          else
          {
            ft_transplant(y, y->left);
            y->left = z->left;
            y->left->parent = y;
          }
    
          ft_transplant(z, y);
          y->right = z->right;
          y->right->parent = y;
          y->color = z->color;
        }   
        alloc.destroy(z);
        alloc.deallocate(z,1);
        if (y_original_color == 0)
        {
            delete_fix(x);
        }
    }

    
    void ft_delete(const value_type&data)
    {
      delete_my_node(data);
      root->parent = endn;
      endn->left = root;
    }
    ////////////////
    void printTree() {
    if (root) {
      printHelper(this->root, "", true);
    }
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
      std::cout << root->data.first << "(" << sColor << ")" << std::endl;
      printHelper(root->left, indent, false);
      printHelper(root->right, indent, true);
    }
  }
};
}
#endif