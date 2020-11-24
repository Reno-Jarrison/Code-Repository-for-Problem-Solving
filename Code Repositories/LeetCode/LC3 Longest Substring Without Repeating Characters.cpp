class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int len = s.size(), pt = 0, ans = 0;
        vector<bool> vis(128, false);
        for (int i = 0; i < len; i++)
        {
            int cur = s[i];
            if (vis[cur])
                while (s[pt++] != s[i])
                    vis[s[pt-1]] = false;
            vis[cur] = true;
            ans = max(ans, i - pt + 1);
        }
        return ans;
    }
};