class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        s = " " + s, p = " " + p;
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, 0));
        for (int i = 1; i <= m; i++)
        {
            if (p[i] != '*') 
                break;
            dp[0][i] = true;
        }
        dp[0][0] = true;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                if (s[i] ==p[j] || p[j] == '?')
                    dp[i][j] = dp[i-1][j-1];
                else if (p[j] == '*')
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
            }
        return dp[n][m];
    }
};