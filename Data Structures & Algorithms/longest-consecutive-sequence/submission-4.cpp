class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int ans = 0;
        if(nums.size()==0)return 0;
        for(auto x : nums) s.insert(x);
        for(auto x : nums){
            int len = 0;
            if(s.count(x-1)){
                continue;
            }
            else{
                while(s.count(++x))len++;
            }
            if(len>ans)ans=len;
        }
        return ans+1;
    }
};
