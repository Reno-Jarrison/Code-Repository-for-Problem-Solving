class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bit[32];
        for (int x: nums)
            for (int i = 0; i < 32; i++)
                if (x & (1 << i))
                    bit[i] = (bit[i] + 1) % 3;
        int ans = 0;
        for (int i = 0; i < 32; i++)
            if (bit[i])
                ans |= 1 << i;
        return ans;
    }
};