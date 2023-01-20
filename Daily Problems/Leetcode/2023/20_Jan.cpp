491. Non-decreasing Subsequences
Time : O(n.2^n)
Space : O(n^2)

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        dfs(nums, 0, {}, ans);
        return ans;
    }
private:
  void dfs(const vector<int>& nums, int s, vector<int>&& path,
        vector<vector<int>>& ans) {
            if (path.size() > 1)
                ans.push_back(path);

            unordered_set<int> visited;
            for (int i = s; i < nums.size(); ++i) {
                if (visited.count(nums[i]))
                    continue;
                if (path.empty() || nums[i] >= path.back()) {
                    visited.insert(nums[i]);
                    path.push_back(nums[i]);
                    dfs(nums, i + 1, move(path), ans);
                    path.pop_back();
            }
        }
    }
};