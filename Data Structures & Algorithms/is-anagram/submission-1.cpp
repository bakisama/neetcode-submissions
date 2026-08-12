class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return false;
        map<char, int> ss;
        map<char, int> tt;
        for(int i = 0; i< s.size();i++){
            ss[s[i]]++;
            tt[t[i]]++;
        }
        if(ss==tt)return true;
        return false;
    }
};
