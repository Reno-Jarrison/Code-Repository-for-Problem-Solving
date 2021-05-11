class Solution {
public:
    int key[128];
    bool isValid(string s) {
        key['('] = -1, key[')'] = 1;
        key['{'] = -2, key['}'] = 2;
        key['['] = -3, key[']'] = 3;
        stack<int> stk;
        for (char ch: s) {
            int id = key[ch];
            if (id < 0)
                stk.push(id);
            else if (stk.empty() || (stk.top() + id)) 
                return false;
            else 
                stk.pop();
        }
        return stk.empty();
    }
};