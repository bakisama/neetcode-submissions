class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<vector<int>> ans;
        vector<int> maxLeft;
        vector<int> maxRight(height.size());
        maxLeft.push_back(0);

        int tempL = 0;
        int tempR = 0;
        for(int i = 1; i<height.size();i++){
            tempL = max(tempL,height[i-1]);
            maxLeft.push_back(tempL);
        }
        for(int i = height.size()-1;i>=0;i--){
            maxRight[i] = tempR;
            tempR = max(tempR, height[i]);

        }
        int  water = 0;
        for(int i = 0; i<height.size();i++){
            int res = min(maxLeft[i],maxRight[i]) - height[i];
            if (res > 0) water += res;
        }
        return water;
    }


};
