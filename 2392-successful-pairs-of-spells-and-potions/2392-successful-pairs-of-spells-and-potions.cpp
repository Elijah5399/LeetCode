class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        vector<int> res(n, 0);
        sort(potions.begin(), potions.end());
        for (int i = 0; i < n; i++) {
            int low = 0, high = m - 1;
            int spell = spells[i];
            if ((long long)spell * potions[high] < success) {
                continue;
            }
            while (low < high) {
                int mid = low + (high - low) / 2;
                if ((long long) spell * potions[mid] >= success) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
            res[i] = m - low;
        }
        return res;
    }
};