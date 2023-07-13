class Solution {
    public int maximizeGreatness(int[] nums) {
      int[] copy = nums;
      int n = nums.length;
      Arrays.sort(copy);
      LinkedList<Integer> l1 = new LinkedList<>();
      LinkedList<Integer> l2 = new LinkedList<>();
      //add items to both linked lists
      for (int i = 0; i < n; i++) {
        int elem = copy[i];
        if (elem <= copy[0]) {
          l1.add(elem); //elements which do not contribute to greatness
        } else {
          l2.add(elem); //elements which contribute to greatness
        }
      }
      int g = 0;
      for (int i = 0; i < n; i++) {
        while (!l2.isEmpty() && l2.peekFirst() <= copy[i]){
          //head no longer valid
          l1.add(l2.remove()); //transfer elements from head of l2 to tail of l1
        }
        if (l2.isEmpty()) {
          return g;
        }
        g++;
        l2.remove();
      }
      return g;
    }
}