Akku and Binary Numbers

class Solution{
public:
    void precompute()
    {
        // Code Here
    }
    
    long long solve(long long l, long long r){
        long long ans = 0;
        for(long long i = 1;i <= r;i *= 2){
            for(long long j = i*2;j <= r;j *= 2){
                for(long long k = j*2;k <= r;k *= 2){
                    long long temp = i|j|k;
                    if(temp >= l && temp <= r)
                        ans++;
                }
            }
        }
        return ans;
    }
    
};