class Solution {
    LinkedList<String> answer;
    public List<String> letterCombinations(String digits) {
        answer = new LinkedList<>();
        if (digits.equals("")) return answer;
        String init = digits.substring(0, 1);
        answer = helper(init);
        for (int i = 1; i < digits.length(); i++) {
            String digit = digits.substring(i, i + 1);
            List<String> poss = helper(digit);
            int len = answer.size();
            while (len > 0) {
                String next = answer.remove();
                for (int j = 0; j < poss.size(); j++) {
                    answer.add(next + poss.get(j));
                }
                len--;
            }
        }
        return answer;
    }
    private LinkedList<String> helper(String digit) {
        int num = Integer.valueOf(digit);
        LinkedList<String> ans = new LinkedList<>();
        int add = 90;
        if (num <= 6) {
            for (int i = 1; i < 4; i++) {
                int next = add + num * 3 + i;
                //System.out.println("next: " + next);
                ans.add(Character.toString((char) next));
                //System.out.println("next conv: " + (char)next);
            }
            return ans;
        } else if (num == 7) {
            ans.add("p");
            ans.add("q");
            ans.add("r");
            ans.add("s");
            return ans;
        } else if (num == 8) {
            ans.add("t");
            ans.add("u");
            ans.add("v");
            return ans;
        } else {
            ans.add("w");
            ans.add("x");
            ans.add("y");
            ans.add("z");
            return ans;
        }
        
    }
}