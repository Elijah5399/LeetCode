class Solution {
    public String gcdOfStrings(String str1, String str2) {
        int len1 = str1.length(), len2 = str2.length();
        for (int i = Math.min(str2.length(), str1.length()); i > 0; i--) {
            if (i > len1 + 1) continue;
            String substr = str2.substring(0, i);
            int s_len = substr.length();
            if (len1 % s_len == 0 && len2 % s_len == 0 && str1.replaceAll(substr, "").isEmpty() && str2.replaceAll(substr, "").isEmpty()) {
                return substr;
            }
        }
        return "";
    }
}