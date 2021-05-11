class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int> > ans;
        vector<int> v(3);
        for (int i = 0; i < n-2; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1, r = n - 1;
            v[0] = nums[i];
            while (l < r) {
                v[1] = nums[l], v[2] = nums[r];
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) ans.push_back(v);
                if (sum <= 0) 
                    while (++l < r && nums[l] == nums[l - 1]);
                else 
                    while(l < --r && nums[r] == nums[r + 1]);
            }
        }
        return ans;
    }
};

