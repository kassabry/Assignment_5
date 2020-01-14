#include <iostream>

using namespace std;

// Make class into template class
template <class Tree>
class TreeNode
{
public:
  TreeNode();
  TreeNode(int key);
  virtual ~TreeNode();

  int key;
  TreeNode* left;
  TreeNode* right;
};

template<class Tree>
TreeNode<Tree>::TreeNode()
{
  left = NULL; // Null pointer
  right = NULL; // Null pointer
}

template <class Tree>
TreeNode::TreeNode(int k)
{
  left = NULL;
  right = NULL;
  key = k;
}

virtual TreeNode::~TreeNode()
{

}
