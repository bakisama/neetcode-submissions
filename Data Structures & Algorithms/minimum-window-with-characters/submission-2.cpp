class Solution {
   public:
    string minWindow(string s, string t) {
        string ans;
        if(s.size()<t.size()) return ans;
        int window = INT_MAX;
        int l = 0;
        int r = 0;
        int start = 0;
        
        unordered_map<char, int> mp1;
        for (auto x : t) mp1[x]++;
        int needCount = mp1.size();
        int haveCount = 0;
        unordered_map<char, int> mp2;
        while (r < s.size()) {
            mp2[s[r]]++;
            if (mp1[s[r]] == mp2[s[r]]) haveCount++;
            r++;
            while (needCount == haveCount) {
                if(window>r-l){
                    start = l;
                    window = r-l;
                }

                mp2[s[l]]--;
                if (mp1[s[l]] > mp2[s[l]]) haveCount--;
                l++;
            }
        }
        if(window==INT_MAX)return "";
        for(int i = start; i<start+window;i++){
            ans.push_back(s[i]);
        }
        return ans;

    }
};
