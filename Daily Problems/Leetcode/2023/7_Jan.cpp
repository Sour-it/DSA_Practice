134. Gas Station

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const int gs = accumulate(begin(gas), end(gas), 0);
        const int cst = accumulate(begin(cost), end(cost), 0);
        if (gs - cst < 0)
            return -1;
        int ans = 0;
        int sum = 0;
        for (int i = 0; i < gas.size(); ++i) {
            sum += gas[i] - cost[i];
            if (sum < 0) {
                sum = 0;
                ans = i + 1;  
            }
        }
        return ans;
    }
};