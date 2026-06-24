class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++; // 9 se chote to direct 10 kardo 
                return digits;
            }

            digits[i] = 0; //  agar 9 he to digit ko banao 0 or 1 ko kardo insert
        }

        digits.insert(digits.begin(), 1);
        return digits;
    }
};