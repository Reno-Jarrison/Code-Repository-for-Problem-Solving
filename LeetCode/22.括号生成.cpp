class Solution {
public:
    vector<string> generateParenthesis(int n) {
        set<string> buf;
        if(n == 0)
            buf.insert("");
        else
            for (int i = 0 ; i < n; i++) {
                vector<string> a = generateParenthesis(i);
                vector<string> b = generateParenthesis(n - i - 1);
                for (string x: a)
                    for (string y: b)
                        buf.insert("(" + x + ")" + y);
            }
        vector<string> ans;
        ans.assign(buf.begin(), buf.end());
        return ans;
    }
};