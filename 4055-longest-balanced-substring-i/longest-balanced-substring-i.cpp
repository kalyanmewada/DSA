class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 1;  
        
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                
                int minFreq = INT_MAX;
                int maxFreq = 0;
                int distinct = 0;
                
                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        distinct++;
                        minFreq = min(minFreq, freq[k]);
                        maxFreq = max(maxFreq, freq[k]);
                    }
                }
                
                if (minFreq == maxFreq) {
                    ans = max(ans, distinct * minFreq);
                }
            }
        }
        return ans;
    }
};
