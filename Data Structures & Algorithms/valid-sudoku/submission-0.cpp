class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> seen1;
        unordered_set<char> seen2;
        for(int i = 0; i<9;i+=1){
            for(int j = 0; j<9;j+=1){
                if(board[i][j]!='.'){
                if(seen1.count(board[i][j]))return false;
                seen1.insert(board[i][j]);}
                if(board[j][i]!='.'){
                if(seen2.count(board[j][i]))return false;
                seen2.insert(board[j][i]);}
            }
            seen1.clear();
            seen2.clear();
        }

        for (int block = 0; block < 9; block++) {
            unordered_set<char> seen3;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    char val = board[3 * (block / 3) + i][3 * (block % 3) + j];
                    if (val != '.') {
                        if (seen3.count(val)) return false;
                        seen3.insert(val);
                    }
                }
            }
        }
        return true;
    }
};
