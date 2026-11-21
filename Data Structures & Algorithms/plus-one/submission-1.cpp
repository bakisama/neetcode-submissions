class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        long long n = 0;
        for(int i = 0; i < digits.size(); i++){
            n += digits[i] * pow(10,digits.size() - i - 1);
        }
        cout << n;
        n += 1;
        vector<int> ans;
        while(n){
            int digit = n % 10;
            ans.push_back((int)digit);
            n /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
        

    }
};
