class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        set<int> st;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (st.count(nums[i])) {
                continue;
            }

            int target = -(nums[i]);
            st.insert(nums[i]);

            int l = i + 1;
            int r = nums.size() - 1;

            while (l < r) {
                int sum = nums[l] + nums[r];

                if (sum > target) {
                    r--;
                } else if (sum < target) {
                    l++;
                } else {
                    temp.push_back(nums[i]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);

                    ans.push_back(temp);
                    temp.clear();

                    l++;
                    r--;

                    // Skip duplicate values
                    while (l < r && nums[l] == nums[l - 1]) l++;

                    while (l < r && nums[r] == nums[r + 1]) r--;
                }
            }
        }

        return ans;
    }
};