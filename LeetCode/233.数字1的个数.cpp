class Solution {
public:
    int num[15], dp[15][15];
    int dfs(int pos, int cnt, bool limit) {
        if (!pos) 
            return cnt;
        if (!limit && dp[pos][cnt] != -1)
            return dp[pos][cnt];
        int bound = limit ? num[pos] : 9, ans = 0;
        for (int i = 0; i <= bound; i++)
            ans += dfs(pos - 1, cnt + (i == 1), limit && i == bound);
        if (!limit) 
            dp[pos][cnt] = ans;
        return ans;
    }
    int countDigitOne(int n) {
        int len = 0;
        while (n)
            num[++len] = n % 10, n /= 10;
        memset(dp, -1, sizeof(dp));
        return dfs(len, 0, true);
    }
};