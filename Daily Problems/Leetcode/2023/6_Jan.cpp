1833. Maximum Ice Cream Bars

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int ans = 0;
        for(int c : costs){
            if(coins >= c){
                ans++;
                coins -= c;
            } else {
                break;
            }
        }
        return ans;
    }
};