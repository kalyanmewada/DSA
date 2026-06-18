class Solution {
public:
    bool isPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        return s == rev;
    }

    void getAllParts(string s, vector<string>& partitions,
                     vector<vector<string>>& ans) {

        // Base case
        if (s.size() == 0) {
            ans.push_back(partitions);
            return;
        }

        // Try every possible prefix
        for (int i = 0; i < s.size(); i++) {

            string part = s.substr(0, i + 1);

            // Only proceed if current prefix is palindrome
            if (isPalindrome(part)) {
                partitions.push_back(part);

                getAllParts(s.substr(i + 1), partitions, ans);

                // Backtrack
                partitions.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partitions;

        getAllParts(s, partitions, ans);

        return ans;
    }
};
