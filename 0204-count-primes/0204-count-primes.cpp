class Solution {
public:
    int countPrimes(int n) {
        // Edge case
        if(n <= 2) return 0;
        // true -> prime, false -> not prime
        vector<bool> primes(n, true);
        primes[0] = primes[1] = false;
        // 2 is the only even prime
        for(int i = 4; i < n; i += 2) {
            primes[i] = false;
        }
        // Check only odd numbers
        for(int i = 3; i * i < n; i += 2) {
            // If i is prime
            if(primes[i]) {
                // Mark multiples of i as non-prime
                for(int j = i * i; j < n; j += 2 * i) {
                    primes[j] = false;
                }
            }
        }
        // Count primes
        int cnt = 0;
        for(int i = 2; i < n; i++) {
            if(primes[i]) {
                cnt++;
            }
        }
        return cnt;
    }
};