class Solution {
public:
    bool canJump(vector<int>& nums) {
        int siz = nums.size(), pt = 0;
        for (int i = 0; i < siz; i++) {
            if (pt < i)
                return false;
            pt = max(pt, i + nums[i]);
        }    
        return true;
    }
};