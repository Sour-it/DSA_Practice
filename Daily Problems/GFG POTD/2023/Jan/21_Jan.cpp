Minimum X (xor) A
Time : O(1)

class Solution {
  public:
    int minVal(int a, int b) {
        int X = 0, count = __builtin_popcount(b);
        for(int i = 31; i >= 0; i--){
            
            if((1<<i) & a){
                if(count > 0){
                    count--;
                    X |= (1<<i);
                }
            }else{
                if(i < count){
                    X |= (1<<i);
                    count--;
                }
            }
        }
        return X;
    }
};