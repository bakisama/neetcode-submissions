class Solution {
public:

    vector<int> t = vector<int>(101, -1);

    int rob(vector<int>& nums) {
        int size = nums.size();

        if (size == 1)
            return nums[0];

        int ans1 = solver(nums, size, 1);

        t = vector<int>(101, -1);

        int ans2 = solver(nums, size - 1, 0);

        return max(ans1, ans2);
    }

    int solver(vector<int>& nums, int n, int l) {

        if (n == l)
            return 0;

        if (n == l + 1)
            return nums[l];

        if (t[n] != -1)
            return t[n];

        t[n] = max(
            nums[n - 1] + solver(nums, n - 2, l),
            solver(nums, n - 1, l)
        );

        return t[n];
    }
};