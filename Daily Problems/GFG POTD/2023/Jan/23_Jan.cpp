Geeks And The String
Medium
String

Time : O(n)

class Solution {
  public:
    string removePair(string s) {
        int i = 0;
        while(i < s.size()){
            if(s[i] == s[i+1]){
                s.erase(i,2);
                i =0 ;
            }else
                i++;
        }
        if(s.size() == 0)
            s ="-1";
        return s;
    }
};