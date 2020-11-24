class Solution {
public:
    int dp[25][25], s[25];
    int sum(int l, int r) { return s[r] - s[l-1]; }
    bool PredictTheWinner(vector<int>& nums) 
    {
        int n = nums.size();
        for (int i = 1; i <= n; i++) 
            dp[i][i] = nums[i-1], s[i] = s[i-1] + nums[i-1];
        for (int i = 2; i <= n; i++)
            for (int l = 1, r = l+i-1; r <= n; l++, r++)
                dp[l][r] = sum(l, r) - min(dp[l+1][r], dp[l][r-1]);
        return dp[1][n] * 2 >= sum(1, n);
    }
};