class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1;
        unordered_set<int> s2;
        for (auto x : nums1) {
            s1.insert(x);
        }
        for (auto x : nums2) {
            s2.insert(x);
        }
        vector<int> n1; vector<int> n2;
        unordered_set<int> a1; unordered_set<int> a2;
        for (auto x : nums1) {
            if (!s2.count(x) && !a1.count(x)) {
                n1.push_back(x);
                a1.insert(x);
            }
        }
        for (auto x : nums2) {
            if (!s1.count(x) && !a2.count(x)) {
                n2.push_back(x);
                a2.insert(x);
            }
        }
        return vector<vector<int>>{n1, n2};
    }
};