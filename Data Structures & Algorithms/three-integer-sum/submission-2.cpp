class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<vector<int>> ans;
        vector<int> temp;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i]==nums[i-1]) {
                continue;
            }
            int target = -(nums[i]);
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

                    while (l < r && nums[l] == nums[l - 1])
                        l++;

                    while (l < r && nums[r] == nums[r + 1])
                        r--;
                }
            }
        }

        return ans;
    }
};