class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        auto s = unordered_set<int>(nums.begin(), nums.end());
        int ans = 0;
        for(auto x : s){
            int len;
            if(s.count(x-1)){
                continue;
            }
            else{
                len = 1;
                while(s.count(x+len))len++;
            }
            ans = max(ans,len);
        }
        return ans;
    }
};
