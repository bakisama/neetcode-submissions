class Solution {
   public:
    int maxArea(vector<int>& heights) {
        // water here is basically area
        // we are trying to maximise area here
        // find max l * b
        // precompute areas ?
        // l = min(nums[i],nums[j])
        // b = j-i;
        int maxArea = 0;
        // for (int i = 0; i < heights.size() - 1; i++) {
        //     for (int j = i + 1; j < heights.size(); j++) {
        //         int area = min(heights[i], heights[j]) * (j - i);
        //         maxArea = max(area,maxArea);
        //     }
        // }
        int area;
        int l = 0;
        int r = heights.size() - 1;
        while (l < r) {
            area = min(heights[l], heights[r]) * (r - l);
            heights[l]>heights[r]?r--:l++;
            maxArea = max(area,maxArea);
        }
        return maxArea;
    }
};
