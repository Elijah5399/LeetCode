class Solution {
public:
    string merge(string& first, string& second) {
        if (first.find(second) != string::npos) {
            return first;
        }
        for (int i = min(first.size(), second.size()); i > 0; i--) {
            if (first.substr(first.size() - i) == second.substr(0, i)) {
                return first + second.substr(i);
            }
        }
        return first + second;
    }
    string helper(string& a, string& b, string& c) {
        string first = merge(a, b);
        return merge(first, c);
    }
    string minimumString(string a, string b, string c) {
        vector<string> poss = 
            {helper(a, b, c), helper(a, c, b), helper(b, a, c), helper(b, c, a),
            helper(c, a, b), helper(c, b, a)};
        sort(poss.begin(), poss.end(), [&](auto one, auto two) {
            if (one.size() == two.size()) return one < two;
            return one.size() < two.size();
        });
        return poss[0];
    }
    
};