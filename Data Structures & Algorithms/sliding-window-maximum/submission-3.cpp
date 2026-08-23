class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> st;
        for(int i = 0; i<k;i++){
            st.insert(nums[i]);
        }
        vector<int> ans;
        int l = 0;
        int r = k-1;
        while(r<nums.size()){
            if(r-l+1==k){
                ans.push_back(*st.rbegin());
            }
            st.erase(st.find(nums[l]));
            l++;
            r++;
            if(r<nums.size())st.insert(nums[r]);
        }
        return ans;
        
    }
};
