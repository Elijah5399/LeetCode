class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1, maxArea = 0;
        while (l < r) {
            //cout << "l is: " << l << ", r is: " << r << endl;
            maxArea = max(maxArea, min(height[l],height[r]) * (r - l));
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return maxArea;
    }
};