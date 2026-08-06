class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt= 0 ;
        for(int i = 0; i<nums.size(); i++) {
            int temp = nums[i];
            int digit = 0 ;
            while(temp>0) {
                digit++;
                temp = temp/10;
            }
        if(digit%2==0) 
        cnt++;
        }
        return cnt;
    }
};