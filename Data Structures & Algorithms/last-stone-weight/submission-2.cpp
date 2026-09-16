class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto x: stones){
            pq.push(x);
        }
        while(pq.size()>1){
            int temp1 = pq.top();
            pq.pop();
            int temp2 = pq.top();
            pq.pop();
            if(temp1==temp2) continue;
            else{
                pq.push(abs(temp1-temp2));
            }
        }
        if(pq.empty()) return 0;
        return pq.top();
    }
};
