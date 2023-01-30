Find the maximum GCD of the siblings of a Binary Tree

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */


class Solution
{
public:
    int temp = 0,ans = 0, gcd = 0;
    void preorder(Node* root){
        if(root == NULL)
            return;
        if(root->left && root->right){
            temp = __gcd(root->left->data, root->right->data);
            if(temp > gcd){
                ans = root->data;
                gcd = temp;
            }else if(temp == gcd){
                ans = max(ans,root->data);
            }
        }
        preorder(root->left);
        preorder(root->right);
    }
    int maxGCD( Node* root)
    {
        if(root == NULL)
            return -1;
        preorder(root);
        return ans;
    }
};