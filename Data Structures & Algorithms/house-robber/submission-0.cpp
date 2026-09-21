class Solution {
public:

    vector<int> t = vector<int>(101, -1);

    int rob(vector<int>& nums) {
        int size = nums.size();

        t[0] = 0;

        return solver(nums, size);
    }

    int solver(vector<int>& nums, int n) {

        if(n == 0)
            return 0;

        if(n == 1)
            return nums[0];

        if(t[n] != -1)
            return t[n];

        t[n] = max(
            nums[n-1] + solver(nums, n-2),
            solver(nums, n-1)
        );

        return t[n];
    }
};