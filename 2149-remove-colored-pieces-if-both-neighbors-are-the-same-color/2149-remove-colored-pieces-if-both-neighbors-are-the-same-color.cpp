class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.length();
        int a = 0, b = 0;
        for (int i = 1; i < n - 1; i++) {
            if (colors[i - 1] == 'A' && colors[i] == 'A' && colors[i + 1] == 'A') {
                a++;
            } else if (colors[i - 1] == 'B' && colors[i] == 'B' && colors[i + 1] == 'B') {
                b++;
            }
        }
        if (a >= b + 1) {
            return true;
        } else {
            return false;
        }
    }
};