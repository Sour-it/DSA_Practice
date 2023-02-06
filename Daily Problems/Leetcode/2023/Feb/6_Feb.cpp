1470. Shuffle the Array
Easy

Array, Math
Time: O(n)
Space : O(n)

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector <int> res(2*n,0);
        for(int i = 0, j = 0; i < n; i++, j+=2){
            res[j] = nums[i];
            res[j+1] = nums[i+n];
        }
        return res;
    }
};