class Solution {
public:
    long long uniquePathsWithObstacles(vector<vector<int>>& g) 
    {
        if (!g.size())
            return 0;
        int n = g.size(), m = g[0].size();
        vector<vector<long long>> dp(n, vector<long long>(m));
        dp[0][0] = !g[0][0];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (g[i][j]) 
                    continue;
                if (i > 0) 
                    dp[i][j] += dp[i-1][j];
                if (j > 0) 
                    dp[i][j] += dp[i][j-1];
            }
        return dp[n-1][m-1];
    }
};