class Solution {
public:
    bool isMatch(string s, string p) 
    {
        int n = s.size(), m = p.size();
        s = " " + s, p = " " + p;
        bool dp[n+1][m+1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = true;
        for (int i = 2; i <= m && p[i] == '*'; i += 2)
            dp[0][i] = true;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                if (p[j] == s[i] || p[j] == '.') 
                    dp[i][j] = dp[i-1][j-1];
                else if (p[j] == '*')
                {
                    dp[i][j] = dp[i][j-1] | dp[i][j-2];
                    if (s[i] == p[j-1] || p[j-1] == '.')
                        dp[i][j] |= dp[i-1][j];
                }
            }
        return dp[n][m];
    }
};