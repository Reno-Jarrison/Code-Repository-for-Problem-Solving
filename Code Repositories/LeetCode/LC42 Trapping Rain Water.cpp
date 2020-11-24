class Solution {
public:
    int trap(vector<int>& height)
    {
        stack<int> stk;
        int ans = 0, size = height.size();
        for (int i = 0; i < size; i++)
        {
            int curh = 0;
            while (!stk.empty() && height[i] >= height[stk.top()])
            {
                ans += (height[stk.top()] - curh) * (i - stk.top() - 1);
                curh = height[stk.top()], stk.pop();
            }
            if (!stk.empty())
                ans += (height[i] - curh) * (i - stk.top() - 1);
            stk.push(i);
        }
        return ans;
    }
};