Case-specific Sorting of Strings
Medium

String
Time : O(N)
class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n){
        vector<int> up(26,0),lr(26,0);
        for(int i=0;i<n;i++){
            if(str[i]>='A' && str[i]<='Z')
                up[str[i]-'A']++;
            else
                lr[str[i]-'a']++;
        }
        int j=0,k=0;
        for(int i=0;i<n;i++){
            if(str[i]>='A' && str[i]<='Z'){
                while(up[j]==0)
                    j++;
                str[i]=j+'A';
                up[j]--;
            }
            else{
                while(lr[k]==0)
                    k++;
                str[i]=k+'a';
                lr[k]--;
            }
        }
        return str;
    }
};