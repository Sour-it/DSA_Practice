974. Subarray Sums Divisible by K

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0, init = 0;
        vector<int> cnt(k);
        cnt[0] = 1;
        for (int a : nums) {
        init = (init + a % k + k) % k;
        ans += cnt[init];
        ++cnt[init];
        }
        return ans;
    }
};