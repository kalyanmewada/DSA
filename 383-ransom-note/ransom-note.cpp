class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        short vocab[128];
        for (char c:magazine) {
            vocab[c]++;
        }
        for (char c:ransomNote) {
            vocab[c]--;
        }
        for (short i :vocab) {
            if (i < 0) return false;
        }
        return true;
    }
};