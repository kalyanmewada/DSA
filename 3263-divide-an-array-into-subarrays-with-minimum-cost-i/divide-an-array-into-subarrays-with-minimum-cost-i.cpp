class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans = nums[0];
        int n = nums.size();
        int mini = INT_MAX;
        int secMini = INT_MAX;

        for(int i = 1; i<n; i++) {
            if (nums[i] < mini) {
                secMini = mini;
                mini = nums[i];
            } 
            else if (nums[i] < secMini) {
                secMini = nums[i];
            }
        }
        ans += mini + secMini;
        return ans;
    }
};