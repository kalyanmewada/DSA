class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
    int mapS[256] = {0};
    int mapT[256] = {0};

    for (int i = 0; i < s.length(); i++) {

        // agar  mappings different hai toh
        if (mapS[s[i]] != mapT[t[i]])
            return false;

        // if match than increse the count
        mapS[s[i]] = i + 1;
        mapT[t[i]] = i + 1;
    }

    return true;
    }
};