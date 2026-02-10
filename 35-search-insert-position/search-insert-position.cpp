class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s  = 0;
        int e = nums.size();
        int mid = s+(e-s)/2;
        while(s<e) {
            if (nums[mid] < target) {
                s = mid+1;
            }
            else {
                e = mid;
            }
            mid = s+(e-s)/2;
        }
        return s;
    }
};