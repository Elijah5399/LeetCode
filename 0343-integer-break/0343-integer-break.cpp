class Solution {
public:
    int integerBreak(int n) {
        int res = 0;
        for (int x = 2; x <= min(58, n); x++) {
            int a = n / x;
            int b = n % x;
            int arr[x];
            for (int i = 0; i < x; i++) {
                arr[i] = a;
            }
            for (int c = 0; c < b; c++) {
                arr[c]++;
            }
            int pdt = 1;
            for (int i = 0; i < x; i++) {
                pdt *= arr[i];
            }
            res = max(res, pdt);
        }
        return res;
    }
};