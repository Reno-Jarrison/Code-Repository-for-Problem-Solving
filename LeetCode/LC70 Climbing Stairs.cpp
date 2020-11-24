class Solution {
public:
    int climbStairs(int n) 
    {
        int las2 = 0, las1 = 1, cur = 0;
        for (int i = 1; i <= n; i++)
            cur = las1 + las2, las2 = las1, las1 = cur;
        return cur;
    }
};