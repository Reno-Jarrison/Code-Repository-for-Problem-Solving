class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        int size = nums.size();
        vector<bool> vis(size + 1);
        for (int x : nums)
            if(x > 0 && x <= size)
                vis[x] = true; 
        int mex = 1;
        for (int i = 1; i <= size; i++, mex++)
            if (!vis[i])
                break;
        return mex;
    } 
};