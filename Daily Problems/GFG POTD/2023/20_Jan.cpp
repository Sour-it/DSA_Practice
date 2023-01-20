Maximum Weight Node

Time : O(n)

class Solution
{
  public:
  int maxWeightCell(int N, vector<int> Edge)
  {
      unordered_map<int,int> mp;
      for(int i = 0;i<N;i++){
          mp[Edge[i]] += i;
      }
      int maxm = 0, res = 0;
      for(auto it:mp){
          if(it.first != -1 && it.second >= maxm){
              maxm = it.second;
              res = it.first;
          }
      }
      return res;
  }
};