class Solution {
public:
    int longestValidParentheses(string s) 
    {
        s = " " + s;
        int n = s.size() - 1, ans = 0;
        vector<int> dp(n+1, 0);
        for (int i = 1; i <= n; i++)
        {
            if (s[i] == '(') 
                continue;
            if (s[i-1] == '(')
                dp[i] = dp[i-2] + 2;
            else if (s[i-dp[i-1]-1] == '(')
                dp[i] = dp[i-1] + dp[i-dp[i-1]-2] + 2;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};