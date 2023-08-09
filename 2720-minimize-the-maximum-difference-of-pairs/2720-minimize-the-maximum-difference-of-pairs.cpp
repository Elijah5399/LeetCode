class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int low = 0 , high = 1000000009;
        sort(nums.begin(), nums.end());
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (checkLimit(mid, nums, p)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
    bool checkLimit(int allowed, vector<int>& nums, int p) {
        //cout << "allowed: " << allowed << endl;
        int i = 0, n = nums.size(), counter = 0;
        while (i < n - 1) {
            if (abs(nums[i] - nums[i + 1]) <= allowed) {
                counter++;
                i += 2;
            } else {
                i++;
            }
        }
        return counter >= p;
    }
};