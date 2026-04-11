class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int> mpp;

        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }
        int hf = 0;
        for (auto i : mpp) {
            hf = max(hf, i.second);
        }
        int count = 0;
        for (auto i : mpp) {
            if (i.second == hf) {
                count++;
            }
        }
        return hf * count;
    }
};