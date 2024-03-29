class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        int n = s.length();
        List<String> dp = new ArrayList<>();
        Set<String> wordSet = new HashSet<>(wordDict);
        for (int i = 0; i <= n; i++) {
            dp.add("");
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j <= n; j++) {
                String x = dp.get(j);
                if (wordSet.contains(s.substring(i, n - x.length()))) {
                    dp.set(i, s.substring(i, n));
                    break;
                }
            }
        }
        return dp.get(0).equals(s);
    }
}