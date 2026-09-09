class Solution {
    public long countCommas(long n) {

        long ans = 0;

        // Numbers having at least 4 digits
        for (long start = 1000; start <= n; start *= 1000) {

            long end = Math.min(n, start * 1000 - 1);

            long count = end - start + 1;

            // start = 1000  -> 1 comma
            // start = 1e6   -> 2 commas
            // start = 1e9   -> 3 commas
            // start = 1e12  -> 4 commas
            long commas = Long.toString(start).length() / 3;

            ans += count * commas;
        }

        return ans;
    }
}