Total Decoding Messages
Medium

String, DP, Array
Time : O(N)
Space : O(N)

class Solution {
	public:
		int CountWays(string str){
		    int modulo = 1e9 + 7, N = str.size(), dp[N + 2] = {0};
		    dp[0] = 1;
		    dp[1] = 1;
		    for(int i = 2; i <= N; i++) {
		        if(str[i - 1] != '0') 
		            dp[i] = dp[i - 1];
		        if((str[i - 2] == '1') || (str[i - 2] == '2' && str[i - 1] <= '6'))
		            dp[i] = (dp[i] + dp[i - 2]) % modulo;
		    }
		    return dp[N];
		}
};