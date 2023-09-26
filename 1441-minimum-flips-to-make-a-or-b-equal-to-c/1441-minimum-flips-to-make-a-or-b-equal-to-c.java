class Solution {
    public int minFlips(int a, int b, int c) {
        String a_string = Integer.toBinaryString(a);
        String b_string = Integer.toBinaryString(b);
        String c_string = Integer.toBinaryString(c);
        int maxLength = Math.max(a_string.length(), Math.max(b_string.length(), c_string.length()));
        while (a_string.length() < maxLength) {
            a_string = "0" + a_string;
        }
        while (b_string.length() < maxLength) {
            b_string = "0" + b_string;
        }
        while (c_string.length() < maxLength) {
            c_string = "0" + c_string;
        }
        int changeCount = 0;
        for (int i = 0; i < maxLength; i++) {
            char a_bin = a_string.charAt(i);
            char b_bin = b_string.charAt(i);
            char c_bin = c_string.charAt(i);
            if (c_bin == '0') {
                if (a_bin == '0' && b_bin == '0') {
                    continue;
                } else if (a_bin == '1' && b_bin == '1') {
                    changeCount += 2;
                } else {
                    changeCount += 1;
                }
            } else {
                if (a_bin == '1' || b_bin == '1') {
                    continue;
                } else {
                    changeCount += 1;
                }
            }
        }
        return changeCount;
    }
}