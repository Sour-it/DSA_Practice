Select Nodes
Hard
Graph, Recursion, DP

Time: O(N)
Space : O(N)

class Solution{
  public:
    int countVertex(int N, vector<vector<int>>edges){
        
        vector<int> gp[N+1];
        
        for(vector<int> e : edges) {
            gp[e[0]].push_back(e[1]);
            gp[e[1]].push_back(e[0]);
        }
        
        vector<vector<int>> dp(N+1,vector<int>(2,-1));
        vector<vector<int>> dp1(N+1,vector<int>(2,-1));
        
        return min(find(gp,1,0,-1,dp),find(gp,1,1,-1,dp1)+1);
    }
        
    int find(vector<int> gp[],int src,int isLighted,int visited,vector<vector<int>>& dp) {
        
        if(dp[src][isLighted]!=-1) 
            return dp[src][isLighted];
            
        int ans=0;
        
        for(int it : gp[src]) {
            if(it!=visited) {
                if(isLighted==0) {
                    int find1= find(gp,it,1,src,dp);
                    ans+=find1+1;
                } else {
                    int find0 = find(gp,it,0,src,dp);
                    int find1 = find(gp,it,1,src,dp);
                    ans+=min(find0,find1+1);
                }
            }
        }
        return dp[src][isLighted]=ans;
    }
};