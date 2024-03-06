// Programmer: <Lincoln Steber>
// Student ID: <LGS6BV>
// Section: <102>
// Date: <12/12/2022>
// File: mybstree.h

#ifndef MYBSTREE_H
#define MYBSTREE_H

#include <iostream>
#include "abstractbstree.h"
using namespace std;

template <typename T>
class TreeNode {
public:
   T m_data;
   TreeNode* m_right;
   TreeNode* m_left;

   TreeNode() : m_right(NULL), m_left(NULL) {}
};

template <typename T>
class MyBSTree : public AbstractBSTree<T>
{
   TreeNode<T>* m_root;
   int m_size;

   void prettyPrint(const TreeNode<T>* t, int pad) const;
   void insertRec(TreeNode<T>*& t, const T& x);
   void clearRec(TreeNode<T>* t);
   TreeNode<T>* cloner(const TreeNode<T>* t);
   int heightRec(TreeNode<T>* t) const;
   void preRec(TreeNode<T>*& t) const;
   void postRec(TreeNode<T>*& t) const;
   void removeRec(TreeNode<T>*& t, const T& x);

public:
   ~MyBSTree();
   const MyBSTree<T>& operator=(const MyBSTree<T>& rhs);
   MyBSTree(const MyBSTree<T>& rhs);
   MyBSTree() 
   {
      m_root = NULL;
      m_size = 0;
   }
   void insert(const T& x);
   void print() const;
   int size() const;
   bool isEmpty() const;
   int height() const;
   void clear();
   const T& getMax() const throw (Oops);
   const T& getMin() const throw (Oops);
   int find(const T& x) const;
   void printPreOrder() const;
   void printPostOrder() const;
   void remove(const T& x);
};

#include "mybstree.hpp"
#endif 