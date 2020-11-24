class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int siz = nums.size();
        map<int, int> mp;
        vector<int> ans;
        for (int i = 0; i < siz; i++)
        {
            if (mp.count(target - nums[i]))
            {
                ans.push_back(mp[target-nums[i]]);
                ans.push_back(i);
                break;
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};