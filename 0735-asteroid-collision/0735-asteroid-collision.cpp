class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        for (int ast : asteroids) {
            if (stk.empty() || stk.top() < 0 || ast > 0) {
                stk.push(ast);
            } else {
                //the asteroid is -ve, and top of stk is +ve
                bool add = true;
                while (!stk.empty() && stk.top() > 0) {
                    if (stk.top() == abs(ast)) {
                        add = false;
                        stk.pop();
                        break;
                    } else if (stk.top() > abs(ast)) {
                        add = false;
                        break;
                    } else {
                        stk.pop();
                    }
                }
                if (add) stk.push(ast);
            }
        }
        vector<int> ans;
        while (!stk.empty()) {
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};