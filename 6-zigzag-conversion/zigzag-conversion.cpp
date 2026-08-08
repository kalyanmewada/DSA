class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) {
            return s;
        }

        vector<string> rows(numRows);

        int row = 0;
        bool goingDown = false;

        for (char ch : s) {
            rows[row] += ch;

            // Change direction at the top or bottom
            if (row == 0 || row == numRows - 1) {
                goingDown = !goingDown;
            }

            if (goingDown)
                row++;
            else
                row--;
        }

        string ans;

        for (string r : rows) {
            ans += r;
        }

        return ans;
    }
};