class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal = prices[0];
        int maxProfit = 0;
        for(auto x:prices){
            minVal = min(minVal,x);
            int profit = x - minVal;
            maxProfit = max(maxProfit, profit);
        }
        return maxProfit;
        
    }
};
