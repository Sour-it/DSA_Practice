Scrambled String
Hard

String, DP, Tree
Time : O(N)

class Solution{
    public:
    unordered_map<string,bool>mp;
    bool isScramble(string S1, string S2){
        if(S1.compare(S2)==0) 
            return true;
        if(S1.size()<=1) 
            return false;
        string key;
        key=S1;
        key.push_back(' ');
        key.append(S2);
        if(mp.find(key)!=mp.end()) 
            return mp[key];
        int n=S1.size();
        bool flag=false;
        for(int i=1;i<n;i++){
            if((isScramble(S1.substr(0,i),S2.substr(0,i)) &&isScramble(S1.substr(i,n-i),S2.substr(i,n-i)))|| (isScramble(S1.substr(0,i),S2.substr(n-i,i))&& isScramble(S1.substr(i,n-i),S2.substr(0,n-i)))){
                flag=true;
                break;
            }
        }
        return mp[key]=flag;
    }    
};