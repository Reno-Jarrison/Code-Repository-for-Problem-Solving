class Solution {
public:
    bool isPalindrome(int x) 
    {
        long long tmp = x, rev = 0;
        while (tmp)
        	rev = rev * 10 + tmp % 10, tmp /= 10;
        return x >= 0 && x == rev;
    }
};