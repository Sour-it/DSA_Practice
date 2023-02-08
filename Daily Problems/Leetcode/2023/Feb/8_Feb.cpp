45. Jump Game II
Medium

Array, DP, Greedy
Time: O(n)
Space:O(1)

class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0,last = 0,distant = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            distant = max(distant, i + nums[i]);
            if (distant >= nums.size() - 1) {
                res++;
                break;
            }
            if (i == last) {
                res++;           
                last = distant;
            }
        }
        return res;
    }
};