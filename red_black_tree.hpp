/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:56:15 by mfagri            #+#    #+#             */
/*   Updated: 2023/01/13 18:45:30 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE
#define RED_BLACK_TREE

template<class T>
struct Node
{
    T data;
    Node *parent;
    Node *left;
    Node *right;
    int color;
    
        
};

template <class T, class Alloc = std::allocator<T> >
class RedBlackTree {
    public:
        typedef Node<T>* node;
    private:
        Alloc _alloc;
        node root;
        node TNULL;
    public:
        RedBlackTree()
        {
            _alloc = Alloc;
            root = nullptr;
            TNULL = nullptr;
        }
        void rotateLeft(node *&, node *&);
        void rotateRight(node *&, node *&);
        void fixViolation(node *&, node *&);
};

#endif