// Programmer: <Lincoln Steber>
// Student ID: <LGS6BV>
// Section: <102>
// Date: <11/1/2022>
// File: hw2.cpp
// Purpose: 
#include <iostream>
using namespace std;

template <typename T>
std::ostream& operator<< (std::ostream& out, const LinkedList<T>& list)
{
  LLNode<T>* temp;
  temp = list.m_head;
  out << "[ ";
  for (int i=0; i < list.m_size; i++){
    out << temp ->m_data<< ", ";
    temp = temp->m_next;
  }
  out << "]";
  temp = NULL;
  return out;
  
}



template <typename T>
LinkedList<T>::~LinkedList()
{
  LLNode<T>* temp;
  while (m_head != NULL)
  {
    temp = m_head;
    m_head = temp->m_next;
    delete temp;
  }
}

// Purpose: performs a deep copy of the data from rhs into this linkedlist
// Parameters: rhs is linked list to be copied
// Returns: *this
// Postconditions: this list contains same data values (in the same order)
//     as are in rhs; any memory previously used by this list has been
//     deallocated.
template <typename T>
const LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs)
{
  this -> clear();
  m_head -> m_data = rhs.m_head -> m_data;
  LLNode<T>* temp = NULL;
  LLNode<T>* rp = rhs.m_head -> m_next;
  LLNode<T>* lp = m_head;
  while (rp -> m_next != NULL)
  {
    temp = new LLNode<T>;
    temp -> m_data = rp -> m_data;
    lp -> m_next = temp;
    lp = lp -> m_next;
    rp = rp -> m_next;
  }
  m_size = rhs.m_size;
  rp = NULL;
  lp = NULL;
  temp = NULL;
  return *this;
}

// Purpose: copy constructor
// Parameters: rhs is the LinkedList that is to be copied
// Postconditions: this list contains same data values (in same order) 
//      as in rhs.
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs)
{
  m_head = new LLNode<T>;
  m_head -> m_data = rhs.m_head -> m_data;
  LLNode<T>* temp = NULL;
  LLNode<T>* rp = rhs.m_head -> m_next;
  LLNode<T>* lp = m_head;
  while (rp -> m_next != NULL)
  {
    temp = new LLNode<T>;
    temp -> m_data = rp -> m_data;
    lp -> m_next = temp;
    lp = lp -> m_next;
    rp = rp -> m_next;
  }
  m_size = rhs.m_size;
  rp = NULL;
  lp = NULL;
  temp = NULL;
}



// -------------
// --------- Basic Accessor Operations ---
// -------------

// Purpose: accessor function to the size the list
// Returns: current size of the list
template <typename T>
int LinkedList<T>::size() const
{
  return m_size;
}

// Purpose: determines whether the list is empty
// Returns: 'true' if list is empty; 'false' otherwise
template <typename T>
bool LinkedList<T>::isEmpty() const
{
  if (m_size == 0)
  {
    {
      return true;
    }
  }
  return true;
}

// Purpose: Get a pointer to the first element node
// Returns: pointer to the first node in the list; 
//     returns NULL if the list is empty
template <typename T>
LLNode<T>* LinkedList<T>::getFirstPtr()
{
  if (m_size == 0)
  {
    {
      cout << "!!! ERROR : PANIC IN LINKED LIST !!! THE LIST IS EMPTY !!!" << endl;
      return NULL;
    }
  }
  return m_head;
}

// Purpose: accessor function for a node in the list
// Returns: pointer to the node at the i'th position in the list;
//          counting starts from '0' .
//     returns NULL if no such element exists.
template <typename T>
LLNode<T>* LinkedList<T>::getAtPtr(int i)
{
  if (m_size <= i || i < 0)
  {
    
    cout << " !!! ERROR : PANIC IN LINKED LIST !!! NODE DOES NOT EXIST !!!" << endl;
    return NULL;
  }
  LLNode<T>* findnode = m_head;
  for (int j = 0; j < i; j++)
  {
    findnode = findnode -> m_next;
  }
  return findnode;
}



// -------------
// --------- Basic Mutator Operations ---
// -------------

// Purpose: effectively "empties" the list, 
//          Turn the list into an empty list.
// Postconditions: dynamically allocated non-sentinel nodes 
//          are de-allicated.
//          m_size is set to zero.
//          m_head points to a sentinel node.
template <typename T>
void LinkedList<T>::clear()
{
  LLNode<T>* temp;
  while(m_head != NULL)
  {
    temp = m_head;
    m_head = temp->m_next;
    delete temp;
  }
  m_size = 0;
  m_head = new LLNode<T>;
}

// Purpose: insert element x in the front of the list 
// Parameters: x is data value to inserted
// Postconditions: x is the first element of the list
template <typename T>
void LinkedList<T>::insert_front(const T& x)
{
  LLNode<T>* temp = new LLNode<T>;
  temp -> m_data = x;
  temp -> m_next = m_head;
  m_head = temp;
  m_size += 1;
  temp = NULL;
}

// Purpose: insert element x in the back of the list 
// Parameters: x is data value to inserted
// Postconditions: x is the last element of the list
template <typename T>
void LinkedList<T>::insert_back(const T& x)
{
  LLNode<T>* temp = new LLNode<T>;
  LLNode<T>* findend = m_head;
  while (findend->m_next != NULL)
  {
    findend = findend -> m_next;
  }
  m_size += 1;
  findend -> m_next = temp;
  findend -> m_data = x;
  temp -> m_next = NULL;
  temp = NULL;
  findend = NULL;
}

