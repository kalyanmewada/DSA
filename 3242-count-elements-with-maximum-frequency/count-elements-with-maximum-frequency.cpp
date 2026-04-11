class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;

        int maxFreq = 0;

        for (int num : nums) {
            freq[num]++;
            maxFreq = max(maxFreq, freq[num]);
        }

        int total = 0;

        for (auto it : freq) {
            if (it.second == maxFreq) {
                total += maxFreq;
            }
        }

        return total;
    }
};