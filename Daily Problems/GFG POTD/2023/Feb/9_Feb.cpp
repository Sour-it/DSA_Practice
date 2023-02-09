Maximum Bipartite Matching
Medium

Graph, BFS
Time: O(n^2)
Space: O(n)

class Solution {
public:
    vector<int> Matched;
    vector<int> visited;
    bool findMatch(int pos, vector<vector<int>> &g){
        for(int j=0;j<g[0].size();j++){
            if(g[pos][j] && !visited[j]){
                visited[j]=1;
                if(Matched[j]==-1 || findMatch(Matched[j],g)){
                    Matched[j]=pos;
                    return true;
                }
            }
        }
        return false;
    }
    
	int maximumMatch(vector<vector<int>>&G){
        int job=G[0].size(),res = 0;
        Matched=vector<int>(job,-1);
        for(int i=0;i<G.size();i++){
            visited=vector<int>(job,0);
            if(findMatch(i,G))  
                res++;
        }
        return res;
	}

};