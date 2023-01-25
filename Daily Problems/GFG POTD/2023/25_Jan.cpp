Type it!
Easy
String, Greedy

Time : O(N)

class Solution {
  public:
    int minOperation(string s) {
        int size = s.length(), check = false, i = size-1, res = 0, idx = 0;
        while(i >= 0){
            res++;
            if(i%2 == 1){
                idx = i/2;
                if(!check && s.substr(0, idx + 1) == s.substr(idx+1,i-idx)){
                    check = true;
                    i = idx + 1;
                }
            }
            i--;
        }
        return res;
    }
};