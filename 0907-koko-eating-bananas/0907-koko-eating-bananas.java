class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int high = 0;
        for(int i = 0; i < piles.length; i++) {
            if (piles[i] > high) {
                high = piles[i];
            }
        }
        int low = 0;
        
        while (low < high) {
            int[] copy = new int[piles.length];
            for (int j = 0; j < piles.length; j++) {
                copy[j] = piles[j];
            }
            int mid = low + (high - low) / 2;
            if (canEat(copy, mid, h, 0)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

    public boolean canEat(int[] piles, int k, int h, int counter) {
        if (counter == piles.length && h >= 0) {
            return true;
        } else if (h < 0) {
            return false;
        } else if (k <= 0) {
            return false; 
        } else {
            int nextElement = piles[counter];
            int hoursRequired = nextElement / k;
            if (nextElement % k == 0) {
                return canEat(piles, k, h-hoursRequired, counter + 1);
            } else {
                return canEat(piles, k, h-hoursRequired-1, counter+1);
            }
        }
    }
}