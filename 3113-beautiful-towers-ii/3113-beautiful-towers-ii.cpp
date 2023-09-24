class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        vector<int> c;
        int n = maxHeights.size();
        if (n == 1) return maxHeights[0];
        
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (maxHeights[0] >= maxHeights[1]) c.push_back(0);
            } else if (i == n - 1) {
                if (maxHeights[i] >= maxHeights[i - 1]) c.push_back(n - 1);
            } else {
                if (maxHeights[i] >= maxHeights[i - 1] && maxHeights[i] >= maxHeights[i + 1] && maxHeights[i] != maxHeights[i - 1]) {
                    c.push_back(i);
                }
            }
        }
        long long res = -1;
        for (auto& x : c) {
            res = max(res, checkIfMax(maxHeights, x, n));
        }
        return res;
    }
    long long checkIfMax(vector<int>& maxHeights, int i, int n) {
        long long res = maxHeights[i];
        int low = i - 1, high = i + 1;
        int prevLow = maxHeights[i], prevHigh = maxHeights[i];
        while (low >= 0) {
            if (maxHeights[low] <= prevLow) {
                prevLow = maxHeights[low];
                res += prevLow;
            } else {   
                res += prevLow;
            }
            low--;
        }
        while (high < n) {
            if (maxHeights[high] <= prevHigh) {
                prevHigh = maxHeights[high];
                res += prevHigh;
            } else {   
                res += prevHigh;
            }
            high++;
        }
        return res;
    }
};