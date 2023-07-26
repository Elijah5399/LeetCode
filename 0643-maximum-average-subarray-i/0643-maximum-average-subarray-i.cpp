class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l = 0, r = 0, sum = 0;
        while (r < k) {
            sum += nums[r];
            r++;
        }
        double highestAvg = (double) sum / k;
        while (r < nums.size()) {
            sum -= nums[l];
            sum += nums[r];
            l++; r++;
            highestAvg = max(highestAvg, (double) sum / k);
        }
        return highestAvg;
    }
};