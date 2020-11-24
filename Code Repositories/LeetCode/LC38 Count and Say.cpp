class Solution {
public:
    string countAndSay(int n) 
    {
        if (n == 1)
            return "1";
        string pre = countAndSay(n - 1), ans = "";
        char las = -1;
        int cnt = 0;
        for (char x : pre)
        {
            if (x != las)
            {
                if (las != -1)
                    ans += to_string(cnt) + las;
                las = x, cnt = 0;
            }
            cnt++;
        }
        ans += to_string(cnt) + las;
        return ans;
    }
};