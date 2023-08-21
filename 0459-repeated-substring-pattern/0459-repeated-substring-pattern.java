class Solution {
    public boolean repeatedSubstringPattern(String s) {
        int n = s.length();
        for (int i = 0; i < n / 2; i++) {
            String substr = s.substring(0, i + 1);
            if (n % (i + 1) != 0) continue;
            if (s.replaceAll(substr, "").length() == 0) return true;
        }
        return false;
    }
}