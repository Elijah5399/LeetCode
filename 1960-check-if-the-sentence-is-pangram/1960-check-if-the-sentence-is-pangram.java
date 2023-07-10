class Solution {
    public boolean checkIfPangram(String sentence) {
        HashSet<Integer> s = new HashSet<>();
        for (int i = 0; i < 26; i++) {
            s.add(i);
        }
        for (char c : sentence.toCharArray()) {
            int x = c - 'a';
            s.remove(x);
        }
        return s.isEmpty();
    }
}