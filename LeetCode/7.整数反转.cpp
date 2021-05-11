class Solution {
public:
    int reverse(int x) {
        long long int ans = 0;
        while (x) 
        	ans = ans * 10 + x % 10, x /= 10;
        if (ans > (1LL << 31) || ans <= - (1LL << 31))
        	return 0;
        return ans;
    }
};

