class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
    auto countBits = [](int num) {
        int count = 0;
        while (num > 0) {
            count += num & 1;
            num >>= 1;
        }
        return count;
    };
    // Sort using custom comparator
    sort(arr.begin(), arr.end(), [&countBits](int a, int b) {
        int bitsA = countBits(a);
        int bitsB = countBits(b);
        
        // If number of 1's is different, sort by number of 1's
        if (bitsA != bitsB) {
            return bitsA < bitsB;
        }
        // If number of 1's is same, sort by value
        return a < b;
    });
    
    return arr;
}
};