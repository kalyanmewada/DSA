class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size()-1;
        sort(nums.begin(), nums.end());
        int mid = nums[n/2];
        return mid;
    }
};