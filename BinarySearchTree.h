#include <iostream>
#include "TreeNode.h"

using namespace std;

// Make into template class
template <class Tree>
class BinarySearchTree
{
public:
  BinarySearchTree();
  virtual ~BinarySearchTree();

// Key = value for this example
  void insert(int value);
  bool contains(int value);
  bool deleteNode(int value);
  bool deleteRec(int key); // -- recursive

  bool isEmpty();

  void printTree(); // iterative
  void recPrint(TreeNode* node); // in-order traversal -- recursive

  TreeNode* getSuccessor(TreeNode* d);

private:
  TreeNode* root;

};

template <class Tree>
BinarySearchTree<Tree>::BinarySearchTree()
{
  root = NULL;
}

template <class Tree>
virtual BinarySearchTree<Tree>::~BinarySearchTree()
{
  // iterate and delete
}

template <class Tree>
void BinarySearchTree<Tree>::printTree()
{
  recPrint(root);
}

template <class Tree>
void BinarySearchTree<Tree>::recPrint(TreeNode* node);
{
  if(node == NULL)
  {
    return;
  }

  recPrint(node->left);
  cout << node->data << endl;
  recPrint(node->right);
}

template <class Tree>
bool BinarySearchTree<Tree>::isEmpty()
{
  return(root == NULL);
}

template <class Tree>
void BinarySearchTree<Tree>::insert(int value)
{
// Check if dupliacte exists, if duplicates are not allowed

  TreeNode* node = new TreeNode(value);

  if(isEmpty())
  {
    root = node;
  }
  else // not an empty tree
  {
    TreeNode* current = root;
    TreeNode* parent; // empty node

    while(current != NULL)
    {
      parent = current;

      if(value < current->key) //we go left
      {
        current = current->left;

        if(current == NULL) // we found insertion point
        {
          parent->left = node;
          break;
        }
      }
      else // go right
      {
        current = current->right;

        if(current == NULL)
        {
          parent->right = node;
          break;
        }
      }
    }
  }
}

template <class Tree>
bool BinarySearchTree<Tree>::contains(int value)
{
  // If tree is empty, it does not contain the value
  if(isEmpty())
  {
    return false;
  }
  else // not an empty tree
  {
      TreeNode* current = root;

      while(current->key != value) // begin searching for value
      {
        if(current == NULL)
        {
          return false;
        }

        if(value < current->key) // go left
        {
          current = current->left;
        }
        else // go right
        {
          current = current->right;
        }
      }
  }

  return true;
}

template <class Tree>
bool BinarySearchTree<Tree>::deleteRec(int key)
{
  if(!contains(key)) // if value is not in tree
  {
    return false;
  }
  else // if value is in tree now go and delete it
  {
    TreeNode* parent = root;
    TreeNode* current = root;
    bool isLeft = true;

    // Now we need to find it
    while(current->key != key)
    {
      parent = current;

      if(k < current->key)
      {
        isLeft = true;
        current = current->left;
      }
      else
      {
        isLeft = false;
        current = current->right;
      }

      if(current == NULL)
      {
        return false;
      }
    }

    // Found the node that needs to be deleted

    // node had no children = leaf node
    if(current->left == NULL && current->right == NULL)
    {
      if(current = root)
      {
        root = NULL;
      }
      else if(isLeft)
      {
        parent->left = NULL;
      }
      else
      {
        parent->right = NULL;
      }
    }

    //check if node had one child
    else if(current->right == NULL) // no right child, but has left child
    {
      if(current = root)
      {
        root = current->left;
      }
      else if(isLeft)
      {
        parent->left = current->left;
      }
      else
      {
        parent->right = current->left;
      }
    }
    else if(current->left == NULL)
    {
      if(current = root)
      {
        root = current->right;
      }
      else if(isLeft)
      {
        parent->left = current->right;
      }
      else
      {
        parent->right = current->right;
      }
    }

    //check if node has 2 children
    else
    {
        TreeNode* successor = getSuccessor(current);

        if(current == root)
        {
          root = successor;
        }
        else if(isLeft)
        {
          parent->left = successor;
        }
        else
        {
          parent->right = successor;
        }

        successor->left = current->left;
    }

    return true;
  }
}

template <class Tree>
// d = node we are deleting
TreeNode* BinarySearchTree<Tree>::getSuccessor(TreeNode* d)
{
  TreeNode* sp = d; // successor's parent
  TreeNode* successor = d; // should be one right, all the way left
  TreeNode* current = d->right;

  while(current != NULL)
  {
    sp = successor;
    successor = current;
    current = current->left;
  }

  if(successor != d->right)
  {
    sp->left = successor->right;
    successor->right = d->right;
  }

  return successor;
}
