Transform to Sum Tree

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int toSumTree(Node *node)
    {
        if (node == NULL)
            return 0;
        int prev = node->data;
        node->data = toSumTree(node->left) + toSumTree(node->right);
        return node->data + prev;
    }
};