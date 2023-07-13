class Solution {
    public boolean find132pattern(int[] nums) {
        if (nums.length < 3) {
            return false;
        }
        Stack<Integer> s = new Stack<>();
        int[] min = new int[nums.length]; //stores minimum elements up till that index
        min[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            min[i] = Math.min(min[i - 1], nums[i]);
        }
        
        for (int i = nums.length - 1; i >= 0; i--) { //iterate from back
            if (nums[i] > min[i]) { 
                //we only consider the elem when it is greater than its min
                while (!s.isEmpty() && s.peek() <= min[i]) {
                    //this guarantees that the subsequent elements are > min[i]
                    s.pop();
                }
                if (!s.isEmpty() && s.peek() < nums[i]) {
                    return true;
                }
                if (s.isEmpty() || nums[i] <= s.peek()) {
                    s.push(nums[i]);
                }
                
            }
        }
        return false;
    }
}

/*
How the stack works:
-Iterate backwards thru array and manipulate the stack along the way
-Ensure that all elements in the stack are > min[i]. Then, our best bet for nums[k] is 
the smallest of all these elements.
-If this elem is smaller than nums[j], we have found a 132 pattern. otherwise, 
we add the current element and continue
-Assume stack is sorted in non-asc order (smallest on top)
-If nums[i] == min[i], it will never be the 2 element! so don't add it to the stack
-If nums[i] > min[i], pop the stack until we find the head is > min[i].
-After popping, all elems in stack are guaranteed to be > nums[i] (or min[j])
-
*/


//[0,2,3,5,1,2] 
//[1,1,1,1,1,1]
//[5,1,2]