Length of the longest subarray with positive product
Medium

Array, DP, Algorithms
Time : O(N)
Space : O(1)

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &arr,int n){
            int pos = 0, neg = 0, ans = 0;
            for (int i : arr) {
                if (i == 0) 
                    pos = 0, neg = 0;
                else {
                    if (i < 0) 
                        swap(pos, neg);
                    if (pos > 0 || i > 0) 
                        ++pos;
                    if (neg > 0 || i < 0) 
                        ++neg;
                    ans = max(ans, pos);
                }
            }
            return ans;
        }
}; 	