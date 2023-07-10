class Solution {
    public int findComplement(int num) {
        String x = Integer.toBinaryString(num);
        StringBuilder s = new StringBuilder();
        for (char c : x.toCharArray()) {
            if (c == '1') {
                s.append('0');
            } else {
                s.append('1');
            }
        }
        String ans_str = s.toString();
        return Integer.parseUnsignedInt(ans_str, 2);
    }
}