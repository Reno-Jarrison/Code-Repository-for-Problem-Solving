class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int> > dp(m + 1, vector<int> (n + 1, 0));
        for (string s: strs) {
            int cnt[2] = {0};
            for (char ch: s)
                cnt[ch-'0']++;
            for (int i = m; i >= cnt[0]; i--)
                for (int j = n; j >= cnt[1]; j--)
                    dp[i][j] = max(dp[i][j], dp[i-cnt[0]][j-cnt[1]] + 1);
        }
        return dp[m][n];
    }
};

