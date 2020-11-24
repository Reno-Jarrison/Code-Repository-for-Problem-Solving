class Solution {
public:
    int inf = 0x7fffffff;
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, inf));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; i++)
            for (int j = 0; j <= i; j++)
            {
                if (j > 0) 
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                if (j < i) 
                    dp[i][j] = min(dp[i][j], dp[i-1][j]);
                dp[i][j] += triangle[i][j];
            }
        int ans = inf;
        for (int i = 0; i < n; i++)
            ans = min(ans, dp[n-1][i]);
        return ans;
    }
};