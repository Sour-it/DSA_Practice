953. Verifying an Alien Dictionary
Easy

Array, Hash Table, String
Time: O(n)
Space : O(1)

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<char> map(26);
    for (int i = 0; i < 26; ++i)
      map[order[i] - 'a'] = i + 'a';
    for (string& word : words)
      for (char& c : word)
        c = map[c - 'a'];
    return is_sorted(begin(words), end(words));
    }
};