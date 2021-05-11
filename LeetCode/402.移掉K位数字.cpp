class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stk;
        int len = num.size();
        for (int i = 0; i < len; i++) {
            while (k > 0 && !stk.empty() && stk.top() > num[i])
                stk.pop(), k--;
            stk.push(num[i]);
        }
        while (k-- && !stk.empty())
            stk.pop();
        string ans = "";
        while (!stk.empty())
            ans.insert(ans.begin(), stk.top()), stk.pop();
        int cnt = 0;
        for (char x: ans) {
            if (x == '0')
                cnt++;
            else 
                break;
        }    
        ans.erase(0, cnt);
        return ans == "" ? "0" : ans;
    }
};