// Purpose: puts the data value x at the position pointed by pos
// Parameters: x : data value to be inserted
//     pos : pointer to the position to insert x at.
// Preconditions: pos is a pointer to a node in this list.
// Postconditions: x is inserted at the position pointed by pos
template <typename T>
void LinkedList<T>::insert(const T& x, LLNode<T>* pos)
{
  LLNode<T>* temp = new LLNode<T>;
  temp -> m_data = pos -> m_data;
  temp -> m_next = pos -> m_next;
  pos -> m_next = temp;
  pos -> m_data = x;
  m_size += 1;
  temp = NULL;
}


  // Purpose: remove the element in the front of the list 
// Postconditions: the first element of the list is removed
template <typename T>
void LinkedList<T>::remove_front()
{
  LLNode<T>* temp;
  temp = m_head;
  m_head = m_head -> m_next;
  m_size -= 1;
  delete temp;
}

// Purpose: removes the element at the back of the list 
// Postconditions: the last element of the list is removed
template <typename T>
void LinkedList<T>::remove_back()
{
  LLNode<T>* front = m_head;
  LLNode<T>* temp = NULL;
  while (front -> m_next != NULL)
  {
    temp = front;
    front = front -> m_next;
  }
  temp -> m_next = NULL;
  delete front;
  front = NULL;
  temp = NULL;
  m_size -= 1; 
}

// Purpose: remove the element in the position pointed by pos
// Parameters: pos : pointer to the position to remove.
// Preconditions: pos is a pointer to a node in this list.
// Postconditions: element pointed by pos is removed from the list
template <typename T>
void LinkedList<T>::remove(LLNode<T>* pos)
{
  LLNode<T>* temp = pos -> m_next;
  pos -> m_next = temp ->m_next;
  pos -> m_data = temp -> m_data;
  m_size -= 1;
  delete temp;
}

// --------
// ---- Complex Operations ---
// --------

// Purpose: determines whether this list is identical to rhs list in
//      terms of data values and their order in the list
// Parameters: rhs is list to be compared to this list
// Returns: true if lists are identical; otherwise, false
template <typename T>
bool LinkedList<T>::operator== (const LinkedList<T>& rhs) const
{
  LLNode<T>* temp = m_head;
  LLNode<T>* rhstemp = rhs.m_head;
  if (m_size != rhs.m_size)
  {
    temp = NULL;
    rhstemp = NULL;
    return false;
  }
  while (temp -> m_next != NULL && rhstemp -> m_next != NULL)
  {
    if (temp -> m_data != rhstemp -> m_data)
    {
      temp = NULL;
      rhstemp = NULL;
      return false;
    }
    temp = temp -> m_next;
    rhstemp = rhstemp -> m_next;
  }
  temp = NULL;
  rhstemp = NULL;
  return true;
}

// Purpose: determines whether x is in the list
// Parameters: x : data value to be found
// Returns: a pointer to the position of x in the list; 
//     otherwise, NULL
template <typename T>
LLNode<T>* LinkedList<T>::find(const T& x)
{
  LLNode<T>* temp = m_head;
  while (temp -> m_next != NULL)
  {
    if (temp -> m_data == x)
    {
      return temp;
    }
    temp = temp -> m_next;
  }
  return NULL;
}

  // Purpose: reverses the elements from the list
// Postconditions: the list is now in reverse order
template <typename T>
void LinkedList<T>::reverse()
{
  LLNode<T>* cur= m_head;
  LLNode<T>* prev = NULL;
  LLNode<T>* next = NULL;
  while (cur != NULL)
  {
    next = cur -> m_next;
    cur -> m_next = prev;
    prev = cur;
    cur = next;
  }
  m_head = prev;
  cur = NULL;
  prev = NULL;
  next = NULL;
  LLNode<T>* first = m_head;
  LLNode<T>* last = m_head;
  while (last -> m_next != NULL)
  {
    last = last -> m_next;
  }
  m_head = first -> m_next;
  first -> m_next = NULL;
  last -> m_next = first;
  first = NULL;
  last = NULL;
}

// Purpose: appends two lists
// Parameters: l2, a list to append to the end of 'this' list
// Postconditions: elements of l2 are appended to 'this' list 
template <typename T>
void LinkedList<T>::append(const LinkedList<T>& l2)
{
  LLNode<T>* temp = l2.m_head;
  while (temp -> m_next != NULL)
  {
    this -> insert_back(temp -> m_data);
    temp = temp -> m_next;
  }
  temp = NULL;
}

// Purpose: Makes 'this' list a slice of another list.
// Parameters:    l2, the source of a slice of data.
//                start, pointer to the begining of the slice.
//                end, pointer to the end of the slice.
// Preconditions: 'start' and 'end' are pointers to nodes in the l2 list.
//                'start' precedes 'end' in the l2 list
// Postconditions: 'this' list is made a copy of the elements between 'start'
//                  and 'end' (*exclusive*) in l2.
template <typename T>
void LinkedList<T>::slice( const LinkedList<T>& l2, LLNode<T>* start, LLNode<T>* stop)
{
  while (start != stop)
  {
    this -> insert_back(start -> m_data);
    start = start -> m_next;
  }
  
}