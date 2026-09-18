class Solution {
   public:
    int arr[46];

    Solution() {
        for (int i = 0; i < 46; i++) arr[i] = -1;
    }

    int climbStairs(int n) {
        if (n == 0 || n == 1) return 1;

        if (arr[n] != -1) return arr[n];

        return arr[n] = climbStairs(n - 1) + climbStairs(n - 2);
    }
};