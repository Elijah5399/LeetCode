class Solution {
    public boolean squareIsWhite(String coordinates) {
        char letter = coordinates.charAt(0);
        char number = coordinates.charAt(1);
        int ascii = (int)(letter - 'a');
        int num = Integer.valueOf(number);
        if ((ascii + num) % 2 == 0) {
            return true;
        } else {
            return false;
        }
    }
}