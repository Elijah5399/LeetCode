class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int change[] = {0, 0, 0};
        for (int x : bills) {
            int y = x - 5;
            if (y == 0) {
                change[0]++;
            } else if (y == 5) {
                if (change[0] == 0) {
                    return false;
                } else {
                    change[0]--;
                    change[1]++;
                }
            } else {
                if (change[0] >= 1 && change[1] >= 1) {
                    change[0]--; change[1]--;
                    change[2]++;
                } else if (change[0] >= 3) {
                    change[0] -= 3;
                    change[2]++;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};