class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int siz = nums.size(), las = 0, nxt = 0, step = 0;
        for (int i = 0; i < siz; i++)
        {
            if (i > las)
                las = nxt, step++;
            nxt = max(nxt, i + nums[i]);
        }    
        return step;
    }
};