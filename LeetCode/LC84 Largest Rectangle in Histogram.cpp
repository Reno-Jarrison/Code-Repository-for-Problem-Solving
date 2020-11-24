class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        heights.push_back(0);
        stack<int> stk;
        int ans = 0, size = heights.size();
        for (int i = 0; i < size; i++)
        {
            int pt = i;
            while (!stk.empty() && heights[i] <= heights[stk.top()])
            {
                ans = max(ans, (i - stk.top()) * heights[stk.top()]);
                pt = stk.top(), stk.pop();
            }
            heights[pt] = heights[i];
            stk.push(pt);
        }
        return ans;
    }
};