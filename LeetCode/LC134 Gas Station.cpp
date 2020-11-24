class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int n = cost.size();
        int sum = 0, id = 0, mnv = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            sum += gas[i] - cost[i];;
            if (sum < mnv)
                mnv = sum, id = i;
        }
        return sum < 0 ? -1 : (id + 1) % n;
    }
};