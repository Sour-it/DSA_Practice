918. Maximum Sum Circular Subarray

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0, currMaxSum = 0, currMinSum = 0, maxSum = INT_MIN, minSum = INT_MAX;
        for (int a : nums) {
            totalSum += a;
            currMaxSum = max(currMaxSum + a, a);
            currMinSum = min(currMinSum + a, a);
            maxSum = max(maxSum, currMaxSum);
            minSum = min(minSum, currMinSum);
        }
        return maxSum < 0 ? maxSum : max(maxSum, totalSum - minSum);
    }
};