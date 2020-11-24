class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int mnv = 0x7fffffff, ans = 0;
        for (int x : prices)
            mnv = min(mnv, x), ans = max(ans, x - mnv);
        return ans;
    }
};