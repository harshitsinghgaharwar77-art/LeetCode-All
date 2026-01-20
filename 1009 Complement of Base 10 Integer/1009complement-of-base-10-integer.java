class Solution {
    public int bitwiseComplement(int n) {
        String bin = Integer.toBinaryString(n);
        StringBuilder sb = new StringBuilder();

        for(char c : bin.toCharArray()){
            sb.append(c == '0' ? '1' : '0');
        }
        return Integer.parseInt(sb.toString(),2);
    }
}