class Solution {
public:
    const int inf=0x3f3f3f3f;
    int minCut(string s) 
    {
        int n = s.size();
        s = " " + s;
        vector<vector<int>> tag(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; i++)
            tag[i][i] = tag[i][i-1] = 1;
        for (int i = 2; i <= n; i++)
            for (int l = 1, r = l+i-1; r <= n; l++, r++)
                if (s[l] == s[r]) 
                    tag[l][r] = tag[l+1][r-1];
        vector<int> dp(n+1, inf);
        for (int i = 1; i <= n; i++)
        {
            if (tag[1][i]) 
                dp[i] = 0;
            else
            {
                for (int j = 2; j <= i; j++)
                    if (tag[j][i])
                        dp[i] = min(dp[i], dp[j-1] + 1);
            }
        }
        return dp[n];
    }
};