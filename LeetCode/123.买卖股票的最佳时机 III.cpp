class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (!n)
            return 0;
        vector<int> dp(n + 1);
        int ans = 0, mnv = prices[0], mxv = -mnv;
        for(int i = 1; i < n; i++) {
            mnv = min(mnv, prices[i]);
            dp[i] = max(dp[i - 1], prices[i] - mnv);
            mxv = max(mxv, dp[i] - prices[i]);
            ans = max(ans, prices[i] + mxv);
        }
        return ans;
    }
};