class Solution {
    public int compress(char[] chars) {
        int readIdx = 0;
        int writeIdx = 0;
        while(readIdx < chars.length){
            char currChar = chars[readIdx];
            int cnt = 0;
            // count duplicate character too
            while(readIdx < chars.length && currChar == chars[readIdx]){
                readIdx++;
                cnt++;
            }
            // inserting cnt and currChar in chars array
            chars[writeIdx] = currChar;
            writeIdx++;
            if(cnt > 1){
                String newStr = String.valueOf(cnt);
                for(char dig : newStr.toCharArray()){
                    chars[writeIdx] = dig;
                    writeIdx++;
                }
            }
        }
        return writeIdx;
    }
}