class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> arr(n+1);
        // arr[i] -> ith ugly num
        // arr[n] -> nth ugly num
        int i5, i2, i3;
        // 1st ugly num
        i5 = i2 = i3 = 1;
        arr[1] = 1;
        for(int i = 2; i <= n; i++){
            int i2uglyNum = arr[i2]*2;
            int i3uglyNum = arr[i3]*3;
            int i5uglyNum = arr[i5]*5;
            int minUglyNum = min(i2uglyNum, min(i3uglyNum,i5uglyNum));
            arr[i] = minUglyNum;
            if(minUglyNum == i2uglyNum) i2++;
            if(minUglyNum == i3uglyNum) i3++;
            if(minUglyNum == i5uglyNum) i5++;
        }
        return arr[n];
    }
};