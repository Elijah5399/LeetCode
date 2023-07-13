class Solution {
    public boolean find132pattern(int[] nums) {
        if (nums.length < 3) {
            return false;
        }
        //use a decreasing stack to store the max values
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
                s.push(nums[i]);
            }
        }
        return false;
    }
}

//[0,2,3,5,1,2] 
//[1,1,1,1,1,1]
//[5,1,2]