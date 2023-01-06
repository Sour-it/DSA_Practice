520. Detect Capital

class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0;
        for (int i = 0; i < word.length(); i ++) {
            char c = word[i];
            if (c >= 'A' && c <= 'Z') {
                count ++;
            }
            if (!(count == 0 || (count == 1 && word[0] >= 'A' && word[0] <= 'Z') || count == i + 1)) {
               return false; 
            }
        }
        return true;
    }
};