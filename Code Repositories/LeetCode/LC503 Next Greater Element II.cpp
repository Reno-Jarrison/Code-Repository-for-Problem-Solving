class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        int size = nums.size();
        for (int i = 0; i < size; i++)
            nums.push_back(nums[i]);
        stack<int> stk;
        vector<int> ans(size, -1);
        for (int i = 0; i < size * 2; i++)
        {
            while (!stk.empty() && nums[i] > nums[stk.top()])
                ans[stk.top()] = nums[i], stk.pop();
            if (i < size)
               stk.push(i);
        }
        return ans;
    }
};