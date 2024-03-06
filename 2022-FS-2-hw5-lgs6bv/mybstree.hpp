// Programmer: <Lincoln Steber>
// Student ID: <LGS6BV>
// Section: <102>
// Date: <12/12/2022>
// File: mybstree.hpp

#include <iostream>
#include <string>

template <typename T>
MyBSTree<T>:: ~MyBSTree()
{
  this -> clear();
}

template <typename T>
const MyBSTree<T>& MyBSTree<T>::operator=(const MyBSTree<T>& rhs)
{
  this -> clear();
  TreeNode<T>* clone = rhs.m_root;
  this -> cloner(clone);
  m_size = rhs.m_size;
  return *this;
}

template <typename T>
MyBSTree<T>::MyBSTree(const MyBSTree<T>& rhs)
{
  TreeNode<T>* clone = rhs.m_root;
  this->cloner(clone);
}



template <typename T>
void MyBSTree<T>::insert(const T& x)
{
  TreeNode<T>* temp = m_root;
  insertRec(temp, x);
}



template <typename T>
void MyBSTree<T>::print() const
{
    TreeNode<T>* temp = m_root;
    prettyPrint(temp, 0);
}

template <typename T>
int MyBSTree<T>::size() const
{
  return m_size;
}

template <typename T>
bool MyBSTree<T>::isEmpty() const
{
  if (m_size == 0)
  {
    return true;
  }
  return false;
}

template <typename T>
int MyBSTree<T>::height() const
{
  if (m_size == 0)
  {
    TreeNode<T>* temp = NULL;
    return heightRec(temp);
  }
  TreeNode<T>* temp = m_root;
  return heightRec(temp);
}

template <typename T>
void MyBSTree<T>::clear()
{
  if(m_root != NULL)
  {
    TreeNode<T>* temp = m_root;
    clearRec(temp);
  }
}

template <typename T>
const T& MyBSTree<T>::getMax() const throw(Oops)
{
  if(m_size != 0)
  {
    TreeNode<T>* temp = m_root;
    while (temp -> m_right != NULL)
    {
      temp = temp -> m_right;
    }
    return temp -> m_data;
  }
  throw Oops("OOPS! : Tree is Empty!!");
}

template <typename T>
const T& MyBSTree<T>::getMin() const throw(Oops)
{
  if(m_size != 0)
  {
    TreeNode<T>* temp = m_root;
    while (temp -> m_left != NULL)
    {
      temp = temp -> m_left;
    }
    return temp -> m_data;
  }
  throw Oops("OOPS! : Tree is Empty!!");
}

template <typename T>
int MyBSTree<T>::find(const T& x) const
{
  TreeNode<T>* temp = m_root;
  int val = 1;
  while (temp != NULL)
  {
    if (x > temp -> m_data)
    {
      temp = temp -> m_right;
    }
    else if (x < temp -> m_data)
    {
      temp = temp -> m_left;
    }
    else
    {
      temp = NULL;
      return val;
    }
    val += 1;
  }
  temp = NULL;
  return -val;
}

template <typename T>
void MyBSTree<T>::printPreOrder() const
{
  if (m_root != NULL)
  {
    TreeNode<T>* temp = m_root;
    preRec(temp);
  }
}

template <typename T>
void MyBSTree<T>::printPostOrder() const
{
  if (m_root != NULL)
  {
    TreeNode<T>* temp = m_root;
    postRec(temp);
  }
}

template <typename T>
void MyBSTree<T>::remove(const T& x)
{
  TreeNode<T>* temp = m_root;
  removeRec(temp, x);
}


template <typename T>
void MyBSTree<T>::prettyPrint(const TreeNode<T>* t, int pad) const
{
  string s(pad, ' ');
  if (t == NULL)
    cout << endl;
  else{
    prettyPrint(t->m_right, pad+4);
    cout << s << t->m_data << endl;
    prettyPrint(t->m_left, pad+4);
  }
}

template <typename T>
void MyBSTree<T>::insertRec(TreeNode<T>*& t, const T& x)
{
  if (m_size == 0)
  {
    t = new TreeNode<T>;
    t -> m_data = x;
    t -> m_left = NULL;
    t -> m_right = NULL;
    m_root = t;
    m_size++;
  }
  else if (t == NULL)
  {
    t = new TreeNode<T>;
    t -> m_data = x;
    t -> m_left = NULL;
    t -> m_right = NULL;
    m_size++;
  }
  else if (x < t -> m_data)
  {
    insertRec(t -> m_left, x);
  }
  else if (x > t -> m_data)
  {
    insertRec(t -> m_right, x);
  }
}

template <typename T>
void MyBSTree<T>::clearRec(TreeNode<T>* t)
{
  if (t -> m_left != NULL)
  {
    clearRec(t -> m_left);
  } 
  if (t -> m_right != NULL)
  {
    clearRec(t -> m_right);
  } 
}

template <typename T>
TreeNode<T>* MyBSTree<T>::cloner(const TreeNode<T>* t)
{
  if(t != NULL)
  {
    TreeNode<T>* temp = new TreeNode<T>;
    if (m_root == NULL)
    {
      m_root = temp;
    }
    temp -> m_data = t -> m_data;
    if (t -> m_left != NULL)
    {
      temp -> m_left = cloner(t -> m_left);
    }
    if (t -> m_right != NULL)
    {
      temp -> m_right = cloner(t -> m_right);
    }
    return temp;
  }
  return NULL;
}

template <typename T>
int MyBSTree<T>::heightRec(TreeNode<T>* t) const
{
  if (t != NULL)
  {
    int left = heightRec(t -> m_left);
    int right = heightRec(t -> m_right);
    if (left > right)
    {
      return left + 1;
    }
    return right + 1;
  } 
  return NULL;
}

template <typename T>
void MyBSTree<T>::preRec(TreeNode<T>*& t) const
{
  cout << t -> m_data << " ";
  if (t -> m_left != NULL)
  {
    preRec(t -> m_left);
  }
  if (t -> m_right != NULL)
  {
    preRec(t -> m_right);
  }
}

template <typename T>
void MyBSTree<T>::postRec(TreeNode<T>*& t) const
{
  if (t -> m_left != NULL)
  {
    postRec(t -> m_left);
  }
  if (t -> m_right != NULL)
  {
    postRec(t -> m_right);
  }
  cout << t -> m_data << " ";
}

template <typename T>
void MyBSTree<T>::removeRec(TreeNode<T>*& t, const T& x)
{

}