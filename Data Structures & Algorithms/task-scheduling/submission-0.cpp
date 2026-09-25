class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for (auto x : tasks) {
            mp[x]++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto x : mp) {
            pq.push({x.second, x.first});
        }
        int cycle = 0;
        while (!pq.empty()) {
            queue<pair<int, char>> temp;
            for (int i = 0; i <= n; i++) {
                if (!pq.empty()) {
                    pair<int, char> tempu = pq.top();
                    pq.pop();
                    tempu.first--;
                    cycle++;
                    if (tempu.first > 0) {
                        temp.push(tempu);
                    }
                }

                else if (!temp.empty()) {
                    cycle++;
                }
            }
            while (!temp.empty()) {
                auto x = temp.front();
                temp.pop();
                pq.push(x);
            }
        }
        return cycle;
    }
};