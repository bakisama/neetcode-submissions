class Solution {
public:

int sum_square(int n){
    int temp = 0;
    int n_copy = n;
    while(n_copy){
        int digit = n_copy%10;
        temp+= digit*digit;
        n_copy /= 10;
    }
    return temp;
}

bool isHappy(int n) {
        // how do I check that it loops infinitely?
        unordered_map<int,int> mp;
        mp.insert({n,1});
        while(n!=1){
            n = sum_square(n);
            if(n!=1) mp[n]++;
            if(mp[n]>1) return false;
            if(n==1) return true;
        }
        if(n==1) return true;
        return true;
    }
};
