//User function Template for C++
BST Downward Traversal
Easy

Tree, DP

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
public:
    long long int sumTree(Node *root,int dist){
        int ans = 0;
        if(root){
            if(dist==0)
                ans+=root->data;
                
            ans += sumTree( root->left, dist-1 );
            ans += sumTree( root->right, dist+1 );
            
            return ans;
        }else 
            return 0;
    }
    
    long long int verticallyDownBST(Node *root,int target){
        int suml,sumr;
        if(root){
            if(root->data == target)
                return sumTree(root->left,-1)+sumTree(root->right,+1);
            else{
                suml=verticallyDownBST(root->left, target);
                sumr=verticallyDownBST(root->right, target);
                return max(suml,sumr);
            }
        }
        return -1;
    }
};