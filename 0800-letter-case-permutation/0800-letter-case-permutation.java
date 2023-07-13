class Solution {
    public List<String> letterCasePermutation(String s) {
        List<String> l1 = new ArrayList<>();
        List<String> l2 = new ArrayList<>();
        if (Character.isDigit(s.charAt(0))) {
            l1.add(Character.toString(s.charAt(0)));
        } else {
            l1.add(Character.toString(Character.toLowerCase(s.charAt(0))));
            l1.add(Character.toString(Character.toUpperCase(s.charAt(0))));
        }
        for (int i = 1; i < s.length(); i++) {
            char c = s.charAt(i);
            Iterator<String> iter = l1.iterator();
            while (iter.hasNext()) {
                String n = iter.next();
                StringBuilder nb = new StringBuilder(n);
                if (Character.isDigit(c)) {
                    nb.append(Character.toString(c));
                    l2.add(nb.toString());
                } else {
                    nb.append(Character.toString(Character.toLowerCase(c)));
                    l2.add(nb.toString());
                    nb = nb.deleteCharAt(nb.length() - 1);
                    nb.append(Character.toString(Character.toUpperCase(c)));
                    l2.add(nb.toString());
                }
            }
            l1 = l2;
            l2 = new ArrayList<>();
        }
        return l1;
    }
}