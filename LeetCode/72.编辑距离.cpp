class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size(), las;
        word1 = " " + word1, word2 = " " + word2;
        vector<int> dp(n2 + 1);
        for(int i = 0; i <= n2; i++)
        	dp[i] = i;
        for(int i = 1; i <= n1; i++) {
            las = dp[0], dp[0] = i;
            for(int j = 1; j <= n2; j++) {
                int val = min(dp[j], dp[j - 1]) + 1;
                val = min(val, las + (word1[i] != word2[j]));
                las = dp[j], dp[j] = val;
            }
        }
        return dp[n2];
    }
};