class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] > b[1];
                 return a[0] < b[0];
             });
        int maxRight = -1;
        int remainingIntervals = 0;
       
        for (const auto& interval : intervals) {
            int currentRight = interval[1];

            if (currentRight > maxRight) {
                remainingIntervals++;
                maxRight = currentRight;
            }
        }
        return remainingIntervals;
    }
};