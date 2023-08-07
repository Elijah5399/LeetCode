class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> v;
        int n = nums1.size();
        for (int i = 0; i < n; i++) {
            v.push_back({nums1[i], nums2[i], i});
        }
        //sort in decreasing order of the 2nd elem
        sort(v.begin(), v.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] > b[1];
        });
        long long total = 0;
        //initialize our min heap
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < k; i++) {
            total += v[i][0];
            pq.push(v[i][0]);
        }
        long long res = v[k - 1][1] * total;
        for (int i = k; i < n; i++) {
            int rmv = pq.top();
            pq.pop();
            total -= rmv;
            total += v[i][0];
            pq.push(v[i][0]);
            if (total * v[i][1] > res) {
                res = total * v[i][1];
            }
        }
        return res;
    }
};