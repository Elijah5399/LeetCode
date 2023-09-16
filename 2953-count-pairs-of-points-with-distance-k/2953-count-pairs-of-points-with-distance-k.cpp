
class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        int n = coordinates.size(), ans = 0;
        map<pair<int, int>, int> m;
        for (auto& coord : coordinates) {
            int x1 = coord[0], y1 = coord[1];
            for (int a = 0; a <= k; a++) {
                // iterate thru all possible x and y 
                // which could give us our ans
                int x = a ^ x1, y = (k - a) ^ y1;
                ans += m[{x, y}];
            }
            m[{x1,y1}]++;
        }
        return ans;
    }
};