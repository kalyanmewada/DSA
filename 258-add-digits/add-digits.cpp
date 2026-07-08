class Solution {
public:
    int addDigits(int num) {

        while (num >= 10) {

            int sum = 0;

            while (num > 0) {
                sum += num % 10;   // Extract last digit
                num /= 10;         // Remove last digit
            }
            
            num = sum;
        }

        return num;
    }
};