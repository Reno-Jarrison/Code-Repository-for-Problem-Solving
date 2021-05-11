class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size(), pt = 0;
        for (int i = 0; i < size; i++) {
            if (nums[i] != 0 && pt < i)
                swap(nums[i], nums[pt]);
            if (nums[pt] != 0)
                pt++;
        }
    }
};