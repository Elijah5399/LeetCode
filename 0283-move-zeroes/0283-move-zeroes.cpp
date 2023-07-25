class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = nums.size();
        int j = 0;
        for (int i = 0; i < l; i++) {
            if (nums[j] == 0) {
                nums.erase(nums.begin() + j);
                nums.push_back(0);
            } else {
                j++;
            }
        }
        
    }
};