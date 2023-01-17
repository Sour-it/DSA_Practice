926. Flip String to Monotone Increasing

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        vector<int> dp(2);
        int temp = 0;
        for (int i = 0; i < s.length(); ++i) {
            temp = dp[0] + (s[i] == '1');
            dp[1] = min(dp[0], dp[1]) + (s[i] == '0');
            dp[0] = temp;
        }
        return min(dp[0], dp[1]);  
    }
};