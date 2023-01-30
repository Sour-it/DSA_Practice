Make array elements unique

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
         map<int, int> dict;
         set<int> used;
         for (int x = 0; x < N; x++) {
             int i = arr[x];
             if (dict[i] != 0)
                 dict[i]++;
             else {
                 dict[i] = 1;
                 used.insert(i);
            }
        }
        int maxUsed = 0;
        int ans = 0;
        for (auto entry : dict) {
            int value = entry.first;
            int freq = entry.second;
            if (freq <= 1)
                continue;
                int duplicates= freq- 1;
                int cur = max(value + 1, maxUsed);
                while (duplicates > 0) {
                    if (used.find(cur) == used.end()) {
                        ans += cur - value;
                        used.insert(cur);
                        duplicates--;
                        maxUsed = cur;
                    }
                    cur++;
                    
                }
            
        }
        return ans;
    }
};