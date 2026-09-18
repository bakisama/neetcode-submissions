class Solution {
   public:
    int arr[1001];
    int minCostClimbingStairs(vector<int>& cost) {
        for (int i = 0; i < 1001; i++) {
            arr[i] = -1;
        }
        arr[0] = 0;
        arr[1] = 0;
        return solver(cost, cost.size());
    }
    int solver(vector<int>& cost, int n) {
        if (n == 0 || n == 1)
            return arr[n];
        else if (arr[n] != -1)
            return arr[n];

        return arr[n] = min(solver(cost, n - 1) + cost[n - 1], solver(cost, n - 2) + cost[n - 2]);
    }
};
