class Solution {
public:
    double myPow(double x, int n) {
        long long pow = n;
        if (pow < 0) 
            x = 1 / x, pow = -pow;
        double ans = 1;
        while (pow) {
            if (pow & 1) 
                ans *= x;
            x *= x, pow >>= 1;
        }
        return ans;
    }
};