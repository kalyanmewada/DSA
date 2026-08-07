class Solution {
public:
    bool canShip(vector<int>& weights, int days, int cap) {
        int usedDays = 1;
        int cur = 0;

        for (int w : weights) {
            if (cur + w > cap) {
                usedDays++;
                cur = w;
            } else {
                cur += w;
            }
        }

        return usedDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (canShip(weights, days, mid))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};