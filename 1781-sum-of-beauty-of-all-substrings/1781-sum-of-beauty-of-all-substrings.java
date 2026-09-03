class Solution {
    public int getMinCnt(int[] freq){
        int mini = Integer.MAX_VALUE;
        for(int i = 0; i < 26; i++){
            if(freq[i] != 0){
                mini = Math.min(mini, freq[i]);
            }
        }
        return mini;
    }

    public int getMaxCnt(int[] freq){
        int maxi = 0;
        for(int i = 0; i < 26; i++){
            maxi = Math.max(maxi, freq[i]);
        }
        return maxi;
    }
    public int beautySum(String s) {
        // in brute force we use an array of 26 size O(1) as string only contains lower case store freq and find maxi-mini

        // optimal approach
        int sum = 0;
        for(int i = 0; i < s.length(); i++){
            int[] freq = new int[26]; //0
            for(int j = i; j < s.length(); j++){
                freq[s.charAt(j) - 'a']++;
                int beauty = getMaxCnt(freq) - getMinCnt(freq);
                sum += beauty;
            }
        }
        return sum;
    }
}