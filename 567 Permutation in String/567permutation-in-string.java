class Solution {
    static boolean compareFreq(int[] cnt1, int[] cnt2){
        for(int i = 0; i < 26; i++){
            if(cnt1[i] != cnt2[i]){
                return false;
            }
        }
        return true;
    }
    public boolean checkInclusion(String s1, String s2) {
        // algorithm
        // 1. basic check whether s1 charaacters are present in s2 or not
        // 2. make table for s1
        // 3. process first window for s2
        // 4. process the remaining windows for s2
        if(s1.length() > s2.length()){
            return false;
        }
        // frequency table for s1
        int cnt1[] = new int[26];   // constant space
        for(int i = 0; i < s1.length(); i++){
            char ch = s1.charAt(i);
            int idx = ch - 'a';
            cnt1[idx]++;
        }
        int i = 0;
        int windowLength = s1.length();
        int cnt2[] = new int[26];
        for(int j = 0; j < windowLength; j++){
            char ch = s2.charAt(j);
            int idx = ch - 'a';
            cnt2[idx]++;
        }
        if(compareFreq(cnt1, cnt2) == true){
            return true;
        }
        else
        {
            // both the frequency tables are not matching
            // processing the remaining windows
            i = windowLength;
            while(i < s2.length()){
                char newChar = s2.charAt(i);
                int newCharIdx = newChar - 'a';
                cnt2[newCharIdx]++;
                int oldCharIdx = i - windowLength;   
                char oldChar = s2.charAt(oldCharIdx);
                int frequencyTableIndexOfOldChr = oldChar - 'a';
                cnt2[frequencyTableIndexOfOldChr]--;
                if(compareFreq(cnt1, cnt2) == true){
                    return true;
                }
                i++;
            }
        }
        return false;
    }
}