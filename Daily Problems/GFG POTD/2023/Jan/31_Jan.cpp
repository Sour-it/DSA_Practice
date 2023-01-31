Minimum times A has to be repeated such that B is a substring of it
Medium

String, Substring
Time : O(|B|)
Space : O(1)

class Solution {
  public:
    int minRepeats(string A, string B) {
        int i,j,res = 1;
        string str = A;
        while(A.find(B) == string::npos && A.length() <= B.length()){
            A += str;
            res++;
        }
        if(A.find(B) == string::npos)
            return -1;
        return res;
    } 
};