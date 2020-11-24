class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        if (!grid.size())
            return 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m, 0x7f7f7f7f));
        dp[0][0] = grid[0][0];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                if (i > 0)
                    dp[i][j] = min(dp[i][j], dp[i-1][j] + grid[i][j]);
                if (j > 0)
                    dp[i][j] = min(dp[i][j], dp[i][j-1] + grid[i][j]);
            }
        return dp[n-1][m-1];
    }
};