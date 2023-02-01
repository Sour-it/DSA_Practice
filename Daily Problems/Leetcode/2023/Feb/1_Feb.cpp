1071. Greatest Common Divisor of Strings
Easy

Math, String
Time : O(SH)
Space: O(SH)

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1.size() < str2.size()) 
            return gcdOfStrings(str2, str1);
        if (str2.empty()) 
            return str1;
        auto res = str1.substr(0, str2.size());
        return res == str2 ? gcdOfStrings(str1.substr(str2.size()), str2) : "";
    }
};