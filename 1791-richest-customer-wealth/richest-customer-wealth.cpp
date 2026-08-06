class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxsum= 0 ;
        int  m= accounts.size();
      int n = accounts[0].size();      
        for(int i = 0 ; i<m; i++) {
            int currsum = 0 ;
             for(int j = 0 ; j<n; j++) {
            currsum = currsum + accounts[i][j];

             }
        maxsum = max(maxsum , currsum);
        }
        return maxsum;
    }
};