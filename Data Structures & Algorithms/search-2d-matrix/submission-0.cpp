class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // binary search on row [i,j] where i
        // binary search on column
        int rows = matrix.size();
        int cols = matrix[0].size();
        int l = 0;
        int r = rows-1;
        int desiredrow = -1;
        int desiredcol = -1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(target>=matrix[mid][0] && target<=matrix[mid][cols-1]){
                desiredrow = mid;
                break;
            }
            else if(target<matrix[mid][0]){
                r = mid - 1 ;
            }
            else{
                l = mid+1;
            }
        }
        l = 0;
        r = cols - 1;
        if(desiredrow!=-1){
        while(l<=r){
            int mid = l + (r-l)/2;
            if(matrix[desiredrow][mid]==target)return true;
            else if(matrix[desiredrow][mid]>target){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }}
        else return false;
        return false;
        
    }
};
