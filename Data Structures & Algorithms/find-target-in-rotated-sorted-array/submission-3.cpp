class Solution {
public:
    int search(vector<int>& nums, int target) {
        int minE = 0;
        int r = nums.size() - 1;
        while (minE < r) {
            int mid = minE + (r - minE) / 2;

            if (nums[mid] > nums[r])
                minE = mid + 1;
            else
                r = mid;
        }
        int l = 0;
        r = nums.size() - 1;

        // Target is in right sorted half
        if (target >= nums[minE] && target <= nums[r]) {
            l = minE;

            while (l <= r) {
                int mid = l + (r - l) / 2;

                if (nums[mid] == target)
                    return mid;
                else if (nums[mid] < target)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        // Target is in left sorted half
        else {
            r = minE - 1;

            while (l <= r) {
                int mid = l + (r - l) / 2;

                if (nums[mid] == target)
                    return mid;
                else if (nums[mid] < target)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }

        return -1;
    }
};