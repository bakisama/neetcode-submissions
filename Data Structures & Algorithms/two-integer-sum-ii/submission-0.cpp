class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
    int n = numbers.size();
    vector<int> ans;
    //r-- as long as num[0]+num[n-1]>target
    int l = 0;
    int r = n-1;
    while(l<r){
        while(numbers[l]+numbers[r]>target)r--;
        while(numbers[l]+numbers[r]<target)l++;
        if(numbers[l]+numbers[r] == target){
            ans.push_back(l+1);
            ans.push_back(r+1);
            return ans;
        }

    }
        return ans;
    }
};
