class Solution {
public:
    long long maxSubArray(vector<int>& nums)
    {
        long long sum = 0, mnv = 0, mxv = -INT_MAX;
        for (int x : nums)
            sum += x, mxv = max(mxv, sum - mnv), mnv = min(mnv, sum);
        return mxv;
    }
};