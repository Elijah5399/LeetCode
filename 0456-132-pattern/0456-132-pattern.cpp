class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int> mins(n);
        mins[0] = nums[0];
        if (n < 3) return false;
        for (int i = 1; i < n; i++) {
            mins[i] = min(mins[i - 1], nums[i]);
        }
        stack<int> stk;
        for (int j = n - 1; j >= 0; j--) {
            int curr = nums[j];
            if (curr == mins[j]) continue;
            while (!stk.empty() && stk.top() <= mins[j]) {
                stk.pop();
            }
            if (!stk.empty() && curr > stk.top()) {
                cout << "curr is: " << curr << endl;
                cout << "stk top: " << stk.top() << endl;
                return true;
            }
            stk.push(curr);
        }
        return false;
    }
};