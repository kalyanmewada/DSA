class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        // Count frequency of each character
        for (char c : s) {
            freq[c]++;
        }

        // Store in vector
        vector<pair<char, int>> arr(freq.begin(), freq.end());

        // Sort by frequency (descending)
        sort(arr.begin(), arr.end(),
             [](pair<char, int>& a, pair<char, int>& b) {
                 return a.second > b.second;
             });

        string ans = "";

        // Build answer
        for (auto &it : arr) {
            ans.append(it.second, it.first);
        }

        return ans;
    }
};