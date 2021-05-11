class Solution {
public:
    bool valid(int x) {
        return x >= 10 && x <= 26; 
    }
    int numDecodings(string s) {
        int n = s.size();
        s = " " + s;
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            if (s[i] != '0')
                dp[i] = dp[i - 1];
            if (i > 1 && valid(s[i] - '0' + (s[i - 1] - '0') * 10))
                dp[i] += dp[i - 2];
        }
        return dp[n];
    }
};