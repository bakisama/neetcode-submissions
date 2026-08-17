class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> lp;
        vector<int> rp;
        lp.push_back(nums[0]);
        rp.push_back(nums[nums.size()-1]);
        for(int i = 1; i<nums.size();i++){
            lp.push_back(lp[i-1]*nums[i]);
        }
        for(int j = nums.size()-2, i = 1;j>=0;j--,i++){
            rp.push_back(rp[i-1]*nums[j]);
        }
        reverse(rp.begin(),rp.end());
        vector<int> ans;
        ans.push_back(rp[1]);
        for(int i = 1;i<nums.size()-1;i++){
            ans.push_back(lp[i-1]*rp[i+1]);
        }
        ans.push_back(lp[nums.size()-2]);
        return ans;
    }
};
