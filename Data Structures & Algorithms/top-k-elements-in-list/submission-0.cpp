class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto x : mp){
            pq.push({x.second,x.first}); 
        }
        for(int i = 0; i<k;i++){
            pair<int,int> temp = pq.top();
            pq.pop();
            ans.push_back(temp.second);
        }
        return ans;

    }
};
