class Solution {
public:
    vector<string> ans;

    void solve(int n, string curr) {
        if(curr.length() == n) {
            ans.push_back(curr);
            return;
        }

        for(char ch : {'a','b','c'}) {
            if(curr.empty() || curr.back() != ch) {
                solve(n, curr + ch);
            }
        }
    }

    string getHappyString(int n, int k) {
        solve(n, "");

        if(ans.size() < k) return "";

        return ans[k-1];
    }
};