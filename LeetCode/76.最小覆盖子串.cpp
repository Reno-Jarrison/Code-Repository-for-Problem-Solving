class Solution {
public:
    bool check(vector<int> cnt, vector<int> lim) {
        for (int i = 0; i < 52; i++)
            if (cnt[i] < lim[i])
                return false;
        return true;
    }
    int idx(char x) {   
        if (islower(x))
            return x - 'a';
        return x - 'A' + 26;
    }
    string minWindow(string s, string t) {
        vector<int> cnt(52, 0), lim(52, 0);
        for (char x: t)
            lim[idx(x)]++;
        int len = s.size(), pt = 0, minlen = len + 1, ok = 0;
        string ans = "";
        for (int i = 0; i < len; i++) {
            cnt[idx(s[i])]++;
            while (pt < len && cnt[idx(s[pt])] > lim[idx(s[pt])])
                cnt[idx(s[pt++])]--;
            if (!ok && check(cnt, lim)) 
                ok = true;
            if (ok && (i - pt + 1) < minlen)
                minlen = i - pt + 1, ans = s.substr(pt, minlen);
        }
        return ans;
    }
};