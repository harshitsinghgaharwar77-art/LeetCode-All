class Solution {
    public boolean sumGame(String num) {
        int n = num.length();
        double sum1 = 0, sum2 = 0;
        double count1 = 0, count2 = 0;
        
        // Process the first half
        for (int i = 0; i < n / 2; i++) {
            if (num.charAt(i) == '?') {
                count1++;
            } else {
                sum1 += num.charAt(i) - '0';
            }
        }
        
        // Process the second half
        for (int i = n / 2; i < n; i++) {
            if (num.charAt(i) == '?') {
                count2++;
            } else {
                sum2 += num.charAt(i) - '0';
            }
        }
        
        // If total '?' is odd, Alice gets the last move and always wins
        if ((count1 + count2) % 2 != 0) {
            return true;
        }
        
        // If Bob can perfectly balance the sums, Bob wins (return false)
        // Otherwise, Alice wins (return true)
        return (sum1 - sum2) != (count2 - count1) * 9.0 / 2.0;
    }
}