
class Solution {
private:
    long long gcd(long long a, long long b){
        // b ko bada assume kar rhe hai
        if(a > b) return gcd(b,a);
        if(a == 0) return b;
        else return gcd(a,b%a);
    }

    long long lcm(long long a, long long b){
        return (a/gcd(a,b))*b;
    }

public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long long s = 1, e = 2e9;

        // hum ek formula ka use kar sakte hai idhar
        // P(a U b U c) = P(a) + P(b) + P(c)
        // - P(a intersection b) - P(b intersection c)
        // - P(c intersection a) + P(a intersection b intersection c)

        while(s <= e){
            long long mid = s + (e-s)/2;

            long long x = (mid/a) + (mid/b) + (mid/c)
                        - (mid/lcm(a,b))
                        - (mid/lcm(a,c))
                        - (mid/lcm(b,c))
                        + (mid/lcm(a,lcm(b,c)));

            if(x < n) s = mid + 1;
            else e = mid - 1;
        }

        return (int)s;
    }
};
