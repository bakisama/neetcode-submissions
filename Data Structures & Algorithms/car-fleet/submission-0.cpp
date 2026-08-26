class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> wombocombo;

        for (int i = 0; i < position.size(); i++) {
            wombocombo.push_back({position[i], speed[i]});
        }

        sort(wombocombo.begin(), wombocombo.end());

        stack<double> st;
        vector<double> times(position.size());

        for (int i = position.size() - 1; i >= 0; i--) {
            times[i] = (double)(target - wombocombo[i].first) / wombocombo[i].second;
        }

        for (int i = times.size() - 1; i >= 0; i--) {
            if (st.empty() || st.top() < times[i]) {
                st.push(times[i]);
            }
        }

        return st.size();
    }
};