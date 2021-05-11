class Solution {
public:
    vector<char> vec[10];
    void dfs(int step, string tmp, int lim, string digits, vector<string>& ans) {
        if (step == lim) {
            if (step)
                ans.push_back(tmp);
            return;
        }
        int id = digits[step] - '0';
        for (char x: vec[id])
            dfs(step + 1, tmp + x, lim, digits, ans);
    }
    vector<string> letterCombinations(string digits) {
        for (int i = 2; i <= 6; i++)
            for (int j = 0; j < 3; j++)
                vec[i].push_back('a' + (i - 2) * 3 + j);
        for (int i = 0; i < 4; i++)
            vec[7].push_back('p' + i);
        for (int i = 0; i < 3; i++)
            vec[8].push_back('t' + i);
        for (int i = 0; i < 4; i++)
            vec[9].push_back('w' + i);
        vector<string> ans;
        dfs(0, "", digits.size(), digits, ans);
        return ans;
    }
};