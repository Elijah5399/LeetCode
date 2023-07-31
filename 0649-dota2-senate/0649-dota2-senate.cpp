class Solution {
public:
    string predictPartyVictory(string senate) {
        int rRem = 0, dRem = 0, rFB = 0, dFB = 0;
        queue<char> q;
        for (char c : senate) {
            q.push(c);
            if (c == 'R') rRem++;
            else dRem++;
        }
        while (!q.empty() && rRem != 0 && dRem != 0) {
            char next = q.front();
            q.pop();
            if (next == 'R') {
                if (rFB > 0) {
                    rFB--;
                    rRem--;
                } else {
                    dFB++;
                    q.push('R');
                }
            } else {
                if (dFB > 0) {
                    dFB--;
                    dRem--;
                } else {
                    rFB++;
                    q.push('D');
                }
            }
        }
        if (rRem == 0) {
            return "Dire";
        } else {
            return "Radiant";
        }
    }
};