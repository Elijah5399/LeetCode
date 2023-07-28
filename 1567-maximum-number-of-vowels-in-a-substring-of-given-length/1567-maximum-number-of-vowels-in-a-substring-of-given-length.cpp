class Solution {
public:
    int maxVowels(string s, int k) {
        string_view sv{s};
        int len{static_cast<int>(s.length())};
        int maxVowels = 0;
        int floatingMax = 0;
        for (int i = 0; i < k; i++) {
            //get and use the first substring
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                    maxVowels++;
                    floatingMax++;
            }
        }
        for (int i = k; i < len; i++) {
            if (maxVowels == k) {
                return k;
            }
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                if (s[i - k] == 'a' || s[i - k] == 'e' ||
                 s[i - k] == 'i' || s[i - k] == 'o' || s[i - k] == 'u') {
                    //do nothing
                } else {
                    floatingMax++;
                    maxVowels = maxVowels > floatingMax ? maxVowels : floatingMax;
                }
            } else {
                if (s[i - k] == 'a' || s[i - k] == 'e' ||
                 s[i - k] == 'i' || s[i - k] == 'o' || s[i - k] == 'u') {
                    floatingMax--;
                } else {
                    //do nothing
                }
            }
        }
        return maxVowels;
    }
};