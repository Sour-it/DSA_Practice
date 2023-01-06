Largest subtree sum in a tree

class Solution {
  public:
    // Function to find largest subtree sum.
    int findLargestSubtreeSumutil(Node* root, int& ans){
        if (root == NULL)
            return 0;
         int cur_sum = root->data+findLargestSubtreeSumutil(root->left, ans) + findLargestSubtreeSumutil(root->right, ans);
         ans = max(cur_sum,ans);
         return cur_sum;
    }
    int findLargestSubtreeSum(Node* root)
    {
        if (root == NULL)
            return 0;
        int ans = INT_MIN;
        findLargestSubtreeSumutil(root, ans);
        return ans;
        
    }
};