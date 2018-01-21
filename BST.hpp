/*Name: Qihan Guan
 *Date: Jan 14, 2016
 *Assignment PA1
 *BST definition file
*/
#ifndef BST_HPP
#define BST_HPP
#include "BSTNode.hpp"
#include "BSTIterator.hpp"
#include <iostream>

template<typename Data>
class BST {

protected:

  /** Pointer to the root of this BST, or 0 if the BST is empty */
  BSTNode<Data>* root;

  /** Number of Data items stored in this BST. */
  unsigned int isize;

  /** Height of this BST. */
  unsigned int iheight;
  
public:

  /** define iterator as an aliased typename for BSTIterator<Data>. */
  typedef BSTIterator<Data> iterator;

  /** Default constructor.
      Initialize an empty BST.
   */
  BST() : root(0), isize(0), iheight(0) {  }


  /** Default destructor.
      Delete every node in this BST.
   */ 
  virtual ~BST() {
    deleteAll(root);
  }

  /** Given a reference to a Data item, insert a copy of it in this BST.
   *  Return  true if the item was added to this BST
   *  as a result of this call to insert,
   *  false if an item equal to this one was already in this BST.
   *  Note: This function should use only the '<' or "==" operator when comparing
   *  Data items. (should not use >, <=, >=)
   */
    virtual bool insert(const Data & item) {
    BSTNode<Data> * newnode = new BSTNode<Data>(item);
    BSTNode<Data>* ptr  = root;
    BSTNode<Data>* temp = root;
    if(root == NULL){
      root = newnode;
      isize++;
      return true;
    }
    unsigned int tempHeight = 0;
    while(ptr != NULL){
      if(ptr->data == item) return false;
      else if(ptr->data > item){
        temp = ptr;
        ptr = ptr->left;
        tempHeight++;
      }
      else{
        temp = ptr;
        ptr = ptr->right;
        tempHeight++;
      }
    }
    if(temp->data > item) temp->left = newnode;
    else temp->right = newnode;
    newnode->parent = temp;
    isize++;
    if(iheight < tempHeight) iheight = tempHeight;
    return true;   
  }
  

  /** Find a Data item in the BST.
    Return an iterator pointing to the item, or pointing past
   *  the last node in the BST if not found.
   *  Note: This function should use only the '<' or "==" operator when comparing
   *  Data items. (should not use >, <=, >=)
   */ 
  iterator find(const Data& item) const {
    if(empty()) return end();
    BSTNode<Data> *ptr = root;
    while(ptr != NULL){
      if(ptr->data == item) return typename BST<Data>::iterator(ptr); 
      if(ptr->data > item)  ptr = ptr->left;
      else if(ptr->data < item)  ptr = ptr->right;
    }
    return end();
  }

  
  /** Return the number of items currently in the BST.
   */
  unsigned int size() const {
    return isize;
  }
  
  /** Return the height of the BST.
   */ 
  unsigned int height() const {
    return iheight;
  }


  /** Return true if the BST is empty, else false.
   */
  bool empty() const {
    if(root == NULL) return true;
    else return false;
  }

  /** Return an iterator pointing to the first item in the BST (not the root).
   */ 
  iterator begin() const {
    return typename BST<Data>::iterator(first(root));
  }

  /** Return an iterator pointing past the last item in the BST.
   */
  iterator end() const {
    return typename BST<Data>::iterator(0);
  }

  /** Perform an inorder traversal of this BST.
   */
  void inorder() const {
    inorder(root);
  }


private:

  /** Recursive inorder traversal 'helper' function */

  /** Inorder traverse BST, print out the data of each node in ascending order.
      Implementing inorder and deleteAll base on the pseudo code is an easy way to get started.
   */
  void inorder(BSTNode<Data>* n) const {
    if(n == NULL) return;
    inorder(n->left);
    std::cout << (n->data);
    inorder(n->right);
    /* Pseudo Code:
      if current node is null: return;
      recursively traverse left sub-tree
      print current node data
      recursively traverse right sub-tree
    */
  }

  /** Find the first element of the BST
   */ 
  static BSTNode<Data>* first(BSTNode<Data>* root) {
    if(root == 0) return 0;
    while(root->left != 0) root = root->left;
    return root;
  }

  /** do a postorder traversal, deleting nodes
   */ 
  static void deleteAll(BSTNode<Data>* n) {
    if(n == NULL) return;
    deleteAll(n->left);
    deleteAll(n->right);
    delete n;
    /* Pseudo Code:
      if current node is null: return;
      recursively delete left sub-tree
      recursively delete right sub-tree
      delete current node
    */
  }


 };


#endif //BST_HPP
