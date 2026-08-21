class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        unordered_set<char> ch;
        int l = 0;
        int r = 0;
        int maxLen = 1;
        while (r < s.size()) {
            while(ch.count(s[r])) {
                ch.erase(s[l]);
                l++;
            }
            ch.insert(s[r]);
            r++;
            maxLen = max(maxLen, r - l);
        }
        return maxLen;
    }
};
