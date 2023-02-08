Count number of free cell
Easy

Hash,Matrix,Data Structure
Time: O(k)
Space: O(n+n+k)

class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
        vector<long long int> ans;
        vector<int> r(100010),c(100010);
        long long int temp = 0;
        int x=0,y=0;
        for(auto it : arr){
            r[it[0]]++;
            if(r[it[0]]==1)
                x++;
            c[it[1]]++;
            if(c[it[1]]==1)
                y++;
            temp=1ll*n*n-(1ll*n*(x+y)-(x*y));
            ans.push_back(temp);
        }
        return ans;
    }
};