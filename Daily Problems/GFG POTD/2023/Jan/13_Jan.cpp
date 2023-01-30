Count Lucky Permutations

class Solution {
  public:
    bool checkBit(int N, int pos){
        return N & (1<<pos);
    }

    long long int luckyPermutations (int N, int M, vector<int> arr, vector<vector<int>> graph) {
        
        vector<vector<long long int>>dp(N,vector<long long int>(1<<N,0)); 
        vector<vector<int>>edges(N, vector<int>(N,0));
        
        for (auto ele : graph){
            edges[ele[0]-1][ele[1]-1]=1;
            edges[ele[1]-1][ele[0]-1]=1;
        }
        
        for(int i=0; i<N; i++){
            dp[i][1<<i]=1;
        }
        
        for (int mask = 0; mask<(1<<N); mask++){
            for (int i=0;i<N; i++){
                for(int j=0; j<N; j++) {
                    if(i!=j and arr[i]!=arr[j] and checkBit (mask, j) and edges [arr[i]-1][arr[j]-1]){
                        dp[i][mask]+=dp[j][mask xor (1<<i)];
                        }
                    }
                }
            }
        long long int ans=0;
        
        for(int i = 0; i < N;i++){
            ans+=dp[i][(1<<N)-1];
        }
        return ans;
    }
};