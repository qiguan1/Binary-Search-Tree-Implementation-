/*Name: Qihan Guan
 *Date: Jan 14, 2016
 *Assignment PA1
 *BSTNode definition file
*/
#ifndef BSTNODE_HPP
#define BSTNODE_HPP
#include <iostream>
#include <iomanip>

template<typename Data>
class BSTNode {

public:

  /** Constructor.  Initialize a BSTNode with the given Data item,
   *  no parent, and no children.
   */
  BSTNode(const Data & d) : data(d) {
    left = right = parent = 0;
  }

  BSTNode<Data>* left;
  BSTNode<Data>* right;
  BSTNode<Data>* parent;
  Data const data;   // the const Data in this node.

  /** Return the successor of this BSTNode in a BST, or 0 if none.
   ** PRECONDITION: this BSTNode is a node in a BST.
   ** POSTCONDITION:  the BST is unchanged.
   ** RETURNS: the BSTNode that is the successor of this BSTNode,
   ** or 0 if there is none.
  */
  BSTNode<Data>* successor(){
    BSTNode<Data>* node = this;
    if(node == NULL) return 0;
    //When the node has a right subtree
    if(node->right){
      BSTNode<Data>* ptr = node->right;
      while(ptr->left != NULL) ptr = ptr->left;
      return ptr;
    }
    //When the node does not have a right subtree
    if(node->right == NULL){
      BSTNode<Data>* temp1 = node;
      BSTNode<Data>* temp2 = node->parent;
      while(temp2 != NULL && temp1 == temp2->right){
        temp1 = temp2;
        temp2 = temp2->parent;
      }
      return temp2;
    }
    return 0;
  }

}; 

/** Overload operator<< to print a BSTNode's fields to an ostream. */
template <typename Data>
std::ostream & operator<<(std::ostream& stm, const BSTNode<Data> & n) {
  stm << '[';
  stm << std::setw(10) << &n;                 // address of the BSTNode
  stm << "; p:" << std::setw(10) << n.parent; // address of its parent
  stm << "; l:" << std::setw(10) << n.left;   // address of its left child
  stm << "; r:" << std::setw(10) << n.right;  // address of its right child
  stm << "; d:" << n.data;                    // its data field
  stm << ']';
  return stm;
}

#endif // BSTNODE_HPP
