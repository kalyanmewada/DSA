class Solution {
public:
    vector<vector<int>> ans;

    void solve(int idx, vector<int>& nums) {
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);   // choose 
            solve(idx + 1, nums);       // explore
            swap(nums[idx], nums[i]);   // backtrack and exclude
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        solve(0, nums);
        return ans;
    }
};