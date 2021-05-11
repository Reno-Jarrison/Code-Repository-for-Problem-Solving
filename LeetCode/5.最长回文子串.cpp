class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), beg = 0, len = 1;
        vector<vector<bool> > dp(n, vector<bool>(n, 0));
        for (int i = 0; i < n; i++) 
            dp[i][i] = true;
        for (int i = 1; i < n; i++)
            dp[i][i - 1] = true;
        for (int i = 2; i <= n; i++)
            for (int l = 0, r = l + i - 1; r < n; l++, r++)
                if (s[l] == s[r] && dp[l + 1][r - 1])
                    dp[l][r] = true, beg = l, len = i;
        return s.substr(beg, len);
    }
};

