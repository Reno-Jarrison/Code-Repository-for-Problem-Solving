class Solution {
public:
    int n;
    vector<vector<int> > ans;
    vector<int> state, vis; 
    void dfs(int step, vector<int>& nums) {
        if (step == n)
            ans.push_back(state);
        for (int i = 0; i < n; i++) {
            if (vis[i]) 
                continue;
            state[step] = nums[i];
            vis[i] = 1;
            dfs(step + 1, nums);
            vis[i] = 0;
        }
    }
    vector<vector<int> > permute(vector<int>& nums) {
        n = nums.size();
        state.resize(n);
        vis.resize(n);
        dfs(0, nums);
        return ans;
    }
};