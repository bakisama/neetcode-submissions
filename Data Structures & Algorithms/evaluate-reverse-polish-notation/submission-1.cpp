class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] != "+" && tokens[i] != "-" &&
                tokens[i] != "*" && tokens[i] != "/") {

                st.push(stoi(tokens[i]));

            } else if (tokens[i] == "+") {
                int temp1 = st.top();
                st.pop();
                int temp2 = st.top();
                st.pop();
                int ans = temp1 + temp2;
                st.push(ans);
            } else if (tokens[i] == "-") {
                int temp1 = st.top();
                st.pop();
                int temp2 = st.top();
                st.pop();
                int ans = temp2 - temp1;
                st.push(ans);
            } else if (tokens[i] == "*") {
                int temp1 = st.top();
                st.pop();
                int temp2 = st.top();
                st.pop();
                int ans = temp1 * temp2;
                st.push(ans);
            } else if (tokens[i] == "/") {
                int temp1 = st.top();
                st.pop();
                int temp2 = st.top();
                st.pop();
                int ans = temp2 / temp1;
                st.push(ans);
            }
        }
        return st.top();
    }
};
